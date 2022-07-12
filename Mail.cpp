#include "Mail.h"
int Mail::Mail_Value = 1;

Mail::Mail(string Date, string** Send_From, string** Send_To, string Subject, string Content, int mail_id) : m_Date(Date),m_Subject(Subject), m_Content(Content),Mail_special_num(mail_id)//ctor
{
	int size = *(&Send_From + 1) - Send_From;
	m_Send_From = new string * [size];
	for (int i = 0; i < size; i++)
	{
		m_Send_From[i] = Send_From[i];
	}
	int size1 = *(&Send_To + 1) - Send_To;
	m_Send_To = new string * [size1];
	for (int i = 0; i < size1; i++)
	{
		m_Send_To[i] = Send_To[i];
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
string* Recived_mail::get_Send_From() const
{
	return *m_Send_From;
}
string* Recived_mail::get_Send_To() const
{
	return *m_Send_To;
}
string* Sent_mail::get_Send_From() const
{
	return *m_Send_From;
}
string* Sent_mail::get_Send_To() const
{
	return *m_Send_To;
}
int Mail::get_uniqe_id() const
{
	return Mail_special_num;
}
void  Mail::seralization(ofstream& ofs)
{
	ofs << "Date:" << this->get_Date() << endl;
	ofs <<"sent from:" << this->get_Send_From() << endl;
	ofs << "sent to:" << this->get_Send_To() << endl;
	ofs <<"subject:" << this->get_Subject() << endl;
	ofs << "content:" << this->get_Content() << endl;
	ofs <<"uniq id:" << this->get_uniqe_id() << endl;
}
