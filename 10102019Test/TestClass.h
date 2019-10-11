#pragma once

class TestClass
{
public:
	TestClass();
	TestClass(int ini_int);
	TestClass(float ini_float);
	TestClass(double ini_double);
	TestClass(int ini_int, float ini_float, double ini_double);
	~TestClass();

	int get_int() const { return stored_int; };
	float get_float() const { return stored_float; };
	double get_double() const { return stored_double; };
	void set_int(int new_int) { stored_int = new_int; };
	void set_float(float new_float) { stored_float = new_float; };
	void set_double(double new_double) { stored_double = new_double; };

	friend TestClass operator+(TestClass t1, TestClass t2);

protected:
	int stored_int;
	float stored_float;
	double stored_double;

};

