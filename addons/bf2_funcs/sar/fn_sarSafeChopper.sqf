params ["_target","_thresholdHeight","_thresholdSpeed"];

if (!isServer) exitWith {};

[_target,_thresholdHeight,_thresholdSpeed] spawn {
	params ["_target","_thresholdHeight","_thresholdSpeed"];
	
	while { !(isNull _target) } do {
		sleep 0.1;
		
		_pos = getPosATL _target;
		_height = _pos select 2;
		_v = velocity _target;
		_vel = vectorMagnitude [_v select 0, _v select 1, 0];
		_captive = captive _target;
		
		if(_target getVariable ["bafops2_track",false]) then {
			hintSilent format ["%1 %2 %3",_height,_vel,_captive];
		};
		
		if (_height > (_thresholdHeight + 3) && (_vel > _thresholdSpeed) && !_captive) then {
			[_target,true] remoteExec ["setCaptive",_target];
		};
		
		if ((_height < (_thresholdHeight - 3) || (_vel < (_thresholdSpeed - 1))) && _captive) then {
			[_target,false] remoteExec ["setCaptive",_target];
		};
	};
};