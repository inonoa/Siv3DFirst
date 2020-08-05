#include "Subject.h"

template <typename T>
Subject<T>::Subject()
{
	actions = MakeShared < Array<std::function<void(T)>>>();
}

template <typename T>
void Subject<T>::OnNext(T param)
{
	for (std::function<void(T)> action : this->actions)
	{
		action(param);
	}
}

template <typename T>
void Subject<T>::Subscribe(std::function<void(T)> action)
{
	this->actions << action;
}
