--
-- captain info message
--

local heroes = require(GetScriptDirectory() .. "/protocol/heroes")

-- returned module
local captaininfo = {}

-- private
local LEVEL1 = "&"
local LEVEL2 = "@"
local LEVEL3 = "#"
local LEVEL4 = "%"
local LEVEL5 = "^"

-- private
local CAPTAIN_INFO_MESSAGE_TYPE = "C"

-- public
function captaininfo.get(activeTeam)
  local cap = {}
  -- [0] CAPTAININFO MESSAGE
  table.insert(cap, CAPTAIN_INFO_MESSAGE_TYPE)
  -- [1] Team ID
  table.insert(cap, activeTeam)
  -- [2] Is Ban Phase
  table.insert(cap, IsInCMBanPhase() and "1" or "0")
  -- [3] Is Pick Phase
  table.insert(cap, IsInCMPickPhase() and "1" or "0")
  -- [4] Hero Infos
  local infos = {}
  for k,h in pairs(heroes.ALL_HEROES) do
    local info = {}
    table.insert(info, h) -- name
    table.insert(info, IsCMBannedHero(h) and "1" or "0")
    local picked = IsCMPickedHero(TEAM_RADIANT, h) or IsCMPickedHero(TEAM_DIRE, h)
    table.insert(info, picked and "1" or "0")
    table.insert(infos, table.concat(info, LEVEL3))
  end
  table.insert(cap, table.concat(infos, LEVEL2))
  return table.concat(cap, LEVEL1)
end

return captaininfo
