// 08102019Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <random>
#include <memory>

using namespace std;

const int s_length = 5;

void printSquare(bool** s_square, int x);
bool guessPosition(bool** sea_square, bool** if_guessed_square);

int main()
{
	
	bool** sea_square;
	bool** if_sea_element_known;
	
	sea_square = new bool* [s_length];					//initialize battleground
	for (int i = 0; i < s_length; i++)
		sea_square[i] = new bool[s_length];

	//memset(sea_square, false, sizeof(sea_square));

	for (int i = 0; i < s_length; i++)
		for (int j = 0; j < s_length; j++)
			sea_square[i][j] = false;

	if_sea_element_known = new bool* [s_length];		//initialize if the element is known
	for (int i = 0; i < s_length; i++)
		if_sea_element_known[i] = new bool[s_length];
	for (int i = 0; i < s_length; i++)
		for (int j = 0; j < s_length; j++)
			if_sea_element_known[i][j] = false;

	default_random_engine r;							//random set player position
	uniform_int_distribution<signed> r_dis(0, 4);
	sea_square[r_dis(r)][r_dis(r)] = true;

	printSquare(if_sea_element_known, 2);

	while (guessPosition(sea_square, if_sea_element_known) == false);

}

void printSquare(bool** s_square, int x) {
	for (int i = 0; i < s_length; i++) {
		for (int j = 0; j < s_length; j++) {
			if(x==1){
				if (s_square[i][j] == true)
					cout << 'O' << ' ';
				else
					cout << 'X' << ' ';
			}
			if (x == 2) {
				if (s_square[i][j] == true)
					cout << 'X' << ' ';
				else
					cout << '?' << ' ';
			}
			
		}
		cout << endl;
	}
}

bool guessPosition(bool** sea_square, bool** if_guessed_square) {
	int x, y;
	cout << "Now input the X position. Start from 1, end by 5." << endl;
	cin >> x;

	cout << "Now input the Y position. Start from 1, end by 5." << endl;
	cin >> y;

	x -= 1;
	y -= 1;

	if (sea_square[x][y] == true) {
		printSquare(sea_square, 1);
		cout << "You are right!" << endl;
		return true;
	}
	else
	{
		if_guessed_square[x][y] = true;
		printSquare(if_guessed_square, 2);
		cout << "Try again" << endl;
		return false;
	}
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
