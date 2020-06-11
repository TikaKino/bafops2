_markername = "bafops2_playerpos";

_createwaypoint = {
	params ["_markername"];
	_playerPos = createMarkerLocal [_markername, position player];//create marker
	_markername setMarkerTextLocal "";
	_markername setMarkerTypeLocal "Select";
	_markername setMarkerColorLocal "ColorWEST";
	_markername setMarkerSize [0.75, 0.75];
	player setVariable ["bafops2_scripts_playermarker_marker",_markername];
};

_deletewaypoint = {
	params ["_markername"];
	deleteMarkerLocal _markername;
	player setVariable ["bafops2_scripts_playermarker_marker",false];
};

_updatewaypoint = {
	_markername = player getVariable ["bafops2_scripts_playermarker_marker",false];
	if(!(_markername isEqualTo false)) then {
		_markername setMarkerPosLocal position player;
	};
};

if(hasInterface)then{
	[_markername,_createwaypoint,_deletewaypoint,_updatewaypoint] spawn {
	
		params ["_markername","_createwaypoint","_deletewaypoint","_updatewaypoint"];
		while {true} do {
			waitUntil { uiSleep 0.1; visibleMap or visibleGPS };
			
			_active = player getVariable ["bafops2_scripts_playermarker_enable",true];
			_marker = player getVariable ["bafops2_scripts_playermarker_marker",false];
			
			if (_active) then {
				
				if (_marker isEqualTo false) then {
					[_markername] call _createwaypoint;
				};
				[] call _updatewaypoint;
			} else {
				if (!(_marker isEqualTo false)) then {
					[_marker] call _deletewaypoint;
				}
			};
		};
		
	};
};