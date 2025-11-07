// Last updated: 07/11/2025, 13:41:00
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
class Solution {
public:
    // ListNode* deleteMiddle(ListNode* head) {
    //     if (head->next == nullptr)
    //     return nullptr;
    //     auto slow = head, fast = head->next->next;
    //     while (fast != nullptr && fast->next != nullptr) {
    //         fast = fast->next->next;
    //         slow = slow->next;
    //     }
    //     slow->next = slow->next->next;
    //     return head; 
    // }

      ListNode* deleteMiddle(ListNode* head) {
        // i thought about this by starting from slowNfast pointer but 
        // when i've reached middle (slow) element, i can't link it to 
        // the node before middle, hence i thought about starting slow
        // from one location before head to make sure that i reaches exactly 
        // one node before middle & then i just skipped the next node ie middle
        ListNode *dummy = new ListNode;
        dummy -> next = head;
        ListNode *slow = dummy;
        ListNode *fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow -> next = slow -> next -> next;
        return dummy -> next;
    }
};