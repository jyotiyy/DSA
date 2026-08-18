link: https://leetcode.com/problems/odd-even-linked-list/submissions/
The idea is basically having a seperate linked list for odd and even 
and smartly ;) 

odd->next = even->next
then update odd => odd = odd->next

even->next = odd->next
then update even => even = even->next

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};