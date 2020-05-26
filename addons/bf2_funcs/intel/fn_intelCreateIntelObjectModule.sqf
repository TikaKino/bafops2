params [["_logic",objNull],["_objects",[]],["_activated",true]];

if (isServer && _activated) then {
	
	_etitle = _logic getVariable ["EntryTitle","Found Intel"];
	_etext = _logic getVariable ["EntryText","(Found an intel item; no text supplied)"];
	_escope = _logic getVariable ["Scope","unit"];
	
	{
		[_x,["bafops2_intel_entrytitle",_etitle]] remoteExec ["setVariable",0];
		[_x,["bafops2_intel_entrytext",_etext]] remoteExec ["setVariable",0];
		[_x,["bafops2_intel_scope",_escope]] remoteExec ["setVariable",0];
		[_x] remoteExec ["bafops2_fnc_intelCreateIntelObject",2];
	} forEach _objects;
	
};