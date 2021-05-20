params ["_fortData"];

_fortComponents = _fortData get "components";
_fortMembers = _fortData get "members";

{
	if(_x getVariable ["bafosp2_forts_persistFortRemoval",false]) then {continue};
	if(vehicle _x != _x) then {
		(vehicle _x) deleteVehicleCrew _x;
	} else {
		deleteVehicle _x;
	};
} forEach _fortMembers;

{
	if(_x getVariable ["bafosp2_forts_persistFortRemoval",false]) then {continue};
	deleteVehicle _x;
} forEach _fortComponents;

deleteVehicle (_fortData get "logic");

