params [["_logic",objNull],["_objects",[]],["_activated",true]];

if (!isServer || !_activated) exitWith { false };

//Setup: a variable to store what we think the current state is for each linked object
//Set marker appropriately.
{
	if (isNull _x) exitWith {};
	_varname = format ["bafops2_terminal_screenstate_%1",_x];
	_currentstate = _x getVariable ["bafops2_terminal_state","off"];
	_logic setVariable [_varname,_currentstate];
	[_logic,_x] call bafops2_fnc_sarTerminalMarkerSet;
} forEach _objects;

//Then, set up a listener that checks the state of the terminal and fires off another setter function (not JIP'd) whenever it doesn't match our stored version.
[_logic,_objects] spawn {
	params [["_logic",objNull],["_objects",[]]];
	
	sleep 1;
	while {true} do {
		sleep 0.5; //only trigger about twice a second, to be sure we don't crowd processor power.
		{
			if (!isNull _x) then {
				_varname = format ["bafops2_terminal_screenstate_%1",_x];
				_oldstate = _logic getVariable [_varname,"off"];
				_newstate = _x getVariable ["bafops2_terminal_state","off"];
				if (!(_newstate == _oldstate)) then {
					_logic setVariable [_varname,_newstate];
					[_logic,_x] call bafops2_fnc_sarTerminalMarkerSet;
				};
			};
		} forEach _objects;
	};

};