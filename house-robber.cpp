#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp;
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);

        return max(dp[n-1], dp[n-2]);
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << s.rob(nums);
}