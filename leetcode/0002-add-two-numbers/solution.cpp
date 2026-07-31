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
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0,sum = 0;
        while(l1 && l2){
            sum= l1->val+l2->val+carry;
            carry=sum/10;
            sum%=10;
            ListNode* node = new ListNode(sum);
            temp->next=node;
            temp=node;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            sum= l1->val+carry;
            carry=sum/10;
            sum%=10;
            ListNode* node = new ListNode(sum);
            temp->next=node;
            temp=node;
            l1=l1->next;
        }
        while(l2){
            sum= l2->val+carry;
            carry=sum/10;
            sum%=10;
            ListNode* node = new ListNode(sum);
            temp->next=node;
            temp=node;
            l2=l2->next;
        }
        if(carry){
             ListNode* node = new ListNode(carry);
            temp->next=node;
            temp=node;
        }
        return dummy->next;
    }
};
