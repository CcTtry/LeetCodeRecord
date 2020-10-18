## 树的基本操作


层次遍历代码

```C++

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    // 定义构造函数
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

```

先序遍历代码
```C++
// 定义一个二维vector 用来存储 每一层遍历的结果 
// 定义一个TreeNode节点的队列
// 每一层的节点数目大小size
// 获取每一个节点之后，将获取的节点加入到当前的vector之中
// 获取二叉树 每一层的节点数目大小 size


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>  res;
        queue<TreeNode*> que;
        if(root) que.push(root);
        while(!que.empty()){
            int size = que.size(); 
            vector<int> temp;
            for(int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(temp);

        }
        return res;
    }
};
```


中序遍历代码
```C++
```

后续遍历代码
```C++
```