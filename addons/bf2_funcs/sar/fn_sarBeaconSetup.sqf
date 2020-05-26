/*
	Creates an SAR beacon logic, with one or more attached physical locations.
 */
params [["_beaconLogic",objNull],["_beaconPhysreps",[]],["_accuracyLevels",[100,200,400,800,1600]]];

//this script can only be run on the server, to ensure an authoritative source.
if (!isServer) exitWith { systemChat "Called bafops2_fnc_sarBeaconSetup on non-server."; false };

_lastAcc = 0;
_lastPos = [0,0];
//array format: [ x , y , size ]
//x and y are relative to physrep locations, not absolute.
_circlePositions = [];

{
	_diff = _x - _lastAcc;
	
	//pick a random direction and distance up to the max. Will cluster slightly in the middle, which is ideal.
	_dir = random 360;
	_dist = random _diff;
	
	_t = _lastPos getPos [_dist,_dir];
	_newPos = [_t select 0, _t select 1];
	
	_circlePositions pushBack (_newPos + [_x]);
	
	_lastAcc = _x;
	_lastPos = _newPos;
} forEach _accuracyLevels;

[_beaconLogic,["bafops2_sarbeacon_physreps",_beaconPhysreps]] remoteExec ["setVariable",0];
[_beaconLogic,["bafops2_sarbeacon_positions",_circlePositions]] remoteExec ["setVariable",0];
[_beaconLogic,["bafops2_sarbeacon_selected",(count _circlePositions) - 1]] remoteExec ["setVariable",0];
[_beaconLogic,["bafops2_sarbeacon_active",false]] remoteExec ["setVariable",0];
[_beaconLogic,["bafops2_sarbeacon_setup",true]] remoteExec ["setVariable",0];

{
	[_x,["bafops2_sarbeacon_logic",_beaconLogic]] remoteExec ["setVariable",0];
	[_x,["bafops2_sarbeacon_marker",false]] remoteExec ["setVariable",0];
	[_x,["bafops2_sarbeacon_marker_text",false]] remoteExec ["setVariable",0];
} forEach _beaconPhysreps;

true