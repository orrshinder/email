#include "Folder.h"
#include <string>


Folder::Folder(string name)
{
	m_name = name;
}
Folder::~Folder()
{
	for (auto it = mail_list.begin(); it != mail_list.end(); ++it)
	{
		it->~Mail();
	}
	mail_list.clear();
	mail_list.~vector();
	m_name = "";
}
void Folder::Move(Mail* mail)
{
	mail_list.emplace(mail_list.begin(), &mail);//problem
}


Mail* Folder::Remove(Mail* mail)
{
	int counter = 0;
	for (auto it = mail_list.begin(); it != mail_list.end(); ++it)
	{
		if (mail->get_uniqe_id() == it->get_uniqe_id())
		{
			Mail* x = &mail_list.at(counter);
			mail_list.erase(it);
			return x;
		}
		counter++;
	}
}
void  Folder::seralization(ofstream& ofs)
{
	ofs <<"Folder:" << this->m_name << endl;
	for (auto it = mail_list.begin(); it != mail_list.end(); ++it)
	{
		it->seralization(ofs);
	}
}
void Folder::Add_old_mail(Mail* mail)
{
	mail_list.push_back(*mail);
}
void Folder::Add_new_mail(Mail* mail)
{
	mail_list.insert(mail_list.begin(), *mail);
}
