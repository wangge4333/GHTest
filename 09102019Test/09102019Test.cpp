// 09102019Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ArmedEnemy.h"
#include "Boss.h"
#include "Enemy.h"

bool make_Damage(Enemy* target_enemy, int damage_value);

int main()
{
	Enemy* ptr_enemies[11];

	ArmedEnemy soldier_1(10, 5, 7);
	ArmedEnemy armedEnemies[10] = { soldier_1 ,soldier_1 ,soldier_1 ,soldier_1 ,soldier_1 ,soldier_1 ,soldier_1 ,soldier_1 ,soldier_1 ,soldier_1 };

	Boss boss_1(50, 15, 15, 5);

	for (int i = 0; i < 10; i++)
		ptr_enemies[i] = &armedEnemies[i];
	ptr_enemies[10] = &boss_1;
	
	for (int i = 0; i < 11; i++) {
		while (make_Damage(ptr_enemies[i], 8) == true) {

		}
	}
}

bool make_Damage(Enemy* target_enemy,int damage_value) {
	return target_enemy->be_Damaged(damage_value);
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
