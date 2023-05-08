class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *forward = head;
        ListNode *back = head;
        while(forward && forward->next)
        {
            back = back->next;
            forward = forward->next->next;

            if(back==forward)
            {
                back = head;
                while(back!=forward)
                {
                    forward = forward->next;
                    back = back->next;
                }
                return back;
            }
        }
        return NULL;
    }
};
