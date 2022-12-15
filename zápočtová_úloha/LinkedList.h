#pragma once

using T = int;

class LinkedList
{
private: 
	struct Node;
	Node* head;
	Node* tail;
public:
	LinkedList();
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
	using LinkedList::void pop_front();
	using LinkedList::void pop_back();
public:
	void insert(T data);
};