params ["_fortLogic"];

_fortDataSource = _fortLogic getVariable ["bafops2_forts_fortdata",false];
if(_fortDataSource isEqualTo false) exitWith { false };
_fortData = +_fortDataSource;


_fortMembers = [_fortLogic,"AllVehicles",false] call BIS_fnc_synchronizedObjects;
_fortComponents = [_fortLogic,"Static",false] call BIS_fnc_synchronizedObjects;
_fortComponents = _fortComponents + ([_fortLogic,"Thing",false] call BIS_fnc_synchronizedObjects);

_fortData set ["members",_fortMembers];
_fortData set ["components",_fortComponents];

_fortData