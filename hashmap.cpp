#include <iostream>
#include <cstring>
#include "hashtable.h"
using namespace std ;

int main ()
{
	Hashtable<int> price_menu ;
	cout<<"***** MENU *****"<<endl<<endl ;

	price_menu.insert("Burger",120) ;
	price_menu.insert("Pizza",140) ;
	price_menu.insert("Pepsi",20) ;
	price_menu.insert("Coke",30) ;
	price_menu.insert("Samosa",15) ;

	price_menu.print() ;

	int *flag_price = price_menu.search("Pepsi") ;

	cout<<endl ;

	if (flag_price == NULL)
	{
		cout<<"Not Found"<<endl ;
	}

	else
	{
		cout<<"Price is : "<<*flag_price<<endl ;
	}

	// price_menu.erase("Samosa") ;
	// cout<<endl<<endl ;

	// price_menu.print() ;

	// insert
	price_menu["Dosa"] = 60 ;

	// update
	price_menu["Dosa"] += 20 ;

	price_menu.print() ;

	// Search
	cout<<"Price is : "<<price_menu["Dosa"]<<endl ;

	return 0 ;
}