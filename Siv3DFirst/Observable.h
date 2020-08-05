#pragma once
#include <Siv3D.hpp>

template <typename T>
class Observable
{
public:
	virtual void Subscribe(std::function<void(T)>) = 0;
};
