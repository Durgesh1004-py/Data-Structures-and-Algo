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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* st = list1;
        ListNode* ed = list1;
        for (int i=0;i<a-1;i++){
            st = st->next;
        }
        for (int i=0;i<b+1;i++){
            ed = ed->next;
        }
        ListNode* l2Temp = list2;
        while(l2Temp->next != NULL){
            l2Temp = l2Temp->next;
        }
        st->next = list2;
        l2Temp->next = ed;
        return list1;
    }
};