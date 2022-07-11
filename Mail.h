#pragma once
#ifndef MAIL_H
#define MAIL_H

#include <iostream>
#include <string>
#include "Folder.h"
#include "Application.h"
#include "Contacts.h"
using namespace std;


class Mail
{
public:
	friend class Folder;
	friend class Contacts;
	friend class Contact;
	friend class Application;
	Mail(string Date, string** Send_From, string** Send_To, string Subject, string Content);
	~Mail();
	string get_Date() const;
	virtual string* get_Send_From() const=0;
	virtual string* get_Send_To() const=0;
	string get_Subject() const;
	string get_Content() const;
	int get_uniqe_id()const;

	friend ostream& operator<<(ostream& os, const Mail& c);

protected:

	string m_Date;
	string*  m_Send_From;
	string*  m_Send_To;
	string  m_Subject;
	string  m_Content;
	int Mail_special_num;
	static int Mail_Value;


};


class Recived_mail : public Mail
{
	Recived_mail(string Date, string** Send_From, string** Send_To, string Subject, string Content):Mail(Date,Send_From,Send_To,Subject,Content) {};
	~Recived_mail() {};
	string* get_Send_From();
	string* get_Send_To();
};

class Sent_mail: public Mail
{
	Sent_mail(string Date, string** Send_From, string** Send_To, string Subject, string Content) :Mail(Date, Send_From, Send_To, Subject, Content) {};
	~Sent_mail() {};
	string* get_Send_From();
	string* get_Send_To();
};

#endif
