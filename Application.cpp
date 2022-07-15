#include "Application.h"
#include <time.h>
#include <fstream>
//int static Mail_Value = 1;

Application::Application()
{
	Mail_Value = 1;
	m_size_contacts=0;
	m_top_contacts=0;
	m_size_folders=0;
	m_top_folders=0;
	mail_folders = new Folder * [0];
	mail_contacts = new Contacts * [0];
	string date = __DATE__;
	ifstream my_file;
	my_file.open("app.txt");
	deseralization(my_file);
	my_file.close();
	cout << "welcom to email system the mail connected is:" << my_mail << endl;
	main_screen();
	ofstream my_file1;
	my_file1.open("app.text", ios::trunc);
	seralization(my_file1);
	my_file1.close();

}
Application::~Application()
{
	for (int i = 0; i < m_size_folders; i++)
	{
		if (mail_folders[i] != nullptr)
		{
			delete[] mail_folders[i];
		}
	}
	for (int i = 0; i < m_size_contacts; i++)
	{
		if (mail_contacts[i] != nullptr)
		{
			delete[] mail_contacts[i];
		}
	}
}
void Application::main_screen()
{
	int more_flag = 1;
	string chose_option;
	while (1)
	{
		chose_option = option();
		if (chose_option=="1")
		{
			Compose();
		}
		else if (chose_option=="2")
		{
			Remove();
		}
		else if (chose_option=="3")
		{
			Print();
		}
		else if (chose_option == "4")
		{
			Move();
		}
		else if (chose_option == "5")
		{
			More(more_flag,"Inbox");
			more_flag++;
		}
		else if (chose_option == "6")
		{
			List("Inbox");
		}
		else if (chose_option == "7")
		{
			ListDir();
		}
		else if (chose_option == "8")
		{
			RmDir();
		}
		else if (chose_option == "9")
		{
			MkDir();
		}
		else if (chose_option == "10")
		{
			CD();
		}
		else if (chose_option == "11")
		{
			contacts();
		}
		else if (chose_option == "12")
		{
			Search();
		}
		else if (chose_option == "13")
		{
			rlist();
		}
		else if (chose_option == "14")
		{
			cout << "Goodby" << endl;
			break;
		}
		else if (chose_option == "help")
		{
			cout << "Compose: create new email" << endl;
			cout << "Remove: remove email by its uniqe id" << endl;
			cout << "Print: print email content" << endl;
			cout << "Move: moving mail to folder" << endl;
			cout << "More: print next 10 emails" << endl;
			cout << "List: print first 10 emails" << endl;
			cout << "ListDir: print all folders exist" << endl;
			cout << "RmDir: delete folder" << endl;
			cout << "MkDir: create folder" << endl;
			cout << "CD: go to folder" << endl;
			cout << "Contacts: manage contacts" << endl;
			cout << "search: search for a mail" << endl;
			cout << "exit" << endl;

		}
		else
		{
			cout << "not valid chiose" << endl;
			main_screen();
		}
	}
}
string Application::option()
{
	string option;
	cout << "Choose option:" << endl;
	cout << "1. Compose" << endl;
	cout << "2. Remove" << endl;
	cout << "3. Print" << endl;
	cout << "4. Move" << endl;
	cout << "5. More" << endl;
	cout << "6. List" << endl;
	cout << "7. ListDir" << endl;
	cout << "8. RmDir" << endl;
	cout << "9. MkDir" << endl;
	cout << "10. CD" << endl;
	cout << "11. Contacts" << endl;
	cout << "12. search" << endl;
	cout << "13. Rlist" << endl;
	cout << "14. exit" << endl;
	cout << "or write help to disply all options" << endl;
	cin >> option;
	return option;
}
void Application::Compose()
{
	string date = "";
	string** sent_from = NULL;
	string** sent_to = NULL;
	string subject = "";
	string content = "";
	while (1)
	{
		int flag = 0;
		int flag_name = 0;
		string option;
		cout << "Choose option:" << endl;
		cout << "1. Recipient" << endl;
		cout << "2. Subject" << endl;
		cout << "3. Content" << endl;
		cout << "4. Send" << endl;
		cout << "5. Back" << endl;
		cin >> option;
		if (option == "1")
		{
			cout << *mail_contacts[0] << endl;
			for (int i=1;i<m_size_contacts;i++)
			{
				cout << mail_contacts[i]->name_list() << endl;
			}
			string contact_option;
			vector<string> contact_mail;
			while (1)
			{
				cout << "which contact would you like:" << endl;
				cin >> contact_option;
				if (serach_contact(contact_option))
				{
					Contact* temp = find_contact(contact_option);
					contact_mail.push_back(temp->get_address());
					if (temp->get_address() == my_mail)
						flag_name = 1;
				}
				else if (find_rlist(contact_option))
				{
					Contacts* temp = find_rlist(contact_option);
					for (int i = 0; i <= temp->size_list(); i++)
					{
						Contact* temp1 = temp->contact_list.at(i);
						contact_mail.push_back(temp1->get_address());
						if (temp1->get_address() == my_mail)
							flag_name = 1;
					}
				}
				else
				{
					cout << "invalive person" << endl;
				}
				string continu_option;
				cout << "1. add another contact" << endl;
				cout << "2. finish contacts" << endl;
				cout << "3. back" << endl;
				cin >> continu_option;
				if (continu_option == "1")
				{
					continue;
				}
				if (continu_option == "2")
				{
					break;
				}
				if (continu_option == "3")
				{
					flag = 1;
					break;
				}
				if (continu_option == "help")
				{

				}
				else
				{
					cout << "invalid option" << endl;
				}



			}
			int size_contacts = contact_mail.size();
			sent_to = new string * [size_contacts];
			for (int i = 0; i <= size_contacts; i++)
			{
				sent_to[i] = &contact_mail.at(i);
			}
			contact_mail.clear();
		}
		if (flag == 1)
		{
			break;
		}
		else if (option == "2")
		{
			string subject_option;
			cout << "1. add subject" << endl;
			cout << "2. back" << endl;
			cin >> subject_option;
			if (subject_option == "1")
			{
				cout << "enter subject:" << endl;
				cin >> subject;
			}
			if (subject_option == "2")
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}
		else if (option == "3")
		{
			string subject_option;
			cout << "1. add content" << endl;
			cout << "2. back" << endl;
			cin >> subject_option;
			if (subject_option == "1")
			{
				cout << "enter subject:" << endl;
				cin >> content;
			}
			if (subject_option == "2")
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}
		else if (option == "4")
		{

			for (int i=0;i<m_size_folders; i++)
			{
				Folder* temp = mail_folders[i];
				if (temp->m_name=="Sent")
				{
					Sent_mail* temp1 = new Sent_mail(date, sent_from, sent_to, subject, content, Mail_Value);
					//it->Add_new_mail(&Sent_mail(date, sent_from, sent_to, subject, content, Mail_Value));
					temp->Add_new_mail(temp1);
					flag = 1;
				}
				if (flag_name == 1)
				{
					if (temp->m_name == "inbox")
					{
						Recived_mail* temp1 = new Recived_mail(date, sent_from, sent_to, subject, content, Mail_Value);
						//it->Add_new_mail(&Recived_mail(date, sent_from, sent_to, subject, content, Mail_Value));
						temp->Add_new_mail(temp1);
						flag_name = 0;
						flag = 1;
					}
				}

			}
			Mail_Value++;
		}
		if (flag == 1)
		{
			break;
		}
		else if (option == "5")
		{
			for (int i = 0; i < m_size_folders; i++)
			{
				Folder* temp1 = mail_folders[i];
				if (temp1->m_name.compare("Drafts"))
				{
					Sent_mail* temp2 = new Sent_mail(date, sent_from, sent_to, subject, content, Mail_Value);
					//it->Add_new_mail(&Sent_mail(date, sent_from, sent_to, subject, content, Mail_Value));
					temp1->Add_new_mail(temp2);
					Mail_Value++;
				}


			}
			break;
		}
    }
	main_screen();	
}

