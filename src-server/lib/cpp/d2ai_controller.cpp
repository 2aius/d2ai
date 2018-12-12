#include <iostream>
#include <iomanip>
#include "d2ai_protocol.h"
#include "d2ai_controller.h"
#include "d2ai_agent.h"
#include "d2ai_util.h"

namespace d2ai {

Controller::Controller(int port, Agent *agent) : port(port),
        agent(agent), httpServer(this) {
}

void Controller::start() {
    Util::print("Controlled by agent '" + agent->getName() + "'");
    httpServer.start();
}

void Controller::process(const std::string& message, std::string& response) const {
    response = "";
    if (message.size() < 3) return; // minimum TYPE-SEP-VALUE
    std::string type{message.substr(0, 1)};
    if (type == Protocol::VERSION_MESSAGE_TYPE) {

        // Verify VERSION
        Util::print("Received Version message from client");
        std::string version{Protocol::decodeVersion(message)};
        if (version == Protocol::VERSION)
            Util::print("Client protocol version '" + version
                    + "' matches controller version");
        else Util::print("ERROR. Client protocol version '" + version
                + "' does not match controller version '"
                + Protocol::VERSION + "'");

    } else if (type == Protocol::CAPTAIN_INFO_MESSAGE_TYPE) {

        // Select Hero from CAPTAIN INFO
        CaptainInfo cap{Protocol::decodeCaptainInfo(message)};
        if (cap.isDecoded()) response = agent->select(cap);
        else Util::print("ERROR. Could not decode CaptainInfo message: " + message);

    } else if (type == Protocol::GAME_INFO_MESSAGE_TYPE) {

        // Assign GAMEINFO
        Util::print("Received GameInfo message from client");
        GameInfo info{Protocol::decodeGameInfo(message)};
        if (agent->getGameInfo().isDecoded())
            Util::print("WARNING. Ignoring GameInfo data as already assigned");
        else if (info.isDecoded()) {
            agent->setGameInfo(info);
            Util::print("GameInfo data assigned (GameTime="
                    + std::to_string(info.getGameTime())
                    + ", DotaTime=" + std::to_string(info.getDotaTime()) +")");
        } else Util::print("ERROR. Could not decode GameInfo message");

    } else if ((type == Protocol::OBSERVATION_MESSAGE_TYPE)
            && agent->getGameInfo().isDecoded()) {

        // Process OBSERVATION after GAMEINFO is received
        Observation obs{Protocol::decodeObservation(message,
                agent->getGameInfo().getAlliedTeamId(),
                agent->getGameInfo().getEnemyTeamId())};
        if (obs.isDecoded()) {
            if (controlledPlayers.find(obs.getPlayerId())
                    == controlledPlayers.end()) {
                controlledPlayers.insert(obs.getPlayerId());
                Util::print("Controlling '"
                        + (agent->getGameInfo().getPlayers().find(
                                obs.getPlayerId())->second).getHeroName()
                        + "' (PlayerId=" + std::to_string(obs.getPlayerId()) + ")");
            }
            response = Protocol::encodeActions(agent->process(obs));
        } else Util::print("ERROR. Could not decode Observation message");

    }
}

} /* namespace d2ai */
