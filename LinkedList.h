#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include"Mail.h"
#include <iostream>

class Node
{
public:
	Node(); //ctor
	~Node(); //dector
	Mail* get_data() const; //returns node data
	Node* get_next() const; //returns the next node
	void set_data(Mail* value); //sets node's data
	void set_next(Node* n); //sets next node
	void set_new_next(); //memory allocation for a new node
	void set_npt_next(); //sets next node to nullptr
private:
	Mail* data; //the value of a Node
	Node* next; //the pointer to the next Node
};
class LinkedList //The purpose is a LinkedList of Cards*
{
public:
	LinkedList(unsigned size = 0); //ctor
	~LinkedList(); //destructor
	friend ostream& operator<<(ostream& os, const LinkedList& arr); //operator << for the LinkedList
	unsigned size() const; //returns the size
	const Mail* find(const Mail* value) const; //if value is in LinkdList, puts the index in the pointer - index
	void push_back(Mail* value); // puts value in the end of LinkedList
	Mail* operator[](int index) const; //get operation returns the card index
	Mail* pop_card(const Mail* my_card);// pops a card from the list
	bool empty() const; //returns true if the LinkedList is empty
private:
	Node* m_head; //a pointer to the beginning Node of the LinkedList
	Node* m_last; //a pointer to the last Node of the LinkedList
	unsigned m_capacity; // the number of Nodes in LinkedList
};
ostream& operator<<(ostream& os, const LinkedList& arr); //Operator overload <<
#endif
