params [["_logic",objNull],["_terminal",objNull]];

_texnum = parseNumber (_logic getVariable ["TextureNumber",""]);
_image = "";
_state = _terminal getVariable ["bafops2_terminal_state","off"];

switch (_state) do {
	case "active": {
		_image = _logic getVariable ["ImageActive",""];
	};
	case "complete": {
		_image = _logic getVariable ["ImageComplete",""];
	};
	case "off": {
		_image = _logic getVariable ["ImageOff",""];
	};
	default {
		_image = _logic getVariable ["ImageOff",""];
	};
};

_terminal setObjectTextureGlobal [_texnum,_image];