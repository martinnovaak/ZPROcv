#pragma once
#include <initializer_list>

using T = int;

class LinkedList
{
private: 
	struct Node;
	Node* head;
	Node* tail;
public:
	LinkedList();
    LinkedList(std::initializer_list);
	LinkedList(LinkedList & list);
	~LinkedList();
	bool empty();
	void push_front(T data);
	void push_back(T data);
	void pop_front();
	void pop_back();
	unsigned int length() const;
	void reverse();
	void sort();

	/* Mozna deklarace Iteratoru
	class Iterator {
	private:
		Node* current_node;
	public:
		Iterator();
		Iterator & operator++();
		bool operator!=(const Iterator& I);
		T& operator*() const;
	};
	Iterator begin();
	Iterator end();
	*/
};

struct LinkedList::Node
{
	T data;
	Node* next;
	// Node* prev; // v pripade obousmerneho spojoveho seznamu
};

template <typename T>
class SortedLinkedList : public LinkedList
{
private:
	using LinkedList::void push_front(T data);
	using LinkedList::void push_back(T data);
public:
	void insert(T data);
};