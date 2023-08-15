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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* smallerThanX = new ListNode(0);
        ListNode* greaterThanEqualX = new ListNode(0);
        ListNode* tempSmaller = smallerThanX;
        ListNode* tempGreaterX = greaterThanEqualX;

        while(head)
        {
            if(head->val < x)
            {
                tempSmaller->next = head;
                tempSmaller = tempSmaller->next;
            }
            else
            {
                tempGreaterX->next = head;
                tempGreaterX = tempGreaterX->next;
            }

            head = head->next;
        }     

        tempSmaller->next = greaterThanEqualX->next;
        tempGreaterX->next = nullptr;

        return smallerThanX->next;
    }
};