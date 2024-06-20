
// Link:https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/?envType=daily-question&envId=2023-09-20




Code
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        int reqSum = totalsum - x;


        if (reqSum < 0)
            return -1;
        if (reqSum == 0)
            return nums.size();


        int sum = 0, start = 0, end = 0, res = 0, n = nums.size();


        while (end < nums.size()) {
            sum += nums[end];


            while (sum > reqSum) {
                sum -= nums[start];
                start++;
            }
            if (sum == reqSum)
                res = max(res, end - start + 1);
            end++;
        }
        return res == 0 ? -1 : n - res;
    }
};
