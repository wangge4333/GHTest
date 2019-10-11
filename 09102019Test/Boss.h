#pragma once
#include "ArmedEnemy.h"
class Boss :
	public ArmedEnemy
{
public:
	Boss(int hps, int new_score, int ammo, int armour);
	~Boss();
	virtual bool be_Damaged(int damage_Value) override;

protected:
	int armour_level;
};

