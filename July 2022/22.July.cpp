class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
          
        ListNode *smaller = new ListNode(0);
        ListNode *larger = new ListNode(0);
        ListNode *sp = smaller; // small previous
        ListNode *lp = larger;  // large previous
        
        ListNode* curr = head;
        
        while(curr)
        {
        
            if(curr->val < x)
            {
                sp->next = curr;
                sp = sp->next;
            } else {
                lp->next = curr;
                lp = lp->next;
            }
            curr = curr->next;
        }
        lp->next = NULL;
        sp->next = larger->next;;
        return smaller->next;
    }
};