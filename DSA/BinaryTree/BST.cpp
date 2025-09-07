// left node value < root node value < right node value
// search TC : O(Height)
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    
    Node(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insert(Node* root, int val){
    if(!root){
        return new Node(val);
    }
    
    if(root->val > val){
        root->left = insert(root->left,val);
    }else{
        root->right = insert(root->right,val);
    }
    
    return root;
}

bool search(Node*root,int val){
    if(!root)   return 0;
    
    if(root->val == val)    return 1;
    else if(root->val > val)    return search(root->left,val);
    else return search(root->right, val);
}

void inorder(Node* root){
    if(!root)   return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
};

int inorderSuccessor(Node* root){
    while(root->left){
        root = root->left;
    }
    return root->val;
};

Node* deleteNode(Node* root, int val){
    if(root->val > val){
        root->left = deleteNode(root->left, val);
    }
    else if(root->val<val){
        root->right = deleteNode(root->right, val);
    }
    else{
        //case 1
        if(!root->left && !root->right)  return nullptr;
        
        //case 2
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        
        // case 3
        int is = inorderSuccessor(root->right);//inorder successor
        root->val = is;
        root->right = deleteNode(root->right, is);
    }
    
    return root;
};

void printInRange(Node* root,int x, int y){
    if(!root)   return;
    
    if(root->val >= x && root->val <= y){
        printInRange(root->left,x,y);
        cout<<root->val<<" ";
        printInRange(root->right,x,y);
    }else if(root->val >= y){
        printInRange(root->left,x,y);
    }else{
        printInRange(root->right,x,y);
    }
}

void print(vector<int> v){
    for(int i=0;i<v.size(); i++){
        cout << v[i]<<" ";
    }
    cout<<endl;
}

void rootToleaf(Node* root,vector<int> &v){
    if(!root) return;
    v.push_back(root->val);
    if(!root->left && !root->right){
         print(v);
    }
    if(root->left){
        rootToleaf(root->left,v);
    }
    if(root->right){
        rootToleaf(root->right,v);
    }
    v.pop_back();
}

int main(){
    vector<int> v = {5, 1, 3, 4, 2, 7, 10, 11 , 65, 8, 70, 0};
    Node* root = nullptr;
    for(int i=0; i<v.size(); i++){
        root = insert(root,v[i]);
    }
    
    inorder(root);
    cout<<endl;
    vector<int> path;
    rootToleaf(root,path);
    
    // printInRange(root,2,10);
    
    // deleteNode(root, 7);
    
    // inorder(root);
    // cout<<endl;
    // int s = 10;
    // cout<<"Search "<<s<<" : "<<search(root,s);

    return 0;
}