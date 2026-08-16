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

    ListNode* Kth(ListNode* temp , int k)
    {
        k = k-1;
        while(temp!=0 && k>0)
        {
            k--;
            temp = temp->next;
        }
        return temp;

    }
    ListNode* Reverse(ListNode* temp)
    {
        ListNode* front = NULL;
        ListNode* prev = NULL;

        while(temp!=NULL)
        {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;

        }
        return prev;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while(temp!=NULL)
        {
            ListNode* KthNode = Kth(temp, k);
            if(KthNode==NULL) 
            {
                if(prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = KthNode->next;
            KthNode->next = NULL;
            Reverse(temp);
            if(temp == head)
            {
                head = KthNode;
            }
            else{
                prevLast->next = KthNode;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;


    }
};