/*
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
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        queue<pair<Node*,int>> q;
        q.push({root,1});
        while(!q.empty()){
            auto elem = q.front();
            Node* curr = elem.first;
            q.pop();
            if(!q.empty()){
            auto nextelem = q.front();
            if(elem.second == nextelem.second)
            elem.first->next=nextelem.first;
            else
            elem.first->next=NULL;
            }
            else
            elem.first->next=NULL;
            if(curr->left!=NULL)
            q.push({curr->left,elem.second+1});
            if(curr->right!=NULL)
            q.push({curr->right,elem.second+1});
        }
        return root;
    }
};