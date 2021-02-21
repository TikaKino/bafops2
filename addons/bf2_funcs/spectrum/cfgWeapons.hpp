class muzzle_antenna_01_f;
class hgun_esd_01_base_F {
	class WeaponSlotsInfo {
		class MuzzleSlot;
	};
};
class TIKA_BF2_muzzle_antenna_radio: muzzle_antenna_01_f {
	displayName = "SD Radio Band Antenna (100-300 MHz)";
};

class hgun_esd_01_F: hgun_esd_01_base_F {
	class WeaponSlotsInfo: WeaponSlotsInfo {
		class MuzzleSlot: MuzzleSlot {
			compatibleItems[] = {"muzzle_antenna_test_01","muzzle_antenna_01_f","TIKA_BF2_muzzle_antenna_radio"};
		};
	};
};