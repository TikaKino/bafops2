class B_Soldier_base_F;
class TIKA_BF2_Armciv_BASE: B_Soldier_base_F {
	side = 0;
	modelSides[] = {3,2,1,0};
	vehicleClass = "TIKA_BF2_Armciv";
	editorCategory = "TIKA_BF2_Armciv";
	uniformClass = "U_I_C_Soldier_Bandit_3_F";
	identityTypes[] = {"LanguageENG_F","Head_NATO","NoGlasses"};
	weapons[] = {Throw, Put};
	respawnWeapons[] = {Throw, Put};
	magazines[] = {};
	respawnMagazines[] = {};
	items[] = {ACE_fieldDressing,ACE_fieldDressing};
	respawnItems[] = {ACE_fieldDressing,ACE_fieldDressing};
	linkedItems[] = {};
	respawnLinkedItems[] = {};
};

class TIKA_BF2_Armciv_G17_O: TIKA_BF2_Armciv_BASE {
	displayName = "Armed Civilian (Glock 17 Pistol)";
	weapons[] = {rhsusf_weap_glock17g4, Throw, Put};
	respawnWeapons[] = {rhsusf_weap_glock17g4, Throw, Put};
	magazines[] = {rhsusf_mag_17Rnd_9x19_JHP};
	respawnMagazines[] = {rhsusf_mag_17Rnd_9x19_JHP};
	INSCOPE;
};
class TIKA_BF2_Armciv_G17_I: TIKA_BF2_Armciv_G17_O {
	side = 2;
};
class TIKA_BF2_Armciv_G17_B: TIKA_BF2_Armciv_G17_O {
	side = 1;
};

class TIKA_BF2_Armciv_M590_O: TIKA_BF2_Armciv_BASE {
	displayName = "Armed Civilian (M590 Shotgun)";
	uniformClass = "U_I_C_Soldier_Bandit_2_F";
	weapons[] = {rhs_weap_M590_5RD, Throw, Put};
	respawnWeapons[] = {rhs_weap_M590_5RD, Throw, Put};
	magazines[] = {rhsusf_5Rnd_00Buck,rhsusf_5Rnd_00Buck,rhsusf_5Rnd_Slug};
	respawnMagazines[] = {rhsusf_5Rnd_00Buck,rhsusf_5Rnd_00Buck,rhsusf_5Rnd_Slug};
	linkedItems[] = {H_Booniehat_oli};
	respawnLinkedItems[] = {H_Booniehat_oli};
	INSCOPE;
};
class TIKA_BF2_Armciv_M590_I: TIKA_BF2_Armciv_M590_O {
	side = 2;
};
class TIKA_BF2_Armciv_M590_B: TIKA_BF2_Armciv_M590_O {
	side = 1;
};

class TIKA_BF2_Armciv_TT33_O: TIKA_BF2_Armciv_BASE {
	displayName = "Armed Civilian (TT-33 Pistol)";
	uniformClass = "U_IG_Guerilla3_1";
	weapons[] = {rhs_weap_tt33, Throw, Put};
	respawnWeapons[] = {rhs_weap_tt33, Throw, Put};
	magazines[] = {rhs_mag_762x25_8,rhs_mag_762x25_8};
	respawnMagazines[] = {rhs_mag_762x25_8,rhs_mag_762x25_8};
	linkedItems[] = {rhs_beanie_green};
	respawnLinkedItems[] = {rhs_beanie_green};
	INSCOPE;
};
class TIKA_BF2_Armciv_TT33_I: TIKA_BF2_Armciv_TT33_O {
	side = 2;
};
class TIKA_BF2_Armciv_TT33_B: TIKA_BF2_Armciv_TT33_O {
	side = 1;
};

class TIKA_BF2_Armciv_Mosin_O: TIKA_BF2_Armciv_BASE {
	displayName = "Armed Civilian (Mosin-Nagant Rifle)";
	uniformClass = "U_IG_Guerilla2_1";
	weapons[] = {rhs_weap_m38, Throw, Put};
	respawnWeapons[] = {rhs_weap_m38, Throw, Put};
	magazines[] = {rhsgref_5Rnd_762x54_m38,rhsgref_5Rnd_762x54_m38};
	respawnMagazines[] = {rhsgref_5Rnd_762x54_m38,rhsgref_5Rnd_762x54_m38};
	linkedItems[] = {H_Cap_tan};
	respawnLinkedItems[] = {H_Cap_tan};
	INSCOPE;
};
class TIKA_BF2_Armciv_Mosin_I: TIKA_BF2_Armciv_Mosin_O {
	side = 2;
};
class TIKA_BF2_Armciv_Mosin_B: TIKA_BF2_Armciv_Mosin_O {
	side = 1;
};

