//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	
	bool twoSum2pointerapproach(int arr[],int n,int x)
	{
	    int l=0;
	    int h=n-1;
	    
	    //O(n)
	    while(l < h)
	    {
	        int csum=arr[l]+arr[h];
	        if(csum==x)
	        {
	            return true;
	        }
	        else if(csum > x)
	        {
	            h--;
	        }
	        else
	        {
	            l++;
	        }
	    }
	    return false;
	}
	
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    
	    //O(nlogn)
	    sort(arr,arr+n);
	    return twoSum2pointerapproach(arr,n,x);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends