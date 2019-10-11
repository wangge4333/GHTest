#pragma once
#include "Ship.h"
class BattleShip :
	public Ship
{
protected:
	int salvo_turn;			//increase every turn, when reach a certain value, able to salvo

public:
	virtual void salvo();

};

