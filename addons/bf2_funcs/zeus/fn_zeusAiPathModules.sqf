if (hasInterface) then {

	["AI Behaviour", "Group Move Enable",{
		params [["_position", [0,0,0], [[]], 3], ["_target", objNull, [objNull]]];
		if (!isNil "_target") then {
			{
				[_x,"PATH"] remoteExec ["enableAI", _x];
			} forEach units group _target;
		}
	}] call zen_custom_modules_fnc_register;

	["AI Behaviour", "Group Move Disable",{
		params [["_position", [0,0,0], [[]], 3], ["_target", objNull, [objNull]]];
		if (!isNil "_target") then {
			{
				[_x,"PATH"] remoteExec ["disableAI", _x];
			} forEach units group _target;
		}
	}] call zen_custom_modules_fnc_register;

};