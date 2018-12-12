--
-- game info message
--

local items = require(GetScriptDirectory() .. "/protocol/items")

-- returned module
local gameinfo = {}

-- public
gameinfo.sent = false

-- private
local LEVEL1 = "&"
local LEVEL2 = "@"
local LEVEL3 = "#"
local LEVEL4 = "%"
local LEVEL5 = "^"

-- private
local GAME_INFO_MESSAGE_TYPE = "I"

-- public
function gameinfo.get()
  local info = {}
  -- [0] GAMEINFO MESSAGE
  table.insert(info, GAME_INFO_MESSAGE_TYPE)
  -- [1] GAME TIME
  table.insert(info, GameTime())
  -- [2] DOTA TIME
  table.insert(info, DotaTime())
  -- [3] DAMAGE TYPE ENUM
  local enum = {}
  table.insert(enum, DAMAGE_TYPE_PHYSICAL)
  table.insert(enum, DAMAGE_TYPE_MAGICAL)
  table.insert(enum, DAMAGE_TYPE_PURE)
  table.insert(enum, DAMAGE_TYPE_ALL)
  table.insert(info, table.concat(enum, LEVEL2))
  -- [4] TEAM ENUM
  enum = {}
  table.insert(enum, TEAM_RADIANT)
  table.insert(enum, TEAM_DIRE)
  table.insert(enum, TEAM_NEUTRAL)
  table.insert(enum, TEAM_NONE)
  table.insert(info, table.concat(enum, LEVEL2))
  -- [5] RUNE TYPE ENUM
  enum = {}
  table.insert(enum, RUNE_INVALID)
  table.insert(enum, RUNE_DOUBLEDAMAGE)
  table.insert(enum, RUNE_HASTE)
  table.insert(enum, RUNE_ILLUSION)
  table.insert(enum, RUNE_INVISIBILITY)
  table.insert(enum, RUNE_REGENERATION)
  table.insert(enum, RUNE_BOUNTY)
  table.insert(enum, RUNE_ARCANE)
  table.insert(info, table.concat(enum, LEVEL2))
  -- [6] RUNE STATUS ENUM
  enum = {}
  table.insert(enum, RUNE_STATUS_UNKNOWN)
  table.insert(enum, RUNE_STATUS_AVAILABLE)
  table.insert(enum, RUNE_STATUS_MISSING)
  table.insert(info, table.concat(enum, LEVEL2))
  -- [7] RUNE SPAWN ENUM
  enum = {}
  table.insert(enum, RUNE_POWERUP_1)
  table.insert(enum, RUNE_POWERUP_2)
  table.insert(enum, RUNE_BOUNTY_1)
  table.insert(enum, RUNE_BOUNTY_2)
  table.insert(enum, RUNE_BOUNTY_3)
  table.insert(enum, RUNE_BOUNTY_4)
  table.insert(info, table.concat(enum, LEVEL2))
  -- [8] ITEM SLOT ENUM
  enum = {}
  table.insert(enum, ITEM_SLOT_TYPE_INVALID)
  table.insert(enum, ITEM_SLOT_TYPE_MAIN)
  table.insert(enum, ITEM_SLOT_TYPE_BACKPACK)
  table.insert(enum, ITEM_SLOT_TYPE_STASH)
  table.insert(info, table.concat(enum, LEVEL2))
  -- [9] BOT ACTION TYPE ENUM
  enum = {}
  table.insert(enum, BOT_ACTION_TYPE_NONE)
  table.insert(enum, BOT_ACTION_TYPE_IDLE)
  table.insert(enum, BOT_ACTION_TYPE_MOVE_TO)
  table.insert(enum, BOT_ACTION_TYPE_MOVE_TO_DIRECTLY)
  table.insert(enum, BOT_ACTION_TYPE_ATTACK)
  table.insert(enum, BOT_ACTION_TYPE_ATTACKMOVE)
  table.insert(enum, BOT_ACTION_TYPE_USE_ABILITY)
  table.insert(enum, BOT_ACTION_TYPE_PICK_UP_RUNE)
  table.insert(enum, BOT_ACTION_TYPE_PICK_UP_ITEM)
  table.insert(enum, BOT_ACTION_TYPE_DROP_ITEM)
  table.insert(enum, BOT_ACTION_TYPE_SHRINE)
  table.insert(enum, BOT_ACTION_TYPE_DELAY)
  table.insert(info, table.concat(enum, LEVEL2))
  -- [10] COURIER ACTION ENUM
  enum = {}
  table.insert(enum, COURIER_ACTION_BURST)
  table.insert(enum, COURIER_ACTION_ENEMY_SECRET_SHOP)
  table.insert(enum, COURIER_ACTION_RETURN)
  table.insert(enum, COURIER_ACTION_SECRET_SHOP)
  table.insert(enum, COURIER_ACTION_SIDE_SHOP)
  table.insert(enum, COURIER_ACTION_SIDE_SHOP2)
  table.insert(enum, COURIER_ACTION_TAKE_STASH_ITEMS)
  table.insert(enum, COURIER_ACTION_TAKE_AND_TRANSFER_ITEMS)
  table.insert(enum, COURIER_ACTION_TRANSFER_ITEMS)
  table.insert(info, table.concat(enum, LEVEL2))
  -- [11] COURIER STATE ENUM
  enum = {}
  table.insert(enum, COURIER_STATE_IDLE)
  table.insert(enum, COURIER_STATE_AT_BASE)
  table.insert(enum, COURIER_STATE_MOVING)
  table.insert(enum, COURIER_STATE_DELIVERING_ITEMS)
  table.insert(enum, COURIER_STATE_RETURNING_TO_BASE)
  table.insert(enum, COURIER_STATE_DEAD)
  table.insert(info, table.concat(enum, LEVEL2))
  -- [12] SHOP ENUM
  enum = {}
  table.insert(enum, SHOP_HOME)
  table.insert(enum, SHOP_SIDE)
  table.insert(enum, SHOP_SECRET)
  table.insert(enum, SHOP_SIDE2)
  table.insert(enum, SHOP_SECRET2)
  table.insert(info, table.concat(enum, LEVEL2))
  -- [13] ABILITY TARGET TEAM ENUM
  enum = {}
  table.insert(enum, ABILITY_TARGET_TEAM_NONE)
  table.insert(enum, ABILITY_TARGET_TEAM_FRIENDLY)
  table.insert(enum, ABILITY_TARGET_TEAM_ENEMY)
  table.insert(info, table.concat(enum, LEVEL2))
  -- [14] ABILITY TARGET TYPE ENUM
  enum = {}
  table.insert(enum, ABILITY_TARGET_TYPE_NONE)
  table.insert(enum, ABILITY_TARGET_TYPE_HERO)
  table.insert(enum, ABILITY_TARGET_TYPE_CREEP)
  table.insert(enum, ABILITY_TARGET_TYPE_BUILDING)
  table.insert(enum, ABILITY_TARGET_TYPE_COURIER)
  table.insert(enum, ABILITY_TARGET_TYPE_OTHER)
  table.insert(enum, ABILITY_TARGET_TYPE_TREE)
  table.insert(enum, ABILITY_TARGET_TYPE_BASIC)
  table.insert(enum, ABILITY_TARGET_TYPE_ALL)
  table.insert(info, table.concat(enum, LEVEL2))
  -- [15] LANE ENUM
  enum = {}
  table.insert(enum, LANE_NONE)
  table.insert(enum, LANE_TOP)
  table.insert(enum, LANE_MID)
  table.insert(enum, LANE_BOT)
  table.insert(info, table.concat(enum, LEVEL2))
  -- [16] Allied Team ID
  table.insert(info, GetTeam())
  -- [17] Enemy Team ID
  table.insert(info, GetOpposingTeam())
  -- [18] Players
  local players = {}
  local teamIds = {TEAM_RADIANT, TEAM_DIRE}
  for k,tid in pairs(teamIds) do
    local playerIds = GetTeamPlayers(tid)
    for k,pid in pairs(playerIds) do
      local player = {}
      table.insert(player, tid)
      table.insert(player, pid)
      table.insert(player, GetSelectedHeroName(pid))
      table.insert(player, IsPlayerBot(pid) and "1" or "0")
      table.insert(players, table.concat(player, LEVEL3))
    end
  end
  table.insert(info, table.concat(players, LEVEL2))
  -- [19] World Bounds min X
  local wb = GetWorldBounds()
  table.insert(info, wb[1])
  -- [20] World Bounds min Y
  table.insert(info, wb[2])
  -- [21] World Bounds max X
  table.insert(info, wb[3])
  -- [22] World Bounds max Y
  table.insert(info, wb[4])
  -- [23] Shop Locations
  local locations = {}
  local shops = {SHOP_HOME, SHOP_SIDE, SHOP_SECRET, SHOP_SIDE2, SHOP_SECRET2}
  for k,tid in pairs(teamIds) do
    for k,sid in pairs(shops) do
      local sloc = GetShopLocation(tid, sid)
      local location = {}
      table.insert(location, sloc.x)
      table.insert(location, sloc.y)
      table.insert(location, sloc.z)
      table.insert(locations, table.concat(location, LEVEL3))
    end
  end
  table.insert(info, table.concat(locations, LEVEL2))
  -- [24] Rune Spawn Locations
  locations = {}
  local spawns = {RUNE_POWERUP_1, RUNE_POWERUP_2,
    RUNE_BOUNTY_1, RUNE_BOUNTY_2, RUNE_BOUNTY_3, RUNE_BOUNTY_4}
  for k,sid in pairs(spawns) do
    local sloc = GetRuneSpawnLocation(sid)
    local location = {}
    table.insert(location, sloc.x)
    table.insert(location, sloc.y)
    table.insert(location, sloc.z)
    table.insert(locations, table.concat(location, LEVEL3))
  end
  table.insert(info, table.concat(locations, LEVEL2))
  -- [25] Ancient Locations
  locations = {}
  for k,tid in pairs(teamIds) do
    local a = GetAncient(tid)
    local aloc = a:GetLocation()
    local location = {}
    table.insert(location, aloc.x)
    table.insert(location, aloc.y)
    table.insert(location, aloc.z)
    table.insert(locations, table.concat(location, LEVEL3))
  end
  table.insert(info, table.concat(locations, LEVEL2))
  -- [26] Items
  local itemInfos = {}
  for k,i in pairs(items.ALL_ITEMS) do
    local itemInfo = {}
    table.insert(itemInfo, i) -- name
    table.insert(itemInfo, GetItemCost(i))
    table.insert(itemInfo, IsItemPurchasedFromSecretShop(i) and "1" or "0")
    table.insert(itemInfo, IsItemPurchasedFromSideShop(i) and "1" or "0")
    table.insert(itemInfos, table.concat(itemInfo, LEVEL3))
  end
  table.insert(info, table.concat(itemInfos, LEVEL2))
  -- return gameinfo
  return table.concat(info, LEVEL1)
end

return gameinfo
