params [["_logic",objNull],["_objects",[]],["_activated",true]];

if (isServer && _activated) then {
	
	_etitle = _logic getVariable ["EntryTitle","Found Intel"];
	_etext = _logic getVariable ["EntryText","(Found an intel item; no text supplied)"];
	_escope = _logic getVariable ["Scope","unit"];
	
	[_logic,["bafops2_intel_entrytitle",_etitle]] remoteExec ["setVariable",0,(str _logic)+"_inteltitle"];
	[_logic,["bafops2_intel_entrytext",_etext]] remoteExec ["setVariable",0,(str _logic)+"_inteltext"];
	[_logic,["bafops2_intel_scope",_escope]] remoteExec ["setVariable",0,(str _logic)+"_intelscope"];
	
	{
		[_x,_logic] call bafops2_fnc_intelCreateIntelObject;
	} forEach _objects;
	
};