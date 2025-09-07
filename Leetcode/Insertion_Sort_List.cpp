class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0);
        dummy.next = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* prev = &dummy;
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }
            ListNode* nextTemp = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = nextTemp;
        }

        return dummy.next;
    }
};
