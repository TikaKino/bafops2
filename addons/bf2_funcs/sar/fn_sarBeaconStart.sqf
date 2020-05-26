params [["_beaconLogic",objNull]];

if (!isServer) exitWith {systemChat "Called bafops2_fnc_sarBeaconStart on non-server."; false};

_physreps =  _beaconLogic getVariable ["bafops2_sarbeacon_physreps",[]];
_positions = _beaconLogic getVariable ["bafops2_sarbeacon_positions",[]];
_selPosition = _beaconLogic getVariable ["bafops2_sarbeacon_selected",-1];
_active = _beaconLogic getVariable ["bafops2_sarbeacon_active",false];

if(_selPosition == -1 || (count _positions) < 1) exitWith { systemChat "Called bafops2_fnc_sarBeaconStart on a non-setup beacon."; false };

if (_active isEqualTo true) exitWith { true }; //already active, ignore this call

{
	_marker = _x getVariable ["bafops2_sarbeacon_marker",false];
	_markerText = _x getVariable ["bafops2_sarbeacon_marker_text",false];
	
	if (!(_marker isEqualTo false)) exitWith {}; //skip this physrep if it already has a marker
	
	_markerName = format ["%1_sarbeacon_area",_x];
	_beaconPos = position _x;
	_markerOffset = _positions select _selPosition;
	_markerPos = [(_beaconPos select 0) + (_markerOffset select 0),(_beaconPos select 1) + (_markerOffset select 1)];
	_markerSize = _markerOffset select 2;
	
	_marker = createMarker [_markerName,_markerPos];
	_marker setMarkerSize [_markerSize,_markerSize];
	_marker setMarkerShape "ELLIPSE";
	_marker setMarkerBrush "SolidBorder";
	_marker setMarkerColor "ColorUNKNOWN";
	_marker setMarkerAlpha 0.75;
	_marker setMarkerPos _markerPos;
	
	_markerName = format ["%1_sarbeacon_text",_x];
	_markerText = createMarker [_markerName,_markerPos];
	_markerText setMarkerSize [0.25,0.25];
	_markerText setMarkerShape "ICON";
	_markerText setMarkerTYPE "mil_dot";
	_markerText setMarkerColor "ColorUNKNOWN";
	_markerText setMarkerText "Beacon";
	_markerText setMarkerAlpha 0.75;
	_markerText setMarkerPos _markerPos;
	
	[_x,["bafops2_sarbeacon_marker",_marker]] remoteExec ["setVariable",0];
	[_x,["bafops2_sarbeacon_marker_text",_markerText]] remoteExec ["setVariable",0];
	
} forEach _physreps;

[_beaconLogic,["bafops2_sarbeacon_active",true]] remoteExec ["setVariable",0];

true