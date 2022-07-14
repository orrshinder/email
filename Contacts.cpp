#include "Contacts.h"


Contacts::Contacts()
{
	contact_list.resize(0);
	list_name = "";
}
Contacts::Contacts(string name)
{
	contact_list.resize(0);
	list_name = name;
}
string Contacts::name_list()const
{
	return list_name;
}
Contacts::~Contacts()
{
	contact_list.clear();
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
	Contact* temp = new Contact(name, address);
	//contact_list.emplace(contact_list.begin(),temp);
	contact_list.insert(contact_list.begin(), *temp);
}

void Rlist::AddToList(string name, string address)
{
	Contact* temp = new Contact(name, address);
	//contact_list.emplace(contact_list.begin(),temp);
	contact_list.insert(contact_list.begin(), *temp);
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

void Contacts::seralization(ofstream& ofs)
{
	ofs << "contacts:" << endl;
	for (auto it = contact_list.begin(); it != contact_list.end(); ++it)
	{
		ofs << it->get_name() << "," << it->get_address() << endl;
	}
}
void Rlist::seralization(ofstream& ofs)
{
	ofs << "contact list:" << this->list_name << endl;
	for (auto it = contact_list.begin(); it != contact_list.end(); ++it)
	{
		ofs << it->get_name() << "," << it->get_address() << endl;
	}
}
ostream& operator<<(ostream& os, const Contacts& c)
{
	for (auto it = c.contact_list.begin(); it != c.contact_list.end(); ++it)
	{
		os << it->get_address() << "  " << it->get_name() << endl;
	}
	return os;
}
