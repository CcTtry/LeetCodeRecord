
使用两个指针，一个先走N步，之后两个指针一起走，直到第一个指针指向最后一个节点为止。


```C++
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* pre, * cur, *next;
		pre = head;
		cur = head;
		next = head;

		int count = 0;
		while (count < n) { // 先前进n个节点  到达第n+1个节点
			next = next->next;
			count ++;
		}

		while (!next) {  // 如果已经到了结尾了， 删除第一个元素
			return pre->next;
		}

		while (next->next) { // next 到达最后一个元素
			cur = cur->next;
			next = next->next;
		}

		pre = cur->next;
		cur->next = pre->next;

		return head;

	}
};


void print(ListNode * head) {
	int count = 1;
	ListNode *temp = head;
	while (temp) {
		printf("%dth node val = %d\n", count++, temp->val);
		temp = temp->next;
	}
}


int main() {

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(6);
	ListNode* n7 = new ListNode(7);
	ListNode* n8 = new ListNode(8);
	ListNode *n9 = new ListNode(9);


	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = n9;

	print(n1);
}

```