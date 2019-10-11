// 08102019Test2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Enemy {
public:
	Enemy(int hps, int _score);
	~Enemy();
	virtual int get_hit_points() const;
	virtual int get_score() const;
	virtual void set_hit_points(int _hit_points);
	virtual void set_score(int _score);
private:
	int hit_points;
	int score;
};

Enemy::Enemy(int hps, int _score) :hit_points(hps), score(_score) {

}

Enemy::~Enemy() {
	cout << "Enemy has been deleted." << endl;
}

int Enemy::get_hit_points() const { return hit_points; }
int Enemy::get_score() const { return score; }

void Enemy::set_hit_points(int _hit_points){
	hit_points = _hit_points;
}

void Enemy::set_score(int _score) {
	score = _score;
}

class Player:public Enemy {
public:
	Player(int hps, int _score, string _name);
	~Player();
	string get_name();
	void set_name(string _name);
private:
	string name;
};

Player::Player(int hps, int _score, string _name) :Enemy::Enemy(hps, _score), name(_name) {

}

Player::~Player() {
	//Enemy::~Enemy();
	cout << "Player has been deleted." << endl;
}

string Player::get_name() { return name; }

void Player::set_name(string _name) {
	name = _name;
}


int main()
{
	Player* player1 = new Player(5, 10, "Joey");
	cout << "Player Name: " << player1->get_name() << endl;
	cout << "HP: " << player1->get_hit_points() << endl;
	cout << "Score: " << player1->get_score() << endl;

	delete player1;
	player1 = nullptr;
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
