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
class Solution 
{
    public:
        ListNode* reverseList(ListNode* head) 
        {
            ListNode* rev = nullptr;
    
            while(head != nullptr)
            {
                ListNode* next_Node = head->next;
                head->next = rev;
                rev = head;
                head = next_Node;
            }
    
            return rev;
        }
};