// 19th september 2023 
// https://leetcode.com/problems/find-the-duplicate-number/description/?envType=daily-question&envId=2023-09-19


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];


        while(true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];


            if(slow == fast) break;
        }


        int slow2 = nums[0];


        while(slow != slow2)
        {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};
