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
	//methods
	bool isNotEmpty() const;
public:
	List();
	List(int dim, T x);
	List(const List<T>& x);
	
	//get-dim
	int getDimEl();
	Node<T>* getFirst();
	//operations
	void pushFront(T x);
	void pushBack(T x);
	void popFront();
	void popBack();
	void insert(int i, T x);
	void remove(int i);
	//operators
	Node<T>* operator[](int i);
	operator bool()const;
	operator int()const;
	const List<T>&operator =(const List<T>& x);

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
	cout << "For a node P:\n\n";
	p->setVal(3);
	p->setNext(NULL);
	p->setPrev(NULL);
	cout << p->getVal() << "\n\n";
	cout << "For a list L trying parametrized constructor:\n\n";
	List<int>l(3,4);
	cout << "\n\nFor a list D, trying copy-constructor\n\n";
	List<int>d=l;
	cout << "\n\nFor a list X, trying to insert elements via pushFront, pushBack, insert and deletion via remove\n\n";
	List<int>x;
	cout << 2<<"\n";
	x.pushFront(2);
	cout << 4 << "\n";
	x.pushFront(4);
	cout << 5 << "\n";
	x.pushBack(5);
	cout <<3 <<" on position 1"<< "\n";
	x.insert(1, 3);
	cout << "7 on position 2\n";
	x.insert(2, 7);
	cout << "9 on position 6\n";
	x.insert(6, 9);
	cout << "9 on position 9\n";
	x.insert(9, 9);
	Node<int>* temp = x.getFirst();
	for (int i = 1; i <=x.getDimEl(); i++)
	{
		if (temp != NULL)
		{
			cout << temp->getVal() << " ";
			temp = temp->getNext();
		}
	}
	
	x.remove(1);
	x.remove(2);
	x.remove(x.getDimEl());
	temp = x.getFirst();
	cout << "\n\nAfter removing elements list becomes:";
	for (int i = 0; i < x.getDimEl(); i++)
	{
		if (temp != NULL)
		{
			cout << temp->getVal() << " ";
			temp = temp->getNext();
		}
	}
	cout <<"\n\nTrying bool and int operator: ";
	if (l)
		cout << (int)l<<"\n\n";
	temp = x.getFirst();
	for (int i = 0; i < x.getDimEl(); i++)
	{
		if (temp != NULL)
		{
			cout << temp->getVal() << " ";
			temp = temp->getNext();
		}
	}
	cout << "\n\nTrying = operator: copying list L to X\n\n";
	x = l;
	temp = x.getFirst();
	//cout << x.getDimEl() << "\n";
	for (int i = 0; i < x.getDimEl(); i++)
	{
		if (temp != NULL)
		{
			cout << temp->getVal() << " ";
			temp = temp->getNext();
		}
		else cout << "Is NULL\n";
	}
	cout << "\n\n";
	//x.popFront();
	//x.popBack();
	//x.popBack();
	
	
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
bool List<T>::isNotEmpty()const
{
	if (dimEl == 0)
		return 0;
	return 1;
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
	cout << "In copy constructor...\n";
	Node<T>* p, * pNew, * oL;
	p = first;
	pNew = NULL;
	oL = x.first;
	for (int i = 1; i <=x.dimEl; i++)
	{	
		cout << "Copying element " << i << "...\n";
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
				cout << "This is ok\n";
			}

		}
		oL = oL->getNext();
		if (i == 1)
			first = pNew;
		if (i == x.dimEl)
			last = pNew;
	
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
int List<T>::getDimEl()
{
	return dimEl;
}

template<class T>
Node<T>* List<T>::getFirst()
{
	return first;
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
	cout << "Pushed-front element\n";
}

template<class T>
void List<T>::pushBack(T x)
{
	Node<T>* temp = new Node<T>;
	temp->setVal(x);
	temp->setNext(NULL);
	if (dimEl == 0)
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
	dimEl++;
	cout << "Pushed-back element\n";
}

template<class T>
void List<T>::popFront()
{
	if (first != NULL)
	{
		first=first->getNext();
		if (first == NULL)
			last = NULL;
		dimEl--;

	}
	cout << "Popped-front element\n";
}

template<class T>
void List<T>::popBack()
{
	if (last != NULL)
	{
		last = last->getPrev();
		if (last == NULL)
			first = NULL;
		dimEl--;
	}
	cout << "Popped-front element\n";
}

template<class T>
void List<T>::insert(int i, T x)
{
	try 
	{
		if (i > dimEl + 1)
			throw 1;
		if (i < 1)
			throw 'a';
		
	}
	catch (int x)
	{
		cout << "Exception: position too big\n";
	}
	catch (char x)
	{
		cout << "Exception: negative position\n";
	}
	
		if(i<dimEl+1&& i>1)
		{
			Node<T>* temp = first;
			//finding element on prev position
			for (int j = 1; j < i-1; j++)
				temp = temp->getNext();
			//creating aux
			Node<T> * aux = new Node<T>;
			aux->setVal(x);
			//setting bonds
			aux->setNext(temp->getNext());
			temp->getNext()->setPrev(aux);
			temp->setNext(aux);
			dimEl++;
		}
		if(i==dimEl+1)
		{
			pushBack(x);
		}
		if (i == 1)
		{
			pushFront(x);
		}
		
	
	
}

template<class T>
void List<T>::remove(int i)
{
	try
	{
		if (i > dimEl + 1)
			throw 1;
		if (i < 1)
			throw 'a';

	}
	catch (int x)
	{
		cout << "Exception: position too big\n";
	}
	catch (char x)
	{
		cout << "Exception: negative position\n";
	}
	if(i<dimEl &&i>0)
	{
		if (i == 1)
			first = first->getNext();
		else if (i == dimEl)
			last = last->getPrev();
		else 
		{
			Node<T>* temp = first;
			int j;
			for ( j = 1; j < i; j++)
				temp = temp->getNext();
			//cout << j;
			Node<T>* prev=temp->getPrev(), *next=temp->getNext();
			prev->setNext(next);
			next->setPrev(prev);
			
			delete temp;
		}
		cout << "\nRemoved successfully!\n";
		dimEl--;

	}
}

template<class T>
Node<T>* List<T>::operator[](int i)
{	
	if (i > dimEl)
		return NULL;
	if (i == 1)
		return first;
	if (i == dimEl)
		return last;
	Node<T>* temp = first;
	for (int j = 1; j < i; j++)
		temp = temp->getNext();
	return temp;
}

template<class T>
List<T>::operator bool() const
{
	return isNotEmpty();
}

template<class T>
List<T>::operator int() const
{
	return dimEl;
}

template<class T>
const List<T>& List<T>::operator=(const List<T>& x)
{	
	if (this != &x)
	{
		dimEl = x.dimEl;
		Node<T>* p, * pNew, * oL;
		p = first;
		pNew = NULL;
		oL = x.first;
		for (int i = 1; i <= x.dimEl; i++)
		{
			cout << "Copying element " << i << "...\n";
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
			if (i == x.dimEl)
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
			if (i == 1)
				first = pNew;
			if (i == x.dimEl)
				last = pNew;


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
		
	}
	
	return *this;
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
