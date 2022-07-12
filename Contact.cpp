#pragma once
#include "Contact.h"
Contact::Contact(string name, string address)
{
	m_name = name;
	m_address = address;
}
Contact::Contact()
{
	m_name ="";
	m_address ="";
}
Contact::~Contact()
{

}
string Contact::get_name() const
{
	return m_name;
}
string Contact::get_address() const
{
	return m_address;
}
