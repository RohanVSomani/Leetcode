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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> elem;
        unordered_map<int,int> childs; 
        unordered_set<int> allelem;
        for(vector<int> desc: descriptions){
            int p = desc[0];
            int c = desc[1];
            int lorr = desc[2];
            if(elem.find(p)==elem.end())
                elem[p] = new TreeNode(p);
            if(elem.find(c)==elem.end())
                elem[c] = new TreeNode(c);
            if(lorr==1)
                elem[p]->left = elem[c];
            else
            elem[p]->right = elem[c];
            childs[c]++;
            allelem.insert(p);
            allelem.insert(p);
        }
        for(int n : allelem){
            if(childs[n]<=0)
                return elem[n];
        }
        return 0;
    }
};