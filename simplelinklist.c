#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node * first;
void display();
void insert_start();
void insert_end();
void insert_mid();
void delete_start();
void delete_end();
void delete_mid();

void main(){
    char ch;
    int choice;
    struct node *prev,*curent;
    curent =(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the 1st info of the starting of the linked list: ");
    scanf("%d",&curent->info);
    first = curent;
    curent->link = NULL;
    do{
        prev= (struct node *) malloc(sizeof(struct node));
        printf("\nenter the next node's info: ");
        scanf("%d",&prev->info);
        curent->link = prev;
        curent= prev;
        printf( "\ndo you want to add more elements? y/n :");
        scanf (" %c", &ch);} while (ch=='y');
        curent-> link= NULL;
    if (ch== 'n'){
        display();
    }
    while(choice != 8){
        printf("\n1.Insert at begining \n2.Insert at End\n3.Insert at desired location\n4.Delete from Starting\n5.Delete from End\n6.Delete from desired location\n7.Dispaly contents\n8.Exit");
        printf("\nEnter the choice : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
            insert_start();
            break;
            case 2:
            insert_end();
            break;
            case 3:
            insert_mid();
            break;
            case 4:
            delete_start();
            break;
            case 5:
            delete_end();
            break;
            case 6:
            delete_mid();
            break;
            case 7:
            display();
            break;

    }
}
}
void display(){
struct node *disp;
 disp = first;
 printf("\n");
 while(disp != NULL){
    printf("%d    ",disp->info);
    disp = disp->link;
 }
}
void insert_start(){
    struct node *pt1;
    pt1 = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value : ");
    scanf( "%d" , &pt1->info );
    pt1->link = first;
    first = pt1;
    display();

}
void insert_end(){
    struct node *pt2, *cp2;
    pt2 = (struct node*) malloc( sizeof( struct node ) );
    cp2=first;
    printf("\nEnter the value: ");
    scanf("%d",&pt2->info);
    while(cp2->link != NULL)
        cp2 = cp2->link;
        pt2->link = NULL;
        cp2->link = pt2;
        display();

}
void insert_mid(){
    struct  node *pt3 ,*cp3 ;
    int data, new_data;
    printf("\nEnter the data after which you want a new node:");
    scanf("%d",&data);
    printf("Enter the new node data :");
    scanf("%d",&new_data);
    pt3= (struct node *)malloc(sizeof(struct node)); 
    pt3->info=new_data;            
    cp3=first;           
    while( (cp3->info != data)){ 
        cp3=cp3->link;
        } 
        pt3->link = cp3->link;   
        cp3->link= pt3;    
    display();
}
void delete_start(){
    struct node *pt4;
    pt4 = first;
    first = first->link;
    free(pt4);
    display();

}
void delete_end(){
    struct node *pt5,*cp5;
    pt5 = first;
    while(pt5->link !=NULL){
        cp5 = pt5;
        pt5 = pt5->link;
    }
    cp5->link = NULL;
    free(pt5);
    display();
}
void delete_mid(){
    struct node *pt6,*cp6;
    int data;
    printf("\nEnter the data of the node to be deleted: ");
    scanf("%d",&data);
    pt6 = first;
    while(pt6->info != data){
        cp6 = pt6;
        pt6 = pt6->link;
        }
    cp6->link = pt6->link;
    free(pt6);
    display();
}