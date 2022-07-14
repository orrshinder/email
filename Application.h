
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
	void Remove();
	void List(string folder_name);
	void Search();
	void Move();
	void More(int flag, string folder_name);
	void CD();
	void MkDir();
	void RmDir();
	void ListDir();
	void contacts();
	void main_screen();
	void rlist();
	string option();
	void Print();
	void seralization(ofstream& ofs);
	void deseralization(ifstream& ofs);

protected:
	vector<Folder> mail_folders;
	vector<Contacts> mail_contacts;
	const string my_mail = "orrshinder@gmail.com";
	static int Mail_Value;

};

#endif
