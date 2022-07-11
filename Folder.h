#pragma once
#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include <string>
#include "Mail.h"
#include "LinkedList.h"

using namespace std;
class Folder
{
	Folder(string m_name);
	~Folder();


protected:
	string m_name;
	LinkedList mail_list;
};
#endif
