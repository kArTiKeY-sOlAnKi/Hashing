#include <iostream>
#include <unordered_set>
using namespace std ;

bool checkSum(int arr[], int n)
{
	unordered_set<int> s ;

	int pre = 0 ;
	for (int i = 0; i < n; i++)
	{
		pre += arr[i] ;

		// check if the sum is already present in the set
		if (pre == 0 or s.find(pre)!=s.end())
		{
			return true ;
		}

		s.insert(pre) ;
	}
	return false ;
}

int main()
{
	int n ;
	cin>>n ;

	int arr[n] ;
	cout<<"Enter the values into the array : " ;
	for(int i = 0; i < n; i++)
	{
		cin>>arr[i] ;
	}
	cout<<endl ;

	if (checkSum(arr,n))
	{
		cout<<"Yes a subarray exists having sum 0"<<endl ;
	}

	else
	{
		cout<<"Doesn't exist"<<endl ;
	}

	return 0 ;
}