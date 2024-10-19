#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int m = 0;
        vector<int> max1;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                max1.push_back(m);
                continue;
            }
            m = max(m, height[i - 1]);
            max1.push_back(m);
        }
        for (int x : max1)
        {
            cout << x << " ";
        }

        int m2 = 0;
        vector<int> max2(n);
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                max2[i] = m2;
                continue;
            }
            m2 = max(m2, height[i + 1]);
            int z = 0;
            max2[i - z] = m2;
            z++;
        }
        cout << endl;

        for (int x : max2)
        {
            cout << x << " ";
        }
        int ans = 0;
        for (int i = 1; i < max1.size() - 1; i++)
        {
            n = min(max1[i], max2[i]) - height[i];
            cout << endl
                 << n << " ";
            if (n > 0)
                ans += n;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> num = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // s.trap(num);
    cout << endl
         << s.trap(num);
}