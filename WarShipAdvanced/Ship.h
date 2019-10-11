#pragma once
#include <string>
#include <iostream>

using namespace std;

class Ship
{
public:
	Ship();
	Ship(int hps, int armour_level, int block, string player_name);
	virtual ~Ship();

	virtual int get_hit_points() { return hit_points; };
	virtual int get_accumulated_damage() { return accumulated_damage; };
	virtual void set_hit_points(int new_HP) { hit_points = new_HP; };
	virtual void set_accumulated_damage(int new_damage) { accumulated_damage = new_damage; };
	virtual int get_armour() { return armour; };
	virtual void set_armour(int new_armour) { armour = new_armour; };
	virtual int get_block() { return block_taken; };
	virtual void set_block(int new_block) { block_taken = new_block; };


	virtual bool being_damaged(int damage_value);
	virtual void cannon_attack(int x, int y);

protected:
	int hit_points;
	int accumulated_damage;
	int armour;
	int block_taken;
	string owner;
};

