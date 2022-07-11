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

}
void Application::deseralization(ifstream& ifs)
{

}
