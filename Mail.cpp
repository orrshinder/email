#include "Mail.h"


Mail::Mail(string Date, string Send_From, string Send_To, string Subject, string Content, int Mail_Value) : m_Date(Date), m_Send_From(Send_From), m_Send_To(Send_To), m_Subject(Subject), m_Content(Content) //ctor
{
}
Mail::~Mail()
{

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
int Mail::get_Mail_Value() const
{
	return Mail_Value;
}
