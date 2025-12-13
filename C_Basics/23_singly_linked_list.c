#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
}Node;

Node *head = NULL;

//insert a node

void insert_node(){

    int val = 0;

    printf("Enter the node value to be inserted val =");
    scanf("%d",&val);

    Node *newnode = (Node *)(malloc(sizeof(Node)));

    newnode->val = val;
    newnode->next = NULL;

    if(head==NULL){

        head = newnode;

    }else{
        Node *temp = head;

        while(temp->next!=NULL)
            temp = temp->next;
        
        temp->next = newnode;

    }

    return;

}

void delete_first(){

    if(head==NULL){

        printf("List is empty");
    }
    else{

        Node * temp = head;
        head = head->next;
        free(temp);
    }

    return;
}



void print_node(){

    Node *temp = head;

    while(temp->next!=NULL){
        printf("%d\t",temp->val);
        temp = temp->next;
    }

    printf("%d\t",temp->val);
    printf("\n");

    return;
}


int main (){

    insert_node();



    insert_node();

    insert_node();
    insert_node();

    print_node();

    delete_first();

    print_node();

    return 0;
}
