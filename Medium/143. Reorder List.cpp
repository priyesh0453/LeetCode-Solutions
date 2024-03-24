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
    void reorderList(ListNode* head) 
    {    
        ListNode* hare = head->next, *tortoise = head;

        while(hare != NULL && hare->next != NULL)
        {
            hare = hare->next->next;
            tortoise = tortoise->next;
        }

        ListNode* firstLinkedList = head, *secondLinkedList = reverseLinkedList(tortoise->next), *temp1, *temp2;
        tortoise->next = NULL;

        while(secondLinkedList != NULL)
        {
            temp1 = firstLinkedList->next;
            firstLinkedList->next = secondLinkedList;
            temp2 = secondLinkedList->next;
            secondLinkedList->next = temp1;

            firstLinkedList = temp1;
            secondLinkedList = temp2;
        }
    }

    private:
    ListNode* reverseLinkedList(ListNode* head)
    {
        ListNode* previous = NULL, *current = head, *next = NULL;

        while(current != NULL)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        return previous;
    }
};