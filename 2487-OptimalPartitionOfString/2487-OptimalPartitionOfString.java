// Last updated: 07/11/2025, 13:40:40
class Solution {
    public int partitionString(String s) {
        int ans = 1;
        int mask = 0;
        for (char ch : s.toCharArray()) {
            int shift = ch - 'a';
            if ((mask & (1 << shift)) > 0) {
                ans++;
                mask = 0;
            }
            mask |= 1 << shift;
        }
        return ans;
        
    }
}