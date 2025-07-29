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
void in(TreeNode* root,vector<int>&ino)
{
    if(!root) return;
    in(root->left,ino);
    ino.push_back(root->val);
    in(root->right,ino);
}
int l = 0; 
void set(TreeNode* root,vector<int>&suf)
{
    if(!root) return;
    set(root->left,suf);
    root->val = suf[l++];
    set(root->right,suf);
}
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>ino;
        in(root,ino);
        int n = ino.size();
        vector<int>suf(n);
        suf[n-1] = ino[n-1];
        // for(auto a:ino)
        // {
        //     cout<<a<<" ";
        // }
        cout<<endl;
        for(int i=n-2;i>=0;i--)
        {
            suf[i] = suf[i+1] + ino[i];
        }
        // reverse(suf.begin(),suf.end());
        set(root,suf);
        return root;
    }
};