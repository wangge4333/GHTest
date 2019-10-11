#include "TestClass.h"

TestClass::TestClass() :stored_int(0), stored_float(0), stored_double(0) {

}

TestClass::TestClass(int ini_int) : stored_int(ini_int), stored_float(0), stored_double(0) {

}

TestClass::TestClass(float ini_float) : stored_int(0), stored_float(ini_float), stored_double(0) {

}

TestClass::TestClass(double ini_double) : stored_int(0), stored_float(0), stored_double(ini_double) {

}

TestClass::TestClass(int ini_int, float ini_float, double ini_double) : stored_int(ini_int), stored_float(ini_float), stored_double(ini_double) {

}

TestClass::~TestClass() {

}

TestClass operator+(TestClass t1, TestClass t2) {
	TestClass result;
	result.set_int(t1.get_int() + t2.get_int());
	result.set_float(t1.get_float() + t2.get_float());
	result.set_double(t1.get_double() + t2.get_double());
	return result;
}