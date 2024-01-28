#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*prev;
    struct Node*next;
};

void doubleLinkedListTraversal(struct Node*ptr){
    while(ptr!=NULL){
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node*insertAtEnd(struct Node*head,int data){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node*q=head;
    while(q->next!=NULL){
        q=q->next;
    }
    ptr->data=data;
    ptr->next=NULL;
    q->next=ptr;
    ptr->prev=q;
    return head;
}

int main(){
    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*second=(struct Node*)malloc(sizeof(struct Node));
    struct Node*third=(struct Node*)malloc(sizeof(struct Node));
    struct Node*fourth=(struct Node*)malloc(sizeof(struct Node));
    struct Node*fifth=(struct Node*)malloc(sizeof(struct Node));

    head->data=78;
    head->prev=NULL;
    head->next=second;


    second->data=781;
    second->prev=head;
    second->next=third;


    third->data=7832;
    third->prev=second;
    third->next=fourth;

    fourth->data=5677;
    fourth->prev=third;
    fourth->next=fifth;

    fifth->data=7373;
    fifth->prev=fourth;
    fifth->next=NULL;

    doubleLinkedListTraversal(head);
    head=insertAtEnd(head,89);
    printf("after inserting at end\n");
    doubleLinkedListTraversal(head);
    return 0;

}
