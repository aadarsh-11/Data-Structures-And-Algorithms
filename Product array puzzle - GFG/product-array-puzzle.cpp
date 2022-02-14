// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& a, int n) {
       vector<long long int> pre(n),post(n);
       if(n==1) 
       {
           a[0] = 1; 
           return a;
       }
       vector<long long int> ans(n);
       pre[0] = a[0];
       post[n-1] = a[n-1];
       for(int i = 1 ; i<n; i++)
       {
           pre[i] = a[i]*pre[i-1];
       }
       for(int i = n-2 ; i>=0; i--)
       {
           post[i] = a[i]*post[i+1];
           ans[i] = pre[i-1]*post[i+1];
       }
       ans[0] = post[1];
       ans[n-1] = pre[n-2];
       
       return ans;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends