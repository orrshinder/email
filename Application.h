
#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <string>
#include "Contacts.h"
#include "Folder.h"
#include "Mail.h"
#include <fstream>
#include <ostream>
using namespace std;
#define _CRTDBG_MAP_ALLOC
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
class Application
{
public:
	friend class Mail;
	friend class Contacts;
	friend class Contact;
	friend class Folder;
	Application();
	~Application();
	void Compose();
	void Add(string name);
	void Remove(string name);
	void List();
	void AddToList(string rlist_name);
	void RemoveFromList(string rlist_name);
	void Back();
	void Search(string search_text);
	void Move(int id_mail, string folder);
	void More(string folder_name);
	void CD(string folder_name);
	void MkDir(string new_folder);
	void RmDir(string folder_name);
	void ListDir();
	void main_screen();
	void seralization(ofstream& ofs);
	void deseralization(ifstream& ofs);

protected:
	vector<Folder> mail_folders;
	vector<Contacts> mail_contacts;
	const string my_mail = "orrshinder@gmail.com";

};

#endif
