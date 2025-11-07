// Last updated: 07/11/2025, 13:42:53
class Solution {
public:
    int tribonacci(int n) {
        int first=0,second=1,third=1;
        
        // here first,second and third are the previous three elements
        if(n<2)
            return n;
        
        // if n=0 or n=1 then the tribonacci number is n itself 
        // else for loop will be executed
        for(int i=3;i<=n;i++)
        {
            int newElement=first+second+third;
            first=second;
            second=third;
            third=newElement;
        }
        
		//If n=2 then the for loop is not executed and the initial value of the
		//variable third is returned which is 1 
        
        return third;
    }
};