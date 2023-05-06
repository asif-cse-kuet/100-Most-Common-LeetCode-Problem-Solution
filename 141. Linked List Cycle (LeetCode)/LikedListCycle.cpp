/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//Program will return false if no cycle exist; otherwise it will return true.

class Solution {
public:
    bool hasCycle(ListNode *head) {
      
      //Checking if there exist a node or not. If no node exist, there is no cycle possible. So the return will be false.
        if (head==NULL){
          return false;
          }
          
      
      /**Taking two pointer, forward pointer will move two times faster than back pointer. 
      If they start form the same point and then again meet in any other point, obviously there exist a Loop or Cycle. **/
        ListNode *back = head;
        ListNode *forward = head;

        while((forward!=NULL) && (forward->next!= NULL))  //If in anytime, forward pointer reached to the NULL, that means it goes to the end of the list. So, no loop exist
        {
            back = back->next;
            forward = forward->next->next;
            
            if(back==forward)
            {
                return true;
            }
        }
        return false;
    }
};
