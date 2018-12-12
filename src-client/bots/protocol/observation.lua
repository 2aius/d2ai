--
-- observation message
--

-- returned module
local observation = {}

-- private
local LEVEL1 = "&"
local LEVEL2 = "@"
local LEVEL3 = "#"
local LEVEL4 = "%"
local LEVEL5 = "^"

-- private
local OBSERVATION_MESSAGE_TYPE = "O"

-- private
local function flagIsSet(bitfield, flag)
  return (bitfield % (2 * flag) >= flag)
end

-- private
local function getAbility(a, slot)
  local ability = {}
  table.insert(ability, slot)
  table.insert(ability, a:GetName())
  table.insert(ability, a:CanAbilityBeUpgraded() and "1" or "0")
  table.insert(ability, a:GetAutoCastState() and "1" or "0") -- isAutoCast()
  table.insert(ability, a:GetToggleState() and "1" or "0") -- isToggled()
  table.insert(ability, a:IsToggle() and "1" or "0") -- isToggle() 
  table.insert(ability, a:IsActivated() and "1" or "0")
  table.insert(ability, a:IsChanneling() and "1" or "0")
  table.insert(ability, a:IsCooldownReady() and "1" or "0")
  table.insert(ability, a:IsFullyCastable() and "1" or "0")
  table.insert(ability, a:IsHidden() and "1" or "0")
  table.insert(ability, a:IsInAbilityPhase() and "1" or "0")
  table.insert(ability, a:IsOwnersManaEnough() and "1" or "0")
  table.insert(ability, a:IsPassive() and "1" or "0")
  table.insert(ability, a:IsStealable() and "1" or "0")
  table.insert(ability, a:IsStolen() and "1" or "0")
  table.insert(ability, a:IsTrained() and "1" or "0")
  table.insert(ability, a:ProcsMagicStick() and "1" or "0")
  table.insert(ability, flagIsSet(a:GetBehavior(), ABILITY_BEHAVIOR_PASSIVE) and "1" or "0")
  table.insert(ability, flagIsSet(a:GetBehavior(), ABILITY_BEHAVIOR_NO_TARGET) and "1" or "0")
  table.insert(ability, flagIsSet(a:GetBehavior(), ABILITY_BEHAVIOR_UNIT_TARGET) and "1" or "0")
  table.insert(ability, flagIsSet(a:GetBehavior(), ABILITY_BEHAVIOR_POINT) and "1" or "0")
  table.insert(ability, flagIsSet(a:GetBehavior(), ABILITY_BEHAVIOR_AOE) and "1" or "0")
  table.insert(ability, flagIsSet(a:GetBehavior(), ABILITY_BEHAVIOR_NOT_LEARNABLE) and "1" or "0")
  table.insert(ability, flagIsSet(a:GetBehavior(), ABILITY_BEHAVIOR_CHANNELLED) and "1" or "0")
  table.insert(ability, a:GetCastPoint())
  table.insert(ability, a:GetCastRange())
  table.insert(ability, a:GetChannelledManaCostPerSecond())
  table.insert(ability, a:GetChannelTime())
  table.insert(ability, a:GetDuration())
  table.insert(ability, a:GetCooldownTimeRemaining())
  table.insert(ability, a:GetCurrentCharges())
  table.insert(ability, a:GetAbilityDamage())
  table.insert(ability, a:GetDamageType())
  table.insert(ability, a:GetHeroLevelRequiredToUpgrade())
  table.insert(ability, a:GetInitialCharges())
  table.insert(ability, a:GetLevel())
  table.insert(ability, a:GetManaCost())
  table.insert(ability, a:GetMaxLevel())
  table.insert(ability, a:GetSecondaryCharges())
  table.insert(ability, a:GetTargetTeam())
  table.insert(ability, a:GetTargetType())
  table.insert(ability, a:IsItem() and "1" or "0")
  table.insert(ability, a:CanBeDisassembled() and "1" or "0")
  table.insert(ability, a:IsCombineLocked() and "1" or "0")
  return ability
end

