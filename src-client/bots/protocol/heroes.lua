--
-- heroes extracted from /game/dota/scripts/npc/npc_heroes.txt
--

-- returned module
local heroes = {}

-- public
heroes.ALL_HEROES = {}
table.insert(heroes.ALL_HEROES, "npc_dota_hero_antimage")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_axe")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_bane")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_bloodseeker")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_crystal_maiden")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_drow_ranger")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_earthshaker")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_juggernaut")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_mirana")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_nevermore")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_morphling")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_phantom_lancer")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_puck")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_pudge")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_razor")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_sand_king")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_storm_spirit")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_sven")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_tiny")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_vengefulspirit")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_windrunner")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_zuus")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_kunkka")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_lina")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_lich")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_lion")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_shadow_shaman")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_slardar")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_tidehunter")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_witch_doctor")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_riki")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_enigma")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_tinker")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_sniper")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_necrolyte")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_warlock")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_beastmaster")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_queenofpain")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_venomancer")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_faceless_void")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_skeleton_king")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_death_prophet")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_phantom_assassin")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_pugna")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_templar_assassin")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_viper")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_luna")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_dragon_knight")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_dazzle")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_rattletrap")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_leshrac")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_furion")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_life_stealer")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_dark_seer")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_clinkz")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_omniknight")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_enchantress")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_huskar")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_night_stalker")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_broodmother")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_bounty_hunter")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_weaver")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_jakiro")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_batrider")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_chen")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_spectre")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_doom_bringer")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_ancient_apparition")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_ursa")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_spirit_breaker")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_gyrocopter")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_alchemist")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_invoker")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_silencer")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_obsidian_destroyer")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_lycan")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_brewmaster")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_shadow_demon")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_lone_druid")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_chaos_knight")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_meepo")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_treant")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_ogre_magi")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_undying")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_rubick")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_disruptor")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_nyx_assassin")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_naga_siren")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_keeper_of_the_light")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_wisp")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_visage")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_slark")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_medusa")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_troll_warlord")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_centaur")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_magnataur")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_shredder")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_bristleback")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_tusk")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_skywrath_mage")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_abaddon")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_elder_titan")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_legion_commander")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_ember_spirit")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_earth_spirit")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_terrorblade")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_phoenix")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_oracle")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_techies")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_winter_wyvern")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_arc_warden")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_abyssal_underlord")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_monkey_king")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_pangolier")
table.insert(heroes.ALL_HEROES, "npc_dota_hero_dark_willow")

return heroes
