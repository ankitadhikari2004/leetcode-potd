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

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {

        vector<pair<int, int>> v;
        for (int i = 0; i < difficulty.size(); i++)
        {
            int diff = difficulty[i];
            int pro = profit[i];
            v.push_back({diff, pro});
        }

        sort(v.begin(), v.end());

        int totalProfit = 0;

        for (int i = 1; i < v.size(); i++)
        {
            v[i].second = max(v[i].second, v[i - 1].second);
        }

        for (int i = 0; i < worker.size(); i++)
        {
            int workerDiff = worker[i];
            int low = 0;
            int high = v.size() - 1;
            int maxProfit = 0;

            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (v[mid].first <= workerDiff)
                {
                    maxProfit = max(maxProfit, v[mid].second);
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            totalProfit += maxProfit;
        }

        return totalProfit;
    }
};