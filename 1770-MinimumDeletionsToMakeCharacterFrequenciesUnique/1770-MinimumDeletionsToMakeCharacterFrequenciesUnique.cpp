// Last updated: 07/11/2025, 13:41:36
class Solution {
public:
    int minDeletions(string s) {
        array<int, 26> freq{};
	for (char c : s) ++freq[c - 'a'];
	sort(freq.begin(), freq.end(), greater<int>());
	int keep = 0, prev = INT_MAX;
	for (int f : freq) {
		if (!f || !prev) break;
		prev = min(f, prev - 1);
		keep += prev;
	}
	return s.size() - keep;      
    }
};

// Steps:
// 1. Count frequency of each letter
// 2. Sort the frequencies
// 3. From the letter with highest frequency, for each letter we keep no more than previous letter
// 4. Total number - number we kept = number we want to delete
 
// Complexity:    
// Time: step 1 is O(n), other steps are O(1) (sorting/checking 26 numbers) - overall O(n)
// space: using array of size 26 - O(1)    