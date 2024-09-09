#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info; //4 BYTES
    struct node *next;  //2 BYTES
}node;  // 6 BYTES

node *start = NULL;
node *end = NULL;   // to create LinkList

//Create
node *create(node *start){
    int data;
    node *p = (node*)malloc(sizeof(node));  //memory allocation of 6 bytes

    if (p == NULL){
        printf("Not Enough Memory:\n");   //old days to prevent memory leak
        exit(1);
    }
    printf("Enter a number:");
    scanf("%d",&data);
    // working inside node:
        p->info = data;     // info field  (TO STORE DATA FOR CURRENT NODE)
        p->next = NULL;     // next field  (TO STORE THE ADDRESS OF NEXT NODE)
//  int a = 5;
    if(start ==NULL){       // only for 1st node
        start = end = p;
    }
    else{                   // for other nodes
        end->next = p;
        end = end->next;
    }
    return start;
}


//Display
void display(node *start){
    node *temp = start;
    while (temp->next != NULL){
        printf("%d  ",temp->info); // printing the data of current node
        temp = temp->next; //shifting to next node
    }
    printf("\n");
}

//alternate
void alter(node *start){
    node *temp = start;
    int count =1;

    while (temp->next != NULL){
        count;
        if(count % 2 != 0)  //
        {
        printf("%d  ",temp->info); // printing the data of current node
        }

        temp = temp->next; //shifting to next node
        count++;
    }
    printf("\n");
}

//insert_at_last
node *insert_last(node *start){
    int num;
    printf("Enter a number to be inserted at last:\n");
    scanf("%d",&num);

    node *p = (node*)malloc(sizeof(node));
    p->info = num;
    p->next = NULL;

    node *temp = start;

    while (temp->next != NULL)
        temp = temp->next;
        temp->next = p;

    return start;
    }

//insert_at_begining
node *insert_begin(node *start){
    int num;

    printf("Enter a number to be inserted at begining:\n");
    scanf("%d",&num);

    node *p = (node*)malloc(sizeof(node));
        p->info = num;
        p->next = start;
        start = p;

    return start;
}

//insert_before   
//insert_towards_left
node *insert_before(node *start){
    node *prev, *temp;
    int num,val;
    printf("Enter the value to insert before the node:\n");
    scanf("%d",&val);
    printf("Now, Enter a number to be inserted: \n");
    scanf("%d",&num);

    node *p = (node*)malloc(sizeof(node));
    p->info = num;
    p->next = start;
    temp = start;

    while(temp->info != val){
        prev = temp;
        temp = temp->next;
    }
    prev->next = p;
    p->next = temp;
    return start;
}

// insert_after
node *insert_after(node *start){
    node *far, *temp;
      int num,val;
    printf("Enter the value to insert after the node:\n");
    scanf("%d",&val);
    printf("Now, Enter a number to be inserted: \n");
    scanf("%d",&num);
    node *p =(node*)malloc(sizeof(node));
    p->info = num;
    p->next = start;
    temp = start;
    
    while (temp->info != val){
         far = temp;
        temp = temp->next;
    }
    far = temp->next;
    temp->next = p;
    p->next = far;
    return start;
}
//delete_at_beginning
node *delete_begin(node *start){
    node *p;
    p = start;
    start = p->next;
    free(p);
    return start;

}

//delete_at_last
node *delete_last(node *start){
    node* temp,*prev;
    temp = start;
    while (temp->next !=NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    return start;

}

//delete_defore
node *delete_before(node *start){
    node *prev,*temp;
    temp = start;
    int num;
    printf("Enter a data of that node to deleted :\n ");
    scanf("%d",&num);
    while (temp->info != num)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return(start);

}

//delete_after
node *delete_after(node *start){
    node *prev,*temp;
    prev = temp = start;
    int num;
    printf("Enter a data of that node to deleted after the node :\n ");
    scanf("%d",&num);
    while (prev->info != num)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return(start);

}

//delete_List
node *delete_list(node *start){
    node *temp;
    
    while(start != NULL){
        temp = start;
    start = start->next;
    free(temp);
    }
     return start; 
}


int main(){
    int ch=0;
    do{
        printf("\nLink List Menu\n");
        printf("1. Create:\t\t\t\t");
        printf("2. Display:\t\t\t\t");
        printf("3. Insert At Last\n");
        printf("4. Insert At Beginning\t\t\t");
        printf("5. Insert Before a given node\t\t");
        printf("6. Insert After a given node\n");
        printf("7. Delete At Beginning\t\t\t");
        printf("8. Delete at Last\t\t\t");
        printf("9. Delete at position\n");
        printf("10. Delete after the given node\t\t");
        printf("11. Delete Link List\t\t\t");
        printf("12. Sorting The Linked List\n\n ");

        printf("\n13. Exit\n");
        scanf("%d",&ch);

        switch (ch){
        case 1:
            start = create(start);
            break;

        case 2:
            printf("Created Link List: \n");
            display(start);
            break;

        case 3:
            start = insert_last(start);
            break;

        case 4:
            start = insert_begin(start);
            break;

        case 5:
            start = insert_before(start);
            break;

        case 6:
            start = insert_after(start);
            break;

        case 7:
            start = delete_begin(start);
            break;

        case 8:
            start = delete_last(start);
            break;

        case 9:
            start = delete_before(start);
            break;

        case 10:
            start = delete_after(start);
            break;
        
        case 11:
            printf("Linked List has been Deleted...\n\n");
            start = delete_list(start);
            break;
        
        case 12:
            printf("Alternate  Linked List:\n");
            alter(start);
            break;

        case 13:
            printf("Exiting... \n");
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }
    while (ch!=13);
    return 0;
}