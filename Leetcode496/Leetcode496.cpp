//
// Created by cestl on 2018/5/2 0002.
//

#include "Leetcode496.h"

vector<int> Leetcode496::nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
    vector<int> ans;
    stack<int> st;
    unordered_map<int, int> m;

    for (int num : nums) {
        while (!st.empty() && st.top() < num) {
            m[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }

    for (int num : findNums) {
        ans.push_back(m.count(num) ? m[num] : -1);
    }
    return ans;
}

vector<int> Leetcode496::nextGreaterElement2(vector<int> &findNums, vector<int> &nums) {
    vector<int> ans;
    if (findNums.empty())
        return ans;

    map<int, int> helper;
    for (int i = 0; i < nums.size(); i++)
        helper[nums[i]] = i;

    for (int i = 0; i < findNums.size(); i++) {
        for (int j = helper[findNums[i]]; j < nums.size(); ++j) {
            if (j + 1 == nums.size())
                ans.push_back(-1);
            else if (nums[j + 1] > findNums[i]) {
                ans.push_back(nums[j + 1]);
                break;
            }
        }
    }
    return ans;
}
