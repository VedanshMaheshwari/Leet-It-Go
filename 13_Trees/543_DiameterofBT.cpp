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
    int depth(TreeNode *root){
        if(root == NULL){
            return 0;
        }

        int l = depth(root->left);
        int r = depth(root->right);

        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;  
        }

        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);

        int combo = depth(root->left) + depth(root->right);

        return max(combo, max(left, right));
    }
};

//Optimized approach -> N

class Solution {
public:
    int depth(TreeNode *node , int &d){

        if(!node){
            return 0;
        }

        int l = depth(node->left, d);
        int r = depth(node->right, d);

        d = max(d, r+l);

        return 1 + max(l,r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        depth(root, d);
        return d;
    }
};
