#pragma once
#include "Observable.h"
#include <Siv3D.hpp>

template <typename T>
class Subject :
    public Observable<T>
{
public:
    Subject();
    void Subscribe(std::function<void(T)> action);
private:
    void OnNext(T param);
    std::shared_ptr<Array<std::function<void(T)>>> actions;
};

 