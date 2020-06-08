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
const int maxn=10010;
int n;
struct node{
    int val;
    node *left,*right;

};
int post[maxn];
int inorder[maxn];
node *create(int left,int right,int left1,int right1){
    if (left>right){
        return NULL;
    }
    int val=post[right];
    int num=left;
    for (int i = left1; i <=right1 ; ++i) {
        if (val==inorder[i]){
            num=i;
            break;
        }
    }
    node *root=new node;
    root->val=val;
    int len=num-left1;
    root->left=create(left,left+len-1,left1,num-1);
    root->right=create(left+len,right-1,num+1,right1);
    return root;


}
int num=0;
void bfs(node *root){
    if (root==NULL){
        return;
    }
    queue<node *> queue;
    queue.push(root);

    while (!queue.empty()){
        node *cur=queue.front();
        queue.pop();
        printf("%d",cur->val);
        num++;
        if (num<n){
            printf(" ");
        }
        if (cur->left!=NULL){
            queue.push(cur->left);
        }
        if (cur->right!=NULL){
            queue.push(cur->right);
        }

    }
}
int main() {

    cin>>n;

    for (int i = 0; i < n; ++i) {
       scanf("%d",&post[i]);
    }
    for (int j = 0; j < n; ++j) {
        scanf("%d",&inorder[j]);
    }
    node *root=create(0,n-1,0,n-1);
    bfs(root);


    return 0;
}
