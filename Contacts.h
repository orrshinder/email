#pragma once
#ifndef CONTACTS_H
#define CONTACTS_H

#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"
#include "Folder.h"
#include "Application.h"
#include "Mail.h"
using namespace std;
class Contacts
{
public:
	friend class Mail;
	friend class Folder;
	friend class Contact;
	friend class Application;
	Contacts();
	~Contacts();
	Contact* Remove(string name);
	void Add(string name, string address);

protected:
	vector<Contact> contact_list;
};
class Rlist:Contacts
{
public:
	Rlist(string name);
	~Rlist();
	void AddToList(string name, string address);
	void RemoveFromList(string name, string address);

protected:
	string list_name;
};
#endif

