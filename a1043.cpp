#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <set>
#include <stack>
#include <queue>

//cin用多了超市

using namespace std;
const long int maxn=10010;
const int inf=0x7fffffff;
int count1[maxn]={0};

//自己模拟一遍pre，post travel
struct node{
    int val;
    node *left,* right;
};
node *create (int val,node *root){
    if (root==NULL){
        root=new node;
        root->val=val;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    if (val>=root->val){
        root->right=create(val,root->right);
    } else{
        root->left=create(val,root->left);
    }
    return root;
}
//前序遍历
vector<int> pre1;
void preOrder1(node *root){
    if (root==NULL){
        return;
    }
    pre1.push_back(root->val);
    preOrder1(root->left);
    preOrder1(root->right);
}
vector<int> pre2;
void preOrder2(node *root){
    if (root==NULL){
        return;
    }
    pre2.push_back(root->val);
    preOrder2(root->right);
    preOrder2(root->left);
}
vector<int> post1;
void postOrder1(node *root){
    if (root==NULL){
        return;
    }
    postOrder1(root->left);
    postOrder1(root->right);
    post1.push_back(root->val);
}
vector<int> post2;
void postOrder2(node *root){
    if (root==NULL){
        return;
    }
    postOrder2(root->right);
    postOrder2(root->left);
    post2.push_back(root->val);
}

int main() {
    int n;
    cin>>n;
    node *root=NULL;
    vector<int> origin;
    for (int i = 0; i < n; ++i) {
        int m;
        cin>>m;
        origin.push_back(m);

        root=create(m,root);
    }
    preOrder1(root);
    preOrder2(root);
    if (pre1==origin){
        printf("YES\n");
        postOrder1(root);
        for (int i = 0; i < post1.size(); ++i) {
            if (i==0){
                printf("%d",post1[i]);
            } else{
                printf(" %d",post1[i]);

            }
        }

    } else if (pre2==origin){
        printf("YES\n");
        postOrder2(root);
        for (int i = 0; i < post2.size(); ++i) {
            if (i==0){
                printf("%d",post2[i]);
            } else{
                printf(" %d",post2[i]);

            }
        }
    } else{
        printf("NO");
    }

    return 0;
}
