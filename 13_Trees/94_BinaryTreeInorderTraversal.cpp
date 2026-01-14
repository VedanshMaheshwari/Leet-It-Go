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

    void inorder(TreeNode *root, vector<int> &ans){
        if(root == nullptr){
            return;
        }

        inorder(root->left,ans);

        ans.push_back(root->val);
        
        inorder(root->right,ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }   
};

//Iterative Approach

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode * node = root;
        
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                //node->left is null
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        } 
        return ans;
    }
};