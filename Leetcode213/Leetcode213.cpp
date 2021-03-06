//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode213.h"

int Leetcode213::robhouse(vector<int> &nums, int begin, int end) //[begin,end)
{
    int pre = 0;
    int cur = 0;
    int ans = 0;
    for (int i = begin; i < end; ++i) {
        ans = max(pre + nums[i], cur);
        pre = cur;
        cur = ans;
    }
    return ans;
}

int Leetcode213::rob(vector<int> &nums) {
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];
    else
        return max(robhouse(nums, 0, nums.size() - 1),
                   robhouse(nums, 1, nums.size()));
}
