class bafops2_ModuleFortsFort: Module_F {
	
	// Standard object definitions
	scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
	scopeCurator = 1;
	displayName = "BAFOPS2 Fort"; // Name displayed in the menu
	//icon = "\myTag_addonName\data\iconNuke_ca.paa"; // Map icon. Delete this entry to use the default icon
	category = "TIKA_BF2_FortsModules";
	
	// Name of function triggered once conditions are met
	function = "bafops2_fnc_fortsCreateFortModule";
	// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
	functionPriority = 10;
	// 0 for server only execution, 1 for global execution, 2 for persistent global execution
	isGlobal = 0;
	// 1 for module waiting until all synced triggers are activated
	isTriggerActivated = 0;
	// 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
	isDisposable = 1;
	// // 1 to run init function in Eden Editor as well
	is3DEN = 0;
	
	// Module attributes, uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific
	class Attributes: AttributesBase
	{	
		// Module specific arguments
		class FortName: Edit
		{
			// Unique property, use "<moduleClass>_<attributeClass>" format to make sure the name is unique in the world
			property = "bafops2_ModuleFortsFort_name";
			displayName = "Name"; // Argument label
			tooltip = "A short descriptive name for this fort, to turn up in scoring etc."; // Tooltip description
			typeName = "STRING"; // Value type, can be "NUMBER", "STRING" or "BOOL"
			defaultValue = """"""; // Default attribute value. WARNING: This is an expression, and its returned value will be used
		};
		class FortScore: Edit
		{
			// Unique property, use "<moduleClass>_<attributeClass>" format to make sure the name is unique in the world
			property = "bafops2_ModuleFortsFort_score";
			displayName = "Score"; // Argument label
			tooltip = "Points received for clearing this fort in a scored scenario."; // Tooltip description
			typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
			defaultValue = "50"; // Default attribute value. WARNING: This is an expression, and its returned value will be used
		};
		
		class ModuleDescription: ModuleDescription{}; // Module description should be shown last
	};

	// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
	class ModuleDescription: ModuleDescription
	{
		description = "Denotes synced units as a fort, which can be removed by the Fort Area module to create random layouts."; // Short description, will be formatted as structured text
		sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)
 
		class LocationArea_F
		{
			description[] = { // Multi-line descriptions are supported
				"Any non-simple object."
			};
			position = 0; // Position is taken into effect
			direction = 0; // Direction is taken into effect
			optional = 0; // Synced entity is optional
			duplicate = 0; // Multiple entities of this type can be synced
			synced[] = {"Anything"}; // Pre-define entities like "AnyBrain" can be used. See the list below
		};
	};
};

class bafops2_ModuleFortsFortArea: Module_F {
	
	// Standard object definitions
	scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
	scopeCurator = 1;
	displayName = "BAFOPS2 Fort Area"; // Name displayed in the menu
	//icon = "\myTag_addonName\data\iconNuke_ca.paa"; // Map icon. Delete this entry to use the default icon
	category = "TIKA_BF2_FortsModules";
	
	// Name of function triggered once conditions are met
	function = "bafops2_fnc_fortsFortAreaModule";
	// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
	functionPriority = 20;
	// 0 for server only execution, 1 for global execution, 2 for persistent global execution
	isGlobal = 0;
	// 1 for module waiting until all synced triggers are activated
	isTriggerActivated = 0;
	// 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
	isDisposable = 1;
	// // 1 to run init function in Eden Editor as well
	is3DEN = 0;
	
	// Module attributes, uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific
	class Attributes: AttributesBase
	{	
		class NumberOfForts: Edit
		{
			// Unique property, use "<moduleClass>_<attributeClass>" format to make sure the name is unique in the world
			property = "bafops2_ModuleFortArea_numberOfForts";
			displayName = "Number of Forts"; // Argument label
			tooltip = "How many of the synced fort objects will remain. Use a negative number to remove that many instead."; // Tooltip description
			typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
			defaultValue = "1"; // Default attribute value. WARNING: This is an expression, and its returned value will be used (50 in this case)
		};
		
		class ModuleDescription: ModuleDescription{}; // Module description should be shown last
	};

	// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
	class ModuleDescription: ModuleDescription
	{
		description = "Randomly deletes synced Fort modules and their contents to create a random layout."; // Short description, will be formatted as structured text
		sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)
 
		class LocationArea_F
		{
			description[] = { // Multi-line descriptions are supported
				"Randomly deletes synced Fort modules and their contents to create a random layout."
			};
			position = 0; // Position is taken into effect
			direction = 0; // Direction is taken into effect
			optional = 0; // Synced entity is optional
			duplicate = 0; // Multiple entities of this type can be synced
			synced[] = {"FortsFort"}; // Pre-define entities like "AnyBrain" can be used. See the list below
		};
		class FortsFort
		{
			description = "One or more BAFOPS2 Fort Modules to be randomly thinned out.";
			displayName = "BAFOPS2 Fort Module"; // Custom name
			icon = ""; // Custom icon (can be file path or CfgVehicleIcons entry)
			side = 1; // Custom side (will determine icon color)
		};
	};
};