#include <iostream>
#include <cstring>
using namespace std ;

template <typename T>
class node
{
	public:
		string key ;
		T value ;
		node<T> *next ;

		node (string key, T val)
		{
			this->key = key ;
			value = val ;
			next = NULL ;
		}

		~node()
		{
			if (next != NULL)
			{
				delete next ;
			}
		}
};

template <typename T>
class Hashtable
{
	private:
		node<T> **table ;
		int current_size ;
		int table_size ;

		int hashfn(string key)
		{
			int index = 0 ;
			int power = 1 ;
			for (int j = 0; j < key.length(); j++)
			{
				index = index + (key[j]*power)%table_size ;
				index = index % table_size ;
				power = (power*27)%table_size ;
			}

			return index ;
		}

		void rehash()
		{
			node<T> **old_table = table ; // created a copy of the current table
			int old_size = table_size ;
			table_size = table_size*2 ;

			table = new node<T> *[table_size] ; // expanded the memory of original table

			// init new increased table with NULL
			for (int i = 0; i < table_size; i++)
			{
				table[i] = NULL ;
			}

			current_size = 0 ; // for new table

			// shift the elements from old to new table
			for (int i = 0; i < old_size; i++)
			{
				node<T> *temp = old_table[i] ;

				while (temp != NULL)
				{
					insert(temp->key,temp->value) ;
					temp = temp -> next ;
				}

				// deleting the linked lists
				if (old_table[i] != NULL)
				{
					delete old_table[i] ;
				}
			}

			// deleting the old table now as it is of no use
			delete [] old_table ;
		}

	public:
		Hashtable(int ts = 5)
		{
			table_size = ts ;
			table = new node<T>*[table_size] ;
			current_size = 0 ;

			for (int i = 0; i < table_size; i++)
			{
				table[i] = NULL ;
			}
		}

		void insert(string key, T value)
		{
			int index = hashfn(key) ; // insertion will be done in this index of hashtable

			node<T> *n = new node<T>(key,value) ; // new node is created in hashtable

			// insert at head of the linked list with each insertion
			n -> next = table[index] ;
			table[index] = n ;
			current_size++ ;

			// rehashing
			float load_factor = current_size/(1.0*table_size) ;

			if (load_factor > 0.7)
			{
				rehash() ;
			}
		}

		void print()
		{
			for (int i = 0; i < table_size; i++)
			{
				cout<<"Bucket "<<i<<" -> " ;
				node<T> *temp = table[i] ;

				while (temp != NULL)
				{
					cout<<temp->key<<"->" ;
					temp = temp -> next ;
				}
				cout<<"NULL"<<endl ;
			}
		}

		T *search(string key)
		{
			int index = hashfn(key) ;
			node<T> *temp = table[index] ;

			while (temp != NULL)
			{
				if (temp -> key == key)
				{
					return &(temp -> value) ;
				}
				temp = temp -> next ;
			}

			return NULL ;
		}

		T &operator[](string key)
		{
			T *f = search(key) ;

			if (f == NULL)
			{
				// insert key into the hashtable
				T garbage ;
				insert(key,garbage) ;
				f = search(key) ;
			}

			return *f ;
		}

		void erase(string key)
		{
			int index = hashfn(key) ; // will return the index of the key
			node<T> *ptr = table[index] ; // temp is at index of table in which operation will be performed

			if (ptr -> key == key)
			{
				table[index] = ptr -> next ;
				ptr -> next = NULL ;
				delete ptr ;
				current_size-- ;
				return ;
			}

			while (ptr != NULL)
			{
				if (ptr -> next -> key == key)
				{
					node<T> *temp = ptr -> next ;
					ptr -> next = temp -> next ;
					delete temp ;
					current_size-- ;
					return ;
				}
				ptr = ptr -> next ;
			}
		}
};