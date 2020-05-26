class bafops2_ModuleIntelItem: Module_F
{
	// Standard object definitions
	scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
	scopeCurator = 1;
	displayName = "BAFOPS2 Collectable Intel Item"; // Name displayed in the menu
	//icon = "\myTag_addonName\data\iconNuke_ca.paa"; // Map icon. Delete this entry to use the default icon
	category = "Intel";

	// Name of function triggered once conditions are met
	function = "bafops2_fnc_intelCreateIntelObjectModule";
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
			property = "bafops2_ModuleIntelItem_units";
		};
		class EntryTitle: Edit
		{
			property = "bafops2_ModuleIntelItem_entrytitle";
			displayName = "Entry Title";
			tooltip = "The title of the found intel entry";
			// Default text filled in the input box
			// Because it's an expression, to return a String one must have a string within a string
			defaultValue = """Found Intel""";
		};
		class EntryText: Edit
		{
			property = "bafops2_ModuleIntelItem_entrytext";
			displayName = "Entry Text";
			tooltip = "The text of the found intel entry";
			// Default text filled in the input box
			// Because it's an expression, to return a String one must have a string within a string
			//defaultValue = "";
		};
		class Scope: Combo
		{
			// Unique property, use "<moduleClass>_<attributeClass>" format to make sure the name is unique in the world
			property = "bafops2_ModuleIntelItem_scope";
			displayName = "Intel Scope"; // Argument label
			tooltip = "Will found intel be added to the finder, their group or their whole side?"; // Tooltip description
			typeName = "STRING"; // Value type, can be "NUMBER", "STRING" or "BOOL"
			defaultValue = """unit"""; // Default attribute value. WARNING: This is an expression, and its returned value will be used (50 in this case)
			class Values
			{
				class VUnit	{name = "Finder only";	value = "unit";};
				class VGroup{name = "Finder's group"; value = "group";};
				class VSide	{name = "Finder's side"; value = "side";};
			};
		};
		
		class ModuleDescription: ModuleDescription{}; // Module description should be shown last
	};

	// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
	class ModuleDescription: ModuleDescription
	{
		description = "Adds a findable, sharable intel entry to the synced object(s)"; // Short description, will be formatted as structured text
		sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)
 
		class LocationArea_F
		{
			description[] = { // Multi-line descriptions are supported
				"First line",
				"Second line"
			};
			position = 0; // Position is taken into effect
			direction = 0; // Direction is taken into effect
			optional = 0; // Synced entity is optional
			duplicate = 0; // Multiple entities of this type can be synced
			synced[] = {"AnyStaticObject"}; // Pre-define entities like "AnyBrain" can be used. See the list below
		};
	};
};

class bafops2_ModuleIntelSharing: Module_F
{
	// Standard object definitions
	scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
	scopeCurator = 1;
	displayName = "BAFOPS2 Setup Intel Sharing"; // Name displayed in the menu
	//icon = "\myTag_addonName\data\iconNuke_ca.paa"; // Map icon. Delete this entry to use the default icon
	category = "Intel";

	// Name of function triggered once conditions are met
	function = "bafops2_fnc_intelSetupSharingModule";
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
		class ModuleDescription: ModuleDescription{}; // Module description should be shown last
	};

	// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
	class ModuleDescription: ModuleDescription
	{
		description = "Sets up all players to be able to have intel items shared to them."; // Short description, will be formatted as structured text
	};
};