class bafops2_ModuleAIPathDisable: Module_F
{
	// Standard object definitions
	scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
	scopeCurator = 1;
	displayName = "BAFOPS2 AI Pathing Disabled"; // Name displayed in the menu
	//icon = "\myTag_addonName\data\iconNuke_ca.paa"; // Map icon. Delete this entry to use the default icon
	category = "GroupModifiers";

	// Name of function triggered once conditions are met
	function = "bafops2_fnc_missionAIPathDisableModule";
	// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
	functionPriority = 1;
	// 0 for server only execution, 1 for global execution, 2 for persistent global execution
	isGlobal = 0;
	// 1 for module waiting until all synced triggers are activated
	isTriggerActivated = 1;
	// 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
	isDisposable = 1;
	// // 1 to run init function in Eden Editor as well
	is3DEN = 0;

	// Menu displayed when the module is placed or double-clicked on by Zeus
	//curatorInfoType = "RscDisplayAttributeModuleNuke";

	// Module attributes, uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific
	class Attributes: AttributesBase
	{
		// Arguments shared by specific module type (have to be mentioned in order to be present)
		class Units: Units
		{
			property = "bafops2_ModuleAIPathDisable_units";
		};
		
		class ModuleDescription: ModuleDescription{}; // Module description should be shown last
	};

	// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
	class ModuleDescription: ModuleDescription
	{
		description = "Disables pathing on all synced units, so they hold their ground."; // Short description, will be formatted as structured text
		sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)
 
		class LocationArea_F
		{
			description[] = { // Multi-line descriptions are supported
				"Any AI-controlled object."
			};
			position = 0; // Position is taken into effect
			direction = 0; // Direction is taken into effect
			optional = 0; // Synced entity is optional
			duplicate = 0; // Multiple entities of this type can be synced
			synced[] = {"AnyAI"}; // Pre-define entities like "AnyBrain" can be used. See the list below
		};
	};
};
class bafops2_ModuleMessageTerminal: Module_F
{
	// Standard object definitions
	scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
	scopeCurator = 1;
	displayName = "BAFOPS2 Message Terminal"; // Name displayed in the menu
	//icon = "\myTag_addonName\data\iconNuke_ca.paa"; // Map icon. Delete this entry to use the default icon
	category = "Intel";

	// Name of function triggered once conditions are met
	function = "bafops2_fnc_missionMessageTerminalModule";
	// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
	functionPriority = 1;
	// 0 for server only execution, 1 for global execution, 2 for persistent global execution
	isGlobal = 0;
	// 1 for module waiting until all synced triggers are activated
	isTriggerActivated = 1;
	// 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
	isDisposable = 1;
	// // 1 to run init function in Eden Editor as well
	is3DEN = 0;

	// Menu displayed when the module is placed or double-clicked on by Zeus
	//curatorInfoType = "RscDisplayAttributeModuleNuke";

	// Module attributes, uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific
	class Attributes: AttributesBase
	{
		// Arguments shared by specific module type (have to be mentioned in order to be present)
		class Units: Units
		{
			property = "bafops2_ModuleMissionMessageTerminal_units";
		};
		class ActionText: Edit {
			property = "bafops2_ModuleMissionMessageTerminal_actiontext";
			defaultValue = """Upload Data""";
			displayName = "Action Text";
			tooltip = "Text displayed when looking at the terminal.";
		};
		class SuccessText: Edit {
			property = "bafops2_ModuleMissionMessageTerminal_successtext";
			defaultValue = """Data uploaded.""";
			displayName = "Success Text";
			tooltip = "Text displayed on screen to all players when action is complete.";
		};
		class ActionTime: Edit {
			property = "bafops2_ModuleMissionMessageTerminal_actiontime";
			defaultValue = 10;
			displayName = "Action Time";
			tooltip = "How long the action takes to complete (in seconds).";
		};
		
		class ModuleDescription: ModuleDescription{}; // Module description should be shown last
	};

	// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
	class ModuleDescription: ModuleDescription
	{
		description = "Turns all linked objects into terminals that display a message to all players when activated."; // Short description, will be formatted as structured text
		sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)
 
		class LocationArea_F
		{
			description[] = { // Multi-line descriptions are supported
				"Any object."
			};
			position = 0; // Position is taken into effect
			direction = 0; // Direction is taken into effect
			optional = 0; // Synced entity is optional
			duplicate = 0; // Multiple entities of this type can be synced
			synced[] = {"Anything"}; // Pre-define entities like "AnyBrain" can be used. See the list below
		};
	};
};