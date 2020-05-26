params [["_intelObject",objNull],["_player",objNull]];

if (!local _player) exitWith {systemChat "non-local player passed to intelAddIntelEntryToPlayer";false};

_subjectid = _intelObject getVariable ["bafops2_intel_subjectid","bf2_intel"];
_subjecttitle = _intelObject getVariable ["bafops2_intel_subjecttitle","Found Intel"];
_entrytitle = _intelObject getVariable ["bafops2_intel_entrytitle","Intel Object"];
_entrytext = _intelObject getVariable ["bafops2_intel_entrytext","(Text Here: no bafops2_intel_entrytext variable set on object)"];

if (!(_player diarySubjectExists _subjectid)) then {
	_player createDiarySubject [_subjectid,_subjecttitle];
};

player createDiaryRecord [_subjectid, [_entrytitle,_entrytext]];
[_intelObject,_player,true] call bafops2_fnc_intelSetPlayerHasFound;