#define	INSCOPE	scope = 2; scopeCurator = 2; scopeArsenal = 2

class CfgPatches {
	class TIKA_BF2_Armciv {
		units[] = {
			"TIKA_BF2_Armciv_G17_O",
			"TIKA_BF2_Armciv_G17_I",
			"TIKA_BF2_Armciv_G17_B",
			"TIKA_BF2_Armciv_M590_O",
			"TIKA_BF2_Armciv_M590_I",
			"TIKA_BF2_Armciv_M590_B",
			"TIKA_BF2_Armciv_TT33_O",
			"TIKA_BF2_Armciv_TT33_I",
			"TIKA_BF2_Armciv_TT33_B",
			"TIKA_BF2_Armciv_Mosin_O",
			"TIKA_BF2_Armciv_Mosin_I",
			"TIKA_BF2_Armciv_Mosin_B",
			"TIKA_BF2_Armciv_PM_O",
			"TIKA_BF2_Armciv_PM_I",
			"TIKA_BF2_Armciv_PM_B",
			"TIKA_BF2_Armciv_Izh_O",
			"TIKA_BF2_Armciv_Izh_I",
			"TIKA_BF2_Armciv_Izh_B",
			"TIKA_BF2_Armciv_PP2K_O",
			"TIKA_BF2_Armciv_PP2K_I",
			"TIKA_BF2_Armciv_PP2K_B",
			"TIKA_BF2_Armciv_M70_O",
			"TIKA_BF2_Armciv_M70_I",
			"TIKA_BF2_Armciv_M70_B",
			"TIKA_BF2_Armciv_M14_O",
			"TIKA_BF2_Armciv_M14_I",
			"TIKA_BF2_Armciv_M14_B",
			"TIKA_BF2_Armciv_L1A1_O",
			"TIKA_BF2_Armciv_L1A1_I",
			"TIKA_BF2_Armciv_L1A1_B",
			"TIKA_BF2_Armciv_AKM_O",
			"TIKA_BF2_Armciv_AKM_I",
			"TIKA_BF2_Armciv_AKM_B",
			"TIKA_BF2_Armciv_AKMS_O",
			"TIKA_BF2_Armciv_AKMS_I",
			"TIKA_BF2_Armciv_AKMS_B",
			"TIKA_BF2_Bodyguard_PDW_O",
			"TIKA_BF2_Bodyguard_PDW_I",
			"TIKA_BF2_Bodyguard_PDW_B",
			"TIKA_BF2_Bodyguard_P07_O",
			"TIKA_BF2_Bodyguard_P07_I",
			"TIKA_BF2_Bodyguard_P07_B",
			"TIKA_BF2_GEN_Soldier_I",
			"TIKA_BF2_GEN_Commander_I"
		};
		weapons[] = {};
		requiredAddons[] = {
			"A3_Characters_F",
			"rhsusf_weapons",
			"rhs_weapons",
			"rhssaf_c_weapons",
			"ace_medical"
		};
		magazines[] = {};
		ammo[] = {};
		author = "Mikael";
        authors[] = {"Mikael"};
		requiredVersion = 2.02;
		version=1.2.3;
		versionStr="1.2.3.0";
		versionAr[]={1,2,3,0};
	};
};
class CfgVehicleClasses {
	class TIKA_BF2_Armciv {
		displayName = "Armed Civilians";
	};
};
class CfgEditorCategories {
	class TIKA_BF2_Armciv {
		displayName = "Armed Civilians";
	};
};
class cfgVehicles
{
	#include "cfgUnlocks.hpp"
	#include "cfgArmedCivilians.hpp"
	#include "cfgGendarmerie.hpp"
};