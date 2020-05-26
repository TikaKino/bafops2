params [["_from",objNull],["_to",objNull]];

_fromitems = _from getVariable ["bafops2_intel_founditems",[]];
_toitems = _to getVariable ["bafops2_intel_founditems",[]];

_shift = _fromitems - _toitems;

{
	//systemChat format ["Handing over item: %1",_x];
	[_x,_to] remoteExec ["bafops2_fnc_intelAddIntelEntryToPlayer",_to];
} forEach _shift;

systemChat format ["Handed over %1 intel items.",(count _shift)];
[format ["%1 intel items donated by %2.",(count _shift),name _from]] remoteExec ["systemChat",_to];