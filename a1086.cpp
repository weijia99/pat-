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
int n;
int pre[maxn];
int in[maxn];
//建树
struct node{
    int val;
    node *left,*right;
};
node *create(int l1,int h1,int l2,int h2){
    if (l1>h1){
        return NULL;
    }
    node *root=new node;
    int val=pre[l1];
    int p=-1;
    for (int i = l2; i <=h2 ; ++i) {
        if (in[i]==val){
//            找到主根
            p=i;
            break;
        }
    }
    int leftlen=p-l2;
    root->val=val;
    root->left=create(l1+1,l1+leftlen,l2,p-1);
    root->right=create(l1+leftlen+1,h1,p+1,h2);
    return root;
}

int index3=0;
void post(node *root){
    if (root==NULL){
        return;
    }
    post(root->left);
    post(root->right);
    if (index3==0){
        printf("%d",root->val);
    } else{
        printf(" %d",root->val);

    }
    index3++;
}
int main() {

    cin>>n;
    stack<int> stack;

    int index1=0,index2=0;
    for (int i = 0; i < 2*n; ++i) {
        string a;
        cin>> a;

        if (a=="Push"){
            int temp;
            cin>>temp;
            stack.push(temp);
            pre[index1++]=temp;
        } else{
            int temp=stack.top();
            stack.pop();
            in[index2++]=temp;
        }
    }
    node *root=create(0,n-1,0,n-1);
    post(root);
    return 0;
}
