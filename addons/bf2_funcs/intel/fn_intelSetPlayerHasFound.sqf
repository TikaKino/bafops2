params [["_intelObject",objNull],["_player",objNull],["_found",true]];

_existing = _player getVariable ["bafops2_intel_founditems",[]];

if (_found) then {
	_existing pushBackUnique _intelObject;
} else {
	_index = _existing find _intelObject;
	if (!(_index == -1)) then {
		_existing deleteAt _index;
	};
};

[_player,["bafops2_intel_founditems",_existing]] remoteExec ["setVariable",0];