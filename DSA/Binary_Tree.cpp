#include <bits/stdc++.h>
using namespace std;
#define lcou(v) {for(auto &x : v) cout<<x<<" "; nl}



// **** Create a tree node ****
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int n){
        val = n;
        left = NULL;
        right = NULL;
    }

};



// **** Build tree ****
TreeNode *buildTree(TreeNode *root){
    int data;
    cin>>data;
    root = new TreeNode(data);
    
    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in the left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in the right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}



// **** Preorder Traversal (root-> left -> right) ****
/*
         1
       /   \
      2     3
     / \   / \
    4   5 6   7

    Preorder = 1, 2, 4, 5, 3, 6, 7
*/
void Preorder(TreeNode *root){
    if(root == NULL){
        return;
    }
    cout<<root->val<<" ";
    Preorder(root->left);
    Preorder(root->right);
}



// **** Inorder Traversal (left -> root -> right) ****
/*
         1
       /   \
      2     3
     / \   / \
    4   5 6   7

    Inorder = 4, 2, 5, 1, 6, 3, 7
*/
void Inorder(TreeNode *root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
}



// **** Postorder Traversal (left -> right -> root) ****
/*
         1
       /   \
      2     3
     / \   / \
    4   5 6   7

    Postorder = 4, 5, 2, 6, 7, 3, 1
*/
void Postorder(TreeNode *root){
    if(root == NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->val<<" ";
}



// **** Search an element in inorder to build a tree ****
int search(vector<int> &inorder, int start, int end, int curr){
    for (int i = start; i <= end; i++)
    {
        if(inorder[i] == curr){
            return i;
        }
    }
    return -1;
}



// **** Build tree from preorder and inorder ****
TreeNode *buildTreePreIn(vector<int> &preorder, vector<int> &inorder, int start, int end){
    static int ind = 0;
    if(start > end){ // base case
        return NULL;
    }

    int curr = preorder[ind];
    ind++;
    TreeNode *node = new TreeNode(curr);
    if(start == end){ // there is no left/right subtree
        return node;
    }
    
    int pos = search(inorder, start, end, curr);
    node->left = buildTreePreIn(preorder, inorder, start, pos-1); // build the left subtree first
    node->right = buildTreePreIn(preorder, inorder, pos+1, end); // then build the right subtree

    return node; // final node
}



// **** Build tree from postorder and inorder ****
TreeNode *buildTreePostIn(vector<int> &postorder, vector<int> &inorder, int start, int end){
    static int ind = postorder.size() - 1;
    if(start > end){ // base case
        return NULL;
    }

    int curr = postorder[ind];
    ind--;
    TreeNode *node = new TreeNode(curr);
    if(start == end){ // there is no left/right subtree
        return node;
    }

    int pos = search(inorder, start, end, curr);
    node->right = buildTreePostIn(postorder, inorder, pos+1, end); // build the right subtree first
    node->left = buildTreePostIn(postorder, inorder, start, pos-1); // then build the left subtree
    
    return node;
};



// **** Height of a Binary Tree ****
bool res = 1;
int minDepth(TreeNode *root){
    if(root == NULL){
        return 0;
    }

    int lHeight = minDepth(root->left);
    int rHeight = minDepth(root->right);
    if(abs(lHeight - rHeight) > 1){
        res = 0;
    }

    return max(lHeight, rHeight) + 1;
}



// **** Diameter of a Binary Tree ****
int diameter(TreeNode* root, int &res) {
    // base condition
    if(!root){
        return 0;
    }

    // hypothesis
    int lHeight = diameter(root->left, res);
    int rHeight = diameter(root->right, res);
    
    // induction
    int temp = max(lHeight, rHeight) + 1; // the current node may not be the root of the diameter
    int ans = max(temp, lHeight + rHeight + 1); // the current node may be the root of the diameter
    res = max(res, ans); // finding the correct diamter
    
    return temp; // to let parent node also calculate the diameter 
}



// **** Maximum Path Sum Non Leaf ****
int maxPathSumNLeaf(TreeNode* root, int &res){
    // base condition
    if(!root){
        return 0;
    }

    // hypothesis
    int lHeight = max(0, maxPathSumNLeaf(root->left, res));
    int rHeight = max(0, maxPathSumNLeaf(root->right, res));
    
    // induction
    int temp = max(lHeight, rHeight) + root->val; // assuming root->val to be +ve. parent node will check whether or not
    int ans = max(temp, lHeight + rHeight + root->val); // current node may be the root of the path which gives the maximum sum
    res = max(res, ans);
    return temp;
}



// **** Validate Binary Search Tree ****
bool checkBST(TreeNode* root, long long int left, long long int right){
    // base condition
    if(!root){
        return 1;
    }
    if(!(left < (long long int)root->val && (long long int)root->val < right)){
        return 0;
    }

    // hypothesis
    bool checkLeft = checkBST(root->left, left, root->val); // check -inf < 1 < 5
    bool checkRight = checkBST(root->right, root->val, right); // check 5 < 7 < inf

    return checkLeft && checkRight; // if one of them is false, ans is false
}




// DO ATLEAST 50 RECURSION PROBLEMS FIRST
// DO ATLEAST 50 RECURSION PROBLEMS FIRST
// DO ATLEAST 50 RECURSION PROBLEMS FIRST
// DO ATLEAST 50 RECURSION PROBLEMS FIRST
// DO ATLEAST 50 RECURSION PROBLEMS FIRST




// ----------- main() ------------
int main(){

    TreeNode *root = new TreeNode(1); // creating a tree with root
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    /*
         1
       /   \
      2     3

    */
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    /*
         1
       /   \
      2     3
     / \
    4   5

    */
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    /*
         1
       /   \
      2     3
     / \   / \
    4   5 6   7

    */


    cout<<"Preorder = "; Preorder(root); // 1,2,4,5,3,6,7
    cout<<endl;
    cout<<"Inorder = "; Inorder(root); // 4,2,5,1,6,3,7
    cout<<endl;
    cout<<"Postorder = "; Postorder(root); // 4,5,2,6,7,3,1
    cout<<endl;

    TreeNode *head = new TreeNode(0);
    cout<<"buildTree"<<endl; Preorder(buildTree(head));
    cout<<endl;


    vector<int> preorder = {1, 2, 4, 3, 5};
    vector<int> inorder = {4, 2, 1, 5, 3};
    vector<int> postorder = {4, 2, 5, 3, 1};
    TreeNode *headPreIn = buildTreePreIn(preorder, inorder, 0, 4);
    cout<<"buildTreePreIn = "; Inorder(headPreIn);
    cout<<endl;
    TreeNode *headPostIn = buildTreePostIn(postorder, inorder, 0, 4);
    cout<<"buildTreePostIn = "; Inorder(headPostIn);
    cout<<endl;

    
    int dia = 0;
    diameter(root, dia);
    cout<<"Diameter = "<<dia<<endl;


    return 0;
}