params ["_frequency","_signalstrength","_emitter","_receiver","_args"];
/*
	Extra parameters:
	_maxStrengthAngle	Angle below which signal will be at max strength
	_minStrengthAngle	Angle above which signal will be at min strength
*/
_args params ["_maxStrengthAngle","_minStrengthAngle"];

_intensity = _signalstrength;
_scalemin = missionNamespace getVariable ["#EM_SMin", -60];
_anglerange = _minStrengthAngle - _maxStrengthAngle;

_direction = player getRelDir _emitter;
if(_direction > 180) then { _direction = _direction - 360; };
_absdir = abs _direction;

if (_absdir > _maxStrengthAngle) then {
	if(_absdir <= _minStrengthAngle) then {
		_scalerange = _intensity - _scalemin;
	
		_absdir = _absdir - _maxStrengthAngle;
		_absdir = _absdir / _anglerange;
		_absdir = 1 - _absdir;
		_scaled = _scalerange * _absdir;
		_intensity = _scalemin + _scaled;
	} else {
		_intensity = _scalemin;
	}
};

_intensity