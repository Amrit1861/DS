#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node*next;
};

void circularLinkedlistTraversal(struct Node*head){
    struct Node*ptr=head;
    do{
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);

    return head;
}

struct Node*insertInBetween(struct Node*head,int data,int index){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node*q=head;
    int i=0;
    while(i!=index-1){
        q=q->next;
        i++;
    }
    ptr->data=data;
    ptr->next=q->next;
    q->next=ptr;
    return head;
}

int main(){
    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*second=(struct Node*)malloc(sizeof(struct Node));
    struct Node*third=(struct Node*)malloc(sizeof(struct Node));
    struct Node*fourth=(struct Node*)malloc(sizeof(struct Node));
    struct Node*fifth=(struct Node*)malloc(sizeof(struct Node));
    struct Node*sixth=(struct Node*)malloc(sizeof(struct Node));




    head->data=7;
    head->next=second;

    second->data=71;
    second->next=third;

    third->data=72;
    third->next=fourth;

    fourth->data=721;
    fourth->next=fifth;

    fifth->data=7122;
    fifth->next=sixth;

    sixth->data=72112;
    sixth->next=head;

    circularLinkedlistTraversal(head);
    head=insertInBetween(head,671,2);
    printf("after inserting in between\n");
    circularLinkedlistTraversal(head);

    return 0;


}
