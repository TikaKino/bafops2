params [["_beaconLogic",objNull]];

if (!isServer) exitWith { systemChat "Called bafops2_fnc_sarBeaconDegrade on non-server."; false };

_positions = _beaconLogic getVariable ["bafops2_sarbeacon_positions",[]];
_selPosition = _beaconLogic getVariable ["bafops2_sarbeacon_selected",-1];

if ((count _positions) > 0 && _selPosition < ((count _positions) -1 )) then {
	_selPosition = _selPosition + 1;
	[_beaconLogic,["bafops2_sarbeacon_selected",_selPosition]] remoteExec ["setVariable",0];
	
	_beaconLogic setVariable ["bafops2_sarbeacon_selected",_selPosition];
	[_beaconLogic] call bafops2_fnc_sarBeaconUpdate;
};