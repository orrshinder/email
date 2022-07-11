#pragma once
#ifndef MAIL_H
#define MAIL_H

#include <iostream>
#include <string>
#include "Folder.h"
using namespace std;


class Mail
{
public:
	Mail(string Date, string Send_From, string Send_To, string Subject, string Content);
	~Mail();
	string get_Date() const;
	string get_Send_From() const;
	string get_Send_To() const;
	string get_Subject() const;
	string get_Content() const;

	friend ostream& operator<<(ostream& os, const Mail& c);

protected:

	string m_Date;
	string  m_Send_From;
	string  m_Send_To;
	string  m_Subject;
	string  m_Content;
	int Mail_special_num;
	static int Mail_Value;


};


class Recived_mail : public Mail
{
	Recived_mail(string Date, string Send_From, string Send_To, string Subject, string Content):Mail(Date,Send_From,Send_To,Subject,Content) {};
	~Recived_mail() {};
};

class Sent_mail: public Mail
{
	Sent_mail(string Date, string Send_From, string Send_To, string Subject, string Content) :Mail(Date, Send_From, Send_To, Subject, Content) {};
	~Sent_mail() {};
};

#endif
