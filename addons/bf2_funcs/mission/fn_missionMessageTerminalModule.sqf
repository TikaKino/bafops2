params [["_logic",objNull],["_objects",[]],["_activated",true]];

if (!isServer || !_activated) exitWith { false };

_actiontext = _logic getVariable ["ActionText","Upload Data"];
_successtext = _logic getVariable ["SuccessText","Data uploaded."];
_actiontime = parseNumber (_logic getVariable ["ActionTime",10]);

{
	[_x,_actiontext,_successtext,_actiontime] call bafops2_fnc_missionMessageTerminal;
} forEach _objects;

true