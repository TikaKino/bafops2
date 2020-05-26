params [["_logic",objNull],["_objects",[]],["_activated",true]];

if (isServer && _activated) then {
	{
		[_x,"PATH"] remoteExec ["disableAI", _x];
	} forEach _objects;
};