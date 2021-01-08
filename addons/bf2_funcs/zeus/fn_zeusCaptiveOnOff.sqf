if(!hasInterface) exitWith {};

["Players", "Group Captive Off",{
	params [["_position", [0,0,0], [[]], 3], ["_target", objNull, [objNull]]];
	if (!isNil "_target") then {
		{
			[_x,false] remoteExec ["setCaptive", _x];
		} forEach units group _target;
	}
}] call Ares_fnc_RegisterCustomModule;

["Players", "Group Captive On",{
	params [["_position", [0,0,0], [[]], 3], ["_target", objNull, [objNull]]];
	if (!isNil "_target") then {
		{
			[_x,true] remoteExec ["setCaptive", _x];
		} forEach units group _target;
	}
}] call Ares_fnc_RegisterCustomModule;