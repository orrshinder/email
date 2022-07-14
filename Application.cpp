#include "Application.h"
#include <time.h>
#include <fstream>
int static Mail_Value = 1;

Application::Application()
{
	//mail_folders.resize(0);
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
	mail_contacts.clear();
	mail_contacts.~vector();
	mail_folders.clear();
	mail_folders.~vector();
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
			cout << mail_contacts.at(0) << endl;
			for (auto it1 = mail_contacts.begin(); it1 != mail_contacts.end(); ++it1)
			{
				if (it1->list_name != "")
				{
					cout << it1->name_list() << endl;
				}
			}
			string contact_option;
			vector<string> contact_mail;
			while (1)
			{
				cout << "which contact would you like:" << endl;
				cin >> contact_option;
				if ((find(mail_contacts.begin()->contact_list.begin()->get_name(), mail_contacts.end()->contact_list.begin()->get_name(), contact_option) != mail_contacts.end()->contact_list.begin()->get_name()) || (find(mail_contacts.begin()->contact_list.begin()->get_address(), mail_contacts.end()->contact_list.begin()->get_address(), contact_option) != mail_contacts.end()->contact_list.begin()->get_name()))
				{
					auto it = find(mail_contacts.begin()->contact_list.begin()->get_name(), mail_contacts.end()->contact_list.begin()->get_name(), contact_option);
					auto it1 = find(mail_contacts.begin()->contact_list.begin(), mail_contacts.end()->contact_list.begin(), it);
					contact_mail.push_back(it1->get_address());
					if (it1->get_address() == my_mail)
						flag_name = 1;
				}
				else if (find(mail_contacts.begin()->name_list(), mail_contacts.end()->name_list(), contact_option) != mail_contacts.end()->name_list())
				{
					auto it4 = find(mail_contacts.begin()->name_list(), mail_contacts.end()->name_list(), contact_option);
					auto it5 = find(mail_contacts.begin(), mail_contacts.end(), it4);
					int size_contacts = it5->contact_list.size();
					int index1 = distance(mail_contacts.begin(), it5);
					for (int i = 0; i <= size_contacts; i++)
					{
						contact_mail.push_back(it5->contact_list.at(i).get_address());
						if (it5->contact_list.at(i).get_address() == my_mail)
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

			for (auto it = mail_folders.begin(); it != mail_folders.end(); ++it)
			{
				
				if (it->m_name=="Sent")
				{
					Sent_mail* temp = new Sent_mail(date, sent_from, sent_to, subject, content, Mail_Value);
					it->Add_new_mail(temp);
					flag = 1;
				}
				if (flag_name == 1)
				{
					if (it->m_name == "inbox")
					{
						Recived_mail* temp = new Recived_mail(date, sent_from, sent_to, subject, content, Mail_Value);
						it->Add_new_mail(temp);
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
			for (auto it = mail_folders.begin(); it != mail_folders.end(); ++it)
			{
				if (it->m_name == "Drafts")
				{
					Sent_mail* temp = new Sent_mail(date, sent_from, sent_to, subject, content, Mail_Value);
					it->Add_new_mail(temp);
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
		cout << *mail_contacts.begin();
	}
	else if (contact_option == "2")
	{
		string name = "";
		string address = "";
		cout << "contact name:" << endl;
		cin >> name;
		cout << "contact address:" << endl;
		cin >> address;
		mail_contacts.begin()->Add(name, address);
	}
	else if (contact_option == "3")
	{
		string name = "";
		cout << "contact name:" << endl;
		cin >> name;
		if (find(mail_contacts.begin()->contact_list.begin()->get_name(), mail_contacts.begin()->contact_list.end()->get_name(), name) != mail_contacts.begin()->contact_list.end()->get_name())
		{
			auto it = find(mail_contacts.begin()->contact_list.begin()->get_name(), mail_contacts.end()->contact_list.begin()->get_name(), name);
			auto it1 = find(mail_contacts.begin()->contact_list.begin(), mail_contacts.end()->contact_list.begin(), it);
			auto it2 = find(mail_contacts.begin(), mail_contacts.end(), it1);
			int index1 = distance(mail_contacts.begin(), it2);
			mail_contacts.at(index1).Remove(it);
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
		int mail_id = 0;
		cout << "what is the mail id:" << endl;
		cin >> mail_id;
		if (find(mail_folders.begin()->mail_list.data()->get_uniqe_id(), mail_folders.end()->mail_list.data()->get_uniqe_id(), mail_id) != mail_folders.end()->mail_list.data()->get_uniqe_id())
		{
			auto it = find(mail_folders.begin()->mail_list.data()->get_uniqe_id(), mail_folders.end()->mail_list.data()->get_uniqe_id(), mail_id);
			auto it1 = find(mail_folders.begin()->mail_list.data(), mail_folders.end()->mail_list.data(), it);
			auto it3 = find(mail_folders.begin()->mail_list, mail_folders.end()->mail_list, it1);
			auto it4 = find(mail_folders.begin(), mail_folders.end(), it3);
			auto it2 = find(mail_folders.begin(), mail_folders.end(), "Trash");
			int index = distance(mail_folders.begin(), it2);
			int index1 = distance(mail_folders.begin(), it4);
			Mail* temp;
			temp = it1;
			mail_folders.at(index1).Remove(it1);
			mail_folders.at(index).mail_list.insert(it2->mail_list.begin(), *temp);
		}
		else
		{
			cout << "mail do no exict" << endl;
			Print();
		}

	}
	else if (print_option == "2")
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
	int size=mail_folders.size();
	if (size > 10)
	{
		for (auto it = mail_folders.begin(); it != mail_folders.end(); ++it)
		{
			if (it->m_name == list_name)
			{

				for (auto it1 = it->mail_list.begin(); it1 < it->mail_list.begin() + 10; ++it1)
				{
					cout << "Date:" << it1->get_Date() << endl;
					cout << "Sent from:" << it1->get_Send_From() << endl;
					cout << "Subject:" << it1->get_Subject() << endl;
				}
			}
		}
	}
	else
	{
		for (auto it = mail_folders.begin(); it != mail_folders.end(); ++it)
		{
			if (it->m_name == "inbox")
			{
				for (auto it1 = it->mail_list.begin(); it1 < it->mail_list.begin() + size; ++it1)
				{
					cout << "Date:" << it1->get_Date() << endl;
					cout << "Sent from:" << it1->get_Send_From() << endl;
					cout << "Subject:" << it1->get_Subject() << endl;
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
		for (auto it = mail_folders.begin(); it != mail_folders.end(); ++it)
		{
			for (auto it1 = it->mail_list.begin(); it1 != it->mail_list.end(); ++it1)
			{
				if (it1->get_Subject() == mail_option || it1->get_Send_To()->compare(mail_option))
				{
					cout << "Date:" << it1->get_Date() << endl;
					cout << "Sent from:" << it1->get_Send_From() << endl;
					cout << "Subject:" << it1->get_Subject() << endl;
				}
			}
		}
	}
	else if (search_option == "1")
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
		string folder_name = "";
		int mail_id = 0;
		cout << "what is the mail id:" << endl;
		cin >> mail_id;
		cout << "what is the folder to move:" << endl;
		cin >> folder_name;
		if (find(mail_folders.begin()->mail_list.data()->get_uniqe_id(), mail_folders.end()->mail_list.data()->get_uniqe_id(), mail_id) != mail_folders.end()->mail_list.data()->get_uniqe_id())
		{
			if (find(mail_folders.begin(), mail_folders.end(), folder_name) != mail_folders.end())
			{
				auto it = find(mail_folders.begin()->mail_list.data()->get_uniqe_id(), mail_folders.end()->mail_list.data()->get_uniqe_id(), mail_id);
				auto it1 = find(mail_folders.begin()->mail_list.data(), mail_folders.end()->mail_list.data(), it);
				auto it3 = find(mail_folders.begin()->mail_list, mail_folders.end()->mail_list, it1);
				auto it4 = find(mail_folders.begin(), mail_folders.end(), it3);
				auto it2 = find(mail_folders.begin(), mail_folders.end(), folder_name);
				int index = distance(mail_folders.begin(), it2);
				int index1 = distance(mail_folders.begin(), it4);
				Mail* temp;
				temp = it1;
				mail_folders.at(index1).Remove(it1);
				mail_folders.at(index).mail_list.insert(it2->mail_list.begin(), *temp);
			}
			else
			{
				cout << "folder do not exist" << endl;
			}
		}
		else
		{
			cout << "mail do no exict" << endl;
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

	for (auto it = mail_folders.begin(); it != mail_folders.end(); ++it)
	{
		if (it->m_name == folder_name)
		{
			int folder_size = it->mail_list.size();
			if (folder_size <= ((flag+1) * 10))
			{
				for (auto it1 = it->mail_list.begin() + 10 * flag; it1 < it->mail_list.begin() + 10 * (flag + 1); ++it1)
				{
					cout << "Date:" << it1->get_Date() << endl;
					cout << "Sent from:" << it1->get_Send_From() << endl;
					cout << "Subject:" << it1->get_Subject() << endl;
					cout << "Uniqe id:" << it1->get_uniqe_id() << endl;
				}
			}
			else
			{
				for (auto it1 = it->mail_list.begin() + 10 * flag; it1 < it->mail_list.begin() + folder_size; ++it1)
				{
					cout << "Date:" << it1->get_Date() << endl;
					cout << "Sent from:" << it1->get_Send_From() << endl;
					cout << "Subject:" << it1->get_Subject() << endl;
					cout << "Uniqe id:" << it1->get_uniqe_id() << endl;
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
		if (find(mail_folders.begin(), mail_folders.end(), folder_name) != mail_folders.end())
		{
			auto it2 = find(mail_folders.begin(), mail_folders.end(), folder_name);
			List(it2->m_name);
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
					More(more_flag, it2->m_name);
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
					List(it2->m_name);
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
		if (folder_name != mail_folders.data()->m_name)
		{
			Folder* temp = new Folder(folder_name);
			mail_folders.push_back(*temp);
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
		if (folder_name != "Trash" && folder_name != "Starred" && folder_name != "Drafts" && folder_name != "Sent" && folder_name != "Inbox" && find(mail_folders.begin()->m_name, mail_folders.end()->m_name, folder_name) != mail_folders.end()->m_name)
		{
			auto it2 = find(mail_folders.begin(), mail_folders.end(), folder_name);
			int index = distance(mail_folders.begin(), it2);
			auto it = find(mail_folders.begin(), mail_folders.end(), "Trash");
			int index1 = distance(mail_folders.begin(), it);
			for (int i = 0; i < it2->mail_list.size(); i++)
			{
				Mail* temp;
				temp = &it2->mail_list.back();
				it2->mail_list.pop_back();
				mail_folders.at(index1).mail_list.insert(it->mail_list.begin(), *temp);
			}
			mail_folders.erase(it2);
			

		}
		else if (folder_name == "Trash")
		{
			auto it = find(mail_folders.begin(), mail_folders.end(), "Trash");
			int index = distance(mail_folders.begin(), it);
			mail_folders.at(index).mail_list.clear();
		}
		else if (folder_name == "Starred")
		{
			auto it2 = find(mail_folders.begin(), mail_folders.end(), "Starred");
			int index = distance(mail_folders.begin(), it2);
			auto it = find(mail_folders.begin(), mail_folders.end(), "Trash");
			int index1 = distance(mail_folders.begin(), it);
			for (int i = 0; i < it2->mail_list.size(); i++)
			{
				Mail* temp;
				temp = &it2->mail_list.back();
				it2->mail_list.pop_back();
				mail_folders.at(index1).mail_list.insert(it->mail_list.begin(), *temp);
			}
		}
		else if (folder_name == "Sent")
		{
			auto it2 = find(mail_folders.begin(), mail_folders.end(), "Sent");
			int index = distance(mail_folders.begin(), it2);
			auto it = find(mail_folders.begin(), mail_folders.end(), "Trash");
			int index1 = distance(mail_folders.begin(), it);
			for (int i = 0; i < it2->mail_list.size(); i++)
			{
				Mail* temp;
				temp = &it2->mail_list.back();
				it2->mail_list.pop_back();
				mail_folders.at(index1).mail_list.insert(it->mail_list.begin(), *temp);
			}
		}
		else if (folder_name == "Inbox")
		{
			auto it2 = find(mail_folders.begin(), mail_folders.end(), "Inbox");
			int index = distance(mail_folders.begin(), it2);
			auto it = find(mail_folders.begin(), mail_folders.end(), "Trash");
			int index1 = distance(mail_folders.begin(), it);
			for (int i = 0; i < it2->mail_list.size(); i++)
			{
				Mail* temp;
				temp = &it2->mail_list.back();
				it2->mail_list.pop_back();
				mail_folders.at(index1).mail_list.insert(it->mail_list.begin(), *temp);
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
	for (auto it = mail_folders.begin(); it != mail_folders.end(); ++it)
	{
		cout << it->m_name << endl;
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
		int mail_id=0;
		cout << "what is the mail id:" << endl;
		cin >> mail_id;
		if (find(mail_folders.begin()->mail_list.data()->get_uniqe_id(), mail_folders.end()->mail_list.data()->get_uniqe_id(), mail_id) != mail_folders.end()->mail_list.data()->get_uniqe_id())
		{
			auto it = find(mail_folders.begin()->mail_list.data()->get_uniqe_id(), mail_folders.end()->mail_list.data()->get_uniqe_id(), mail_id);
			auto it1 = find(mail_folders.begin()->mail_list.data(), mail_folders.end()->mail_list.data(), it);
			cout << *it1 << endl;
		}
		else
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
		
		for (auto it = mail_contacts.begin(); it != mail_contacts.end(); ++it)
		{
			if (it->name_list() != "")
			{
				cout << it->name_list() << endl;
			}
		}
	}
	else if (rlist_option == "2")
	{
		string rlist_name;
		cout << "enter rlist name:" << endl;
		cin >> rlist_name;
		if (find(mail_contacts.begin()->name_list(), mail_contacts.end()->name_list(), rlist_name)== mail_contacts.end()->name_list())
		{
			Rlist* temp = new Rlist(rlist_name);
			mail_contacts.push_back(*temp);

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
		if (find(mail_contacts.begin()->name_list(), mail_contacts.end()->name_list(), rlist_name1) == mail_contacts.end()->name_list())
		{
			auto it = find(mail_contacts.begin()->name_list(), mail_contacts.end()->name_list(), rlist_name1);
			auto it1 = find(mail_contacts.begin(), mail_contacts.end(), it);
			mail_contacts.erase(it1);
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
		if (find(mail_contacts.begin()->name_list(), mail_contacts.end()->name_list(), rlist_name2) == mail_contacts.end()->name_list())
		{
			auto it = find(mail_contacts.begin()->name_list(), mail_contacts.end()->name_list(), rlist_name2);
			auto it1 = find(mail_contacts.begin(), mail_contacts.end(), it);
			string name = "";
			string address = "";
			cout << "contact name:" << endl;
			cin >> name;
			cout << "contact address:" << endl;
			cin >> address;
			it1->Add(name, address);
		}
		else
		{
			cout << "rlist not found" << endl;
			rlist();
		}
	}
	else if (rlist_option == "5")
	{
		string rlist_name2;
		cout << "enter rlist name:" << endl;
		cin >> rlist_name2;
		if (find(mail_contacts.begin()->name_list(), mail_contacts.end()->name_list(), rlist_name2) == mail_contacts.end()->name_list())
		{
			auto it = find(mail_contacts.begin()->name_list(), mail_contacts.end()->name_list(), rlist_name2);
			auto it1 = find(mail_contacts.begin(), mail_contacts.end(), it);
			string name = "";
			string address = "";
			cout << "contact name:" << endl;
			cin >> name;
			cout << "contact address:" << endl;
			cin >> address;
			if (find(it1->contact_list.begin()->get_name(), it1->contact_list.end()->get_name(), name) != mail_contacts.begin()->contact_list.end()->get_name())
			{
				auto it2 = find(it1->contact_list.begin()->get_name(), it1->contact_list.end()->get_name(), name);
				auto it3 = find(mail_contacts.begin()->contact_list.begin(), mail_contacts.end()->contact_list.begin(), it2);
				if (it3->get_address() == address)
				{
					auto it4 = find(mail_contacts.begin(), mail_contacts.end(), it3);
					int index1 = distance(mail_contacts.begin(), it4);
					mail_contacts.at(index1).Remove(it);
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
	for (auto it = mail_folders.begin(); it != mail_folders.end(); ++it)
	{
		it->seralization(ofs);
	}
	for (auto it = mail_contacts.begin(); it != mail_contacts.end(); ++it)
	{
		it->seralization(ofs);
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
		if (single_line.rfind("mail value:", 0))
		{
			size_t pos = single_line.find("mail value:");
			string str_line = single_line.substr(pos);
			Mail_Value= stoi(single_line.substr(pos));
		}
	}
}
