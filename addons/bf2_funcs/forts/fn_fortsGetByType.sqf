params ["_fortType"];

_list = [];

_area = missionNamespace getVariable [_fortType,false];

//If the supplied string isn't the variable name of a fort area object, fall back to the old method of logics with a set string type.
if(_area isEqualTo false) then {

	_logics = entities "Logic";

	{
		_fortData = [_x] call bafops2_fnc_fortsGetFort;
		if(_fortData isEqualTo false) then {continue};
		
		if((_fortData get "type") != _fortType) then {continue};
		_list pushBack _fortData;
	} forEach _logics;
	
} else {
	
	_logics = [_area,"Logic",false] call BIS_fnc_synchronizedObjects;
	{
		_fortData = [_x] call bafops2_fnc_fortsGetFort;
		if(_fortData isEqualTo false) then {continue};
		_list pushBack _fortData;
		
	} forEach _logics;
	
};

_list