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
    private:
    int calcGCD(int x, int y)
    {
        if(!x) return y;
        
        return calcGCD((y % x), x);
    }
    
    public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        ListNode* gcdInsertedList = head;
        int tempGCD;
        
        while(gcdInsertedList && gcdInsertedList->next)
        {
            tempGCD = calcGCD(gcdInsertedList->val, gcdInsertedList->next->val);
            
            ListNode* tempNode = new ListNode(tempGCD);
            tempNode->next = gcdInsertedList->next;
            gcdInsertedList->next = tempNode;
            gcdInsertedList = tempNode->next;
        }
        
        return head;
    }
};