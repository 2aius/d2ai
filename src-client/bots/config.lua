--
-- d2ai configuration
--

-- returned module
local config = {}

-- server port (IP is forced to be localhost)
config.server = {}
config.server[TEAM_RADIANT] = ":4101"
config.server[TEAM_DIRE] = ":4102"

-- CAPTAINS MODE selection (threshold in seconds)
config.captainThreshold = 25.0
config.captainRandom = {}
config.captainRandom[TEAM_RADIANT] = false
config.captainRandom[TEAM_DIRE] = false

-- ALL PICK fixed selection (for development/testing only)
config.allPick = {}
config.allPick[2] = "npc_dota_hero_meepo"       -- TEAM_RADIANT Player ID = 2-6
config.allPick[3] = "npc_dota_hero_axe"
config.allPick[4] = "npc_dota_hero_bane"
config.allPick[5] = "npc_dota_hero_bloodseeker"
config.allPick[6] = "npc_dota_hero_crystal_maiden"
config.allPick[7] = "npc_dota_hero_drow_ranger" -- TEAM_DIRE Player ID = 7-11
config.allPick[8] = "npc_dota_hero_earthshaker"
config.allPick[9] = "npc_dota_hero_juggernaut"
config.allPick[10] = "npc_dota_hero_mirana"
config.allPick[11] = "npc_dota_hero_nevermore"

-- debug settings
config.actionDebugEnabled = true

return config
