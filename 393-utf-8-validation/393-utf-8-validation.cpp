class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0;
        int n = data.size();
        while(i<n)
        {
            if(data[i]>>7 == 0)
            {
                i++;
                continue;
            }
            int bytes = 0;
            int x = 7;
            while(x>=0 and (data[i]>>x) & 1 == 1)
            {
                bytes++;
                x--;
            }
            if(bytes > 4 or bytes == 1) return false;
            if(bytes + i > n) return false;
            while(--bytes)
            {
                i++;
                if(data[i] >> 7 != 1 or (data[i] >> 6) & 1 != 0) return 0;
            }
            i++;
        }
        return true;
    }
};