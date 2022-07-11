#include "Mail.h"
int Mail::Mail_Value = 1;

Mail::Mail(string Date, string** Send_From, string** Send_To, string Subject, string Content) : m_Date(Date),m_Subject(Subject), m_Content(Content)//ctor
{
	Mail_special_num = Mail_Value;
	int size = *(&Send_From + 1) - Send_From;
	for (int i = 0; i < size; i++)
	{
		m_Send_From=Send_From[i];
	}
	int size1 = *(&Send_To + 1) - Send_To;
	for (int i = 0; i < size1; i++)
	{
		m_Send_To=Send_To[i];
	}
	Mail_Value++;
}
Mail::~Mail()
{
	delete &m_Content;
	delete& m_Date;
	delete& m_Send_From;
	delete& m_Send_To;
	delete& m_Subject;

}
string Mail::get_Date() const
{
	return m_Date;
}
string Mail::get_Subject() const
{
	return m_Subject;
}
string Mail::get_Content() const
{
	return m_Content;
}
ostream& operator<<(ostream& os, const Mail& c)
{
	os << c.get_Content() <<endl;
	return os;
}
string* Recived_mail::get_Send_From()
{
	return m_Send_From;
}
string* Recived_mail::get_Send_To()
{
	return m_Send_To;
}
string* Sent_mail::get_Send_From()
{
	return m_Send_From;
}
string* Sent_mail::get_Send_To()
{
	return m_Send_To;
}
int Mail::get_uniqe_id()const
{
	return Mail_special_num;
}
