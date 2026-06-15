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
    ListNode* deleteMiddle(ListNode* head) {
        int cnt =0 ;
        ListNode* temp = head;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        if(cnt == 1)
        return NULL;
        int half = floor(cnt/2);
        temp = head;
        ListNode* prev = head;
        while(half!=0){
            half--;
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        return head;
    }
};