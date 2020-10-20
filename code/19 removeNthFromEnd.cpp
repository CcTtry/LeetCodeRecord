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
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
}; 
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
    	ListNode *pre, *cur, *next;
		pre = head;
		next = head;
		cur = head;
		int count = 0;
		while(count < n){//先让 next指针前进n次，然后让next和cur指针一起前进直到next到达了尾部 
			next = next->next;
			count ++;
		}
		if(!next){//  ******  注意分析 到达尾部的情况  已经最后一个节点了 
			return pre->next;
		}
		
		while(next->next){
			next = next->next;
			cur = cur->next;
		}// 此时cur为倒数第 n+1 个 节点
		ListNode *tem = cur->next;
		cur->next = tem->next;
		return pre;
		
    }
};
void print(ListNode * head)
{//′òó?
	if (head == NULL)
	{
		return;
	}
	ListNode * p = head;
	while (p->next != NULL)
	{
		cout<<p->val<<"->";
		p = p->next;
	}

	cout<<p->val<<endl;
}
int main() {
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);
	ListNode *p6 = new ListNode(6);

	ListNode *p7 = new ListNode(7);
	ListNode *p8 = new ListNode(8);
	ListNode *p9 = new ListNode(9);
	ListNode *p10 = new ListNode(10);
	ListNode *p11 = new ListNode(11);
	ListNode *p12 = new ListNode(12);

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = NULL;
	print(p1);
	Solution sl;
	print(sl.removeNthFromEnd(p1, 2));
//	print(reverse(p1));

	return 0;
}