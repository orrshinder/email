#pragma once
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include "Contacts.h"
using namespace std;
class Contact
{
public:
	Contact(string name,string address);
	~Contact();


protected:
	string name;
	string address;
};
#endif
