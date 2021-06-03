params["_fortType","_numberOfForts"];

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