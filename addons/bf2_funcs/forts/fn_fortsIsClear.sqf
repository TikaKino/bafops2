params ["_fortLogic"];

_fortData = [_fortLogic] call bafops2_fnc_fortsGetFort;
if(_fortData isEqualTo false) exitWith { false };

_clear = true;
{
	if(alive _x) then {
		_clear = false;
		break;
	};
} forEach (_fortData get "members");

_clear