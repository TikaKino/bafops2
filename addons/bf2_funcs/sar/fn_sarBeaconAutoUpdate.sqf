params [["_beaconLogic",objNull],["_updateTime",5]];

if (!isServer) exitWith {systemChat "Called bafops2_fnc_sarBeaconAutoUpdate on non-server."; false};

[_beaconLogic,["bafops2_sarbeacon_autoupdate_time",_updateTime]] remoteExec ["setVariable",0];
_updater = _beaconLogic getVariable ["bafops2_sarbeacon_autoupdater",false];

if ((_updater isEqualTo false) && !(_updateTime isEqualTo false) ) then {
	_updater = [_beaconLogic] spawn {
		params [["_beaconObjectSp",player]];
		
		_time = _beaconObjectSp getVariable ["bafops2_sarbeacon_autoupdate_time",false];
		
		while { true; } do {
			if(!(_time isEqualTo false)) then {
				[_beaconObjectSp] call bafops2_fnc_sarBeaconUpdate;
			} else {
				_time = 2;
			};
			sleep _time;
			_time = _beaconObjectSp getVariable ["bafops2_sarbeacon_autoupdate_time",false];
		}
	};
	[_beaconLogic,["bafops2_sarbeacon_autoupdater",_updater]] remoteExec ["setVariable",0];
};