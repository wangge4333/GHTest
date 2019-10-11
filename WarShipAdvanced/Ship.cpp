#include "Ship.h"

Ship::Ship() :hit_points(5), accumulated_damage(0), armour(0), block_taken(1) {

}

Ship::Ship(int hps, int armour_level, int block, string player_name) : hit_points(hps), accumulated_damage(0), armour(armour_level), block_taken(block), owner(player_name) {

}

Ship::~Ship() {
	cout << owner << "'s warship has been destroyed!" << endl;
}

bool Ship::being_damaged(int damage_value) {
	int real_damage = damage_value - armour;
	if (real_damage < 1)
		real_damage = 1;
	accumulated_damage += real_damage;
	if (accumulated_damage >= hit_points)
		return false;								//ship sink
	else
		return true;								//ship still alive
}

void Ship::cannon_attack(int x, int y) {

}