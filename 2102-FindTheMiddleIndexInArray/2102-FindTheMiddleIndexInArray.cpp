// Last updated: 07/11/2025, 13:41:07
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
         int sum = 0, leftsum=0;
        
        for( int x: nums ) sum += x;
        for( int i=0; i<nums.size(); ++i )
        {
            if (leftsum == sum - leftsum - nums[i]) return i;
            leftsum += nums[i];
            
        }
        return -1;
    }
};