#include <iostream>
#include <vector>
#include <map>
using namespace std ;

class node
{
	public:
		int data ;
		node *left ;
		node *right ;

		node (int data)
		{
			this -> data = data ;
			left = right = NULL ;	
		}
};

void vertical_print(node *root, int distance, map<int,vector<int>> &m)
{
	// base case
	if (root == NULL)
	{
		return ;
	}

	m[distance].push_back(root->data) ;
	vertical_print(root->left,distance-1,m) ;
	vertical_print(root->right,distance+1,m) ;
	return ;
}

int main()
{
	node *root = new node(1) ;
	root -> left = new node(2) ;
	root -> right = new node(3) ;
	root -> left -> left = new node(4) ;
	root -> left -> right = new node(5) ;

	root -> right -> left = new node(6) ;
	root -> right -> right = new node(7) ;

	root -> right -> right -> right = new node(9) ;

	root -> left -> right -> right = new node(8) ;

	// creating a map
	map<int,vector<int>> m ;
	int distance = 0 ;
	vertical_print(root,distance,m) ;

	// printing the vertical print now
	for (auto p : m)
	{
		// cout<<p.first<<"->" ;
		for (auto x : p.second)
		{
			cout<<x<<" " ;
		}
		cout<<endl ;
	}

	return 0 ;
}