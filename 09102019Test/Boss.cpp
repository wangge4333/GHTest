#include "Boss.h"
#include <iostream>

Boss::Boss(int hps, int new_score, int ammo, int armour) : ArmedEnemy(hps, new_score, ammo), armour_level(armour) {

}

Boss::~Boss() {
	std::cout << "One of Boss died." << std::endl;
}

bool Boss::be_Damaged(int damage_Value) {
	int real_damage = damage_Value - armour_level;
	if (real_damage < 1)
		real_damage = 1;
	hit_points -= real_damage;
	

	if (hit_points > 0) {
		std::cout << "Boss HP : " << hit_points << std::endl;
		return true;
	}
		
	else {
		this->~Boss();
		return false;
	}
		
}
