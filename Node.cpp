#include "Node.h"


template <typename T> Node<T>::Node()
{
	next = NULL;
	prev = NULL;
}


template <typename T> Node<T>::~Node()
{
	next = NULL;
	prev = NULL;
}
