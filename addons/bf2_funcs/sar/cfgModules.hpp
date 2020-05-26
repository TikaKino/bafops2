class bafops2_ModuleSarBeacon: Module_F
{
	// Standard object definitions
	scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
	scopeCurator = 1;
	displayName = "BAFOPS2 SAR Beacon"; // Name displayed in the menu
	//icon = "\myTag_addonName\data\iconNuke_ca.paa"; // Map icon. Delete this entry to use the default icon
	category = "Intel";

	// Name of function triggered once conditions are met
	function = "bafops2_fnc_sarBeaconSetupModule";
	// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
	functionPriority = 5;
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
			property = "bafops2_ModuleSarBeacon_units";
		};
		class BeaconAccuracy: Edit {
			property = "bafops2_ModuleSarBeacon_accuracy";
			defaultValue = """[100,200,400,800,1600]""";
			displayName = "Beacon Accuracy Levels";
			tooltip = "Array where each entry is one of the accuracy levels you want the beacon to have, in meters.";
		};
		class NumberOfBeacons: Edit {
			property = "bafops2_ModuleSarBeacon_number";
			defaultValue = 1;
			displayName = "Number of beacons";
			tooltip = "Number of beacons to spawn, chosen randomly from among the synced objects. Leave as 0 for all.";
		};
		class BeaconAutoUpdate: Combo
		{
			property = "bafops2_ModuleSarBeacon_autoupdate";
			displayName = "Auto-Update?"; // Argument label
			tooltip = "Will the position of the beacon be automatically updated?"; // Tooltip description
			typeName = "STRING"; // Value type, can be "NUMBER", "STRING" or "BOOL"
			defaultValue = """yes"""; // Default attribute value. WARNING: This is an expression, and its returned value will be used
			class Values
			{
				class VUnit	{name = "Yes";	value = "yes";};
				class VGroup{name = "No"; value = "no";};
			};
		};
		class BeaconAutoStart: Combo
		{
			property = "bafops2_ModuleSarBeacon_autostart";
			displayName = "Start Active?"; // Argument label
			tooltip = "Will this beacon start activated? If not, it must be activated by module or code to appear."; // Tooltip description
			typeName = "STRING"; // Value type, can be "NUMBER", "STRING" or "BOOL"
			defaultValue = """yes"""; // Default attribute value. WARNING: This is an expression, and its returned value will be used
			class Values
			{
				class VUnit	{name = "Yes";	value = "yes";};
				class VGroup{name = "No"; value = "no";};
			};
		};
		
		class ModuleDescription: ModuleDescription {}; // Module description should be shown last
	};

	// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
	class ModuleDescription: ModuleDescription
	{
		description = "Sets up an improvable SAR beacon. Picks one or more of the synced objects at random as its physical manifestation(s)."; // Short description, will be formatted as structured text
		sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)
 
		class LocationArea_F
		{
			description[] = { // Multi-line descriptions are supported
				"List of objects to pick from as beacon physical location.",
			};
			position = 1; // Position is taken into effect
			direction = 0; // Direction is taken into effect
			optional = 0; // Synced entity is optional
			duplicate = 1; // Multiple entities of this type can be synced
			synced[] = {"Anything"}; // Pre-define entities like "AnyBrain" can be used. See the list below
		};
	};
};
class bafops2_ModuleSarTerminalImprover: Module_F
{
	// Standard object definitions
	scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
	scopeCurator = 1;
	displayName = "BAFOPS2 SAR Intel Terminal"; // Name displayed in the menu
	//icon = "\myTag_addonName\data\iconNuke_ca.paa"; // Map icon. Delete this entry to use the default icon
	category = "Intel";

