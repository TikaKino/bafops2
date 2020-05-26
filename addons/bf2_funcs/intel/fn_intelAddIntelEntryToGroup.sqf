params [["_intelObject",objNull],["_group",grpNull]];

if(isNull _group) exitWith {false;};

{
	[_intelObject,_x] remoteExec ["bafops2_fnc_intelAddIntelEntryToPlayer",_x];
} forEach (units _group)