void Application::contacts()
{
	string contact_option;
	cout << "1. List" << endl;
	cout << "2. add contact" << endl;
	cout << "3. Remove contact" << endl;
	cout << "4. back " << endl;
	cin >> contact_option;
	if (contact_option == "1")
	{
		cout << *mail_contacts[0];
	}
	else if (contact_option == "2")
	{
		string name = "";
		string address = "";
		cout << "contact name:" << endl;
		cin >> name;
		cout << "contact address:" << endl;
		cin >> address;
		mail_contacts[0]->Add(name, address);
	}
	else if (contact_option == "3")
	{
		string name = "";
		cout << "contact name:" << endl;
		cin >> name;
		if (serach_contact(contact_option))
		{
			Contact* temp = find_contact(contact_option);
			remove_contact(temp);
		}
		else
		{
			cout << "contact not found" << endl;
			contacts();
		}

	}
	else if (contact_option == "4")
	{
		main_screen();
	}
	else
	{
		cout << "option not valid" << endl;
		contacts();
	}
}
void Application::Remove()
{
	string print_option;
	cout << "1. remove mail" << endl;
	cout << "2. back"<< endl;
	cin >> print_option;
	if (print_option == "1")
	{
		int flag = 0;
		int mail_id = 0;
		cout << "what is the mail id:" << endl;
		cin >> mail_id;
		//Mail* temp = mail_folders.begin()->mail_list.data();
		for (int i=0; i<m_size_folders; i++)
		{
			for (int j = 0; j < mail_folders[i]->size(); j++)
			{
				Mail* temp = mail_folders[i]->mail_list[i];
				if (temp->get_uniqe_id() == mail_id)
				{
					for (int k = 0; k < m_size_folders; k++)
					{
						if (mail_folders[k]->m_name.compare("Trash"))
						{
							mail_folders[k]->Add_new_mail(temp);
							flag = 1;
						}
						if (!mail_folders[k]->m_name.compare("Trash"))
						{
							mail_folders[k]->Remove(temp);
							
						}
					}

				}
			}

		}
		if (flag == 0)
		{
			cout << "mail  do no exict" << endl;
			Move();
		}

	}
	else if (print_option.compare("2"))
	{
		main_screen();
	}
	else
	{
		cout << "option not valid" << endl;
		Remove();
	}
}
void Application::List(string list_name)
{
	for (int i = 0; i < m_size_folders; i++)
	{
		if (mail_folders[i]->m_name == list_name)
		{
			int size = mail_folders[i]->size();
			if (size > 10)
			{
				for (int k = 0; k < 10; k++)
				{
					Mail* temp = mail_folders[i]->mail_list[k];
					cout << "Date:" << temp->get_Date() << endl;
					cout << "Sent from:" << temp->get_Send_From() << endl;

					cout << "Subject:" << temp->get_Subject() << endl;
					
				}	

			}
			else
			{
				for (int k = 0; k < size; k++)
				{
					Mail* temp = mail_folders[i]->mail_list[k];
					cout << "Date:" << temp->get_Date() << endl;
					cout << "Sent from:" << temp->get_Send_From() << endl;
					cout << "Subject:" << temp->get_Subject() << endl;
				}
					cout << "no more mails" << endl;
			}
		}
	}
}




