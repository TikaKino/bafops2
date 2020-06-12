
if(hasInterface) then { //Only trigger for players
	[] spawn {
		waitUntil {sleep 0.1; (time > 0) && (!isNull player) && (alive player)};
		player setVariable ["bafops2_scripts_navpoint_marker",false];
		
		//Add an event handler for onSingleMapClick - we care about _shift, _alt and _pos
		//Remember to return false to allow other click handlers to happen!
		["bafops2_navpoint_click", "onMapSingleClick", {
			
			if(_shift && !_alt) then { //Only care if we have shift-clicked
				player setVariable ["bafops2_scripts_navpoint_marker",_pos]; //Set the location of the click to the player
			};
			
			//Return in sqf is the last line executed in a code block, because reasons.
			false;
		}] call BIS_fnc_addStackedEventHandler;
		
		//Add a mission event handler for Draw3D to draw the icon
		_id = addMissionEventHandler ["Draw3D",{
			
			_active = player getVariable ["bafops2_scripts_navpoint_enable",false];
			_wploc = player getVariable ["bafops2_scripts_navpoint_marker",false];
			//Only draw if we have a location to draw to and are active
			if(!(_wploc isEqualTo false) && !(_active isEqualTo false)) then {
				//Get a useful position from the click position (i.e. don't go under the waves; drawIcon3D expects PositionAGL)
				_iconpos = [_wploc select 0,_wploc select 1,0.75];
				
				drawIcon3D ["\a3\ui_f\data\map\markers\military\circle_ca.paa", [1,1,1,0.5], _iconpos, 0.5, 0.5, 0, "", 0, 0.05, "TahomaB", "left", true];
				drawIcon3D ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0,0,0,0.5], _iconpos, 0.5, 0.5, 0, "", 0, 0.05, "TahomaB", "left", true];
			};
			
		}];
	};
};