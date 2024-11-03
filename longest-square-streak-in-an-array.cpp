#include <bits/stdc++.h>
using namespace std;
class Solution
{
    unordered_map<int, int> numMap;
    int search(vector<int> &nums, int x)
    {
        if (numMap.find(x) != numMap.end())
            return numMap[x];
        return -1;
    }

public:
    int longestSquareStreak(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            numMap[nums[i]] = i;
        }
        int cnt1 = 0;
        vector<bool> global(nums.size(), false);
        for (long long i = 0; i < nums.size(); i++)
        {
            if (global[i])
                continue;

            int cnt2 = 1;
            long long j = i;
            global[j] = true;
            while (true)
            {
                long long sq = (long long)nums[j] * (long long)nums[j];
                long long index = search(nums, sq);
                if (index != -1 && !global[index])
                {
                    j = index;
                    cnt2++;
                    global[index] = true;
                }
                else
                    break;
            }
            cnt1 = max(cnt1, cnt2);
        }
        return cnt1 < 2 ? -1 : cnt1;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {4, 3, 6, 16, 8, 2};
    cout << s.longestSquareStreak(nums);
}