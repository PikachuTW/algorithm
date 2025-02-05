/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */
#include <bits/stdc++.h>
using namespace std;
// 我自己的暴力解 (beats 99.71%) O(nlogn) (sort)
// @lc code=start
class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> arr(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            arr[i] = make_pair(nums[i], i);
        }
        sort(arr.begin(), arr.end());
        int lastNum = 1e9 + 1, lastIndex = 0;
        for (pair<int, int> el : arr) {
            if (el.first == lastNum && el.second - lastIndex <= k) {
                return true;
            }
            lastNum = el.first;
            lastIndex = el.second;
        }
        return false;
    }
};
// @lc code=end

/* O(n) (hashmap) (slower?)
class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> table;
        for (int i = 0; i < nums.size(); i++) {
            if (table.count(nums[i])) return true;
            table.emplace(nums[i]);
            if (i >= k) table.erase(nums[i - k]);
        }
        return false;
    }
};
*/
