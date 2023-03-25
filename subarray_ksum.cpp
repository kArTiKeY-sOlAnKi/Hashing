#include <iostream>
#include <unordered_map>
using namespace std ;

int subarray_ksum(int arr[], int n, int k)
{
	unordered_map<int,int> m ;
	int presum = 0 ;

	int len = 0 ;

	for (int i = 0; i < n; i++)
	{
		// calculating the presum of the array
		presum += arr[i] ;

		if (presum == k)
		{
			len = max(len,i+1) ;
		}

		else if (m.find(presum-k) != m.end())
		{
			len = max(len,i - m[presum - k]) ;
		}

		else
		{
			m[presum] = i ;
		}
	}
	return len ;
}

int main()
{
	int n, k ;
	cin>>n>>k ;

	// sample: 1 -1 5 -2 3; and take k as 3
	int arr[n] ;
	cout<<"Enter values into the array: " ;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i] ;
	}
	cout<<endl ;

	cout<<"Length is: "<<subarray_ksum(arr,n,k) ;

	return 0 ;
}