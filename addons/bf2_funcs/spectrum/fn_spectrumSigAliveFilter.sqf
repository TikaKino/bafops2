params ["_frequency","_signalstrength","_emitter","_receiver","_args"];
/*
	Extra parameters:
	none
*/

if (alive _emitter) then {
	_signalstrength
} else {
	false
};