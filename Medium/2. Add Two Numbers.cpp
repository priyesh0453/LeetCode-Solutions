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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* Sum = new ListNode();
        ListNode* output = Sum;
        int carry = 0, sum;

        while(l1 != NULL && l2 != NULL)
        {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            Sum->next = new ListNode(sum % 10);
            l1 = l1->next;
            l2 = l2->next;
            Sum = Sum->next;
        }
        while(l1 != NULL)
        {
            sum = l1->val + carry;
            carry = sum / 10;
            Sum->next = new ListNode(sum % 10);
            l1 = l1->next;
            Sum = Sum->next;
        }
        while(l2 != NULL)
        {
            sum = l2->val + carry;
            carry = sum / 10;
            Sum->next = new ListNode(sum % 10);
            l2 = l2->next;
            Sum = Sum->next;
        }

        if(carry != 0)
        {
            Sum->next = new ListNode(carry);
        }

        return output->next;
    }
};