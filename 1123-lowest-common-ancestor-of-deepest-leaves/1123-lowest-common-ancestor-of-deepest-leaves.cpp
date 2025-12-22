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
private:
    TreeNode* lca(TreeNode* root,TreeNode* a,TreeNode* b){
        if(!root) return root;
        if(root == a || root == b) return root;
        TreeNode* lft = lca(root->left,a,b);
        TreeNode* ryt = lca(root->right,a,b);
        // if(ryt && lft){
        //    return root; 
        // }
        if(!lft) return ryt;
        if(!ryt) return lft;
        return root;
    } 
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*>t;
        while(!q.empty()){
            int si = q.size();
            vector<TreeNode*>temp;
            // cout<<si<<endl;
            for(int i=0;i<si;i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(i == 0 || si-1 == i) temp.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            // cout<<temp.size()<<endl;
            t = temp;
        }
        if(t.size() == 1) return t[0];
        cout<<t[0]->val<<" "<<t[1]->val;
        return lca(root,t[0],t[1]);
    }
};