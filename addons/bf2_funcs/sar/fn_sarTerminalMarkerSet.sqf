params [["_logic",objNull],["_terminal",objNull]];

if (!isServer) exitWith { false };

_markername = _logic getVariable ["MarkerName",""];
_shape = "";
_state = _terminal getVariable ["bafops2_terminal_state","off"];

switch (_state) do {
	case "active": {
		_shape = _logic getVariable ["ShapeActive","mil_objective"];
	};
	case "complete": {
		_shape = _logic getVariable ["ShapeComplete","mil_dot"];
	};
	case "off": {
		_shape = _logic getVariable ["ShapeOff","Empty"];
	};
	default {
		_shape = _logic getVariable ["ShapeOff","Empty"];
	};
};

_markername setMarkerType _shape;

true