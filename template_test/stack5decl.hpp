#pragma once

#include <deque>
#include <cassert>

template<typename T>
class Stack
{
private:
	std::deque<T> elems;

public:
	void push(T const& elem);
	void pop();
	T const& top();
	bool empty() const {
		return elems.empty();
	}

	template<typename T2>
	Stack<T>& operator=(Stack<T2> const& op2);

	template<typename> friend class Stack;
};

template<typename T>
template<typename T2>
inline Stack<T>& Stack<T>::operator=(Stack<T2> const & op2)
{
	//Stack<T2> temp(op2);

	//elems.clear();
	//while (!temp.empty())
	//{
	//	elems.push_front(temp.top());	// type check occure hera
	//	temp.pop();
	//}
	//return *this;

	// declare all Stack instances are friend class 
	elems.clear();
	elems.insert(elems.begin(), op2.elems.begin(), op2.elems.end());
	return *this;
}

template<typename T>
inline void Stack<T>::push(T const & elem)
{
	elems.push_back(elem);
}

template<typename T>
inline void Stack<T>::pop()
{
	assert(!empty());
	elems.pop_back();
}

template<typename T>
inline T const & Stack<T>::top()
{
	return elems.back();
}
