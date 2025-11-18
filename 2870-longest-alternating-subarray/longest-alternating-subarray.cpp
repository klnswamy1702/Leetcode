class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
    int front = 1, back = 0, state = INT_MAX, ans = 0;
    while(front < nums.size()){
        int diff = nums[front] - nums[front-1];
        if(diff == state*(-1)){
            state = state * (-1);
            ans = max(ans, front - back + 1);
        }else{
            if(diff == 1){
                state = diff;
                back = front - 1;
                ans = max(ans, front - back + 1);
            }else state = INT_MAX;
        }
        front++;
    }
    return ans?ans: -1;
}
};