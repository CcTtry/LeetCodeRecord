#include<cstdio>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*队列实现层序遍历*/
void printTree(TreeNode* arr[])
{
    queue<TreeNode*> rel; //定义一个队列，数据类型是二叉树指针，不要仅是int！！不然无法遍历
    rel.push(arr[1]);
    while (!rel.empty())
    {
        TreeNode* front = rel.front();
        printf("%d \n", front->val);
        rel.pop();                  //删除最前面的节点
        if (front->left != nullptr) //判断最前面的左节点是否为空，不是则放入队列
            rel.push(front->left);  
        if (front->right != nullptr)//判断最前面的右节点是否为空，不是则放入队列
            rel.push(front->right);
    }
}

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

int main(){

    TreeNode* s_arr[12];
    s_arr[0] = new TreeNode(0);
    s_arr[1] = new TreeNode(1);
    s_arr[2] = new TreeNode(2);
    s_arr[3] = new TreeNode(3);
    s_arr[4] = new TreeNode(4);
    s_arr[5] = new TreeNode(5);

    s_arr[6] = new TreeNode(6);
    s_arr[7] = new TreeNode(7);
    s_arr[8] = new TreeNode(8);
    s_arr[9] = new TreeNode(9);
    s_arr[10] = new TreeNode(10);
    s_arr[11] = new TreeNode(11);

    s_arr[1]->left = s_arr[2];  //   0
    s_arr[1]->right = s_arr[3]; //  1  2
    s_arr[2]->left = s_arr[4];  // 3     5
    s_arr[2]->right = s_arr[5];  //4

    s_arr[3]->left = s_arr[6];  //   0
    s_arr[3]->right = s_arr[7]; //  1  2
    
    s_arr[4]->left = s_arr[8];  // 3     5
    s_arr[4]->right = s_arr[9]; //
    
    s_arr[5]->left = s_arr[10];  //4
    s_arr[5]->right = s_arr[11];  //4
    
    printTree(s_arr);
    
    for (int i = 0; i < 6; i++)
        delete s_arr[i];
    return 0;
}