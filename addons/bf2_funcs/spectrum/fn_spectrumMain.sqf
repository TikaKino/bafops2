[] spawn {

	waitUntil {alive ACE_player};

	missionNamespace setVariable ["#EM_SMin", -38];
	missionNamespace setVariable ["#EM_SMax", -20];
	
	while {true} do {
		waitUntil {alive ACE_player};
		
		if (currentWeapon player == "hgun_esd_01_F") then {		
			_attachment = handgunItems player;
			_attachment = _attachment select 0;
			
			_attachmentStored = player getVariable ["bafops2_spectrum_attachment",""];
			//Set up ranges if attachment has changed
			if(_attachment != _attachmentStored) then {
				_min = 0;
				_max = 10;
				_swidth = 0.4;
				switch(_attachment) do {
					case "muzzle_antenna_01_f": {
						//Military attachment
						_min = 78;
						_max = 89;
						_swidth = 0.4;
					};
					case "muzzle_antenna_02_f": {
						//Experimental attachment
						_min = 390;
						_max = 500;
						_swidth = 5.0;
					};
					case "muzzle_antenna_03_f": {
						//Drone attachment
						_min = 432.5;
						_max = 433.5;
						_swidth = 1.0;
					};
				};
				
				missionNamespace setVariable ["#EM_FMin", _min];
				missionNamespace setVariable ["#EM_FMax", _max];
				missionNamespace setVariable ["#EM_SelMin", _min];
				missionNamespace setVariable ["#EM_SelMax", _min + _swidth];
				missionNamespace setVariable ["#EM_Progress", 0];
				missionNamespace setVariable ["#EM_Transmit", false];
				player setVariable ["bafops2_spectrum_attachment",_attachment];
			};
			
			_fmin = missionNamespace getVariable ["#EM_FMin", 0];
			_fmax = missionNamespace getVariable ["#EM_FMax", 10];
			
			//Go through emitters, run their strength code if they are within the range.
			_emitters = missionNamespace getVariable ["bafops2_spectrum_emitters",[]];
			_strengths = [];
			{
				//expected format: [frequency,intital strength,[
				//	[{filter 1 code},[extra arguments to filter 1]],
				//	[{filter 2 code},[extra arguments to filter 2]],
				//	...
				//]]
				//Each filter receives as arguments: [
				//	_frequency,
				//	_strength, //output from previous filter, or intital strength for first filter
				//	[extra arguments]
				//]
				_x params ["_freq","_strength","_filters"];
				
				if(_freq >= _fmin && _freq <= _fmax) then {
					
					_signalstrength = _strength;
					{
						_x params ["_fcode","_fargs"];
						
						if(!(_signalstrength isEqualTo false)) then {
							_signalstrength = [_freq,_signalstrength,_fargs] call _fcode;
						};
						
					} forEach _filters;
					
					if(!(_signalstrength isEqualTo false)) then {
						_strengths pushBack _freq;
						_strengths pushBack _signalstrength;
					};
				};
				
			} forEach _emitters;
			
			missionNamespace setVariable ["#EM_Values", _strengths];
		};
	};
}