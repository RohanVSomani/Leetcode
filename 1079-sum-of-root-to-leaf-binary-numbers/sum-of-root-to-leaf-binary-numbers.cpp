/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void allBinaries(TreeNode* root,string curr,vector<string> &v){
        if(root == NULL)
        return;
        curr = curr + to_string(root->val);
        if(root->left == NULL && root->right==NULL){
            v.push_back(curr);
            return;
        }
        
        allBinaries(root->left,curr,v);
        allBinaries(root->right,curr,v);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string> v;
        allBinaries(root,"",v);
        int sum=0;
        for(string s:v){
            int num = stoi(s,nullptr,2);
            sum+=num;
        }
        return sum;
    }
};