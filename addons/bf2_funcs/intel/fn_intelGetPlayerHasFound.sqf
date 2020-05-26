params [["_intelObject",objNull],["_player",objNull]];

_existing = _player getVariable ["bafops2_intel_founditems",[]];
_index = _existing find _intelObject;
if (_index == -1) then {
	false
} else {
	true
};