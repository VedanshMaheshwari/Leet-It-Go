#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:

    void post(TreeNode* root, vector<int> &ans){
        if(root == nullptr){
            return;
        }
        post(root->left,ans);
        post(root->right,ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        post(root,ans);
        return ans;

    }

};

//Postorder Traversal using Iteration - 2 STACKS

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL ){
            return ans;
        }

        stack <TreeNode *> s1;
        stack <TreeNode *> s2;
        s1.push(root);

        while(!s1.empty()){
           
            root = s1.top();
            s1.pop();
            s2.push(root);

            if(root->left != NULL){
                s1.push(root->left);
            }

            if(root->right != NULL){
                s1.push(root->right);
            }
        }

        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }

        return ans;
    }
};