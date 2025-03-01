class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        ListNode* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }
        
        temp->next = head;
        k = k % length;
        int steps = length - k;
        while (steps--) temp = temp->next;
        
        head = temp->next;
        temp->next = NULL;
        
        return head;
    }
};
