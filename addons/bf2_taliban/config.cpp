#define	INSCOPE	scope = 2; scopeCurator = 2; scopeArsenal = 2

class CfgPatches {
	class TIKA_BF2_Taliban {
		units[] = {
			"TIKA_BF2_Taliban_R1_O",
			"TIKA_BF2_Taliban_R1_I",
			"TIKA_BF2_Taliban_R1_B",
			"TIKA_BF2_Taliban_R2_O",
			"TIKA_BF2_Taliban_R2_I",
			"TIKA_BF2_Taliban_R2_B",
			"TIKA_BF2_Taliban_R3_O",
			"TIKA_BF2_Taliban_R3_I",
			"TIKA_BF2_Taliban_R3_B",
			"TIKA_BF2_Taliban_R4_O",
			"TIKA_BF2_Taliban_R4_I",
			"TIKA_BF2_Taliban_R4_B",
			"TIKA_BF2_Taliban_R5_O",
			"TIKA_BF2_Taliban_R5_I",
			"TIKA_BF2_Taliban_R5_B",
			"TIKA_BF2_Taliban_R6_O",
			"TIKA_BF2_Taliban_R6_I",
			"TIKA_BF2_Taliban_R6_B",
			"TIKA_BF2_Taliban_RPG1_O",
			"TIKA_BF2_Taliban_RPG1_I",
			"TIKA_BF2_Taliban_RPG1_B",
			"TIKA_BF2_Taliban_RPG2_O",
			"TIKA_BF2_Taliban_RPG2_I",
			"TIKA_BF2_Taliban_RPG2_B",
			"TIKA_BF2_Taliban_RPG3_O",
			"TIKA_BF2_Taliban_RPG3_I",
			"TIKA_BF2_Taliban_RPG3_B",
			"TIKA_BF2_Taliban_MG4_O",
			"TIKA_BF2_Taliban_MG4_I",
			"TIKA_BF2_Taliban_MG4_B",
			"TIKA_BF2_Taliban_MG5_O",
			"TIKA_BF2_Taliban_MG5_I",
			"TIKA_BF2_Taliban_MG5_B",
			"TIKA_BF2_Taliban_S2M_O",
			"TIKA_BF2_Taliban_S2M_I",
			"TIKA_BF2_Taliban_S2M_B",
			"TIKA_BF2_Taliban_S6_O",
			"TIKA_BF2_Taliban_S6_I",
			"TIKA_BF2_Taliban_S6_B"
		};
		weapons[] = {
			"bafops2_m38_scoped"
		};
		requiredAddons[] = {
			"A3_Characters_F",
			"Taliban_Fighters",
			"rhsusf_weapons",
			"rhs_weapons",
			"ace_medical"
		};
		magazines[] = {};
		ammo[] = {};
		requiredVersion = 1.98; 
		version=1.0;
		versionStr="1.0.0.0";
		versionAr[]={1,0,0,0};
	};
};
class CfgVehicleClasses {
	class TIKA_BF2_Afghan {
		displayName = "Afghan Fighters";
	};
	class TIKA_BF2_Afghan_Civ {
		displayName = "Afghan Civilians";
	};
};
class CfgEditorCategories {
	class TIKA_BF2_Afghan {
		displayName = "Afghan Fighters";
	};
	class TIKA_BF2_Afghan_Civ {
		displayName = "Afghan Civilians";
	};
};
class cfgWeapons {
	#include "cfgWeapons.hpp"
};
class cfgVehicles {
	#include "cfgAfghanUnlocks.hpp"
	#include "cfgAfghan.hpp"
};


