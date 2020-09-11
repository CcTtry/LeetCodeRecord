#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <climits>
#include <string>
#include <map> 
#include <unordered_map>
#include <stack>
#include <vector>
#include<set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        else if (!head->next) return head;
        ListNode* h, * pre, * cur, * a, * b, * temp;
        pre = new ListNode(0);
        pre->next = head;
        h = pre;
        cur = head;

        while (cur && cur->next) {
            temp = cur->next->next; //第三个节点
            cur->next->next = cur;
            pre->next = cur->next;
            cur->next = temp;

            pre = cur;
            cur = temp;
        }
        return h->next;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *test = head;
        int len = 0, index = 0;
        while (test) {
            len++;
            test = test->next;
        }
        printf("len is %d\n\n", len);
        if (len < k) return head;
        cout<<"haimeiyou tuichu  \n\n";
        ListNode *pre, * cur = head, *temp, *res;
        pre = new ListNode(0);
        res = new ListNode(0);
        res = pre;   // 保留头结点的位置
        pre->next = head;    
        for (int i = 0; i < len / k; i++) {
            for (int j = 0; j < k - 1; j++) {
                temp = cur->next;
                cur->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
            }
            pre = cur;
            cur = pre->next;
        }
        return res->next;
    }
    
};

void print(ListNode* head)
{//
    if (head == NULL)
    {
        return;
    }
    ListNode* p = head;
    while (p->next != NULL)
    {
        cout << p->val << "->";
        p = p->next;
    }

    cout << p->val << endl;
}
int main() {

    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(5);
    ListNode* p6 = new ListNode(6);

    ListNode* p7 = new ListNode(7);
    ListNode* p8 = new ListNode(8);
    ListNode* p9 = new ListNode(9);
    ListNode* p10 = new ListNode(10);
    ListNode* p11 = new ListNode(11);
    ListNode* p12 = new ListNode(12);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;
    p7->next = p8;
    p8->next = NULL;
    print(p1);
    Solution sl;
    print(sl.reverseKGroup(p1, 3));
}

