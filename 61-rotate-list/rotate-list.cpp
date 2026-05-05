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
    ListNode* rotateRight(ListNode* head, int k) {
        int size =0;;
        ListNode* temp = head;
        if(temp ==nullptr || temp -> next == nullptr){
            return temp;
        }
        while(temp != nullptr){
            size++;
            temp = temp->next;
        }
         k= k%size;
        int n =1;
        while(n <=k){
            ListNode* last = head;
            ListNode* seclast = nullptr;
            while(last ->next !=nullptr ){
                seclast=last;
                last=last->next;

            }
            seclast->next = nullptr;
            last->next = head;
            head = last;
            n++;
        }
        return head;
    }
};