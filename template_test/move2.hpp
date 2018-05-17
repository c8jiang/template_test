#pragma once

//#include <utility>
#include <iostream>

class X
{

};

void g(X&)
{
	std::cout << "g() for variable\n";
}

void g(X const&)
{
	std::cout << "g() for constant\n";
}

void g(X&&)
{
	std::cout << "g() for movable object\n";
}

// let f() perfect forward argument val to g()
template<typename T>
void f(T&& val)
{
	g(std::forward<T>(val));
}
