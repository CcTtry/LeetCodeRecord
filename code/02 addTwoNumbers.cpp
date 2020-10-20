#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {};
};
ListNode * reverse(ListNode * head)
{//·′×a
	if (head == NULL)
	{
		return NULL;
	}
	ListNode *pre,*cur,*next;
	pre = head;
	cur = head->next;
	while (cur)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;  // pre->next 指向的是pre （就是上一个节点）
		cur = next;
		// cout<<"   pre val "<<pre->val<<endl;
		// cout<<"   pre next  val "<<pre->next->val<<endl<<endl;
	}
	head->next = NULL;
	head = pre;
	return head;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 存储结果
        ListNode newNode(0); //指向头指针
        ListNode *pnext = &newNode;

        int carry = 0, val1 = 0, val2 = 0, val = 0;
        while(l1 != NULL || l2 != NULL){
        	if(l1){
        		val1 = l1->val;
        		l1 = l1->next;
        	}else{
        		val1 = 0;
        	}

        	if(l2){
        		val2 = l2->val;
        		l2 = l2->next;
        	}else{
        		val2 = 0;
        	}

        	val = (l1->val + l2->val + carry)%10;  
        	carry = (l1->val + l2->val)/10;
        	pnext->next = new ListNode(val1);
        	pnext = pnext->next;
       	
         }
        return newNode.next;
    }
};
 
int main(){
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
	print(reverse(p1));

	p6->next = p7;
	p7->next = p8;
	p8->next = p9;
	p9->next = p10;
	p10->next = p11;
	p11->next = p12;
	p12->next = NULL;
	print(p6);
	print(reverse(p6));
	Solution sl;

	print(sl.addTwoNumbers(p1, p6));
	return 1;
}