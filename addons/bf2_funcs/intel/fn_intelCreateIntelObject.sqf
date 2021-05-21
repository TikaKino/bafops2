params [["_terminalObject",objNull],["_intelObject",objNull]];

if (isServer) then {
	[_terminalObject,[
		"Recover Intel", 
		{
			params ["_target", "_caller", "_actionId", "_arguments"];
			_intelObject = _target getVariable ["bafops2_intel_logic",false];
			if(_intelObject isEqualTo false) exitWith { systemChat "No intel logic found!" };
			
			_scope = _intelObject getVariable ["bafops2_intel_scope","unit"];
			
			if (_scope == "unit") then {
				[_intelObject,_caller] remoteExec ["bafops2_fnc_intelAddIntelEntryToPlayer",_caller];
			};
			if (_scope == "group") then {
				[_intelObject,group _caller] remoteExec ["bafops2_fnc_intelAddIntelEntryToGroup",_caller];
			};
			if (_scope == "side") then {
				[_intelObject,side _caller] remoteExec ["bafops2_fnc_intelAddIntelEntryToSide",_caller];
			};
			
			systemChat "New intel recovered. Check Map menu.";
		},
		[],
		2, 
		true, 
		true, 
		"",
		"!([_target getVariable ['bafops2_intel_logic',objNull],_this] call bafops2_fnc_intelGetPlayerHasFound)", // _target, _this, _originalTarget // Might make it show up and give a "you found this" message instead?
		3,
		false,
		"",
		""
	]] remoteExec ["addAction",0,true];
	[_terminalObject,["bafops2_intel_logic",_intelObject]] remoteExec ["setVariable",0,true];
};