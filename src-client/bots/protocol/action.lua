--
-- action executor
--

local config = require(GetScriptDirectory() .. "/config")

-- returned module
local action = {}

-- private
local LEVEL1 = "&"
local LEVEL2 = "@"
local LEVEL3 = "#"
local LEVEL4 = "%"
local LEVEL5 = "^"

-- private
local function splitString(encodedAction, sep)
  local ss = {}
  local i = 1
  for str in string.gmatch(encodedAction, "([^" .. sep .. "]+)") do
    ss[i] = str
    i = i + 1
  end
  return ss
end

-- private
local function execute(bot, act, unitHandles, droppedItemsHandles)
  -- execute debug actions
  if config.actionDebugEnabled then
    if act[1] == "90" then -- ACTION_DEBUG_DRAW_LINE
      local vs = Vector(tonumber(act[2]), tonumber(act[3]), tonumber(act[4]))
      local ve = Vector(tonumber(act[5]), tonumber(act[6]), tonumber(act[7]))
      local red = tonumber(act[8])
      local green = tonumber(act[9])
      local blue = tonumber(act[10])
      DebugDrawLine(vs, ve, red, green, blue)
    elseif act[1] == "91" then -- ACTION_DEBUG_DRAW_CIRCLE
      local c = Vector(tonumber(act[2]), tonumber(act[3]), tonumber(act[4]))
      local r = tonumber(act[5])
      local red = tonumber(act[6])
      local green = tonumber(act[7])
      local blue = tonumber(act[8])
      DebugDrawCircle(c, r, red, green, blue)
    elseif act[1] == "92" then -- ACTION_DEBUG_DRAW_TEXT
      local x = tonumber(act[2])
      local y = tonumber(act[3])
      local txt = act[4]
      local red = tonumber(act[5])
      local green = tonumber(act[6])
      local blue = tonumber(act[7])
      DebugDrawText(x, y, txt, red, green, blue)
    end
  end
  -- execute non-immediate/immediate actions
  if act[1] == "0" then -- ACTION_NONE
    -- do nothing
  elseif act[1] == "1" then -- ACTION_CLEAR_ACTIONS
    local stop = (act[2] == "1")
    bot:Action_ClearActions(stop)
  elseif act[1] == "2" then -- ACTION_MOVE_PATHFINDER
    local v = Vector(tonumber(act[2]), tonumber(act[3]), tonumber(act[4]))
    bot:Action_MoveToLocation(v)
  elseif act[1] == "3" then -- ACTION_MOVE_DIRECTLY
    local v = Vector(tonumber(act[2]), tonumber(act[3]), tonumber(act[4]))
    bot:Action_MoveDirectly(v)
  elseif act[1] == "4" then -- ACTION_MOVE_PATH
    local n = tonumber(act[2])
    local waypoints = {}
    for i=1,n do
      local v = Vector(tonumber(act[(3*i)+0]), tonumber(act[(3*i)+1]), tonumber(act[(3*i)+2]))
      table.insert(waypoints, v)
    end
    bot:Action_MovePath(waypoints)
  elseif act[1] == "5" then -- ACTION_MOVE_TO_UNIT
    local hUnit = unitHandles[tonumber(act[2])]
    if hUnit ~= nil then
      bot:Action_MoveToUnit(hUnit)
    end
  elseif act[1] == "6" then -- ACTION_ATTACK_UNIT
    local hUnit = unitHandles[tonumber(act[2])]
    local stop = (act[3] == "1")
    if hUnit ~= nil then
      bot:Action_AttackUnit(hUnit, stop)
    end
  elseif act[1] == "7" then -- ACTION_ATTACK_MOVE
    local v = Vector(tonumber(act[2]), tonumber(act[3]), tonumber(act[4]))
    bot:Action_AttackMove(v)
  elseif act[1] == "8" then -- ACTION_USE_ABILITY
    local hAbility = bot:GetAbilityInSlot(tonumber(act[2]))
    if hAbility ~= nil then
      bot:Action_UseAbility(hAbility)
    end
  elseif act[1] == "9" then -- ACTION_USE_ABILITY_ON_UNIT
    local hAbility = bot:GetAbilityInSlot(tonumber(act[2]))
    local hUnit = unitHandles[tonumber(act[3])]
    if (hAbility ~= nil) and (hUnit ~= nil) then
      bot:Action_UseAbilityOnEntity(hAbility, hUnit) 
    end
  elseif act[1] == "10" then -- ACTION_USE_ABILITY_ON_LOCATION
    local hAbility = bot:GetAbilityInSlot(tonumber(act[2]))
    local v = Vector(tonumber(act[3]), tonumber(act[4]), tonumber(act[5]))
    if hAbility ~= nil then
      bot:Action_UseAbilityOnLocation(hAbility, v) 
    end
  elseif act[1] == "11" then -- ACTION_USE_ABILITY_ON_TREE
    local hAbility = bot:GetAbilityInSlot(tonumber(act[2]))
    local treeId = tonumber(act[3])
    if hAbility ~= nil then
      bot:Action_UseAbilityOnTree(hAbility, treeId)
    end
  elseif act[1] == "12" then -- ACTION_USE_ITEM
    local hAbility = bot:GetItemInSlot(tonumber(act[2]))
    if hAbility ~= nil then
      bot:Action_UseAbility(hAbility)
    end
  elseif act[1] == "13" then -- ACTION_USE_ITEM_ON_UNIT
    local hAbility = bot:GetItemInSlot(tonumber(act[2]))
    local hUnit = unitHandles[tonumber(act[3])]
    if (hAbility ~= nil) and (hUnit ~= nil) then
      bot:Action_UseAbilityOnEntity(hAbility, hUnit) 
    end
  elseif act[1] == "14" then -- ACTION_USE_ITEM_ON_LOCATION
    local hAbility = bot:GetItemInSlot(tonumber(act[2]))
    local v = Vector(tonumber(act[3]), tonumber(act[4]), tonumber(act[5]))
    if hAbility ~= nil then
      bot:Action_UseAbilityOnLocation(hAbility, v)
    end
  elseif act[1] == "15" then -- ACTION_USE_ITEM_ON_TREE
    local hAbility = bot:GetItemInSlot(tonumber(act[2]))
    local treeId = tonumber(act[3])
    if hAbility ~= nil then
      bot:Action_UseAbilityOnTree(hAbility, treeId)
    end
  elseif act[1] == "16" then -- ACTION_PICK_UP_RUNE
    local nRune = tonumber(act[2])
    bot:Action_PickUpRune(nRune)
  elseif act[1] == "17" then -- ACTION_PICK_UP_ITEM
    local hItem = droppedItemsHandles[tonumber(act[2])]
    if hItem ~= nil then
      bot:Action_PickUpItem(hItem)
    end
  elseif act[1] == "18" then -- ACTION_DROP_ITEM
    local hAbility = bot:GetItemInSlot(tonumber(act[2]))
    local v = Vector(tonumber(act[3]), tonumber(act[4]), tonumber(act[5]))
    if hAbility ~= nil then
      bot:Action_DropItem(hAbility, v)
    end
  elseif act[1] == "19" then -- ACTION_USE_SHRINE
    local hShrine = unitHandles[tonumber(act[2])]
    if hShrine ~= nil then
      bot:Action_UseShrine(hShrine)
    end
  elseif act[1] == "20" then -- ACTION_DELAY
    local delay = tonumber(act[2])
    bot:Action_Delay(delay)
  elseif act[1] == "21" then -- ACTION_PURCHASE_ITEM
    local itemName = act[2]
    bot:ActionImmediate_PurchaseItem(itemName)
  elseif act[1] == "22" then -- ACTION_SELL_ITEM
    local hAbility = bot:GetItemInSlot(tonumber(act[2]))
    if hAbility ~= nil then
      bot:ActionImmediate_SellItem(hAbility)
    end
  elseif act[1] == "23" then -- ACTION_DISASSEMBLE_ITEM
    local hAbility = bot:GetItemInSlot(tonumber(act[2]))
    if hAbility ~= nil then
      bot:ActionImmediate_DisassembleItem(hAbility) 
    end
  elseif act[1] == "24" then -- ACTION_SET_ITEM_COMBINE_LOCK
    local hAbility = bot:GetItemInSlot(tonumber(act[2]))
    local locked = (act[3] == "1")
    if hAbility ~= nil then
      bot:ActionImmediate_SetItemCombineLock(hAbility, locked)  
    end
  elseif act[1] == "25" then -- ACTION_SWAP_ITEMS
    local slot1 = tonumber(act[2])
    local slot2 = tonumber(act[3])
    bot:ActionImmediate_SwapItems(slot1, slot2) 
  elseif act[1] == "26" then -- ACTION_COURIER
    local hCourier = GetCourier(tonumber(act[2]))
    local nActions = tonumber(act[3])
    if hCourier ~= nil then
      bot:ActionImmediate_Courier(hCourier, nActions)
    end
  elseif act[1] == "27" then -- ACTION_BUYBACK
    bot:ActionImmediate_Buyback()
  elseif act[1] == "28" then -- ACTION_GLYPH
    bot:ActionImmediate_Glyph()
  elseif act[1] == "29" then -- ACTION_LEVEL_ABILITY
    local abilityName = act[2]
    bot:ActionImmediate_LevelAbility(abilityName)
  elseif act[1] == "30" then -- ACTION_CHAT
    local msg = act[2]
    local toAll = (act[3] == "1")
    bot:ActionImmediate_Chat(msg, toAll)
  end
end

-- public
function action.perform(bot, encodedActions, unitHandles, droppedItemsHandles)
  if encodedActions == nil then return end
  local actions = splitString(encodedActions, LEVEL1)
  for k,a in pairs(actions) do
    local act = splitString(a, LEVEL2)
    execute(bot, act, unitHandles, droppedItemsHandles)
  end
end

return action
