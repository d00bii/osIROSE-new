registerNpc(1010, {
  walk_speed        = 0,
  run_speed         = 0,
  scale             = 120,
  r_weapon          = 0,
  l_weapon          = 0,
  level             = 10,
  hp                = 100,
  attack            = 100,
  hit               = 100,
  def               = 100,
  res               = 100,
  avoid             = 100,
  attack_spd        = 100,
  is_magic_damage   = 0,
  ai_type           = 207,
  give_exp          = 30,
  drop_type         = 67,
  drop_money        = 0,
  drop_item         = 0,
  union_number      = 0,
  need_summon_count = 237,
  sell_tab0         = 237,
  sell_tab1         = 238,
  sell_tab2         = 239,
  sell_tab3         = 240,
  can_target        = 0,
  attack_range      = 200,
  npc_type          = 999,
  hit_material_type = 0,
  face_icon         = 4,
  summon_mob_type   = 4,
  quest_type        = 0,
  height            = 0
});

function OnInit(entity)
  return true
end

function OnCreate(entity)
  return true
end

function OnDelete(entity)
  return true
end

function OnDead(entity)
end

function OnDamaged(entity)
end