	// Name of function triggered once conditions are met
	function = "bafops2_fnc_sarTerminalImproverModule";
	// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
	functionPriority = 10;
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
			property = "bafops2_ModuleSarTerminalImprover_units";
		};
		class BeaconName: Edit {
			property = "bafops2_ModuleSarTerminalImprover_beacon";
			defaultValue = """""";
			displayName = "Associated Beacon";
			tooltip = "The variable name of the SAR Beacon module these terminals affect.";
		};
		class NumberOfTerminals: Edit {
			property = "bafops2_ModuleSarTerminalImprover_number";
			defaultValue = 1;
			displayName = "Number of terminals";
			tooltip = "Number of terminals to create, or all connected objects if 0.";
		};
		
		class ModuleDescription: ModuleDescription {}; // Module description should be shown last
	};

	// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
	class ModuleDescription: ModuleDescription
	{
		description = "Sets up terminal(s) which improve the accuracy of a given SAR Beacon when activated."; // Short description, will be formatted as structured text
		sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)
 
		class LocationArea_F
		{
			description[] = { // Multi-line descriptions are supported
				"List of objects to pick from as terminals.",
			};
			position = 1; // Position is taken into effect
			direction = 0; // Direction is taken into effect
			optional = 0; // Synced entity is optional
			duplicate = 1; // Multiple entities of this type can be synced
			synced[] = {"Anything"}; // Pre-define entities like "AnyBrain" can be used. See the list below
		};
	};
};
class bafops2_ModuleSarTerminalActivater: Module_F
{
	// Standard object definitions
	scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
	scopeCurator = 1;
	displayName = "BAFOPS2 SAR Beacon Activation Terminal"; // Name displayed in the menu
	//icon = "\myTag_addonName\data\iconNuke_ca.paa"; // Map icon. Delete this entry to use the default icon
	category = "Intel";

	// Name of function triggered once conditions are met
	function = "bafops2_fnc_sarTerminalActivaterModule";
	// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
	functionPriority = 8;
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
			property = "bafops2_ModuleSarTerminalActivater_units";
		};
		class BeaconName: Edit {
			property = "bafops2_ModuleSarTerminalActivater_beacon";
			defaultValue = """""";
			displayName = "Associated Beacon";
			tooltip = "The variable name of the SAR Beacon module these terminals affect.";
		};
		class NumberOfTerminals: Edit {
			property = "bafops2_ModuleSarTerminalActivater_number";
			defaultValue = 1;
			displayName = "Number of terminals";
			tooltip = "Number of terminals to create, or all connected objects if 0.";
		};
		
		class ModuleDescription: ModuleDescription {}; // Module description should be shown last
	};

	// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
	class ModuleDescription: ModuleDescription
	{
		description = "Sets up terminal(s) which start the linked beacon when activated."; // Short description, will be formatted as structured text
		sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)
 
		class LocationArea_F
		{
			description[] = { // Multi-line descriptions are supported
				"List of objects to pick from as terminals.",
			};
			position = 1; // Position is taken into effect
			direction = 0; // Direction is taken into effect
			optional = 0; // Synced entity is optional
			duplicate = 1; // Multiple entities of this type can be synced
			synced[] = {"Anything"}; // Pre-define entities like "AnyBrain" can be used. See the list below
		};
	};
};
class bafops2_ModuleSarTerminalScreenSetter: Module_F
{
	// Standard object definitions
	scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
	scopeCurator = 1;
	displayName = "BAFOPS2 Terminal Screen Setter"; // Name displayed in the menu
	//icon = "\myTag_addonName\data\iconNuke_ca.paa"; // Map icon. Delete this entry to use the default icon
	category = "ObjectModifiers";

