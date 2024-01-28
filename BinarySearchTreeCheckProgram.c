#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
};

struct node*createNode(int data){
    struct node*n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void inOrder(struct node*root){
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

int isBST(struct node*root){       ///inOrder Traversal arrangement for checking if given tree is BST.
    static struct node*prev=NULL;      ///// static keyword sets the value and prevents any change to happen throughout a recursive function.
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev =root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main(){
    struct node*p=createNode(3);
    struct node*p1=createNode(4);
    struct node*p2=createNode(5);

    p->left=p1;
    p->right=p2;

    printf("%d ",isBST(p));
    return 0;

}
