class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // return nums[n/2];

        // int n = nums.size();
        // unordered_map<int, int> m;
        
        // for(int i = 0; i < n; i++){
        //     m[nums[i]]++;
        // }
        // n = n/2;
        // for(auto x: m){
        //     if(x.second > n){
        //         return x.first;
        //     }
        // }
        // return 0;
        int count = 0;
        int candidate = 0;
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
        
    }
};