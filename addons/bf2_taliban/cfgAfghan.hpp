class O_Soldier_base_F;

class TIKA_BF2_Taliban_BASE: O_Soldier_base_F {
	side = 0;
	vehicleClass = "TIKA_BF2_Afghan";
	editorCategory = "TIKA_BF2_Afghan";
	uniformClass = "U_Afghan01";
	weapons[] = {Throw, Put};
	respawnWeapons[] = {Throw, Put};
	magazines[] = {};
	respawnMagazines[] = {};
	items[] = {ACE_fieldDressing,ACE_fieldDressing,ACE_fieldDressing,ACE_tourniquet};
	respawnItems[] = {ACE_fieldDressing,ACE_fieldDressing,ACE_fieldDressing,ACE_tourniquet};
	linkedItems[] = {};
	respawnLinkedItems[] = {};
};

class TIKA_BF2_Taliban_R1_O: TIKA_BF2_Taliban_BASE {
	displayName = "Rifleman 1 (AKM)";
	uniformClass = "U_Afghan01";
	side = 0;
	weapons[] = {rhs_weap_akm, Throw, Put};
	respawnWeapons[] = {rhs_weap_akm, Throw, Put};
	magazines[] = {rhs_30Rnd_762x39mm_bakelite,rhs_30Rnd_762x39mm_bakelite,rhs_30Rnd_762x39mm_bakelite,rhs_30Rnd_762x39mm_bakelite};
	respawnMagazines[] = {rhs_30Rnd_762x39mm_bakelite,rhs_30Rnd_762x39mm_bakelite,rhs_30Rnd_762x39mm_bakelite,rhs_30Rnd_762x39mm_bakelite};
	linkedItems[] = {rhsgref_chicom_m88,ItemMap,ItemWatch,ItemCompass};
	respawnLinkedItems[] = {rhsgref_chicom_m88,ItemMap,ItemWatch,ItemCompass};
	INSCOPE;
};
class TIKA_BF2_Taliban_R1_I: TIKA_BF2_Taliban_R1_O {
	side = 1;
};
class TIKA_BF2_Taliban_R1_B: TIKA_BF2_Taliban_R1_O {
	side = 2;
};


class TIKA_BF2_Taliban_R2_O: TIKA_BF2_Taliban_R1_O {
	displayName = "Rifleman 2 (AKM)";
	uniformClass = "U_Afghan02";
};
class TIKA_BF2_Taliban_R2_I: TIKA_BF2_Taliban_R2_O {
	side = 1;
};
class TIKA_BF2_Taliban_R2_B: TIKA_BF2_Taliban_R2_O {
	side = 2;
};

class TIKA_BF2_Taliban_R3_O: TIKA_BF2_Taliban_R1_O {
	displayName = "Rifleman 3 (AKM)";
	uniformClass = "U_Afghan03";
	linkedItems[] = {V_BandollierB_rgr,ItemMap,ItemWatch,ItemCompass};
	respawnLinkedItems[] = {V_BandollierB_rgr,ItemMap,ItemWatch,ItemCompass};
};
class TIKA_BF2_Taliban_R3_I: TIKA_BF2_Taliban_R3_O {
	side = 1;
};
class TIKA_BF2_Taliban_R3_B: TIKA_BF2_Taliban_R3_O {
	side = 2;
};

class TIKA_BF2_Taliban_R4_O: TIKA_BF2_Taliban_R1_O {
	displayName = "Rifleman 4 (AKM)";
	uniformClass = "U_Afghan04";
	linkedItems[] = {rhs_vydra_3m,ItemMap,ItemWatch,ItemCompass};
	respawnLinkedItems[] = {rhs_vydra_3m,ItemMap,ItemWatch,ItemCompass};
};
class TIKA_BF2_Taliban_R4_I: TIKA_BF2_Taliban_R4_O {
	side = 1;
};
class TIKA_BF2_Taliban_R4_B: TIKA_BF2_Taliban_R4_O {
	side = 2;
};

class TIKA_BF2_Taliban_R5_O: TIKA_BF2_Taliban_R1_O {
	displayName = "Rifleman 5 (AKM)";
	uniformClass = "U_Afghan05";
	linkedItems[] = {rhs_vydra_3m,ItemMap,ItemWatch,ItemCompass};
	respawnLinkedItems[] = {rhs_vydra_3m,ItemMap,ItemWatch,ItemCompass};
};
class TIKA_BF2_Taliban_R5_I: TIKA_BF2_Taliban_R5_O {
	side = 1;
};
class TIKA_BF2_Taliban_R5_B: TIKA_BF2_Taliban_R5_O {
	side = 2;
};

