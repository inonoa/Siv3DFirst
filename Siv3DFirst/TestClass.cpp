#include "TestClass.h"

TestClass::TestClass(String name, int age) : name(name), age(age) {}

String TestClass::IntroduceSelf() {
	return U"I'm {}, and I'm {} years old."_fmt(name, age);
}
