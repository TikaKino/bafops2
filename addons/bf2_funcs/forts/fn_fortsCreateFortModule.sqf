params [["_logic",objNull],["_objects",[]],["_activated",true]];

if(!isServer) exitWith {};

_fortName = _logic getVariable ["FortName",""];
_fortScore = _logic getVariable ["FortScore",50];

private _fortMap = createHashMap;
_fortMap set ["logic",_logic];
_fortMap set ["name",_fortName];
_fortMap set ["score",_fortScore];

_fortLogic setVariable ["bafops2_forts_fortdata",_fortMap];