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
        unordered_map<int, int> mp;
        ListNode *slow, *fast;
        slow = head;
        while(slow)
        {
            //checking if the node is present in heap or not
            if(mp.count(slow->val))
            {   
                //If the node is present already then it's value or count will increase
                mp[slow->val]++;
            }
            else
            {
                //If the node is not present, then it will be inserted along with it's count values as 1;
                mp[slow->val] = 1;
            }

            //if next node is present then slow will traverse next node, otherwise it will be set as NULL;
            if(slow->next)
            {
                slow = slow->next;
            }
            else
            {
                slow = NULL;
            }
        }

        slow = head;
        fast = head;
        while(fast && fast->next)
        {
            if(mp[fast->val]>1)
            {
                if(fast==head)
                {
                    fast = fast->next;
                    head = NULL;
                    slow = head;
                }
                else
                {
                    fast = fast->next;
                    if(slow){
                        slow->next = NULL;
                    }
                }
            }
            else
            {
                if((slow==fast))
                {fast=fast->next;}
                else if(slow==NULL)
                {
                    head = fast;
                    slow = head;
                }
                else
                {
                    slow->next = fast;
                    fast = fast->next;
                    slow = slow->next;
                }
            }
            if(fast->next == NULL)
            {
                if(mp[fast->val]==1)
                {
                    if(slow==NULL)
                    {
                        head = fast;
                        slow = head;
                    }
                    else
                    {
                        slow->next = fast;
                    }
                }
            }
        }
        return head;
    }
};