class TIKA_BF2_Taliban_R6_O: TIKA_BF2_Taliban_R1_O {
	displayName = "Rifleman 6 (AKM)";
	uniformClass = "U_Afghan06";
	linkedItems[] = {rhs_6sh92_digi,ItemMap,ItemWatch,ItemCompass};
	respawnLinkedItems[] = {rhs_6sh92_digi,ItemMap,ItemWatch,ItemCompass};
};
class TIKA_BF2_Taliban_R6_I: TIKA_BF2_Taliban_R6_O {
	side = 1;
};
class TIKA_BF2_Taliban_R6_B: TIKA_BF2_Taliban_R6_O {
	side = 2;
};

class TIKA_BF2_Taliban_RPG1_O: TIKA_BF2_Taliban_BASE {
	displayName = "RPG 1";
	uniformClass = "U_Afghan01";
	backpack = "rhs_rpg_v";
	side = 0;
	weapons[] = {rhs_weap_pp2000, rhs_weap_rpg7, Throw, Put};
	respawnWeapons[] = {rhs_weap_pp2000, rhs_weap_rpg7, Throw, Put};
	magazines[] = {rhs_mag_9x19mm_7n21_20,rhs_mag_9x19mm_7n21_20,rhs_mag_9x19mm_7n21_20,rhs_mag_9x19mm_7n21_20};
	respawnMagazines[] = {rhs_mag_9x19mm_7n21_20,rhs_mag_9x19mm_7n21_20,rhs_mag_9x19mm_7n21_20,rhs_mag_9x19mm_7n21_20};
	linkedItems[] = {ItemMap,ItemWatch,ItemCompass};
	respawnLinkedItems[] = {ItemMap,ItemWatch,ItemCompass};
	INSCOPE;
};
class TIKA_BF2_Taliban_RPG1_I: TIKA_BF2_Taliban_RPG1_O {
	side = 1;
};
class TIKA_BF2_Taliban_RPG1_B: TIKA_BF2_Taliban_RPG1_O {
	side = 2;
};

class TIKA_BF2_Taliban_RPG2_O: TIKA_BF2_Taliban_RPG1_O {
	displayName = "RPG 2";
	uniformClass = "U_Afghan02";
};
class TIKA_BF2_Taliban_RPG2_I: TIKA_BF2_Taliban_RPG2_O {
	side = 1;
};
class TIKA_BF2_Taliban_RPG2_B: TIKA_BF2_Taliban_RPG2_O {
	side = 2;
};

class TIKA_BF2_Taliban_RPG3_O: TIKA_BF2_Taliban_RPG1_O {
	displayName = "RPG 3";
	uniformClass = "U_Afghan03";
};
class TIKA_BF2_Taliban_RPG3_I: TIKA_BF2_Taliban_RPG3_O {
	side = 1;
};
class TIKA_BF2_Taliban_RPG3_B: TIKA_BF2_Taliban_RPG3_O {
	side = 2;
};

class TIKA_BF2_Taliban_MG4_O: TIKA_BF2_Taliban_BASE {
	displayName = "Machinegunner 4";
	uniformClass = "U_Afghan04";
	backpack = "rhs_sidorMG";
	side = 0;
	weapons[] = {rhs_weap_pkm, Throw, Put};
	respawnWeapons[] = {rhs_weap_pkm, Throw, Put};
	magazines[] = {};
	respawnMagazines[] = {};
	linkedItems[] = {ItemMap,ItemWatch,ItemCompass};
	respawnLinkedItems[] = {ItemMap,ItemWatch,ItemCompass};
	INSCOPE;
};
class TIKA_BF2_Taliban_MG4_I: TIKA_BF2_Taliban_MG4_O {
	side = 1;
};
class TIKA_BF2_Taliban_MG4_B: TIKA_BF2_Taliban_MG4_O {
	side = 2;
};

class TIKA_BF2_Taliban_MG5_O: TIKA_BF2_Taliban_MG4_O {
	displayName = "Machinegunner 5";
	uniformClass = "U_Afghan05";
};
class TIKA_BF2_Taliban_MG5_I: TIKA_BF2_Taliban_MG5_O {
	side = 1;
};
class TIKA_BF2_Taliban_MG5_B: TIKA_BF2_Taliban_MG5_O {
	side = 2;
};