class TIKA_BF2_Armciv_PM_O: TIKA_BF2_Armciv_BASE {
	displayName = "Armed Civilian (PM Pistol)";
	uniformClass = "U_IG_Guerilla2_3";
	weapons[] = {rhs_weap_makarov_pm, Throw, Put};
	respawnWeapons[] = {rhs_weap_makarov_pm, Throw, Put};
	magazines[] = {rhs_mag_9x18_8_57N181S,rhs_mag_9x18_8_57N181S};
	respawnMagazines[] = {rhs_mag_9x18_8_57N181S,rhs_mag_9x18_8_57N181S};
	linkedItems[] = {H_Hat_Safari_olive_F};
	respawnLinkedItems[] = {H_Hat_Safari_olive_F};
	INSCOPE;
};
class TIKA_BF2_Armciv_PM_I: TIKA_BF2_Armciv_PM_O {
	side = 2;
};
class TIKA_BF2_Armciv_PM_B: TIKA_BF2_Armciv_PM_O {
	side = 1;
};

class TIKA_BF2_Armciv_Izh_O: TIKA_BF2_Armciv_BASE {
	displayName = "Armed Civilian (IZh-18 Shotgun)";
	uniformClass = "U_IG_Guerrilla_6_1";
	weapons[] = {rhs_weap_Izh18, Throw, Put};
	respawnWeapons[] = {rhs_weap_Izh18, Throw, Put};
	magazines[] = {rhsgref_1Rnd_00Buck,rhsgref_1Rnd_00Buck,rhsgref_1Rnd_00Buck,rhsgref_1Rnd_00Buck,rhsgref_1Rnd_Slug,rhsgref_1Rnd_Slug,rhsgref_1Rnd_Slug,rhsgref_1Rnd_Slug};
	respawnMagazines[] = {rhsgref_1Rnd_00Buck,rhsgref_1Rnd_00Buck,rhsgref_1Rnd_00Buck,rhsgref_1Rnd_00Buck,rhsgref_1Rnd_Slug,rhsgref_1Rnd_Slug,rhsgref_1Rnd_Slug,rhsgref_1Rnd_Slug};
	linkedItems[] = {H_Beret_blk};
	respawnLinkedItems[] = {H_Beret_blk};
	INSCOPE;
};
class TIKA_BF2_Armciv_Izh_I: TIKA_BF2_Armciv_Izh_O {
	side = 2;
};
class TIKA_BF2_Armciv_Izh_B: TIKA_BF2_Armciv_Izh_O {
	side = 1;
};

class TIKA_BF2_Armciv_PP2K_O: TIKA_BF2_Armciv_BASE {
	displayName = "Armed Civilian (PP-2000 SMG)";
	uniformClass = "U_IG_Guerilla3_1";
	weapons[] = {rhs_weap_pp2000, Throw, Put};
	respawnWeapons[] = {rhs_weap_pp2000, Throw, Put};
	magazines[] = {rhs_mag_9x19mm_7n21_20,rhs_mag_9x19mm_7n21_20};
	respawnMagazines[] = {rhs_mag_9x19mm_7n21_20,rhs_mag_9x19mm_7n21_20};
	linkedItems[] = {H_StrawHat_dark};
	respawnLinkedItems[] = {H_StrawHat_dark};
	INSCOPE;
};
class TIKA_BF2_Armciv_PP2K_I: TIKA_BF2_Armciv_PP2K_O {
	side = 2;
};
class TIKA_BF2_Armciv_PP2K_B: TIKA_BF2_Armciv_PP2K_O {
	side = 1;
};

class TIKA_BF2_Armciv_M70_O: TIKA_BF2_Armciv_BASE {
	displayName = "Armed Civilian (M70 Rifle)";
	uniformClass = "U_IG_Guerilla3_1";
	weapons[] = {rhs_weap_m70b3n, Throw, Put};
	respawnWeapons[] = {rhs_weap_m70b3n, Throw, Put};
	magazines[] = {rhssaf_30Rnd_762x39mm_M67,rhssaf_30Rnd_762x39mm_M67};
	respawnMagazines[] = {rhssaf_30Rnd_762x39mm_M67,rhssaf_30Rnd_762x39mm_M67};
	linkedItems[] = {H_Hat_Safari_olive_F};
	respawnLinkedItems[] = {H_Hat_Safari_olive_F};
	INSCOPE;
};
class TIKA_BF2_Armciv_M70_I: TIKA_BF2_Armciv_M70_O {
	side = 2;
};
class TIKA_BF2_Armciv_M70_B: TIKA_BF2_Armciv_M70_O {
	side = 1;
};

