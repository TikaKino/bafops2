params [["_terminalObject",objNull],["_actionText","Upload Data"],["_successText","Data uploaded. Mission complete."],["_completeTime",10]];

if (isServer) then {
	
	if (isNil "_terminalObject") then {
	} else {
		[
			_terminalObject,									// Object the action is attached to
			_actionText,										// Title of the action
			"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",	// Idle icon shown on screen
			"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",	// Progress icon shown on screen
			"_this distance _target < 4",						// Condition for the action to be shown
			"_caller distance _target < 4",						// Condition for the action to progress
			{},													// Code executed when action starts
			{},													// Code executed on every progress tick
			{ 													// Code executed on completion
				params ["_target", "_caller", "_actionId", "_arguments"];
				[[format ["<t size='2.0'>%1</t>",_arguments select 0], "PLAIN",0.6,true,true]] remoteExec ["titleText",0];
				_screens = _target getVariable ["bafops2_terminal_screens_complete",[]];
				{
					_target setObjectTextureGlobal [_x select 0,_x select 1];
				} forEach _screens;
				//If we have an attached SAR beacon, turn it off.
				_sar = _target getVariable ["bafops2_sarbeacon_marker",false];
				if(!(isNil "bafops2_fnc_sarBeaconStop")) then {
					[_target] remoteExecCall ["bafops2_fnc_sarBeaconStop",2];
				};
				//Remove action for all clients
				[_target,_actionId] remoteExecCall ["removeAction",0,_target];
				[_target, ["bafops2_terminal_state","complete"]] remoteExec ["setVariable",0];
			},
			{},													// Code executed on interrupted
			[_successText],			// Arguments passed to the scripts as _this select 3
			_completeTime,										// Action duration [s]
			0,													// Priority
			false,												// Remove on completion
			false												// Show in unconscious state 
		] remoteExec ["BIS_fnc_holdActionAdd", 0, _terminalObject];	// MP compatible implementation
	};
	[_terminalObject, ["bafops2_terminal_state","active"]] remoteExec ["setVariable",0];
};

