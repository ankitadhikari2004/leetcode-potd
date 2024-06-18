#include<bits/stdc++.h>


// approach 1

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {

        priority_queue<pair<int, int>> pq; // max heap of pairs
        for (int i = 0; i < difficulty.size(); i++)
        {
            int diff = difficulty[i];
            int pro = profit[i];
            pq.push({pro, diff});
        }

        sort(worker.begin(), worker.end(), greater<int>()); // descending order

        int i = 0;
        int totalProfit = 0;
        while (i < worker.size() && !pq.empty())
        {
            if (worker[i] < pq.top().second)
            {
                pq.pop();
            }
            else
            {
                totalProfit += pq.top().first;
                i++;
            }
        }
        return totalProfit;
    }
};



// approach 2