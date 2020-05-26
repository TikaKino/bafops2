params [["_logic",objNull],["_objects",[]],["_activated",true]];

if (isServer && _activated) then {
	
	_physreps = +_objects;
	_number = parseNumber (_logic getVariable ["NumberOfTerminals","0"]);
	_beaconName = _logic getVariable ["BeaconName","[]"];
	_beaconLogic = missionNamespace getVariable [_beaconName, objNull];
	
	//Randomly narrow down our physreps, if we've asked for less physreps than supplied objects
	if (_number > 0 && _number < (count _physreps)) then {
		_rem = (count _physreps) - _number;
		while { _rem > 0 } do {
			_index = floor random count _physreps;
			_physreps deleteAt _index;
			_rem = _rem - 1;
		};
	};
	
	{
		[_x,_beaconLogic] call bafops2_fnc_sarTerminalImprover;
	} forEach _physreps;
	
};