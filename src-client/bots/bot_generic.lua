--
-- Think() is executed 30 times per seconds for each bot
-- require's are shared for each RADIANT and DIRE team
--

local config = require(GetScriptDirectory() .. "/config")
local version = require(GetScriptDirectory() .. "/protocol/version")
local gameinfo = require(GetScriptDirectory() .. "/protocol/gameinfo")
local observation = require(GetScriptDirectory() .. "/protocol/observation")
local action = require(GetScriptDirectory() .. "/protocol/action")

-- non-shared variables (1 local var for each bot)
local observationInProgress = false
local pendingUnitHandles = nil
local pendingDroppedItemsHandles = nil
local pendingActions = nil

function Think()
  local team = GetTeam()
  
  if not version.sent then

    version.sent = true
    -- send VERSION message only one time per team (1 version.sent for each TEAM)
    local message = version.get()
    local httpRequest = CreateHTTPRequest(config.server[team])
    httpRequest:SetHTTPRequestRawPostBody("d2ai", message)
    httpRequest:Send(function(res) end)

  elseif not gameinfo.sent then

    gameinfo.sent = true
    -- send GAMEINFO message only one time per team (1 gameinfo.sent for each TEAM)
    local message = gameinfo.get()
    local httpRequest = CreateHTTPRequest(config.server[team])
    httpRequest:SetHTTPRequestRawPostBody("d2ai", message)
    httpRequest:Send(function(res) end)

  elseif not observationInProgress then

    observationInProgress = true
    -- perform pending actions
    action.perform(GetBot(), pendingActions, pendingUnitHandles, pendingDroppedItemsHandles)
    -- send OBSERVATION message
    local message, unitHandles, droppedItemsHandles = observation.get()
    local httpRequest = CreateHTTPRequest(config.server[team])
    httpRequest:SetHTTPRequestRawPostBody("d2ai", message)
    httpRequest:Send(function(res)
      pendingActions = res.Body
      pendingUnitHandles = unitHandles
      pendingDroppedItemsHandles = droppedItemsHandles
      observationInProgress = false
    end)

  end

end
