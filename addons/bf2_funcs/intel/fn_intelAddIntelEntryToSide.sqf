params [["_intelObject",objNull],["_side",west]];

{if ((side _x) == _side) then {
	[_intelObject,_x] remoteExec ["bafops2_fnc_intelAddIntelEntryToPlayer",_x];
}} forEach allUnits;