#pragma once
#ifndef CONTACTS_H
#define CONTACTS_H

#include <iostream>
#include <string>
#include "Contact.h"
using namespace std;
class Contacts
{
public:
	//friend class Contact;
	Contacts();
	~Contacts();
	Add(string name, string address);
	Remove(string name);

protected:
	Contact** contact_list;
};
class Rlist:Contacts
{
public:
	Rlist():Contacts(){};
	~Rlist();
	//Add(string list_name);
	//Remove(string name);
	//List();
	AddToList(string name, string address);
	RemoveFromList(string name, string address);

protected:
	string list_name;
	Contacts** rlist_contacts_list;
};
#endif
