// Last updated: 07/11/2025, 13:40:44
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
//     }
// };


// class Solution {
// public:
//     vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) 
//     {
// 		// Create a matrix of n x m with values filled with -1.
//         vector<vector<int>> spiral(n, vector<int>(m, -1));
//         int i = 0, j = 0;
// 		// Traverse the matrix in spiral form, and update with the values present in the head list.
// 		// If head reacher NULL pointer break out from the loop, and return the spiral matrix.
//         while (head != NULL)
//         {
//             if (j < m)
//             {
//                 while (head != NULL && j < m && spiral[i][j] == -1)
//                 {
//                     spiral[i][j] = head->val;
//                     head = head->next;
//                     j++;
//                 }
//                 if (head == NULL)
//                     break;
//                 i++;
//                 j--;
//             }
//             if (i < n)
//             {
//                 while (head != NULL && i < n && spiral[i][j] == -1)
//                 {
//                     spiral[i][j] = head->val;
//                     head = head->next;
//                     i++;
//                 }
//                 i--;
//                 j--;
//             }
//             if (j >= 0)
//             {
//                 while (head != NULL && j >= 0 && spiral[i][j] == -1)
//                 {
//                     spiral[i][j] = head->val;
//                     head = head->next;
//                     j--;
//                 }
//                 j++;
//                 i--;
//             }
//             if (i >= 0)
//             {
//                 while (head != NULL && i >= 0 && spiral[i][j] == -1)
//                 {
//                     spiral[i][j] = head->val;
//                     head = head->next;
//                     i--;
//                 }
//                 i++;
//                 j++;
//             }
//             n--;
//             m++;
//         }
// 		// Rest values are itself -1.
//         return spiral;
//     }
// };



class Solution {
	public:
		vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
			vector<vector<int>> mat(m,vector<int>(n,-1));
			ListNode* curr=head;
			int minr=0;
			int minc=0;
			int maxr=m-1;
			int maxc=n-1;
			int t=0;
			while(curr!=NULL && t<=m*n){
				for(int j=minc;j<=maxc && curr!=NULL && t<=m*n;j++){
					int i=minr;
					mat[i][j]=curr->val;
					curr=curr->next;
					t++;
				}
				minr++;
				for(int i=minr;i<=maxr && curr!=NULL && t<=m*n;i++){
					int j=maxc;
					mat[i][j]=curr->val;
					curr=curr->next;
					t++;
				}
				maxc--;
				for(int j=maxc;j>=minc && curr!=NULL && t<=m*n;j--){
					int i=maxr;
					mat[i][j]=curr->val;
					curr=curr->next;
					t++;
				}
				maxr--;
				for(int i=maxr;i>=minr && curr!=NULL && t<=m*n;i--){
					int j=minc;
					mat[i][j]=curr->val;
					curr=curr->next;
					t++;
				}
				minc++;
			}
			return mat;
		}
	};