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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr=head;
        int c=0;
        while(curr!=0){
            c++;
            curr=curr->next;
        }
        int n=c/2 ;
        while(head->next!=NULL && n-->0){
            head=head->next;
        }
        return head;
    }
};