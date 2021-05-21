params [["_logic",objNull],["_objects",[]],["_activated",true]];

if (!isServer) exitWith { false };
if (!_activated) exitWith { false };

[] remoteExec ["bafops2_fnc_intelSetupSharingToPlayer",0,true];