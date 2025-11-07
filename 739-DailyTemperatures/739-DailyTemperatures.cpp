// Last updated: 07/11/2025, 13:44:03
class Solution {
public:
    // vector<int> dailyTemperatures(vector<int>& temperatures) {
        
    // //     stack<pair<int,int>>st; 
    // //     vector<int>ans(temperatures.size(),0);

    // //       for(int i=temperatures.size()-1;i>=0;i--)
    // //       {
       
    // //        while(st.size()>0 && st.top().first<=temperatures[i]) 
    // //         {   
    // //             st.pop();
    // //         }

    // //         if(st.size()!=0) 
    // //         ans[i] = (st.top().second-i); 
        
    // //         st.push({temperatures[i],i}); 
    // //         }
    // //         return ans;
    // //     }

    // //  vector<int> dailyTemperatures(vector<int>& temp) {
    // //     stack<int> stk;
    // //     int n= temp.size();
    // //     vector<int> ans(n, 0);

    // //     stk.push(0);
    // //     for (int i = 1; i < temp.size(); i++) {
    // //         while (!stk.empty() && temp[i] > temp[stk.top()]) {
    // //             ans[stk.top()] = i - stk.top();
    // //             stk.pop();
    // //         }
    // //         stk.push(i);
    // //     }

    // //     return ans;

    //   int n = temperatures.size();
    //     vector<int>nge(n, 0); // initially all 0, stores distance between their next greater element and current temperature
    //     stack<int>st{};
        
	// 	// move from right to left
    //     for(int i = n-1; i>=0; --i){
    //         // pop until we find next greater element to the right
	// 		// since we came from right stack will have element from right only
	// 		// s.top() is the index of elements so we put that index inside temperatures vector to check
    //         while(!st.empty() && temperatures[st.top()] <= temperatures[i])
    //             st.pop();
				
    //         // if stack not empty, then we have some next greater element, 
	// 		// so we take distance between next greater and current temperature
	// 		// as we are storing indexes in the stack
    //         if(!st.empty())
    //             nge[i] = st.top()-i; // distance between next greater and current
            
	// 		// push the index of current temperature in the stack,
	// 		// same as pushing current temperature in stack
    //         st.push(i);
    //     }
        
    //     return nge;    
    // }

    



vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size());
    for (int i = temperatures.size() - 1; i >= 0; --i) {
        int j = i+1;
        while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
            if (res[j] > 0) j = res[j] + j;
            else j = temperatures.size();
        }
        // either j == size || temperatures[j] > temperatures[i]
        if (j < temperatures.size()) res[i] = j - i;
    }
    return res;
}

};