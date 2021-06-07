params [["_logic",objNull],["_objects",[]],["_activated",true]];

if(!isServer) exitWith {};

{
	_x setVariable ["bafosp2_forts_persistFortRemoval",true];
} forEach _objects;