params["_fortType","_numberOfForts"];

/*_logics = entities "Logic";
_list = [];

{
	_fortData = [_x] call bafops2_fnc_fortsGetFort;
	if(_fortData isEqualTo false) then {continue};
	
	if((_fortData get "type") != _fortType) then {continue};
	_list pushBack _fortData;
} forEach _logics;*/
_list = [_fortType] call bafops2_fnc_fortsGetByType;

_rem = _numberOfForts;
while { _rem > 0 } do {
	_index = floor random count _list;
	_list deleteAt _index;
	_rem = _rem - 1;
};

{
	[_x] call bafops2_fnc_fortsDeleteFort;
} forEach _list;