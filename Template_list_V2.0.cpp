#include <iostream>
//#include "Node.h"
using namespace std;

//node class
template <typename T>
class Node
{
private:
	T val;
	Node<T>* next, * prev;

public:
	Node();
	Node(const Node<T>& x);

	//set-functions
	void setVal(T x);
	void setNext(Node<T>* x);
	void setPrev(Node<T>* x);

	//get-functions
	T getVal()const;
	Node<T>* getNext()const;
	Node<T>* getPrev()const;

	//operations
	
	~Node();
};

//list class
template<class T>
class List
{
private:

	friend class Node<T>;
	int dimEl;
	Node<T>* first; // trebuie facut si clasa nod
	Node<T>* last;
public:
	List();
	List(int dim, T x);
	List(const List<T>& x);

	void pushFront(T x);
	void pushBack(T x);
	void popFront();
	void popBack();
	~List();
};
template <typename T> Node<T>::Node()
{

	next = NULL;
	prev = NULL;
}
int main()
{
	Node<int>*p=new Node<int>;
	p->setVal(3);
	p->setNext(NULL);
	p->setPrev(NULL);
	cout<<p->getVal();
	
	List<int>l(3,4);
	List<int>d=l;

	//delete p;
	return 0;
}
template<typename T>
Node<T>::Node(const Node<T>& x)
{
	val = x.val;
	prev = x.prev;
	next = x.next;
}

template<typename T>
void Node<T>::setNext(Node<T>* x)
{
	next = x;
}

template<typename T>
void Node<T>::setPrev(Node<T>* x)
{
	prev = x;
}

template<typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
}

template<typename T>
Node<T>* Node<T>::getPrev()const
{
	return prev;
}


template <typename T> void Node<T>::setVal(T x)
{
	val = x;
}
template <typename T>T Node<T>::getVal()const
{
	return val;
}
template <typename T> Node<T>::~Node()
{
	next = NULL;
	prev = NULL;
}

template<class T>
List<T>::List()
{	
	dimEl = 0;
	first = NULL;
	last = NULL;
}

template<class T>
List<T>::List(int dim, T x)
{	
	dimEl = dim;
    first = new Node<T>;
	first->setPrev(NULL);
	first->setVal(x);
	Node<T>* p=first;
	for (int i = 2; i < dim; i++)
	{
		Node<T>* aux = new Node<T>;
		aux->setPrev(p);
		aux->setVal(x);
		p->setNext(aux);
		p = aux;
	}
	last = new Node<T>;
	last->setNext(NULL);
	last->setVal(x);
	last->setPrev(p);
	p->setNext(last);
	p = first;
	for (int i = 0; i < dim; i++)
	{
		cout << p->getVal();
		p = p->getNext();
	}
}

template<class T>
List<T>::List(const List<T>& x)
{
	Node<T>* p, * pNew, * oL;
	p = first;
	pNew = NULL;
	oL = x.first;
	for (int i = 1; i <=x.dimEl; i++)
	{	
		cout << "Copying element " << i << "...\n ";
		Node<T>* aux = new Node<T>;
		//setting Val
		aux->setVal(oL->getVal());
		//setting Prev
		if (i == 1)
			aux->setPrev(NULL);
		else 
		{
			aux->setPrev(pNew);
			
			pNew->setNext(aux);
		}
		//setting Next only if needed
		if (i == x.dimEl )
			aux->setNext(NULL);
		//updates
		pNew = aux;

		if (p != NULL)
		{
			if (p->getNext() != NULL)
			{
				p = p->getNext();
				delete p->getPrev();
			}

		}
		oL = oL->getNext();
		if (i == 0)
			first = pNew;
		
	
	}
	if (x.dimEl < dimEl)
	{
		while (p->getNext() != NULL)
		{
			//delete p;
			p = p->getNext();
			delete p;
			cout << "Deleting the rest...\n";
		}

	}
	dimEl = x.dimEl;
}

template<class T>
void List<T>::pushFront(T x)
{
	Node<T>* temp = new Node<T>;
	temp->setVal(x);
	temp->setPrev(NULL);
	if (dimEl == 0)
	{
		temp->setNext(NULL);
		first = temp;
		last = temp;
	}
	else
	{
		temp->setNext(first);
		first->setPrev(temp);
		first = temp;
	}
	dimEl++;
}

template<class T>
void List<T>::pushBack(T x)
{
	Node<T>* temp = new Node<T>;
	temp->setVal(x);
	temp->setNext(NULL);
	if (dim == 0)
	{
		last = temp;
		first = temp;
		temp->setPrev(NULL);
	}
	else
	{
		last->setNext(temp);
		temp->setPrev(last);
		last = temp;
	}

}

template<class T>
void List<T>::popFront()
{
	if (first != NULL)
	{
		Node* temp = first->getNext();

	}
}

template<class T>
List<T>::~List()
{
	Node<T>* p = first;
	while (p != NULL)
	{
		Node<T>* nextNode = p->getNext();
		delete p;
		p = nextNode;
	}
	cout << "Deletion done";
}
