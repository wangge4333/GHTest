#include "ArmedEnemy.h"
#include <iostream>

ArmedEnemy::ArmedEnemy(int hps, int new_score, int ammo) :Enemy(hps, new_score), ammo_level(ammo) {

}

ArmedEnemy::~ArmedEnemy() {
	std::cout << "One of ArmedEnemy died." << std::endl;
}

int ArmedEnemy::get_Hit_Points() { return hit_points; }
int ArmedEnemy::get_Score() { return score; }

void ArmedEnemy::set_Hit_Points(int new_HP) {
	hit_points = new_HP;
}

void ArmedEnemy::set_Score(int new_score) {
	score = new_score;
}

bool ArmedEnemy::be_Damaged(int damage_Value) {
	hit_points -= damage_Value;
	
	if (hit_points > 0) {
		std::cout << "Enemy HP : " << hit_points << std::endl;
		return true;
	}
	else {
		this->~ArmedEnemy();
		return false;
	}
		
}

void ArmedEnemy::shoot() {
	if (ammo_level > 0) {
		std::cout << "BIU" << std::endl;
		ammo_level--;
	}
	else
	{
		std::cout << "Out of ammo, need to reload." << std::endl;
	}
}