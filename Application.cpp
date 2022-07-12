#include "Application.h"
#include <time.h>
#include <fstream>
Application::Application()
{
	mail_folders.resize(0);
	string date = __DATE__;
	ifstream my_file;
	my_file.open("app.txt");
	deseralization(my_file);
	my_file.close();




















	ofstream my_file1;
	my_file1.open("app.text", ios::trunc);
	seralization(my_file1);
	my_file1.close();

}
Application::~Application()
{

}
void Application::main_screen()
{

}
void Application::Compose()
{

}
void Application::Add(string name)
{

}
void Application::Remove(string name)
{

}
void Application::List()
{

}
void Application::AddToList(string rlist_name)
{

}
void Application::RemoveFromList(string rlist_name)
{

}
void Application::Back()
{

}
void Application::Search(string search_text)
{

}
void Application::Move(int id_mail, string folder)
{

}
void Application::More(string folder_name)
{

}
void Application::CD(string folder_name)
{

}
void Application::MkDir(string new_folder)
{

}
void Application::RmDir(string folder_name)
{

}
void Application::ListDir()
{

}
void Application::seralization(ofstream& ofs)
{
	for (auto it = mail_folders.begin(); it != mail_folders.end(); ++it)
	{
		it->seralization(ofs);
	}
	for (auto it = mail_contacts.begin(); it != mail_contacts.end(); ++it)
	{
		it->seralization(ofs);
	}

}
void Application::deseralization(ifstream& ifs)
{
	string single_line;
	streampos oldpos = ifs.tellg();
	while (getline(ifs, single_line))
	{
		if (single_line.rfind("Folder:", 0))
		{
			size_t pos = single_line.find("Folder:");
			string str_line = single_line.substr(pos);
			Folder* temp = new Folder(str_line);
			mail_folders.emplace(mail_folders.begin(), temp);
			getline(ifs, single_line);
			string date="";
			string** sent_from;
			string** sent_to;
			string subject="";
			string content="";
			int uniqe_d=0;
			int size1=0;
			int size2 = 0;
			while (!single_line.rfind("Folder:", 0)&& !single_line.rfind("contacts", 0)&& !single_line.rfind("contact list :", 0))
			{
				if (single_line.rfind("Date:", 0))
				{
					size_t pos = single_line.find("Date:");
					date = single_line.substr(pos);
					oldpos = ifs.tellg();
					getline(ifs, single_line);

				}
				if (single_line.rfind("sent from:", 0))
				{
					size_t pos = single_line.find("sent from:");
					string sent_from1 = single_line.substr(pos);
					size1 = sent_from1.size();
					int counter = 0;
					for (int i = 0; i < size1; i++)
					{
						if (sent_from1.compare(","))
						{
							counter++;
						}
					}
					sent_from = new string * [counter+1];
					int place = 0;
					for (int j = 0; j < size1; j++)
					{
						if ((&sent_from1.at(j)!=",") && (sent_from1.at(j)!='\n'))
						{
							sent_from[place]->append(&sent_from1.at(j));
						}
						if ((&sent_from1.at(j) == ","))
						{
							place++;
						}
					}
					oldpos = ifs.tellg();
					getline(ifs, single_line);
				}
				if (single_line.rfind("sent to:", 0))
				{
					size_t pos = single_line.find("sent from:");
					string sent_to1 = single_line.substr(pos);
					size2 = sent_to1.size();
					int counter = 0;
					for (int i = 0; i < size2; i++)
					{
						if (sent_to1.compare(","))
						{
							counter++;
						}
					}
					sent_to = new string * [counter + 1];
					int place = 0;
					for (int j = 0; j < size2; j++)
					{
						if ((&sent_to1.at(j) != ",") && (sent_to1.at(j) != '\n'))
						{
							sent_from[place]->append(&sent_to1.at(j));
						}
						if ((&sent_to1.at(j) == ","))
						{
							place++;
						}
					}
					oldpos = ifs.tellg();
					getline(ifs, single_line);
				}
				if (single_line.rfind("subject:", 0))
				{
					size_t pos = single_line.find("subject:");
					subject = single_line.substr(pos);
					oldpos = ifs.tellg();
					getline(ifs, single_line);
				}
				if (single_line.rfind("content:", 0))
				{
					size_t pos = single_line.find("content:");
					content = single_line.substr(pos);
					oldpos = ifs.tellg();
					getline(ifs, single_line);
				}
				if (single_line.rfind("uniq id:", 0))
				{
					size_t pos = single_line.find("uniq id:");
					uniqe_d = stoi(single_line.substr(pos));
				}
				if (mail_folders.at(0).m_name != "Sent")
				{
					for (int i = 0; i <= size2; i++)
					{
						if (sent_to[i] == &my_mail)
						{
							Recived_mail* temp = new Recived_mail(date, sent_from, sent_to, subject, content, uniqe_d);
							mail_folders.at(0).Add_old_mail(temp);
						}
					}
				}
				if (mail_folders.at(0).m_name != "Inbox")
				{
					for (int i = 0; i <= size2; i++)
					{
						if (sent_to[i] == &my_mail)
						{
							Sent_mail* temp = new Sent_mail(date, sent_from, sent_to, subject, content, uniqe_d);
							mail_folders.at(0).Add_old_mail(temp);
						}
					}
				}

			}
			ifs.seekg(oldpos);
		}
		if (single_line.rfind("contacts:", 0))
		{
			mail_contacts.push_back(Contacts());
			oldpos = ifs.tellg();
			getline(ifs, single_line);
			while (!single_line.rfind("Folder:", 0)  && !single_line.rfind("contact list:", 0))
			{
				string name = "";
				string address = "";
				int counter = 0;
				while(&single_line.at(counter) != ",")
				{
						counter++;
				}
				single_line.compare(",");
				for (int j = 0; j <= counter; j++)
				{
					name.append(&single_line.at(j));
		
				}
				for (int i = counter+2; i <= single_line.size(); i++)
				{
					address.append(&single_line.at(i));

				}
				mail_contacts.at(mail_contacts.size()).Add(name, address);
				oldpos = ifs.tellg();
				getline(ifs, single_line);
			}
			ifs.seekg(oldpos);
		}
		if (single_line.rfind("contact list:", 0))
		{
			size_t pos = single_line.find("contact list:");
			string str_line = single_line.substr(pos);
			mail_contacts.push_back(Rlist(str_line));
			oldpos = ifs.tellg();
			getline(ifs, single_line);
			while (!single_line.rfind("Folder:", 0) && !single_line.rfind("contacts:", 0))
			{
				string name = "";
				string address = "";
				int counter = 0;
				while (&single_line.at(counter) != ",")
				{
					counter++;
				}
				single_line.compare(",");
				for (int j = 0; j <= counter; j++)
				{
					name.append(&single_line.at(j));

				}
				for (int i = counter + 2; i <= single_line.size(); i++)
				{
					address.append(&single_line.at(i));

				}
				mail_contacts.at(mail_contacts.size()).Add(name, address);
				oldpos = ifs.tellg();
				getline(ifs, single_line);
			}
			ifs.seekg(oldpos);
		}
	}
}