-- public
function observation.get()
  local obs = {}
  -- [0] OBSERVATION MESSAGE
  table.insert(obs, OBSERVATION_MESSAGE_TYPE)
  -- [1] GAME TIME
  table.insert(obs, GameTime())
  -- [2] DOTA TIME
  table.insert(obs, DotaTime())
  -- [3] PLAYER ID
  table.insert(obs, GetBot():GetPlayerID())
  -- [4] PLAYER CURRENT ACTION TYPE
  table.insert(obs, GetBot():GetCurrentActionType())
  -- [5] TIME OF DAY
  table.insert(obs, GetTimeOfDay())
  -- [6] GLYPH COOLDOWN
  table.insert(obs, GetGlyphCooldown())
  -- [7] ROSHAN KILL TIME
  table.insert(obs, GetRoshanKillTime())
  -- [8] IS COURIER AVAILABLE
  table.insert(obs, IsCourierAvailable() and "1" or "0")
  -- [9] UNITS
  local unitList = GetUnitList(UNIT_LIST_ALL)
  local unitHandles = {}
  local units = {}
  local hu = 0
  for k,u in pairs(unitList) do
    hu = hu + 1
    unitHandles[hu] = u
    local unit = {}
    table.insert(unit, hu) -- handle ID
    table.insert(unit, u:GetPlayerID())
    table.insert(unit, u:GetTeam())
    table.insert(unit, u:GetUnitName())
    table.insert(unit, u:GetCurrentActionType())
    local isControlled = (u == GetBot())
    table.insert(unit, isControlled and "1" or "0")
    table.insert(unit, u:IsHero() and "1" or "0")
    table.insert(unit, u:IsCreep() and "1" or "0")
    table.insert(unit, u:IsAncientCreep() and "1" or "0")
    table.insert(unit, u:IsBuilding() and "1" or "0")
    table.insert(unit, u:IsTower() and "1" or "0")
    table.insert(unit, u:IsFort() and "1" or "0")
    table.insert(unit, GetCourierState(u))
    table.insert(unit, u:GetCourierValue())
    table.insert(unit, IsFlyingCourier(u) and "1" or "0")
    table.insert(unit, u:IsIllusion() and "1" or "0")
    table.insert(unit, u:CanBeSeen() and "1" or "0")
    local tloc = {}
    local loc = u:GetLocation()
    table.insert(tloc, loc.x)
    table.insert(tloc, loc.y)
    table.insert(tloc, loc.z)
    table.insert(unit, table.concat(tloc, LEVEL4))
    table.insert(unit, u:GetFacing())
    local tvel = {}
    local vel = u:GetVelocity()
    table.insert(tvel, vel.x)
    table.insert(tvel, vel.y)
    table.insert(tvel, vel.z)
    table.insert(unit, table.concat(tvel, LEVEL4))
    table.insert(unit, u:GetHealth())
    table.insert(unit, u:GetMaxHealth())
    table.insert(unit, u:GetHealthRegen())
    table.insert(unit, u:GetMana())
    table.insert(unit, u:GetMaxMana())
    table.insert(unit, u:GetManaRegen())
    table.insert(unit, u:GetBaseMovementSpeed())
    table.insert(unit, u:GetCurrentMovementSpeed())
    table.insert(unit, u:IsAlive() and "1" or "0")
    table.insert(unit, u:GetRespawnTime())
    table.insert(unit, u:HasBuyback() and "1" or "0")
    table.insert(unit, u:GetBuybackCost())
    table.insert(unit, u:GetBuybackCooldown())
    table.insert(unit, u:GetRemainingLifespan())
    table.insert(unit, u:GetBaseDamage())
    table.insert(unit, u:GetBaseDamageVariance())
    table.insert(unit, u:GetAttackDamage())
    table.insert(unit, u:GetAttackRange())
    table.insert(unit, u:GetAttackSpeed())
    table.insert(unit, u:GetSecondsPerAttack())
    table.insert(unit, u:GetLastAttackTime())
    table.insert(unit, u:GetAcquisitionRange())
    table.insert(unit, u:GetAttackProjectileSpeed())
    table.insert(unit, u:GetSpellAmp())
    table.insert(unit, u:GetArmor())
    table.insert(unit, u:GetMagicResist())
    table.insert(unit, u:GetEvasion())
    table.insert(unit, u:GetBountyXP())
    table.insert(unit, u:GetBountyGoldMin())
    table.insert(unit, u:GetBountyGoldMax())
    table.insert(unit, u:GetXPNeededToLevel())
    table.insert(unit, u:GetAbilityPoints())
    table.insert(unit, u:GetLevel())
    table.insert(unit, u:GetGold())
    table.insert(unit, u:GetNetWorth())
    table.insert(unit, u:GetStashValue())
    table.insert(unit, u:GetLastHits())
    table.insert(unit, u:GetDenies())
    table.insert(unit, u:GetBoundingRadius())
    table.insert(unit, u:GetDayTimeVisionRange())
    table.insert(unit, u:GetNightTimeVisionRange())
    table.insert(unit, u:GetCurrentVisionRange())
    table.insert(unit, u:GetHealthRegenPerStr())
    table.insert(unit, u:GetManaRegenPerInt())
    table.insert(unit, u:IsChanneling() and "1" or "0")
    table.insert(unit, u:IsUsingAbility() and "1" or "0")
    table.insert(unit, u:IsCastingAbility() and "1" or "0")
    table.insert(unit, u:IsAttackImmune() and "1" or "0")
    table.insert(unit, u:IsBlind() and "1" or "0")
    table.insert(unit, u:IsBlockDisabled() and "1" or "0")
    table.insert(unit, u:IsDisarmed() and "1" or "0")
    table.insert(unit, u:IsDominated() and "1" or "0")
    table.insert(unit, u:IsEvadeDisabled() and "1" or "0")
    table.insert(unit, u:IsHexed() and "1" or "0")
    table.insert(unit, u:IsInvisible() and "1" or "0")
    table.insert(unit, u:IsInvulnerable() and "1" or "0")
    table.insert(unit, u:IsMagicImmune() and "1" or "0")
    table.insert(unit, u:IsMuted() and "1" or "0")
    table.insert(unit, u:IsNightmared() and "1" or "0")
    table.insert(unit, u:IsRooted() and "1" or "0")
    table.insert(unit, u:IsSilenced() and "1" or "0")
    table.insert(unit, u:IsSpeciallyDeniable() and "1" or "0")
    table.insert(unit, u:IsStunned() and "1" or "0")
    table.insert(unit, u:IsUnableToMiss() and "1" or "0")
    table.insert(unit, u:HasScepter() and "1" or "0")
    table.insert(unit, u:TimeSinceDamagedByAnyHero())
    table.insert(unit, u:TimeSinceDamagedByCreep())
    table.insert(unit, u:TimeSinceDamagedByTower())
    --  abilities
    local abilities = {}
    for slot = 0, 15 do
      local a = u:GetAbilityInSlot(slot)
      if a ~= nil then
        local ability = getAbility(a, slot)
        table.insert(abilities, table.concat(ability, LEVEL5))
      end
    end
    table.insert(unit, table.concat(abilities, LEVEL4))
    -- items
    local items = {}
    for slot = 0, 15 do
      local i = u:GetItemInSlot(slot)
      if i ~= nil then
        local item = getAbility(i, slot)
        table.insert(items, table.concat(item, LEVEL5))
      end
    end
    table.insert(unit, table.concat(items, LEVEL4))
    -- nearby trees
    local nearbyTrees = {}
    local trees = u:GetNearbyTrees(1500)
    if trees ~= nil then
      for k,tid in pairs(trees) do
        table.insert(nearbyTrees, tid)
      end
    end
    table.insert(unit, table.concat(nearbyTrees, LEVEL4))
    --
    table.insert(units, table.concat(unit, LEVEL3))
  end
  table.insert(obs, table.concat(units, LEVEL2))
  -- [10] DROPPED ITEMS
  local droppedItemsHandles = {}
  local droppedItems = {}
  local hdi = 0
  local droppedItemList = GetDroppedItemList()
  if droppedItemList ~= nil then
    for k,tbl in pairs(droppedItemList) do
      hdi = hdi + 1
      droppedItemsHandles[hdi] = tbl.item
      local droppedItem = {}
      table.insert(droppedItem, hdi) -- handle ID
      table.insert(droppedItem, tbl.item:GetName())
      local loc = {}
      table.insert(loc, tbl.location.x)
      table.insert(loc, tbl.location.y)
      table.insert(loc, tbl.location.z)
      table.insert(droppedItem, table.concat(loc, LEVEL4))
      table.insert(droppedItems, table.concat(droppedItem, LEVEL3))
    end
  end
  table.insert(obs, table.concat(droppedItems, LEVEL2))
  -- [11] RUNES
  local runes = {}
  local runeSpawnList = {RUNE_POWERUP_1, RUNE_POWERUP_2,
    RUNE_BOUNTY_1, RUNE_BOUNTY_2, RUNE_BOUNTY_3, RUNE_BOUNTY_4}
  for k,rs in pairs(runeSpawnList) do
    local rune = {}
    table.insert(rune, rs)
    table.insert(rune, GetRuneType(rs))
    table.insert(rune, GetRuneStatus(rs))
    table.insert(rune, GetRuneTimeSinceSeen(rs))
    table.insert(runes, table.concat(rune, LEVEL3))
  end
  table.insert(obs, table.concat(runes, LEVEL2))
  -- [12] LANE FRONTS
  local laneFronts = {}
  local lanes = {LANE_TOP, LANE_MID, LANE_BOT}
  for k,l in pairs(lanes) do
    local front = GetLaneFrontLocation(GetBot():GetTeam(), l, -300) -- slight delta
    local loc = {}
    table.insert(loc, front.x)
    table.insert(loc, front.y)
    table.insert(loc, front.z)
    table.insert(laneFronts, table.concat(loc, LEVEL3))
  end
  table.insert(obs, table.concat(laneFronts, LEVEL2))
  -- return observation
  return table.concat(obs, LEVEL1), unitHandles, droppedItemsHandles
end

return observation
