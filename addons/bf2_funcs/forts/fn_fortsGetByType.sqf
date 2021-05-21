params ["_fortType"];

_logics = entities "Logic";
_list = [];

{
	_fortData = [_x] call bafops2_fnc_fortsGetFort;
	if(_fortData isEqualTo false) then {continue};
	
	if((_fortData get "type") != _fortType) then {continue};
	_list pushBack _fortData;
} forEach _logics;

_list