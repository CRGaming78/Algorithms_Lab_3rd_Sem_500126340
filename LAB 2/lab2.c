#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void printList(struct Node* head){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

struct Node* reverseList(struct Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct Node* rest=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return rest;
}

void deleteList(struct Node* head){
    if(head==NULL){
        return;
    }
    deleteList(head->next);
    free(head);
}

struct Node* deleteAtPosition(struct Node* head, int position){
    if(head==NULL){
        return NULL;
    }
    if(position==0){
        struct Node* temp=head->next;
        free(head);
        return temp;
    }
    head->next=deleteAtPosition(head->next,position-1);
    return head;
}

struct Node* appendNode(struct Node* head,int data){
    if(head==NULL){
        return createNode(data);
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=createNode(data);
    return head;
}

int main(){
    struct Node* head=NULL;
    int choice,data,position;
    while(1){
        printf("\nMenu:\n");
        printf("1. Append to Linked List\n");
        printf("2. Print Linked List\n");
        printf("3. Reverse Linked List\n");
        printf("4. Delete Entire Linked List\n");
        printf("5. Delete Node at Position\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to append: ");
                scanf("%d",&data);
                head=appendNode(head,data);
                break;
            case 2:
                printf("Linked List:\n");
                printList(head);
                break;
            case 3:
                head=reverseList(head);
                printf("Linked List reversed.\n");
                break;
            case 4:
                deleteList(head);
                head=NULL;
                printf("Linked List deleted.\n");
                break;
            case 5:
                printf("Enter position to delete (0-based index): ");
                scanf("%d",&position);
                head=deleteAtPosition(head,position);
                printf("Node at position %d deleted.\n",position);
                break;
            case 6:
                deleteList(head);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}