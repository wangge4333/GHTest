#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int hps, int ini_score) :hit_points(hps), score(ini_score) {

}

Enemy::~Enemy() {
	//std::cout << "One of Class Enemy has been deleted." << std::endl;
}

//int Enemy::get_Hit_Points() const { return hit_points; }
//int Enemy::get_Score() const { return score; }
//
//void Enemy::set_Hit_Points(int new_HP) {
//	hit_points = new_HP;
//}
//
//void Enemy::set_Score(int new_score) {
//	score = new_score;
//}