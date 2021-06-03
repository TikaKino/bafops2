params [["_logic",objNull],["_objects",[]],["_activated",true]];

if(!isServer) exitWith {};

_attlogics = [_logic,"Logic",false] call BIS_fnc_synchronizedObjects;

_forts = [];

{
	_fortData = [_x] call bafops2_fnc_fortsGetFort;
	if(_fortData isEqualTo false) then { continue; };
	_forts pushBack _fortData;
	
} forEach _attLogics;

_target = _logic getVariable ["NumberOfForts",1];
if(_target < 0) then { _target = (count _forts) - _target; };
if(_target < 0) then { _target = 0; };

_rem = _target;
while { _rem > 0 } do {
	_index = floor random count _forts;
	_forts deleteAt _index;
	_rem = _rem - 1;
};

{
	[_x] call bafops2_fnc_fortsDeleteFort;
} forEach _forts;