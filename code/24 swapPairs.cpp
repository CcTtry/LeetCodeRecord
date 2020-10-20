/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 画图 指示指针的交换方式
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        else if(!head->next) return head;
        ListNode *h, *pre, *cur, *a, * b, *temp;
        pre = new ListNode(0);
        pre->next = head;
        h = pre;
        cur = head;
       
        while (cur && cur->next) {
            temp = cur->next->next; //第三个节点
            cur->next->next = cur;
            pre->next = cur->next;
            cur ->next = temp;

            pre = cur;
            cur = temp;
        }
        return h->next;
    }
};