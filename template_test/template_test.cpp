// template_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "arrays.hpp"
#include "stack5decl.hpp"

//template<typename T1, typename T2, typename T3>
//void foo(int a1[7], int a2[],		// pointers by language rules
//	int(&a3)[42],					// reference to array of known bound
//	int(&x0)[],						// reference to array of unknown bound
//	T1 x1,							// passing by value	decays
//	T2& x2, T3& x3)					// passing by reference
//{
//	MyClass<decltype(a1)>::print();	// MyClass<T*>
//	MyClass<decltype(a2)>::print();	// MyClass<T*>
//	MyClass<decltype(a3)>::print();	// MyClass<T(&)[SZ]>
//	MyClass<decltype(x0)>::print();	// MyClass<T(&)[]>
//	MyClass<decltype(x1)>::print();	// MyClass<T*>
//	MyClass<decltype(x2)>::print();	// MyClass<T(&)[]>
//	MyClass<decltype(x3)>::print();	// MyClass<T(&)[]>
//}

int main()
{
	//int a[42];
	//MyClass<decltype(a)>::print();	// MyClass<T[SZ]>

	//extern int x[];
	//MyClass<decltype(x)>::print();	// MyClass<T[]>

	//foo(a, a, a, x, x, x, x);

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

//int x[] = { 0, 8, 15 };
