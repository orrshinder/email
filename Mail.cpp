#include "Mail.h"
int Mail::Mail_Value = 1;

Mail::Mail(string Date, string Send_From, string Send_To, string Subject, string Content) : m_Date(Date), m_Send_From(Send_From), m_Send_To(Send_To), m_Subject(Subject), m_Content(Content)//ctor
{
	Mail_special_num = Mail_Value;
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
string Mail::get_Send_From() const
{
	return m_Send_From;
}
string Mail::get_Send_To() const
{
	return m_Send_To;
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
