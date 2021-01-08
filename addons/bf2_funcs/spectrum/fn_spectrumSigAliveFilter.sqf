params ["_frequency","_signalstrength","_args"];
/*
	Extra parameters:
	_emitter			Emitting object
*/
_args params ["_emitter"];

if (alive _emitter) then {
	_signalstrength
} else {
	false
};