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
    ListNode* deleteDuplicates(ListNode* head) {
        int val1,val2;
        ListNode *nd = head;
        ListNode *nd2 = head;
        if(head && head->next){
            nd2 = head->next;
        } else {return head;}

        while(nd && nd2){
            val1 = nd->val;
            val2 = nd->next->val;
            if(val1==val2)
            {
                nd->next = nd2->next;
                nd2 = nd2->next;
            }
            else
            {
                nd=nd->next;
                nd2=nd2->next;
            }
        }
        return head;
    }
};
