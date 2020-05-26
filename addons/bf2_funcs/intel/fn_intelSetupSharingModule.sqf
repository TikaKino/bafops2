params [["_logic",objNull],["_objects",[]],["_activated",true]];

if (!isServer) exitWith { systemChat "Attempted to call bafops2_fnc_intelSetupSharingModule on non-server."; };
if (!_activated) exitWith { false };

[] remoteExec ["bafops2_fnc_intelSetupSharingToPlayer",0,true];