void Application::Search()
{

	string search_option;
	cout << "1. search mail" << endl;
	cout << "2. back" << endl;
	cin >> search_option;
	if (search_option == "1")
	{
		string mail_option;
		cout << "please enter name or subject" << endl;
		cin >> mail_option;
		for (int i = 0; i < m_size_folders; i++)
		{
			for (int j=0; j<mail_folders[i]->size();j++)
			{
				Mail* temp = mail_folders[i]->mail_list[j];
				if (temp->get_Subject() == mail_option || temp->get_Send_To()->compare(mail_option))
				{
					cout << "Date:" << temp->get_Date() << endl;
					cout << "Sent from:" << temp->get_Send_From() << endl;
					cout << "Subject:" << temp->get_Subject() << endl;
				}
			}
		}
	}
	else if (search_option == "2")
	{
		main_screen();
	}
	else
	{
		cout << "option not valid" << endl;
		Remove();
	}


}
void Application::Move()
{
	string move_option;
	cout << "1. move mail" << endl;
	cout << "2. back" << endl;
	cin >> move_option;
	if (move_option == "1")
	{
		int flag = 0;
		string folder_name = "";
		int mail_id = 0;
		cout << "what is the mail id:" << endl;
		cin >> mail_id;
		cout << "what is the folder to move:" << endl;
		cin >> folder_name;
		for (int i = 0; i < m_size_folders; i++)
		{
			for (int j = 0; j < mail_folders[i]->size(); j++)
			{
				Mail* temp = mail_folders[i]->mail_list[j];
				if (temp->get_uniqe_id() == mail_id)
				{
					for (int k = 0; k < m_size_folders; k++)
					{
						if (mail_folders[k]->m_name == folder_name)
						{
							mail_folders[k]->Add_new_mail(temp);
							flag = 1;
						}
						if (mail_folders[k]->m_name != folder_name)
						{
							mail_folders[k]->Remove(temp);
							flag = 1;
						}
					}
				}
		
			}

		}
		if (flag == 0)
		{
			cout << "mail or folder do no exict" << endl;
			Move();
		}
	}
	if (move_option == "2")
	{
		main_screen();
	}
	
}
void Application::More(int flag,string folder_name)
{

	for (int i = 0; i < m_size_folders; i++)
	{
		if (mail_folders[i]->m_name == folder_name)
		{
			int folder_size = mail_folders[i]->size();
			if (folder_size <= ((flag + 1) * 10))
			{
				for (int j = 0 + 10 * flag; j < 10 * (flag + 1); j++)
				{
					Mail* temp = mail_folders[i]->mail_list[j];
					cout << "Date:" << temp->get_Date() << endl;
					cout << "Sent from:" << temp->get_Send_From() << endl;
					cout << "Subject:" << temp->get_Subject() << endl;
					cout << "Uniqe id:" << temp->get_uniqe_id() << endl;
				}
			}
			else
			{
				for (int j = 0 + 10 * flag; j < mail_folders[i]->size(); j++)
				{
					Mail* temp = mail_folders[i]->mail_list[j];
					cout << "Date:" << temp->get_Date() << endl;
					cout << "Sent from:" << temp->get_Send_From() << endl;
					cout << "Subject:" << temp->get_Subject() << endl;
					cout << "Uniqe id:" << temp->get_uniqe_id() << endl;
				}
				cout << "no more mails" << endl;
			}

		}
	}
}

