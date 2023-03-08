/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* hare = head;
        ListNode* tortoise = head;

        while(hare->next != nullptr && hare->next->next != nullptr)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;

            if(tortoise == hare)
            {
                hare = head;

                while(tortoise != hare)
                {
                    tortoise = tortoise->next;
                    hare = hare->next;
                }

                return tortoise;
            }
        }

        return nullptr;    
    }
};