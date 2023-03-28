class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int sz = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < sz-1  ; i++)
        {  
            if(nums[i] == nums[i+1])
            return 1;

        }
        return 0;
    }
};
