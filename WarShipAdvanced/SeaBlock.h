#pragma once
#ifndef _SHIP_H_
#define _SHIP_H_
#include "Ship.h"
#endif // !_SHIP_H_


class SeaBlock
{
protected:
	SeaBlock* north_block = nullptr;
	SeaBlock* south_block = nullptr;
	SeaBlock* west_block = nullptr;
	SeaBlock* east_block = nullptr;

	Ship* warship = nullptr;

public:;
	   virtual SeaBlock* get_north_block() { return north_block; };
	   virtual SeaBlock* get_south_block() { return south_block; };
	   virtual SeaBlock* get_west_block() { return west_block; };
	   virtual SeaBlock* get_east_block() { return east_block; };

	   virtual void set_north_block(SeaBlock* block) { north_block = block; };
	   virtual void set_south_block(SeaBlock* block) { south_block = block; };
	   virtual void set_west_block(SeaBlock* block) { west_block = block; };
	   virtual void set_east_block(SeaBlock* block) { east_block = block; };

	   virtual void set_ship_on_block(Ship* ship) { warship = ship; };
	   virtual Ship* get_warship() { return warship; };

	   SeaBlock() {};
	   ~SeaBlock() {};
};

