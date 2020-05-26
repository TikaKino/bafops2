params [["_player",player]];

if (hasInterface) then {
	_action = ["IntelShareAction","Share Intel","",{
	params ["_target", "_caller", "_params"];
		[_caller,_target] call bafops2_fnc_intelShareIntel;
	},{true}] call ace_interact_menu_fnc_createAction;
	[_player, 0, ["ACE_MainActions"], _action] remoteExec ["ace_interact_menu_fnc_addActionToObject",0,true];
};