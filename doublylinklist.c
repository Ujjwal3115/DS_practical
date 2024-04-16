#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node {
    struct node *lpt;
    int info;
    struct node *rpt;
};
struct node *first;
void display();
void rwd_tra();
void ins_beg();
void ins_end();
void ins_mid();
void del_beg();
void del_end();
void del_mid();
void main(){
    char ch;
    int choice;
    struct node *prev,*curent;
    curent =(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the 1st info of the starting of the linked list: ");
    scanf("%d",&curent->info);
    first = curent;
    curent->lpt = NULL;
    curent->rpt = NULL;
    do{
        prev= (struct node *) malloc(sizeof(struct node));
        printf("\nenter the next node's info: ");
        scanf("%d",&prev->info);
        curent->rpt = prev;
        prev->lpt = curent;
        curent= prev;
        printf( "\ndo you want to add more elements? y/n :");
        scanf (" %c", &ch);} while (ch=='y');
        curent->rpt= NULL;
    if (ch== 'n'){
        display();
    }
    while(choice != 9){
        printf("\n1.Forward Traversal(display)\n2.Reverse Traversal\n3.Insert at begining \n4.Insert at End\n5.Insert at desired location\n6.Delete from Starting\n7.Delete from End\n8.Delete from desired location\n9.Exit");
        printf("\nEnter the choice : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
            display();
            break;
            case 2:
            rwd_tra();
            break;
            case 3:
            ins_beg();
            break;
            case 4:
            ins_end();
            break;
            case 5:
            ins_mid();
            break;
            case 6:
            del_beg();
            break;
            case 7:
            del_end();
            break;
            case 8:
            del_mid();
            break;
        }
    }
}
void display(){
    struct node *disp;
    disp = first;
    while(disp!=NULL){
        printf("%d   ",disp->info);
        disp = disp -> rpt;
    }
}
void rwd_tra(){
    struct node *rev = first;
    while(rev->rpt!=NULL)
    {
        rev = rev->rpt;
    }
    while(rev!=NULL){
        printf("%d   ",rev->info);
        rev = rev->lpt;
    }
}
void ins_beg(){
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value: ");
    scanf("%d",&ptr->info);
    ptr->lpt = NULL;
    ptr->rpt = first;
    first->lpt = ptr;
    first= ptr;
    display();
}
void ins_end(){
    struct node *ptr,*cpt;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value: ");
    scanf("%d",&ptr->info);
    cpt = first;
    while(cpt->rpt != NULL){
        cpt = cpt->rpt;
        }
    ptr->lpt = cpt;
    cpt->rpt  = ptr;
    ptr->rpt = NULL;
    display();
}
void ins_mid(){
struct  node *ptr ,*cpt ;
    int data, new_data;
    printf("\nEnter the data after which you want a new node:");
    scanf("%d",&data);
    printf("Enter the new node data :");
    scanf("%d",&new_data);  
    ptr= (struct node *)malloc(sizeof(struct node));   
    ptr->info = new_data;  
    cpt=first;
    while(cpt->info != data){
        cpt = cpt->rpt;
    }
    ptr->lpt = cpt;
    cpt->rpt->lpt = ptr;
    ptr->rpt = cpt->rpt;
    cpt->rpt = ptr;
    display();
}
void del_beg(){
    struct node *ptr;
    ptr = first;
    first = ptr->rpt;
    first->lpt = NULL;
    free(ptr);
    display();
}
void del_end(){
    struct node *ptr;
    ptr = first;
    while(ptr->rpt != NULL)
        ptr = ptr->rpt;
        ptr->lpt->rpt = NULL;
        free(ptr);
        display();
}
void del_mid(){
    struct node *cpt;
    int data;
    printf("\nEnter the data of the node to be deleted: ");
    scanf("%d",&data);
    cpt = first;
    while(cpt->info!=data)
    {
        cpt = cpt->rpt;
    }
    cpt->lpt->rpt = cpt->rpt;
    cpt->rpt->lpt = cpt->lpt;
    free(cpt);
    display();
}