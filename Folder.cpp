#include "Folder.h"
#include <string>


Folder::Folder(string name)
{
	m_name = name;
}
void Folder::Move(Mail* mail)
{
	mail_list.emplace(mail_list.begin(), &mail);
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
