#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

struct BST_Node {
    int val;
    BST_Node *left, *right;
};

BST_Node* Insert(BST_Node *root, int val) {
    BST_Node *newNode = new BST_Node();
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL) {root = newNode; return root;}
    else {
        BST_Node *currNode = root;
        while(1) {
            if(val < currNode->val) {
                if(currNode->left != NULL) currNode = currNode->left;
                else {currNode->left = newNode; return root;}
            } else {
                if(currNode->right != NULL) currNode = currNode->right;
                else {currNode->right = newNode; return root;}
            } 
        }
    }
}

void PreOrder(BST_Node *node) {
    if(node == NULL) return;
    cout<<node->val<<" ";
    PreOrder(node->left);
    PreOrder(node->right);
}

void InOrder(BST_Node *node) {
    if(node == NULL) return;
    InOrder(node->left);
    cout<<node->val<<" ";
    InOrder(node->right);
}

void PostOrder(BST_Node *node) {
    if(node == NULL) return;
    PostOrder(node->left);
    PostOrder(node->right);
    cout<<node->val<<" ";
}

int Search(BST_Node *root, int val) {
    BST_Node *currNode = root;
    while(currNode != NULL) {
        if(val < currNode->val) {
            if(currNode->left != NULL) currNode = currNode->left;
            else return 0;
        } else if(val > currNode->val) {
            if(currNode->right != NULL) currNode = currNode->right;
            else return 0;
        } else return 1;
    }
    return 0;
}

void solve() {
    BST_Node *root = NULL;
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        root = Insert(root, x);
    }
    cout<<"Preorder : ";
    PreOrder(root); cout<<endl;
    cout<<"Inorder : ";
    InOrder(root); cout<<endl;
    cout<<"Postorder : ";
    PostOrder(root); cout<<endl;

    int q; cin>>q;
    while(q--) {
        int x; cin>>x;
        if(Search(root, x)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 5
     13 5 10 3 1
     3
     5
     2
     1
o/p: Preorder : 13 5 3 1 10 
     Inorder : 1 3 5 10 13 
     Postorder : 1 3 10 5 13 
     YES
     NO
     YES
*/ 