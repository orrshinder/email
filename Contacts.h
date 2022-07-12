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
#include <ostream>
using namespace std;
#define _CRTDBG_MAP_ALLOC
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
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
	void seralization(ofstream& ofs);

protected:
	vector<Contact> contact_list;
};
class Rlist:public Contacts
{
public:
	Rlist(string name);
	~Rlist();
	void AddToList(string name, string address);
	void RemoveFromList(string name, string address);
	void seralization(ofstream& ofs);

protected:
	string list_name;
};
#endif