class TIKA_BF2_Armciv_M14_O: TIKA_BF2_Armciv_BASE {
	displayName = "Armed Civilian (M14 Rifle)";
	uniformClass = "U_IG_Guerilla2_1";
	weapons[] = {rhs_weap_m14, Throw, Put};
	respawnWeapons[] = {rhs_weap_m14, Throw, Put};
	magazines[] = {rhsusf_20Rnd_762x51_m80_Mag,rhsusf_20Rnd_762x51_m80_Mag};
	respawnMagazines[] = {rhsusf_20Rnd_762x51_m80_Mag,rhsusf_20Rnd_762x51_m80_Mag};
	linkedItems[] = {H_WirelessEarpiece_F};
	respawnLinkedItems[] = {H_WirelessEarpiece_F};
	INSCOPE;
};
class TIKA_BF2_Armciv_M14_I: TIKA_BF2_Armciv_M14_O {
	side = 2;
};
class TIKA_BF2_Armciv_M14_B: TIKA_BF2_Armciv_M14_O {
	side = 1;
};

class TIKA_BF2_Armciv_L1A1_O: TIKA_BF2_Armciv_BASE {
	displayName = "Armed Civilian (L1A1 Rifle)";
	uniformClass = "U_IG_Guerrilla_6_1";
	weapons[] = {rhs_weap_l1a1_wood, Throw, Put};
	respawnWeapons[] = {rhs_weap_l1a1_wood, Throw, Put};
	magazines[] = {rhs_mag_20Rnd_762x51_m80_fnfal,rhs_mag_20Rnd_762x51_m80_fnfal};
	respawnMagazines[] = {rhs_mag_20Rnd_762x51_m80_fnfal,rhs_mag_20Rnd_762x51_m80_fnfal};
	linkedItems[] = {H_Cap_red};
	respawnLinkedItems[] = {H_Cap_red};
	INSCOPE;
};
class TIKA_BF2_Armciv_L1A1_I: TIKA_BF2_Armciv_L1A1_O {
	side = 2;
};
class TIKA_BF2_Armciv_L1A1_B: TIKA_BF2_Armciv_L1A1_O {
	side = 1;
};

class TIKA_BF2_Armciv_AKM_O: TIKA_BF2_Armciv_BASE {
	displayName = "Armed Civilian (AKM Rifle)";
	uniformClass = "U_OG_Guerilla2_3";
	weapons[] = {rhs_weap_akm, Throw, Put};
	respawnWeapons[] = {rhs_weap_akm, Throw, Put};
	magazines[] = {rhs_30Rnd_762x39mm_bakelite,rhs_30Rnd_762x39mm_bakelite};
	respawnMagazines[] = {rhs_30Rnd_762x39mm_bakelite,rhs_30Rnd_762x39mm_bakelite};
	linkedItems[] = {H_Cap_red};
	respawnLinkedItems[] = {H_Cap_red};
	INSCOPE;
};
class TIKA_BF2_Armciv_AKM_I: TIKA_BF2_Armciv_AKM_O {
	side = 2;
	uniformClass = "U_IG_Guerilla2_3";
};
class TIKA_BF2_Armciv_AKM_B: TIKA_BF2_Armciv_AKM_O {
	side = 1;
	uniformClass = "U_BG_Guerilla2_3";
};

class TIKA_BF2_Armciv_AKMS_O: TIKA_BF2_Armciv_BASE {
	displayName = "Armed Civilian (AKMS Rifle)";
	uniformClass = "U_OG_Guerilla2_2";
	weapons[] = {rhs_weap_akms, Throw, Put};
	respawnWeapons[] = {rhs_weap_akms, Throw, Put};
	magazines[] = {rhs_30Rnd_762x39mm_bakelite,rhs_30Rnd_762x39mm_bakelite};
	respawnMagazines[] = {rhs_30Rnd_762x39mm_bakelite,rhs_30Rnd_762x39mm_bakelite};
	linkedItems[] = {H_Cap_red};
	respawnLinkedItems[] = {H_Cap_red};
	INSCOPE;
};
class TIKA_BF2_Armciv_AKMS_I: TIKA_BF2_Armciv_AKMS_O {
	side = 2;
	uniformClass = "U_IG_Guerilla2_2";
};
class TIKA_BF2_Armciv_AKMS_B: TIKA_BF2_Armciv_AKMS_O {
	side = 1;
	uniformClass = "U_BG_Guerilla2_2";
};