--
-- CAPTAINS MODE random selector 
-- Useful for Valve's default bots as CM is not implemented
--

local heroes = require(GetScriptDirectory() .. "/protocol/heroes")

-- returned module
local randomcaptain = {}

-- public
function randomcaptain.select()
  local found = false
  while not found do
    local i = RandomInt(1, #heroes.ALL_HEROES)
    local h = heroes.ALL_HEROES[i]
    local banned = IsCMBannedHero(h)
    local picked = IsCMPickedHero(TEAM_RADIANT, h) or IsCMPickedHero(TEAM_DIRE, h)
    if not banned and not picked then
      found = true
      if IsInCMBanPhase() then
        CMBanHero(h)
      elseif IsInCMPickPhase() then
        CMPickHero(h)
      end
    end
  end
end

return randomcaptain
