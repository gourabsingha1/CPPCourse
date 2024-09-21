#include <bits/stdc++.h>
using namespace std;
#define lcou(v) {for(auto &x : v) cout<<x<<" "; cout<<endl;}

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



/*
      1
   /     \
  2       7
   \     /
    3   8
     \
      4
       \
        5
         \
          6
*/


// **** Preorder Traversal ****
vector<int> preorderTraversal(TreeNode *root) {
    if(!root) {
        return {};
    }

    vector<int> res;
    stack<TreeNode*> st;
    st.push(root);
    while(st.size()) {
        root = st.top();
        st.pop();
        res.push_back(root->val);
        if(root->right) {
            st.push(root->right);
        }
        if(root->left) {
            st.push(root->left);
        }
    }
    return res;
}



// **** Postorder Traversal (Reverse of preorder) ****
vector<int> postorderTraversal(TreeNode *root) {
    if(!root) {
        return {};
    }

    vector<int> res;
    stack<TreeNode*> st;
    st.push(root);
    while(st.size()) {
        root = st.top();
        st.pop();
        res.push_back(root->val);
        if(root->right) {
            st.push(root->right);
        }
        if(root->left) {
            st.push(root->left);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}



// **** Inorder Traversal ****
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode *curr = root;
    while(1) {
        if(curr) {
            st.push(curr);
            curr = curr->left;
        }
        else{
            if(!st.size()) {
                break;
            }
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
    }
    return res;
}



// **** Postorder Traversal (Didn't Understand) ****
vector<int> postorderTraversalII(TreeNode *root) {
    if(root == NULL){
        return {};
    }
    
    vector<int> res;
    stack<TreeNode*> st;
    while(st.size() || root) {
        if(root) {
            st.push(root); // st = 1,2,3,4,5,6
            root = root->left; // root = NULL
        }
        else {
            TreeNode *temp = st.top()->right; // NULL
            if(temp == NULL) {
                temp = st.top(); // 6
                st.pop();
                res.push_back(temp->val); // res = 6

                while(st.size() && temp == st.top()->right) { // 6 = 6
                    temp = st.top(); // 5
                    st.pop();
                    res.push_back(temp->val); // res = 6,5
                }
            }
            else {
                root = temp;
            }
        }
    }
    return res;
}



// **** Levelorder Traversal (push NULL after pushing left and right subtree) ****
/* 
         1
       /   \
      2     3
     / \   / \
    4   5 6   7

    Queue = 1,NULL             Res = 0
    q.top() = 1                Res = 0
    Queue = NULL,2,3           Res = 1
    q.top() = NULL, !Q.empty() Res = 1
    Queue = 2,3,NULL           Res = 1
    q.top() = 2                Res = 1
    Queue = 3,NULL,4,5         Res = 1,2
    q.top() = 3                Res = 1,2
    Queue = NULL,4,5,6,7       Res = 1,2,3
    Q.top() = NULL, !Q.empty() Res = 1,2,3
    Queue = 4,5,6,7,NULL       Res = 1,2,3,4,5,6,7
    Q.top() = NULL, Q.empty()  Res = 1,2,3,4,5,6,7
    Q is empty here

*/
vector<int> levelorderTraversal(TreeNode *root) {
    if(!root) {
        return {};
    }

    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()) {
        int size = q.size();
        while(size--) {
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }
    return res;
}



// **** Build Tree from Level Order ****
TreeNode *buildTreeLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root = new TreeNode(data);
    q.push(root);
    while(!q.empty()) {
        TreeNode *temp = q.front();
        q.pop();
        cout<<"Enter left node for : "<<temp->val<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1) {
            temp->left = new TreeNode(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for : "<<temp->val<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1) {
            temp->right = new TreeNode(rightData);
            q.push(temp->right);
        }
    }
    return root;
}



// **** Tree to Graph ****
unordered_map<int, vector<int>> adj;

void treeToGraph(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()) {
        auto node = q.front();
        q.pop();
        if(node->left) {
            adj[node->val].push_back(node->left->val);
            adj[node->left->val].push_back(node->val);
            q.push(node->left);
        }
        if(node->right) {
            adj[node->val].push_back(node->right->val);
            adj[node->right->val].push_back(node->val);
            q.push(node->right);
        }
    }   
}


// Morris Traversal
// If no left, print it
// Else, cur = root, go to extreme right
// If NULL, then connect that pointer to cur, then cur = cur->left
// Else cut the thread, print and cur = cur->right

vector<int> morrisInorder(TreeNode* root) {
    vector<int> inorder;
    TreeNode *cur = root;
    while(cur) {
        if(cur->left == NULL) {
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else {
            TreeNode *prev = cur->left;
            while(prev->right && prev->right != cur) {
                prev = prev->right;
            }

            if(prev->right == NULL) {
                prev->right = cur;
                cur = cur->left;
            }
            else {
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return inorder;
}

vector<int> morrisPreorder(TreeNode* root) {
    vector<int> preorder;
    TreeNode *cur = root;
    while(cur) {
        if(cur->left == NULL) {
            preorder.push_back(cur->val);
            cur = cur->right;
        }
        else {
            TreeNode *prev = cur->left;
            while(prev->right && prev->right != cur) {
                prev = prev->right;
            }

            if(prev->right == NULL) {
                prev->right = cur;
                preorder.push_back(cur->val);
                cur = cur->left;
            }
            else {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
}


int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout<<"Preorder = "; lcou(preorderTraversal(root)); // 1,2,4,5,3,6,7
    // cout<<"Inorder = "; Inorder(root); // 4,2,5,1,6,3,7
    cout<<"Postorder = "; lcou(postorderTraversal(root)); // 4,5,2,6,7,3,1
    cout<<"Postorder II = "; lcou(postorderTraversalII(root)); // 4,5,2,6,7,3,1
    cout<<"Levelorder = "; lcou(levelorderTraversal(root)); // 1,2,3,4,5,6,7

    cout<<"buildTreeLevelOrder";
    lcou(levelorderTraversal(buildTreeLevelOrder(NULL)));

    return 0;
}