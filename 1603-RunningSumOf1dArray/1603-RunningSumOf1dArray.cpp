// Last updated: 07/11/2025, 13:42:12
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        vector<int>V;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            V.push_back(sum);
        }
        return V;
    }
};