class TIKA_BF2_Taliban_S2M_O: TIKA_BF2_Taliban_BASE {
	displayName = "Sharpshooter 2 (Mosin Nagant)";
	uniformClass = "U_Afghan02NH";
	side = 0;
	weapons[] = {bafops2_m38_scoped, Throw, Put};
	respawnWeapons[] = {bafops2_m38_scoped, Throw, Put};
	magazines[] = {rhsgref_5Rnd_762x54_m38,rhsgref_5Rnd_762x54_m38,rhsgref_5Rnd_762x54_m38,rhsgref_5Rnd_762x54_m38,rhsgref_5Rnd_762x54_m38,rhsgref_5Rnd_762x54_m38};
	respawnMagazines[] = {rhsgref_5Rnd_762x54_m38,rhsgref_5Rnd_762x54_m38,rhsgref_5Rnd_762x54_m38,rhsgref_5Rnd_762x54_m38rhsgref_5Rnd_762x54_m38,rhsgref_5Rnd_762x54_m38};
	linkedItems[] = {ItemMap,ItemWatch,ItemCompass};
	respawnLinkedItems[] = {ItemMap,ItemWatch,ItemCompass};
	INSCOPE;
};
class TIKA_BF2_Taliban_S2M_I: TIKA_BF2_Taliban_S2M_O {
	side = 1;
};
class TIKA_BF2_Taliban_S2M_B: TIKA_BF2_Taliban_S2M_O {
	side = 2;
};

class TIKA_BF2_Taliban_S6_O: TIKA_BF2_Taliban_BASE {
	displayName = "Sharpshooter 6 (SVD)";
	uniformClass = "U_Afghan06";
	side = 0;
	weapons[] = {rhs_weap_svd_pso1, Throw, Put};
	respawnWeapons[] = {rhs_weap_svd_pso1, Throw, Put};
	magazines[] = {rhs_10Rnd_762x54mmR_7N1,rhs_10Rnd_762x54mmR_7N1,rhs_10Rnd_762x54mmR_7N1,rhs_10Rnd_762x54mmR_7N1};
	respawnMagazines[] = {rhs_10Rnd_762x54mmR_7N1,rhs_10Rnd_762x54mmR_7N1,rhs_10Rnd_762x54mmR_7N1,rhs_10Rnd_762x54mmR_7N1};
	linkedItems[] = {ItemMap,ItemWatch,ItemCompass};
	respawnLinkedItems[] = {ItemMap,ItemWatch,ItemCompass};
	INSCOPE;
};
class TIKA_BF2_Taliban_S6_I: TIKA_BF2_Taliban_S6_O {
	side = 1;
};
class TIKA_BF2_Taliban_S6_B: TIKA_BF2_Taliban_S6_O {
	side = 2;
};
class TIKA_BF2_Taliban_C_Warlord_O: TIKA_BF2_Taliban_BASE {
	displayName = "Warlord";
	uniformClass = "U_Afghan02";
	side = 0;
	weapons[] = {rhs_weap_aks74un,rhs_weap_makarov_pm, Throw, Put};
	respawnWeapons[] = {rhs_weap_aks74un,rhs_weap_makarov_pm, Throw, Put};
	magazines[] = {rhs_30Rnd_545x39_7N6M_AK,rhs_30Rnd_545x39_7N6M_AK,rhs_30Rnd_545x39_7N6M_AK,rhs_mag_9x18_8_57N181S};
	respawnMagazines[] = {rhs_30Rnd_545x39_7N6M_AK,rhs_30Rnd_545x39_7N6M_AK,rhs_30Rnd_545x39_7N6M_AK,rhs_mag_9x18_8_57N181S};
	linkedItems[] = {rhs_vest_pistol_holster,H_ShemagOpen_khk,G_Squares_Tinted,ItemMap,ItemWatch,ItemCompass};
	respawnLinkedItems[] = {rhs_vest_pistol_holster,H_ShemagOpen_khk,G_Squares_Tinted,ItemMap,ItemWatch,ItemCompass};
	INSCOPE;
};
class TIKA_BF2_Taliban_C_Warlord_I: TIKA_BF2_Taliban_C_Warlord_O {
	side = 1;
};
class TIKA_BF2_Taliban_C_Warlord_B: TIKA_BF2_Taliban_C_Warlord_O {
	side = 2;
};