class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr =dummy;
        while(l1!=NULL || l2!=NULL){
            int sum = carry;
            carry=0;
            if(l1)sum+=l1->val;
            if(l2)sum+=l2->val;
            int val = sum % 10;
            carry = sum/10;
            ListNode* temp = new ListNode(val);
            curr->next = temp;
            curr = curr->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        if(carry!=0){
            ListNode* temp = new ListNode(carry);
            temp->next=NULL;
            curr->next = temp;   
        }
        return dummy->next;
    }
};