#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std ;

int main()
{
	unordered_map<string,vector<string>> phonebook ;

	phonebook["Daffy"].push_back("9110") ;
	phonebook["Daffy"].push_back("9111") ;
	phonebook["Daffy"].push_back("9112") ;
	phonebook["Daffy"].push_back("9113") ;

	phonebook["Major"].push_back("8710") ;
	phonebook["Major"].push_back("8711") ;
	phonebook["Major"].push_back("8712") ;
	phonebook["Major"].push_back("8713") ;

	// Printing the phonebook
	cout<<"PhoneBook is : "<<endl ;
	for (auto p : phonebook)
	{
		cout<<"Name: "<<p.first<<" -> " ;
		for (string s : p.second)
		{
			cout<<s<<", " ;
		}
		cout<<endl ;
	}

	string str ;
	cout<<"Enter the contact name you wish to find : " ;
	cin>>str ;
	cout<<endl ;

	if (phonebook.count(str) == 0)
	{
		cout<<"Absent"<<endl ;
	}

	else
	{
		cout<<"Found details are : "<<endl ;
		for (string s : phonebook[str])
		{
			cout<<s<<endl ;
		}
	}

	return 0 ;
}