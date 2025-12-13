#include<stdio.h>
#include<stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;
    struct Node *prev;

}Node;

Node *head = NULL;

//insert
void insert(){

    int val;

    printf("Enter the node value to be inserted\n");
    scanf("%d",&val);

    Node *newnode = (Node *)(malloc(sizeof(Node)));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;

    Node *temp = head;

    if (head == NULL) {  // empty list
        head = newnode;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }

    return;
}

void display(){

    Node * temp = head;
    if(head==NULL){

        printf("List is empty\n");
    }
    else{
        while(temp->next!=NULL){

            printf("%d\n",temp->data);
            temp = temp->next;
        }

        printf("%d\n",temp->data);
        printf("\n");

    }
    
    return;
}

int main(){

    for (int i=0;i<4; i++){
        insert();
    }
    display();

    return 0;
}