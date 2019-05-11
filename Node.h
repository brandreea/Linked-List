#pragma once
#include <iostream>
using namespace std;
template <typename T>

class Node
{
private:
	T val;
	//Node<T>* prev, *next;

public:
	 Node();

	//set-functions
	void setVal(T x);
	
	//get-functions
	T getVal();
	 ~Node();
};

template<typename T>
inline void Node<T>::setVal(T x)
{
	val = x;
}

template<typename T>
inline T Node<T>::getVal()
{
	return val;
}
