// 10102019Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TestClass.h"

int main()
{
	TestClass* ptr_t1 = new TestClass(1, 3.3, 5.555555);
	TestClass* ptr_t2 = new TestClass(2, 4.4, 6.666666);

	TestClass ptr_T = (*ptr_t1) + (*ptr_t2);
	
	std::cout << "Result's int is " << ptr_T.get_int() << std::endl;
	std::cout << "Result's float is " << ptr_T.get_float() << std::endl;
	std::cout << "Result's double is " << ptr_T.get_double() << std::endl;
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
