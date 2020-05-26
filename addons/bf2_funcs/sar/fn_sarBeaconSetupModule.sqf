params [["_logic",objNull],["_objects",[]],["_activated",true]];

if (isServer && _activated) then {
	
	_accstr = _logic getVariable ["BeaconAccuracy","[]"];
	_acc = parseSimpleArray _accstr;
	_number = parseNumber (_logic getVariable ["NumberOfBeacons","1"]);
	_auto = _logic getVariable ["BeaconAutoUpdate","yes"];
	_start = _logic getVariable ["BeaconAutoStart","yes"];
	_physreps = +_objects;
	
	//Randomly narrow down our physreps, if we've asked for less physreps than supplied objects
	if (_number > 0 && _number < (count _physreps)) then {
		_rem = (count _physreps) - _number;
		while { _rem > 0 } do {
			_index = floor random count _physreps;
			_physreps deleteAt _index;
			_rem = _rem - 1;
		};
	};
	
	[_logic,_physreps,_acc] call bafops2_fnc_sarBeaconSetup;
	
	if(_auto == "yes") then {
		[_logic] call bafops2_fnc_sarBeaconAutoUpdate;
	};
	
	if (_start == "yes") then {
		[_logic] spawn {
			params ["_logic"];
			waitUntil { _logic getVariable ["bafops2_sarbeacon_setup",false]; };
			[_logic] call bafops2_fnc_sarBeaconStart;
		};
	};
};