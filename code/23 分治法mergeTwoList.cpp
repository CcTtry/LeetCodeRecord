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
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) { // 合并两个链表
        ListNode* head, * tail, * a = l1, * b = l2;
        if (!a || !b) return a ? a : b;
        head = new ListNode(0);
        tail = head;
        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            }
            else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = (a ? a : b);

        return head->next;
    }
    // 分治递归 合并整个链表的数组
    ListNode* merge(vector<ListNode*>& list, int left, int right) {
        if (left == right) {
            return list[left];
        }
        if (left > right) return nullptr;
        int middle = (left + right) / 2;
        return mergeTwoList(merge(list, left, middle), merge(list, middle + 1, right));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int N = lists.size();
        return merge(lists, 0, N - 1);
    }
};

