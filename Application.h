
#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <string>
#include "Contacts.h"
#include "Folder.h"
#include "Mail.h"


class Application
{
public:
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


protected:
	Folder** mail_folders;
	string my_mail = "orrshinder@gmail.com";

};

#endif
