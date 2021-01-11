params ["_frequency","_signalstrength","_emitter","_receiver","_args"];
/*
	Extra parameters:
	_scaling	multiplier to scale the terrain interception by
*/
_args params ["_scaling"];

_imax = 10 ^ _signalstrength;
_terrainBase = _emitter call TFAR_fnc_calcTerrainInterception;
_terrain = 1 + (_terrainBase * 100 * _scaling);
_scalemin = missionNamespace getVariable ["#EM_SMin", -60];

_intensity = _imax / _terrain;

_intensity = log _intensity;
if (_intensity < _scalemin) then { _intensity = _scalemin; };
_intensity