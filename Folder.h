#pragma once
#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include <string>
#include "Mail.h"
#include "Application.h"
#include "Contacts.h"
#include <vector>

using namespace std;
class Folder
{
	friend class Mail;
	friend class Contacts;
	friend class Contact;
	friend class Application;
	Folder(string m_name);
	~Folder();
	void Move(Mail* mail);
	Mail* Remove(Mail* mail);


protected:
	string m_name;
	vector<Mail> mail_list;
};
#endif
