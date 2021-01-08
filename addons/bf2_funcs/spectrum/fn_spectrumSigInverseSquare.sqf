params ["_frequency","_signalstrength","_args"];
/*
	Extra parameters:
	_object			Emitting object
	_falloff		Coefficient of how quickly the signal falls off; 2 will be visible most of the way across the map, 4 from a couple of kilometers away and 6 only from with a hundred meters or so.
*/
_args params ["_object","_falloff"];

_player = player;

_imax = 10 ^ _signalstrength;

_rangemin = 1;

_angleoffmax = 5;
_angleoffmin = 120;
_anglerange = _angleoffmin - _angleoffmax;

_scalemin = missionNamespace getVariable ["#EM_SMin", -60];

_range = _player distance _object;
if(_range < _rangemin) then {_range = _rangemin};
_direction = _player getRelDir _object;
if(_direction > 180) then { _direction = _direction - 360; };
_absdir = abs _direction;

//Use inverse square law(-ish) to get intensity at this distance.
_intensity = ((_rangemin) / (_range ^ _falloff)) * _imax;

_intensity = log _intensity;
if (_intensity < _scalemin) then { _intensity = _scalemin; };

/*//Second: scale by direction
if (_absdir > _angleoffmax) then {
	if(_absdir <= _angleoffmin) then {
		_scalerange = _intensity - _scalemin;
	
		_absdir = _absdir - _angleoffmax;
		_absdir = _absdir / _anglerange;
		_absdir = 1 - _absdir;
		_scaled = _scalerange * _absdir;
		_intensity = _scalemin + _scaled;
	} else {
		_intensity = _scalemin;
	}
};*/

_out = _intensity;

_out