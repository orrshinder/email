#include "Contacts.h"


Contacts::Contacts()
{
	contact_list.resize(0);
}
Contacts::~Contacts()
{
	contact_list.~vector();
}
Contact* Contacts::Remove(string name)
{
	int counter = 0;
	for (auto it = contact_list.begin(); it != contact_list.end(); ++it)
	{
		if (name == it->get_name())
		{
			Contact* x = &contact_list.at(counter);
			contact_list.erase(it);
			return x;
		}
		counter++;
	}
}
void Contacts::Add(string name, string address)
{
	auto it = contact_list.emplace(contact_list.begin(), &Contact(name, address));
}

void Rlist::AddToList(string name, string address)
{
	contact_list.emplace(contact_list.begin(), &Contact(name, address));
}
void Rlist::RemoveFromList(string name, string address)
{
	for (auto it = contact_list.begin(); it != contact_list.end(); ++it)
	{
		if (name == it->get_name() && address == it->get_address())
			contact_list.erase(it);
	}
}
Rlist::~Rlist()
{
	contact_list.~vector();
}
Rlist::Rlist(string name):Contacts()
{
	list_name = name;
}

