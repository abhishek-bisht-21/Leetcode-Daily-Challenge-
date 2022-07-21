class Solution {
public:
    
    // temporary head, temporary tail
ListNode *th = nullptr;
ListNode *tt = nullptr;

void addFirstNode(ListNode *node)
{
    if (th == nullptr)
    {
        th = node;
        tt = node;
    }
    else
    {
        node->next = th;
        th = node;
    }
}
    
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
         if (head == nullptr || head->next == nullptr || m == n)
        return head;

    ListNode *curr = head;
    ListNode *prev = nullptr;

    int idx = 1;

    while (curr != nullptr)
    {
        while (idx >= m && idx <= n)
        {
            ListNode *forw = curr->next;
            curr->next = nullptr;
            addFirstNode(curr);
            curr = forw;
            idx++;
        }

        if (idx > n)
        {
            if (prev != nullptr)
            {
                prev->next = th;
                tt->next = curr;
                return head;
            }
            else
            {
                tt->next = curr;
                return th;
            }
        }

        idx++;
        prev = curr;
        curr = curr->next;
    }

    return head;
    }
    
    
};