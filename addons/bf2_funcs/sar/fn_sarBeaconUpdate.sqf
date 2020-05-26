params [["_beaconLogic",objNull]];

if (!isServer) exitWith {systemChat "Called bafops2_fnc_sarBeaconUpdate on non-server."; false};

_physreps =  _beaconLogic getVariable ["bafops2_sarbeacon_physreps",[]];
_positions = _beaconLogic getVariable ["bafops2_sarbeacon_positions",[]];
_selPosition = _beaconLogic getVariable ["bafops2_sarbeacon_selected",-1];
_active = _beaconLogic getVariable ["bafops2_sarbeacon_active",false];

if(_selPosition == -1 || (count _positions) < 1) exitWith { systemChat "Called bafops2_fnc_sarBeaconUpdate on a non-setup beacon."; false };

{
	
	_marker = _x getVariable ["bafops2_sarbeacon_marker",false];
	_markerText = _x getVariable ["bafops2_sarbeacon_marker_text",false];
	
	if (!(_marker isEqualTo false)) then {
		_beaconPos = position _x;
		_markerOffset = _positions select _selPosition;
		_markerPos = [(_beaconPos select 0) + (_markerOffset select 0),(_beaconPos select 1) + (_markerOffset select 1)];
		_markerSize = _markerOffset select 2;
		
		_marker setMarkerSize [_markerSize,_markerSize];
		_marker setMarkerPos _markerPos;
	};
	
	if (!(_markerText isEqualTo false)) then {
		_beaconPos = position _x;
		_markerOffset = _positions select _selPosition;
		_markerPos = [(_beaconPos select 0) + (_markerOffset select 0),(_beaconPos select 1) + (_markerOffset select 1)];
		_markerSize = _markerOffset select 2;
		
		_markerText setMarkerPos _markerPos;
	};
	
} forEach _physreps;