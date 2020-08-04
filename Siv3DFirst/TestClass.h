#pragma once

# include <Siv3D.hpp>

class TestClass
{
private:
	String name;
	int age;
public:
	TestClass(String name, int age);
	String IntroduceSelf();
};

