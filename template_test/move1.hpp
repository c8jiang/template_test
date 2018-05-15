#pragma once

#include <utility>
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

// let f() forward argument val to g()
void f(X& val)
{
	g(val);		// val is non-const lvalue => calls g(X&)
}

void f(X const& val)
{
	g(val);		// val is const lvalue => calls g(X const&)
}

void f(X&& val)
{
	g(std::move(val));	// val is non-const lvalue => needs std::move() to call g(X&&)
}
