if (hasInterface) then {

	["ACE Utility", "Spectator Mode On",{
		params [["_position", [0,0,0], [[]], 3], ["_target", objNull, [objNull]]];
		if (!isNil "_target" && isPlayer _target) then {
			[true] remoteExec ["ace_spectator_fnc_setSpectator",_target];
		}
	}] call Ares_fnc_RegisterCustomModule;

	["ACE Utility", "Spectator Mode Off",{
		params [["_position", [0,0,0], [[]], 3], ["_target", objNull, [objNull]]];
		if (!isNil "_target" && isPlayer _target) then {
			[false] remoteExec ["ace_spectator_fnc_setSpectator",_target];
		}
	}] call Ares_fnc_RegisterCustomModule;

};