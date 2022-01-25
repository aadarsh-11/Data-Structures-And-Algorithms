class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int flag = -1;
        for(int i = 0 ; i< n-1 ; i++)
        {
            if(arr[i] == arr[i+1])
                return false;
            else if(arr[i] > arr[i+1])
            {
                flag = i;
                break;
            }
        }
        if(flag <= 0)
        {
            return false;
        }
        for(int i = flag; i<n-1; i++)
        {
            if(arr[i] <= arr[i+1]) return false;
        }
        return true;
    }
};