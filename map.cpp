#include <iostream>
#include <string>
#include <map>
using namespace std ;

int main()
{
	map<string,int> m ;

	// 1. Insert
	m.insert(make_pair("Mango",100)) ;

	// or
	pair<string,int> p ;
	p.first = "Apple" ;
	p.second = 80 ;
	m.insert(p) ;

	// 2. Search
	string fruit ;
	cout<<"Enter Fruit : " ;
	cin>>fruit ;
	cout<<endl ;

	auto it = m.find(fruit) ;
	if (it != m.end())
	{
		cout<<"Price of "<<fruit<<" is : "<<m[fruit] ;
	}

	else
	{
		cout<<"Fruit is not present"<<endl ;
	}

	// another way to find a particular map
	if (m.count(fruit))
	{
		cout<<"Price of "<<fruit<<" is : "<<m[fruit]<<endl ;
	}

	else
	{
		cout<<"Fruit is not present"<<endl ;
	}

	// 3. Erase
	m.erase(fruit) ;

	// 4. Iterate over all the key-value pairs
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout<<it->first<<" --> "<<it->second<<endl ;
		// cout<<it.first<<" --> "<<it.second<<endl ;
	}

	// for each loop
	for (auto p : m)
	{
		cout<<p.first<<" : "<<p.second<<endl ;
	}

	return 0 ;
}