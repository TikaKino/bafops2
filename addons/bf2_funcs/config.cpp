#define	INSCOPE	scope = 2; scopeCurator = 2; scopeArsenal = 2

class CfgPatches {
	class TIKA_BF2_Funcs {
		units[] = {
			"bafops2_ModuleIntelItem",
			"bafops2_ModuleIntelSharing",
			"bafops2_ModuleSarBeacon",
			"bafops2_ModuleSarTerminalImprover",
			"bafops2_ModuleSarTerminalActivater",
			"bafops2_ModuleSarTerminalMarkerSetter",
			"bafops2_ModuleSarTerminalScreenSetter",
			"bafops2_ModuleAIPathDisable",
			"bafops2_ModuleMessageTerminal"
		};
		weapons[] = {};
		requiredAddons[] = {};
		magazines[] = {};
		ammo[] = {};
		requiredVersion = 1.98; 
		version=1.1.0;
		versionStr="1.1.0.0";
		versionAr[]={1,1,0,0};
	};
};
class CfgFunctions {
	class bafops2 {
		#include "mission\cfgFunctions.hpp"
		#include "intel\cfgFunctions.hpp"
		#include "sar\cfgFunctions.hpp"
		#include "zeus\cfgFunctions.hpp"
	};
};
class CfgVehicles{
	class Logic;
	class Module_F: Logic
	{
		class AttributesBase
		{
			class Default;
			class Edit; // Default edit box (i.e., text input field)
			class Combo; // Default combo box (i.e., drop-down menu)
			class Checkbox; // Default checkbox (returned value is Bool)
			class CheckboxNumber; // Default checkbox (returned value is Number)
			class ModuleDescription; // Module description
			class Units; // Selection of units on which the module is applied
		};
		// Description base classes, for more information see below
		class ModuleDescription
		{
			class AnyBrain;
		};
	};
	#include "intel\cfgModules.hpp"
	#include "sar\cfgModules.hpp"
	#include "mission\cfgModules.hpp"
};