	// Name of function triggered once conditions are met
	function = "bafops2_fnc_sarTerminalScreenSetterModule";
	// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
	functionPriority = 20;
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
			property = "bafops2_ModuleSarTerminalScreenSetter_units";
		};
		class TextureNumber: Edit {
			property = "bafops2_ModuleSarTerminalScreenSetter_texnum";
			defaultValue = 0;
			displayName = "Texture Number";
			tooltip = "Which texture to set on the linked terminals";
		};
		class ImageOff: Edit {
			property = "bafops2_ModuleSarTerminalScreenSetter_off";
			defaultValue = """""";
			displayName = "Image (Off)";
			tooltip = "The image to use when the state is Off";
		};
		class ImageActive: Edit {
			property = "bafops2_ModuleSarTerminalScreenSetter_active";
			defaultValue = """""";
			displayName = "Image (Active)";
			tooltip = "The image to use when the state is Active";
		};
		class ImageComplete: Edit {
			property = "bafops2_ModuleSarTerminalScreenSetter_complete";
			defaultValue = """""";
			displayName = "Image (Complete)";
			tooltip = "The image to use when the state is Complete";
		};
		
		class ModuleDescription: ModuleDescription {}; // Module description should be shown last
	};

	// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
	class ModuleDescription: ModuleDescription
	{
		description = "Sets up a listener that sets textures on an object when it is in certain BAFOPS2 terminal states."; // Short description, will be formatted as structured text
		sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)
 
		class LocationArea_F
		{
			description[] = { // Multi-line descriptions are supported
				"Terminals to set this texture on.",
			};
			position = 1; // Position is taken into effect
			direction = 0; // Direction is taken into effect
			optional = 0; // Synced entity is optional
			duplicate = 1; // Multiple entities of this type can be synced
			synced[] = {"Anything"}; // Pre-define entities like "AnyBrain" can be used. See the list below
		};
	};
};
class bafops2_ModuleSarTerminalMarkerSetter: Module_F
{
	// Standard object definitions
	scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
	scopeCurator = 1;
	displayName = "BAFOPS2 Terminal Marker Setter"; // Name displayed in the menu
	//icon = "\myTag_addonName\data\iconNuke_ca.paa"; // Map icon. Delete this entry to use the default icon
	category = "ObjectModifiers";

	// Name of function triggered once conditions are met
	function = "bafops2_fnc_sarTerminalMarkerSetterModule";
	// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
	functionPriority = 20;
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
			property = "bafops2_ModuleSarTerminalMarkerSetter_units";
		};
		class MarkerName: Edit {
			property = "bafops2_ModuleSarTerminalMarkerSetter_marker";
			defaultValue = """""";
			displayName = "Marker Name";
			tooltip = "Which marker should be set";
		};
		class ShapeOff: Edit {
			property = "bafops2_ModuleSarTerminalMarkerSetter_shape_off";
			defaultValue = """Empty""";
			displayName = "Type (Off)";
			tooltip = "The marker type to use when the state is Off (see cfgMarkers)";
		};
		class ShapeActive: Edit {
			property = "bafops2_ModuleSarTerminalMarkerSetter_shape_active";
			defaultValue = """mil_objective""";
			displayName = "Type (Active)";
			tooltip = "The marker type to use when the state is Active (see cfgMarkers)";
		};
		class ShapeComplete: Edit {
			property = "bafops2_ModuleSarTerminalMarkerSetter_shape_complete";
			defaultValue = """mil_dot""";
			displayName = "Type (Complete)";
			tooltip = "The marker type to use when the state is Complete (see cfgMarkers)";
		};
		
		class ModuleDescription: ModuleDescription {}; // Module description should be shown last
	};

	// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
	class ModuleDescription: ModuleDescription
	{
		description = "Sets up a listener that changes a marker when an object is in certain BAFOPS2 terminal states."; // Short description, will be formatted as structured text
		sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)
 
		class LocationArea_F
		{
			description[] = { // Multi-line descriptions are supported
				"Terminal that controls this marker.",
			};
			position = 1; // Position is taken into effect
			direction = 0; // Direction is taken into effect
			optional = 0; // Synced entity is optional
			duplicate = 0; // Multiple entities of this type can be synced
			synced[] = {"Anything"}; // Pre-define entities like "AnyBrain" can be used. See the list below
		};
	};
};