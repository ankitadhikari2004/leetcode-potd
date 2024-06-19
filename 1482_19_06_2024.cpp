class Solution
{
public:
    int canBloom(vector<int> &bloomDay, int mid, int k)
    {
        int boqCount = 0;
        int consequetiveCount = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                consequetiveCount++;
            }
            else
            {
                consequetiveCount = 0;
            }

            if (consequetiveCount == k)
            {
                boqCount++;
                consequetiveCount = 0;
            }
        }

        return boqCount;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {

        int start_day = 1;
        int end_day = *max_element(bloomDay.begin(), bloomDay.end());
        int minDay = -1;

        while (start_day <= end_day)
        {
            int mid = start_day + (end_day - start_day) / 2;
            if (canBloom(bloomDay, mid, k) >= m)
            {
                minDay = mid;
                end_day = mid - 1;
            }
            else
            {
                start_day = mid + 1;
            }
        }

        return minDay;
    }
};