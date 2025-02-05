/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */
using namespace std;
#include <bits/stdc++.h>
// @lc code=start
class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> occured;
        for (int num : nums) {
            if (occured.count(num)) return true;
            occured.emplace(num);
        }
        return false;
    }
};
// @lc code=end