void Application::CD()
{
	string move_option;
	cout << "1. enter folder" << endl;
	cout << "2. back" << endl;
	cin >> move_option;

	if (move_option == "1")
	{
		string folder_name = "";
		cout << "what is the folder to move:" << endl;
		cin >> folder_name;
		if (find_folder(folder_name))
		{
			Folder* temp = find_folder(folder_name);
			List(temp->m_name);
			string chose_option;
			cout << "1. More" << endl;
			cout << "2. Remove" << endl;
			cout << "3. Print" << endl;
			cout << "4. Move" << endl;
			cout << "5. List" << endl;
			cout << "6. Babk" << endl;
			cin>>chose_option;
			int more_flag = 1;
			while (1)
			{
				if (chose_option == "1")
				{
					More(more_flag, temp->m_name);
					more_flag++;
				}
				if (chose_option == "2")
				{
					Remove();
				}
				else if (chose_option == "3")
				{
					Print();
				}
				else if (chose_option == "4")
				{
					Move();
				}

				else if (chose_option == "5")
				{
					List(temp->m_name);
				}
				else if (chose_option == "6")
				{
					break;
				}

				else if (chose_option == "help")
				{
					cout << "Compose: create new email" << endl;
					cout << "Remove: remove email by its uniqe id" << endl;
					cout << "Print: print email content" << endl;
					cout << "Move: moving mail to folder" << endl;
					cout << "More: print next 10 emails" << endl;
					cout << "List: print first 10 emails" << endl;
					cout << "ListDir: print all folders exist" << endl;
					cout << "RmDir: delete folder" << endl;
					cout << "MkDir: create folder" << endl;
					cout << "CD: go to folder" << endl;
					cout << "Contacts: manage contacts" << endl;
					cout << "search: search for a mail" << endl;
					cout << "exit" << endl;

				}
				else
				{
					cout << "not valid chiose" << endl;
					CD();
				}
			}
		}
		else
		{
			cout << "folder do not exist" << endl;
			CD();
		}
		main_screen();
	}
	else if (move_option == "2")
	{
		main_screen();
	}
}
void Application::MkDir()
{
	string folder_option;
	cout << "1. add folder" << endl;
	cout << "2. back" << endl;
	cin >> folder_option;
	if (folder_option == "1")
	{
		string folder_name;
		cout << "enter folder name:" << endl;
		cin >> folder_name;
		if (!find_folder(folder_name))
		{
			Folder* temp = find_folder(folder_name);
			push_folder(temp);
		}
		else
		{
			cout << "folder allredy exist" << endl;
			MkDir();
		}
	}
	if (folder_option == "2")
	{
		main_screen();
	}


}
void Application::RmDir()
{
	string folder_option;
	cout << "1. delete folder" << endl;
	cout << "2. back" << endl;
	cin >> folder_option;
	if (folder_option == "1")
	{
		string folder_name;
		cout << "enter folder name:" << endl;
		cin >> folder_name;
		if (folder_name != "Trash" && folder_name != "Starred" && folder_name != "Drafts" && folder_name != "Sent" && folder_name != "Inbox" && find_folder(folder_name))
		{
			Folder* temp = find_folder(folder_name);
			Folder* temp1 = find_folder("Trash");
			for (int i=temp->size()-1; i >=0; i--)
			{
				Mail* temp2;
				temp2 = temp->mail_list[i];
				temp->Remove(temp2);
				temp1->Add_new_mail(temp2);
			}
			pop_folder(temp);
		}
		else if (folder_name == "Trash")
		{
			Folder* temp1 = find_folder("Trash");
			for (int i = temp1->size() - 1; i >= 0; i--)
			{
				Mail* temp2;
				temp2 = temp1->mail_list[i];
				temp1->Remove(temp2);
			}
		}
		else if (folder_name == "Starred")
		{
			Folder* temp = find_folder("Starred");
			Folder* temp1 = find_folder("Trash");
			for (int i = temp->size() - 1; i >= 0; i--)
			{
				Mail* temp2;
				temp2 = temp->mail_list[i];
				temp->Remove(temp2);
				temp1->Add_new_mail(temp2);
			}

		}
		else if (folder_name == "Sent")
		{
			Folder* temp = find_folder("Sent");
			Folder* temp1 = find_folder("Trash");
			for (int i = temp->size() - 1; i >= 0; i--)
			{
				Mail* temp2;
				temp2 = temp->mail_list[i];
				temp->Remove(temp2);
				temp1->Add_new_mail(temp2);
			}

		}
		else if (folder_name == "Inbox")
		{
			Folder* temp = find_folder("Inbox");
			Folder* temp1 = find_folder("Trash");
			for (int i = temp->size() - 1; i >= 0; i--)
			{
				Mail* temp2;
				temp2 = temp->mail_list[i];
				temp->Remove(temp2);
				temp1->Add_new_mail(temp2);
			}

		}
		else
		{
			cout << "folder allredy exist" << endl;
			MkDir();
		}
	}
	if (folder_option == "2")
	{
		main_screen();
	}
}
void Application::ListDir()
{
	for (int i = 0; i < m_size_folders ; i++)
	{
		cout << mail_folders[i]->m_name << endl;
	}
}
void Application::Print()
{
	string print_option;
	cout << "1. print mail" << endl;
	cout << "2. back" << endl;
	cin >> print_option;
	if (print_option == "1")
	{
		int flag = 0;
		int mail_id=0;
		cout << "what is the mail id:" << endl;
		cin >> mail_id;
		for (int i = 0; i < m_size_folders; i++)
		{
			for (int j = 0; j < mail_folders[i]->size(); j++)
			{
				Mail* temp = mail_folders[i]->mail_list[j];
				if (temp->get_uniqe_id() == mail_id)
				{
					cout << *temp << endl;
					flag = 1;
				}
			}
		}
		if(flag==0)
		{
			cout << "mail do no exict" << endl;
			Print();
		}

	}
	if (print_option == "2")
	{
		main_screen();
	}
}
void Application::rlist()
{
	string rlist_option;
	cout << "1. List" << endl;
	cout << "2. Add list" << endl;
	cout << "3. Remove List" << endl;
	cout << "4. Add To list" << endl;
	cout << "5. Remove from list" << endl;
	cout << "6. back " << endl;
	cin >> rlist_option;
	if (rlist_option == "1")
	{
		for (int i = 0; i < m_size_folders; i++)
		{
			if (mail_folders[i]->m_name != "")
			{
				cout << mail_folders[i]->m_name << endl;
			}
		}
	}
	else if (rlist_option == "2")
	{
		string rlist_name;
		cout << "enter rlist name:" << endl;
		cin >> rlist_name;
		if (!find_rlist(rlist_name))
		{
			Rlist* temp = new Rlist(rlist_name);
			push_contacts(temp);
		}
		else
		{
			cout << "rlist allredy exist" << endl;
			rlist();
		}
	}
	else if (rlist_option == "3")
	{
		string rlist_name1;
		cout << "enter rlist name:" << endl;
		cin >> rlist_name1;
		if (find_rlist(rlist_name1))
		{
			Contacts* temp = find_rlist(rlist_name1);
			pop_contacts(temp);
		}
		else
		{
			cout << "rlist not found" << endl;
			rlist();
		}
	}
	else if (rlist_option == "4")
	{
		string rlist_name2;
		cout << "enter rlist name:" << endl;
		cin >> rlist_name2;
		if (find_rlist(rlist_name2))
		{
			Contacts* temp = find_rlist(rlist_name2);
			string name = "";
			string address = "";
			cout << "contact name:" << endl;
			cin >> name;
			cout << "contact address:" << endl;
			cin >> address;
			temp->Add(name, address);
		}
		else
		{
			cout << "rlist not found" << endl;
			rlist();
		}
	}
	else if (rlist_option.compare("5"))
	{
		string rlist_name2;
		cout << "enter rlist name:" << endl;
		cin >> rlist_name2;
		if (find_rlist(rlist_name2))
		{
			Contacts* temp = find_rlist(rlist_name2);
			string name = "";
			string address = "";
			cout << "contact name:" << endl;
			cin >> name;
			cout << "contact address:" << endl;
			cin >> address;
			if (find_contact(name))
			{
				Contact* temp1 = find_contact(name);
				if (temp1->get_address() == address)
				{
					temp->Remove(temp1);
				}
				else
				{
					cout << "mail and name does not match" << endl;
					rlist();
				}

			}
			else
			{
				cout << "contact not found" << endl;
				contacts();
			}
		}
		else
		{
			cout << "rlist not found" << endl;
			rlist();
		}

	}
	else if (rlist_option == "6")
	{
		main_screen();
	}
	else
	{
		cout << "option not valid" << endl;
		rlist();
	}
}
void Application::seralization(ofstream& ofs)
{
	for (int i = 0; i < m_size_folders; i++)
	{
		mail_folders[i]->seralization(ofs);
	}
	for (int j=0; j< m_size_contacts;j++)
	{
		mail_contacts[j]->seralization(ofs);
	}
	ofs << "mail value:" << Mail_Value << endl;

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
			push_folder(temp);
			getline(ifs, single_line);
			string date="";
			string** sent_from=NULL;
			string** sent_to=NULL;
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
							sent_to[place]->append(&sent_to1.at(j));
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
				if (mail_folders[0]->m_name != "Sent")
				{
					for (int i = 0; i <= size2; i++)
					{
						if (sent_to[i]->compare(my_mail))
						{
							Recived_mail* temp = new Recived_mail(date, sent_from, sent_to, subject, content, uniqe_d);
							//mail_folders.at(0).Add_old_mail(&Recived_mail(date, sent_from, sent_to, subject, content, uniqe_d));
							mail_folders[0]->push_back(temp);
						}
					}
				}
				if (mail_folders[0]->m_name != ("Inbox"))
				{
					for (int i = 0; i <= size2; i++)
					{
						if (sent_to[i]->compare(my_mail))
						{
							Sent_mail* temp = new Sent_mail(date, sent_from, sent_to, subject, content, uniqe_d);
							//mail_folders.at(0).Add_old_mail(&Sent_mail(date, sent_from, sent_to, subject, content, uniqe_d));
							mail_folders[0]->push_back(temp);
						}
					}
				}

			}
			ifs.seekg(oldpos);
		}
		if (single_line.rfind("contacts:", 0))
		{
			Contacts* temp = new Contacts();
			push_contacts(temp);
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
				mail_contacts[m_size_contacts]->Add(name, address);
				oldpos = ifs.tellg();
				getline(ifs, single_line);
			}
			ifs.seekg(oldpos);
		}
		if (single_line.rfind("contact list:", 0))
		{
			size_t pos = single_line.find("contact list:");
			string str_line = single_line.substr(pos);
			Rlist* temp = new Rlist(str_line);
			push_contacts(temp);
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
				mail_contacts[m_size_contacts]->Add(name, address);
				oldpos = ifs.tellg();
				getline(ifs, single_line);
			}
			ifs.seekg(oldpos);
		}
		if (single_line.rfind("mail value:", 0))
		{
			size_t pos = single_line.find("mail value:");
			string str_line = single_line.substr(pos);
			Mail_Value= stoi(single_line.substr(pos));
		}
	}
}
bool  Application::serach_contact(string name)
{
	for (int i = 0; i < m_size_contacts; i++)
	{
		if (mail_contacts[i]->contact_exsit(name))
		{
			return true;
		}
	}
	return false;
}
Contact*  Application::find_contact(string name)
{
	Contact* temp;
	temp = mail_contacts[0]->find_contact(name);
	return temp;
}
Contacts* Application::find_rlist(string name)
{
	for (int i = 1; m_size_contacts; i++)
	{
		if (mail_contacts[i]->name_list() == name)
		{
			return mail_contacts[i];
		}
	}
}
void Application::remove_contact(Contact* c)
{
	for (int i = 0; i < m_size_contacts; i++)
	{
		if (mail_contacts[i]->contact_exsit(c->get_name()))
		{
			mail_contacts[i]->Remove(c);
		}
	}
}
Folder* Application::find_folder(string name)
{
	for (int i = 0; i < m_size_folders; i++)
	{
		if (mail_folders[i]->m_name == name)
		{
			return mail_folders[i];
		}
	}
}
void Application::push_folder(Folder* c)
{
	if (!folder_isFull())
	{
		if (folder_isEmpty())
		{
			mail_folders[0] = c;
			m_top_folders++;
		}
		else
		{
			Folder** temp = new Folder * [m_size_folders];
			for (int i = 0; i < m_size_folders; i++) {
				temp[i] = mail_folders[i];
			}
			for (int i = 0; i < m_size_folders; i++) {
				mail_folders[i + 1] = temp[i];
			}
			mail_folders[0] = (c);
			m_top_folders++;
		}
		
	}


	else
	{
	Folder** temp = new Folder * [m_size_folders];
	for (int i = 0; i < m_size_folders; i++) {
		temp[i] = (mail_folders[i]);
	}
	mail_folders = new  Folder * [m_size_folders + 1];;
	for (int j = 0; j < m_size_folders; j++) {
		mail_folders[j + 1] = temp[j];
	}
	mail_folders[0] = c;
	m_size_folders++;
	m_top_folders++;
	}
}
void Application::push_contacts(Contacts* c)
{
	if (!contacts_isFull())
	{
		if (contacts_isEmpty())
		{
			mail_contacts[0] = c;
			m_top_contacts++;
		}
		else
		{
			Contacts** temp = new Contacts * [m_size_folders];
			for (int i = 0; i < m_size_folders; i++) {
				temp[i] = mail_contacts[i];
			}
			for (int i = 0; i < m_size_folders; i++) {
				mail_contacts[i + 1] = temp[i];
			}
			mail_contacts[0] = (c);
			m_top_contacts++;
		}

	}


	else
	{
		Contacts** temp = new Contacts * [m_size_folders];
		for (int i = 0; i < m_size_folders; i++) {
			temp[i] = (mail_contacts[i]);
		}
		mail_contacts = new  Contacts * [m_size_folders + 1];;
		for (int j = 0; j < m_size_folders; j++) {
			mail_contacts[j + 1] = temp[j];
		}
		mail_contacts[0] = c;
		m_size_contacts++;
		m_top_contacts++;
	}
}
void Application::pop_contacts(Contacts* folder)
{
	unsigned index = 0;
	if (contacts_isEmpty())
	{
		cout << "contacts nothing to pop." << endl;
	}
	else
	{
		for (int i = 0; i < m_size_folders; i++)
		{
			if (mail_contacts[i] == folder)
			{
				index = i;

				break;
			}
		}
		for (unsigned j = index; j < m_size_folders; j++)
		{
			mail_contacts[j] = mail_contacts[j + 1];
		}
		m_size_contacts--;
		m_top_contacts--;
	}
}
void Application::pop_folder(Folder* folder)
{
	unsigned index = 0;
	if (folder_isEmpty())
	{
		cout << "folder nothing to pop." << endl;
	}
	else
	{
		for (int i = 0; i < m_size_folders; i++)
		{
			if (mail_folders[i] == folder)
			{
				index = i;

				break;
			}
		}
		for (unsigned j = index; j < m_size_folders; j++)
		{
			mail_folders[j] = mail_folders[j + 1];
		}
		m_size_folders--;
		m_top_folders--;
	}
}
bool Application::folder_isFull() const
{
	return m_size_folders == m_top_folders;
}
bool Application::folder_isEmpty()
{
	return m_size_folders == 0;
}
unsigned Application::folder_size()const
{
	return m_size_folders;
}
bool Application::contacts_isFull() const
{
	return  m_size_contacts == m_top_contacts;
}
bool Application::contacts_isEmpty()
{
	return m_size_contacts == 0;
}
unsigned Application::contacts_size()const
{
	return m_size_contacts;
}
