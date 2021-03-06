
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root != NULL) que.push(root);
        vector<vector<int>> result;
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;   // 存储所有的结果
            // size表示当前层的 节点数目
            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();

                if(i < size - 1){// 如果不是最后一个节点
                    node->next = que.front();
                }
 
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return root;
    }
};


int main(){
    queue<int> Qi;
    Qi.push(1);
    Qi.push(2);
    Qi.push(3);
    Qi.push(4);
    Qi.push(4);
    Qi.push(5);
    Qi.push(6);
    Qi.push(7);
    Qi.push(8);
    Qi.push(9);
    Qi.push(10);
 
    while(!Qi.empty()){
        cout<<Qi.front()<<endl;
        Qi.pop();
    }
    

}
