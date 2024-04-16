#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node * first;
void display();
void revlist();

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
    revlist();
}
void revlist(){
    struct node *current,*previous,*next;
    next = first;
    current = first;
    previous = NULL;
    while (next!=NULL)
    {
    next = next->link;
    current->link = previous;
    previous = current;
    current = next;
    }
    first = previous;
display();
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