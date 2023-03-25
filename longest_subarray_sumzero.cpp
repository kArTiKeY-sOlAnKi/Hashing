#include <iostream>
#include <unordered_map>
using namespace std ;

int longest_subarray(int arr[], int n)
{
	unordered_map<int,int> m ; // pre_sum and index
	int pre_sum = 0 ;

	int len = 0 ;

	for (int i = 0; i < n; i++)
	{
		pre_sum += arr[i] ;

		if (pre_sum == 0)
		{
			len = max(len,i+1) ;
		}

		if (m.find(pre_sum) != m.end())
		{
			len = max(len,i - m[pre_sum]) ;
		}

		// store the first occ
		else
		{
			m[pre_sum] = i ;
		}
	}
	return len ;
}

int main()
{
	int n ;
	cin>>n ;

	// Sample Array: 0 -1 1 2 5 -5 -2
	int arr[n] ;
	cout<<"Enter the values into the array : " ;
	for(int i = 0; i < n; i++)
	{
		cin>>arr[i] ;
	}
	cout<<endl ;

	cout<<"Length of the Longest Subarray having sum as 0 is : "<<longest_subarray(arr,n) ;

	return 0 ;
}