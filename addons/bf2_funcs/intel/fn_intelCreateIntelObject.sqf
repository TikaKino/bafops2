params [["_intelObject",objNull]];

if (isServer) then {
	[_intelObject,[
		"Recover Intel", 
		{
			params ["_target", "_caller", "_actionId", "_arguments"];
			
			_scope = _target getVariable ["bafops2_intel_scope","unit"];
			
			if (_scope == "unit") then {
				[_target,_caller] remoteExec ["bafops2_fnc_intelAddIntelEntryToPlayer",_caller];
			};
			if (_scope == "group") then {
				[_target,group _caller] remoteExec ["bafops2_fnc_intelAddIntelEntryToGroup",_caller];
			};
			if (_scope == "side") then {
				[_target,side _caller] remoteExec ["bafops2_fnc_intelAddIntelEntryToSide",_caller];
			};
			
			systemChat "New intel recovered. Check Map menu.";
		},
		[],
		2, 
		true, 
		true, 
		"",
		"!([_target,_this] call bafops2_fnc_intelGetPlayerHasFound)", // _target, _this, _originalTarget // Might make it show up and give a "you found this" message instead?
		3,
		false,
		"",
		""
	]] remoteExec ["addAction",0,true];
};