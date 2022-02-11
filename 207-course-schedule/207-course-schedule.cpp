class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses);
        for(auto i: prereq)
        {
            graph[i[1]].push_back(i[0]);
            degree[i[0]]++;
        }
        queue<int> zerodeg;
        for(int i = 0 ; i <degree.size(); i++)
        {
            if(degree[i] == 0)
            {
                zerodeg.push(i);
                numCourses --;
            }
        }
        while(!zerodeg.empty())
        {
            int curr = zerodeg.front();
            zerodeg.pop();
            for(auto v: graph[curr])
            {
                if(--degree[v] == 0)
                {
                    zerodeg.push(v);
                    numCourses--;
                }
            }
        }
        return numCourses == 0;
    }
};