class Solution {
public:
    double champagneTower(int poured, int row, int col) {
        
        if(row == 0 or poured == 0)
        {
            if(poured > 0) return 1;
            return 0;
        }
        
        vector<vector<double>> rem(row+1);
        rem[0].push_back(((double)poured-1.0)/2.0);
        
        for(int i = 1 ; i<= row; i++)
        {
            rem[i].resize(i+1);
            for(int j = 0 ; j< i+1; j++)
            {
                if(i == row and j == col)
                {
                    if(j == 0)
                        return rem[i-1][j] > 1.0 ? 1.0: rem[i-1][j];
                    if(j == i)
                        return rem[i-1][j-1] > 1.0? 1.0: rem[i-1][j-1];
                    return rem[i-1][j-1] + rem[i-1][j] > 1.0 ? 1.0: rem[i-1][j-1] + rem[i-1][j];
                }
                else
                {
                    if(j == 0)
                        rem[i][j] = rem[i-1][j] > 1.0 ? (rem[i-1][j] - 1.0)/2.0 : 0;
                    else if(j == i)
                        rem[i][j] = rem[i-1][j-1] > 1.0 ? (rem[i-1][j-1] - 1.0)/2.0 : 0;
                    else
                        rem[i][j] = rem[i-1][j-1] + rem[i-1][j] > 1.0? (rem[i-1][j-1] + rem[i-1][j] - 1.0)/2.0 : 0;
                }
            }
        }
        return 0;
    }
};