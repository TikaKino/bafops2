if (!hasInterface) exitWith {};

["Respawn", "Respawn Player Now",
{
	// Get all the passed parameters
	params [["_position", [0,0,0], [[]], 3], ["_objectUnderCursor", objNull, [objNull]]];
	
	_dead = [];
	_deadObj = [];
	{
		if (!alive _x) then {
			_dead pushBack (name _x);
			_deadObj pushBack _x;
		}
	} forEach allPlayers;
	
	if ((count _dead) < 1) exitWith { hintSilent "No dead players." };

	private _dialogResult =
	[
		"Respawn Player Now",
		[
			// The last number is optional! If you want the first selection you can remove the number.
			["Player", _dead]
		]
	] call Ares_fnc_showChooseDialog;
	
	if (_dialogResult isEqualTo []) exitWith {};
	
	_dialogResult params ["_selected"];
	_target = _deadObj select _selected;
	
	[0] remoteExec ["setPlayerRespawnTime",_target];
	[_target] spawn {
		params["_target"];
		sleep 2;
		_delay = getMissionConfigValue ["respawnDelay",3000000];
		[_delay] remoteExec ["setPlayerRespawnTime",_target];
	};
	
}] call zen_custom_modules_fnc_register;