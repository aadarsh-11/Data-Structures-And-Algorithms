class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& bef) {
        // making new self groups for members with no groups
        for (int i = 0 ; i < n; i++)
        {
            if (group[i] == -1)
                group[i] = m++;
        }

        vector<int> group_in_degree(m), in_degree(n);

        // invers of after graph
        vector<vector<int>> after(n);

        // mapping group to its members
        map<int, vector<int>> group_members;

        for (int i = 0 ; i < n ; i++)
        {
            for (auto x : bef[i])
            {
                after[x].push_back(i);

                // edge from x(before) to i(after)
                in_degree[i]++;

                // add degree of group if they are from different groups
                if (group[i] != group[x])
                {
                    group_in_degree[group[i]]++;
                }
            }
            group_members[group[i]].push_back(i);
        }

        queue<int> group_q;
        for (int i = 0 ; i < m; i++)
        {
            if (group_in_degree[i] == 0)
            {
                group_q.push(i);
            }
        }

        vector<int> ans;

        while (!group_q.empty())
        {
            int curr_group = group_q.front();
            group_q.pop();

            auto items = group_members[curr_group];

            queue<int> item_q;
            for (auto i : items)
            {
                if (in_degree[i] == 0)
                {
                    item_q.push(i);
                }
            }

            while (!item_q.empty())
            {
                int curr_item = item_q.front();
                item_q.pop();

                // add item to ans
                ans.push_back(curr_item);
                for (auto child : after[curr_item])
                {
                    // add after item if in same group
                    if (--in_degree[child] == 0 and group[child] == group[curr_item])
                    {
                        item_q.push(child);
                    }
                    // check if degree of child group can be reduced if from another group
                    if (group[child] != group[curr_item])
                    {
                        if (--group_in_degree[group[child]] == 0)
                            group_q.push(group[child]);
                    }
                }
            }
        }

        // if all intems not in ans, ans is not possible
        if (ans.size() != n) ans.clear();
        
        return ans;
    }
};