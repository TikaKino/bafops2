params ["_fortLogic","_fortType","_fortName",["_params",[]]];

private _fortMap = createHashMap;
_fortMap set ["logic",_fortLogic];
_fortMap set ["name",_fortName];
_fortMap set ["type",_fortType];
_fortMap set ["score",50];

{
	_fortMap set [_x select 0,_x select 1];
} forEach _params;

_fortLogic setVariable ["bafops2_forts_fortdata",_fortMap];