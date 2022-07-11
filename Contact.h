#pragma once
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include "Contacts.h"
using namespace std;
class Contact
{
public:
	friend class Mail;
	friend class Folder;
	friend class Contacts;
	friend class Application;
	Contact(string name,string address);
	~Contact();
	string get_name() const;
	string get_address() const;

protected:
	string m_name;
	string m_address;
};
#endif
