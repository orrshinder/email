#ifndef MAIL_H
#define MAIL_H

#include <iostream>
#include <string>

using namespace std;


class Mail
{
public:
	Mail(string Date, string Send_From, string Send_To, string Subject, string Content, int Mail_Value);
	~Mail();
	string get_Date() const;
	string get_Send_From() const;
	string get_Send_To() const;
	string get_Subject() const;
	string get_Content() const;
	int get_Mail_Value() const;


protected:

	string m_Date;
	string  m_Send_From;
	string  m_Send_To;
	string  m_Subject;
	string  m_Content;
	int  Mail_Value;


};
