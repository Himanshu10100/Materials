#include <bits/stdc++.h>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int i=-1;

TreeNode* BuildTree(vector<int>& arr) {
    ++i;

    // Assuming -1 means NULL
    if (i >= arr.size() || arr[i] == -1){
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[i]);
    root->left = BuildTree(arr);
    root->right = BuildTree(arr);

    return root;
}

void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void levelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(!curr){
            // cout<<endl;
            if(q.empty()){
                break;
            }
            else{
                q.push(nullptr);
            }
        }else{
            cout<<curr->val<<" ";
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}

int countNodes(TreeNode* root){
    if(!root)   return 0;
    
    int leftCnt = countNodes(root->left);
    int rightCnt = countNodes(root->right);
    
    return leftCnt+rightCnt+1;
}

int sumOfNodes(TreeNode* root){
    if(!root)   return 0;
    
    int leftCnt = sumOfNodes(root->left);
    int rightCnt = sumOfNodes(root->right);
    
    return leftCnt+rightCnt+root->val;
}

int heightOfTree(TreeNode* root){
    if(!root)   return 0;
    
    int leftCnt = heightOfTree(root->left);
    int rightCnt = heightOfTree(root->right);
    
    return max(leftCnt,rightCnt)+1;
}

int diameterOn2(TreeNode* root){
    if(!root) return 0;
    
    int dia1 = diameterOn2(root->left);
    int dia2 = diameterOn2(root->right);
    int dia3 = heightOfTree(root->left) + heightOfTree(root->right) + 1;
    
    return max(max(dia1,dia2),dia3);
}

struct TreeInfo{
    int ht;
    int mx;
    
    TreeInfo(int ht,int mx){
        this->ht = ht;
        this->mx = mx;
    }
};

TreeInfo* diameterOn(TreeNode* root){
    if(!root){
        return new TreeInfo(0,0);
    }
    
    TreeInfo* dia1 = diameterOn(root->left);
    TreeInfo* dia2 = diameterOn(root->right);
    int dia3 = dia1->ht + dia2->ht + 1;
    int maxH = max(dia1->ht, dia2->ht) + 1;
    
    int mx = max(max(dia1->mx,dia2->mx),dia3);
    return new TreeInfo(maxH,mx);
}

int main() {
    vector<int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    TreeNode* root = BuildTree(arr);

    levelOrder(root);
    cout << endl;
    
    cout<<"Node count : "<<countNodes(root)<<endl;
    
    cout<<"Node Sum : "<<sumOfNodes(root)<<endl;

    cout<<"Tree height : "<<heightOfTree(root)<<endl;
    
    cout<<"Tree Diameter On2 : "<<diameterOn2(root)<<endl;
    
    cout<<"Tree Diameter On : "<<diameterOn(root)->mx<<endl;
    
    return 0;
}
