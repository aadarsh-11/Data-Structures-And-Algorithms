// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int findElement(int a[], int n) {
    vector<int> mx(n, INT_MIN),mn(n, INT_MAX);
    mx[0] = a[0];
    mn[n-1]=a[n-1];
    for(int i = n-2 ; i >=0; i--)
    {
        mn[i] = min(mn[i+1],a[i]);
    }
    for(int i = 1 ; i <n-1; i++)
    {
        if(mx[i-1] <= a[i] and a[i] <= mn[i+1]) return a[i];
        mx[i] = max(mx[i-1],a[i]);
    }
    return -1;
}