// template_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#if 0
#include "arrays.hpp"

template<typename T1, typename T2, typename T3>
void foo(int a1[7], int a2[],		// pointers by language rules
	int(&a3)[42],					// reference to array of known bound
	int(&x0)[],						// reference to array of unknown bound
	T1 x1,							// passing by value	decays
	T2& x2, T3& x3)					// passing by reference
{
	MyClass<decltype(a1)>::print();	// MyClass<T*>
	MyClass<decltype(a2)>::print();	// MyClass<T*>
	MyClass<decltype(a3)>::print();	// MyClass<T(&)[SZ]>
	MyClass<decltype(x0)>::print();	// MyClass<T(&)[]>
	MyClass<decltype(x1)>::print();	// MyClass<T*>
	MyClass<decltype(x2)>::print();	// MyClass<T(&)[]>
	MyClass<decltype(x3)>::print();	// MyClass<T(&)[]>
}

int main()
{
	int a[42];
	MyClass<decltype(a)>::print();	// MyClass<T[SZ]>

	extern int x[];
	MyClass<decltype(x)>::print();	// MyClass<T[]>

	foo(a, a, a, x, x, x, x);

	system("pause");
    return 0;
}

int x[] = { 0, 8, 15 };

#endif

#if 0
#include "stack5decl.hpp"

int main()
{
	Stack<int> intStack;
	Stack<float> floatStack;

	intStack.push(7);
	intStack.push(6);

	floatStack.push(1.7f);
	floatStack.push(1.8f);
	floatStack.push(1.9f);

	intStack = floatStack;

	system("pause");
	return 0;
}

#endif

#if 0
#include "move1.hpp"
//#include "move2.hpp"

int main()
{
	X v;			// variable
	X const c;		// constant

	f(v);
	f(c);
	f(X());
	f(std::move(v));

	system("pause");
	return 0;
}

#endif

#if 1
#include "specialmemtempl1.hpp"

int main()
{
	//std::string s = "test";

	//Person p1(s);
	//Person p2("temp");

	Person const pc("const");

	//Person p3(p1);		// ERROR. overload resolution rule
	Person p3(pc);
	//Person p4(std::move(p1));

	//Person p5(std::string("ss"));

	system("pause");
	return 0;
}
#endif
