#pragma once
#include "LinkedList.h"
#include "Mail.h"
#include <iostream>
using namespace std;
Node::Node() {}
Node::~Node()
{
}
Mail* Node::get_data() const
{
	return data;
}
Node* Node::get_next() const
{
	return next;
}
void Node::set_data(Mail* value)
{
	this->data = value;
}
void Node::set_next(Node* n)
{
	this->next = n;
}
void Node::set_new_next()
{
	this->next = new Node;
}
void Node::set_npt_next()
{
	this->next = nullptr;
}
LinkedList::LinkedList(unsigned capacity) : //ctor
	m_capacity(capacity)
{
	m_last = nullptr;
	m_head = m_last;
}
LinkedList::~LinkedList() //destructor
{
	Node* current_node = m_head;
	while (current_node != nullptr) //deletes the Nodes of the LinkedList
	{
		Node* next_node = current_node->get_next();
		delete current_node->get_data();
		delete current_node;
		current_node = next_node;
	}
	m_head = nullptr;
}
ostream& operator<<(ostream& os, const LinkedList& arr) //operator cout << LinkedList
{
	os << "";
	Node* current_node = arr.m_head;
	for (int i = 0; i < arr.m_capacity; i++)
	{
		cout << i + 1 << "." << "\t" << *(current_node->get_data()) << endl;
		current_node = current_node->get_next();
	}
	return os;
}
unsigned LinkedList::size() const //returns the size
{
	return m_capacity;
}
const Mail* LinkedList::find(const Mail* value) const //if value is in LinkdList, puts the index in the pointer - index
{
	Node* current_node = m_head;
	for (int i = 0; i < m_capacity; i++)
	{
		if (*(current_node->get_data()) == *value)
			return current_node->get_data();
		current_node = current_node->get_next();
	}
	return nullptr;
}
void LinkedList::push_back(Mail* value) // puts value in the end of LinkedList
{
	if (m_capacity > 0)
	{
		m_last->set_new_next();
		m_last = m_last->get_next();
		m_last->set_data(value);
		m_last->set_npt_next();
	}
	else
	{
		m_last = new Node;
		m_last->set_data(value);
		m_last->set_npt_next();
		m_head = m_last;
	}
	m_capacity++;
}
Mail* LinkedList::operator[](int index) const
{
	Node* current_node = m_head;
	for (int i = 0; i < index; i++)
	{
		current_node = current_node->get_next();
	}
	return current_node->get_data();
}
Mail* LinkedList::pop_card(const Mail* my_card)
{
	if (*(m_head->get_data()) == *my_card)
	{
		Node* save_next = m_head->get_next();
		Mail* poped_card = m_head->get_data();
		delete m_head;
		m_head = save_next;
		m_capacity--;
		if (m_capacity == 0)
			m_last = m_head;
		return poped_card;
	}
	else
	{
		Node* current_node = m_head;
		for (int i = 0; i < m_capacity; i++)
		{
			if (*(current_node->get_next()->get_data()) == *my_card)
			{
				if (i == m_capacity - 2)
				{
					Mail* poped_card = current_node->get_next()->get_data();
					delete m_last;
					m_last = current_node;
					m_last->set_npt_next();
					m_capacity--;
					return poped_card;
				}
				Node* save_next = current_node->get_next()->get_next();
				Mail* poped_card = current_node->get_next()->get_data();
				delete current_node->get_next();
				current_node->set_next(save_next);
				m_capacity--;
				return poped_card;
			}
			current_node = current_node->get_next();
		}
	}
}
bool LinkedList::empty() const //returns true if the LinkedList is empty
{
	return m_capacity == 0;
}
