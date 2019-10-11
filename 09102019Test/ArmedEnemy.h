#pragma once
#include "Enemy.h"
class ArmedEnemy :
	public Enemy
{
public:
	ArmedEnemy(int hps, int new_score, int ammo);
	virtual ~ArmedEnemy();
	virtual void shoot();

	virtual int get_Hit_Points();
	virtual int get_Score();
	virtual void set_Hit_Points(int new_HP);
	virtual void set_Score(int new_Score);
	virtual bool be_Damaged(int damage_Value);

protected:
	int ammo_level;
};

