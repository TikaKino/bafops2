params [["_beaconLogic",objNull]];

if (!isServer) exitWith {systemChat "Called bafops2_fnc_sarBeaconStop on non-server."; false};

_physreps =  _beaconLogic getVariable ["bafops2_sarbeacon_physreps",[]];

{
	_marker = _x getVariable ["bafops2_sarbeacon_marker",false];
	_markerText = _x getVariable ["bafops2_sarbeacon_marker_text",false];
	
	if (!(_marker isEqualTo false)) then {
		deleteMarker _marker;
		[_x,["bafops2_sarbeacon_marker",false]] remoteExec ["setVariable",0];
	};
	
	if (!(_markerText isEqualTo false)) then {
		deleteMarker _markerText;
		[_x,["bafops2_sarbeacon_marker_text",false]] remoteExec ["setVariable",0];
	};
} forEach _physreps;

[_beaconLogic,["bafops2_sarbeacon_active",false]] remoteExec ["setVariable",0];