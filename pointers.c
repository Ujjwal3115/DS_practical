/*#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node * first;

void display();

void main()
{
struct node *ptr,*cpt;
char Ch;
ptr = (struct node*)malloc(sizeof(struct node));
printf("Enter the values: ");
scanf("%d ",&ptr->info);
ptr->link  = NULL;
first = ptr;
do{
    cpt = (struct node*)malloc(sizeof(struct node));
    printf("Enter the next value for cpt:");
        scanf(" %d", &cpt->info );

    ptr -> link= cpt;
    ptr = cpt;
    printf("\n Do you want to continue? Y/N : ");
    Ch = getch();
}while((Ch == 'y')||(Ch=='Y'));
    
ptr->link = NULL;
printf("\n The list is :");
display();
}
void display(){
 struct node *disp;
 disp = first;
 while(disp != NULL){
    printf("%d    ",disp->info);
    disp = disp->link;
 }
}
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link; };
    struct node * first;  /* pointer to the first element  */
void display_struct();
void insert_after_given_data();
void insert_end_of_list();
void insert_starting_of_list();
void delete_starting_node_of_list();
void delete_ending_node_of_list();
void delete_any_node_of_given_data();
void main(){
    char ch , choice='1';
    struct node *prev,*curent;
    curent =(struct node*)malloc(sizeof(struct node));
    printf("Enter the 1st info of the starting of the linked list: ");
    scanf("%d",&curent->info);
    first = curent;
    curent->link = NULL;
    do{
        prev= (struct node *) malloc(sizeof(struct node)); /* create new node and point it to the previous one*/
        printf("\nenter the next node's info: ");
        scanf("%d",&prev->info);
        curent->link = prev; /* link the new node with previous one*/
        curent= prev;
        printf( "\ndo you want to add more elements? y/n :");
        scanf (" %c", &ch);} while (ch=='y');
        curent-> link= NULL; /* point to the last element jiska link is NULL */
    if (ch== 'n'){
        display_struct();
    }
    while (choice != '0'){
    printf("\n\nchoice -> 1. insert at starting \n2. insert at end \n3. insert after the given data \n");
    printf("4. delete the first node \n5. delete the last node \n6. delete the node of given data");
    printf(" \n and 0. to end\n choice = ");
    choice  = getchar();
    switch (choice) {
    case  '1':
    insert_starting_of_list();
    break;
    case '2':
    insert_end_of_list();
    break;
    case  '3':
    insert_after_given_data();
    break;
    case '4':
    delete_starting_node_of_list();
    break; 
    case '5':
    delete_ending_node_of_list();
    break;
    case  '6':
    delete_any_node_of_given_data();
    break;
    }}
}

void display_struct(){
    struct node *ptr;
    ptr = first;
    printf("\nthe linked list is: ");
    while(ptr != NULL) {   /* until end of list */
    printf("%d  ", ptr->info);     /* show info */
        ptr = ptr -> link;    }   /* movement to next item in list */
    printf("\n");
} 
void insert_starting_of_list(){
    struct node *new_node;
    new_node= (struct node *)malloc(sizeof(struct node));
    printf("\nenter info of new node: ");
    scanf("%d", &new_node->info );
    new_node->link = first;       /* link to 2nd node */
    first = new_node;      /* make new_node the start of the list*/
    display_struct();
}
void insert_end_of_list(){
    struct node  *new_node, *ptr;
    new_node= (struct node *)malloc(sizeof(struct node));
    ptr = first;         /* point to the first node */
    printf("\nenter info of new node: ");
    scanf("%d",&new_node->info);
    while (ptr->link != NULL){
        ptr= ptr->link; }     /*  till the end of the list */
        new_node->link = NULL;
        ptr->link= new_node;     /*  put it at the end */
    display_struct();
}
void insert_after_given_data(){ 
    struct  node *prev_node ,*new_node ;
    int data, new_data;
    printf("\nenter the given  data :\n");
    scanf("%d",&data);
    printf("\n enter the new node data :");
    scanf("%d",&new_data);
    new_node= (struct node *)malloc(sizeof(struct node)); /*new node*/
    new_node->info=new_data;             /*pehle fill the empty dibba of new node */
    prev_node=first;            /*initializes to first*/
    while( (prev_node->info != data)){ 
        prev_node=prev_node->link;} /*wo node jiske baad humne node add karni hai */
        new_node->link = prev_node->link;    /*linking new node with the right wala node*/
        prev_node->link= new_node;      /* linking previous node with new node */
    display_struct();
}
void delete_starting_node_of_list(){
    struct node *ptr;
    ptr=first;
    first=first->link;     /* overwriting the add of of 1st node to the 2nd node making it the new starting node */
    free(ptr);             /* free memory occupied by deleted node */
    display_struct();
}
void delete_ending_node_of_list() {
    struct node *last_node, *prev_node;
    last_node=first;
    while (last_node->link != NULL){
        prev_node=last_node; /* movement to the 2nd last node */ 
        last_node= last_node->link; /* move along the list until we find the end*/
    }
    prev_node->link = NULL;    /* make the link of the node before the last one as NULL */
    free(last_node);              /* free memory occupied by deleted node */
    display_struct();
}
void  delete_any_node_of_given_data() {
    struct node  *del_node, *prev_node;
    int data;
    printf("\nEnter the data which you want to delete: ");
    scanf("%d", &data);
    del_node = first;
    while(del_node->info != data){
        prev_node = del_node;    /* keep track of previous node */
        del_node = del_node->link; } /* go on till we find the required node or reach NULL */
    prev_node->link = del_node->link; /* replaces the address of the deleted node*/
    free(del_node);         /* deallocates the info of the deleted node*/
    display_struct();
}
