params [["_terminalObject",objNull],["_beaconLogic",objNull]];

if (!isServer) exitWith { systemChat "Called bafops2_fnc_sarBeaconTerminalActivater on non-server."; false };
	
if (isNil "_terminalObject" || isNil "_beaconLogic") exitWith {systemChat format ["Null terminal or beacon to CreateImproveTerminal: %1, %2",_terminalObject,_beaconLogic]; false};

_terminalObject setVariable ["bafops2_terminal_state","active"]; //set on server first to avoid propogation delay
[_terminalObject,["bafops2_terminal_state","active"]] remoteExec ["setVariable",0];

[
	_terminalObject,										// Object the action is attached to
	"Activate Beacon",										// Title of the action
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",	// Idle icon shown on screen
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",	// Progress icon shown on screen
	"_this distance _target < 3",						// Condition for the action to be shown
	"_caller distance _target < 3.5",					// Condition for the action to progress
	{},													// Code executed when action starts
	{},													// Code executed on every progress tick
	{ 													// Code executed on completion
		params ["_target", "_caller", "_actionId", "_arguments"];
		["Terminal connected. Beacon signal received."] remoteExec ["systemChat",0];
		[_arguments select 0] remoteExecCall ["bafops2_fnc_sarBeaconStart",2];
		//Remove action for all clients
		[_target,_actionId] remoteExecCall ["removeAction",0,true];
		//Set state to complete
		[_target,["bafops2_terminal_state","complete"]] remoteExec ["setVariable",0];
	},
	{},													// Code executed on interrupted
	[_beaconLogic],									// Arguments passed to the scripts as _this select 3
	6,													// Action duration [s]
	0,													// Priority
	false,												// Remove on completion
	false												// Show in unconscious state 
] remoteExec ["BIS_fnc_holdActionAdd", 0, true];	// MP compatible implementation

