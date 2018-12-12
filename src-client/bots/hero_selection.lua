--
-- Think() is executed 30 times per seconds during hero selection phase
-- GetBot() is nil
--

local config = require(GetScriptDirectory() .. "/config")
local captaininfo = require(GetScriptDirectory() .. "/protocol/captaininfo")
local randomcaptain = require(GetScriptDirectory() .. "/protocol/randomcaptain")

-- non-shared variables (1 local var for each team)
local captainInProgress = false
local pendingHero = nil

function Think()

  if GetGameMode() == GAMEMODE_AP then

    -- ALL PICK fixed selection (for development/testing only)
    if GetTeam() == TEAM_RADIANT then
      SelectHero(2, config.allPick[2]);
      SelectHero(3, config.allPick[3]);
      SelectHero(4, config.allPick[4]);
      SelectHero(5, config.allPick[5]);
      SelectHero(6, config.allPick[6]);
    elseif GetTeam() == TEAM_DIRE then
      SelectHero(7, config.allPick[7]);
      SelectHero(8, config.allPick[8]);
      SelectHero(9, config.allPick[9]);
      SelectHero(10, config.allPick[10]);
      SelectHero(11, config.allPick[11]);
    end

  elseif GetGameMode() == GAMEMODE_CM then

    -- CAPTAINS MODE
    if (IsInCMBanPhase() or IsInCMPickPhase())
      and (GetCMPhaseTimeRemaining() < config.captainThreshold) then

      -- API bug: Think() is called for BOTH teams even when it is not its ban/pick phase
      -- activeTeam variable properly identify the team being active (assumes RADIANT starting)
      local activeTeam = TEAM_RADIANT
      local s = GetHeroPickState()
      if (s == HEROPICK_STATE_CM_BAN2) or (s == HEROPICK_STATE_CM_BAN4) or (s == HEROPICK_STATE_CM_BAN6)
        or (s == HEROPICK_STATE_CM_SELECT2) or (s == HEROPICK_STATE_CM_SELECT3)
        or (s == HEROPICK_STATE_CM_BAN8) or (s == HEROPICK_STATE_CM_BAN10)
        or (s == HEROPICK_STATE_CM_SELECT5) or (s == HEROPICK_STATE_CM_SELECT7)
        or (s == HEROPICK_STATE_CM_BAN11) or (s == HEROPICK_STATE_CM_SELECT10) then
        activeTeam = TEAM_DIRE
      end

      if config.captainRandom[activeTeam] then

        -- random selection (useful against Valve bots)
        randomcaptain.select()

      elseif GetTeam() == activeTeam then

        if pendingHero ~= nil then

          -- select pending hero
          if IsInCMBanPhase() then
            CMBanHero(pendingHero)
          elseif IsInCMPickPhase() then
            CMPickHero(pendingHero)
          end
          pendingHero = nil

        elseif not captainInProgress then

          -- send CAPTAININFO message
          captainInProgress = true;
          local message = captaininfo.get(activeTeam)
          local httpRequest = CreateHTTPRequest(config.server[activeTeam])
          httpRequest:SetHTTPRequestRawPostBody("d2ai", message)
          httpRequest:Send(function(res)
            pendingHero = res.Body
            captainInProgress = false
          end)

        end

      end -- activeTeam

    end -- config.captainThreshold

  else
  
    -- GAME MODE ERROR
    print("ERROR. Game mode must be CAPTAINS MODE or ALL PICK")

  end

end
