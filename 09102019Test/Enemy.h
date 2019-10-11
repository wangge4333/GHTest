#pragma once
class Enemy
{
public:
	Enemy(int hps, int ini_score);
	virtual ~Enemy();
	virtual int get_Hit_Points() = 0;
	virtual int get_Score() = 0;
	virtual void set_Hit_Points(int new_HP) = 0;
	virtual void set_Score(int new_Score) = 0;
	virtual bool be_Damaged(int damage_Value) = 0;
protected:
	int hit_points;
	int score;
};

