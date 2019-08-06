#include <stdio.h>
#include <stdlib.h>


struct node { int data;struct node *next;};

typedef struct node * list;

list insert_node(list head,int value){

list temp,linked;
linked=(struct node *)malloc(sizeof(struct node));
temp=head;
while(temp->next!=NULL)
temp=temp->next;

linked->data=value;
linked->next=NULL;
temp->next=linked;

return(head);
}
list remove_node(list head,int value){
	list temp;
	list prev;
	temp=head;
	int flag=0;
	while(temp->next!=NULL && flag==0){
		if(temp->data==value)
			flag=1;
			else{
				prev=temp;
				temp=temp->next;
			}
		
	}
	if(flag==1)
	prev->next=temp->next;
	return head;
	}
void display(list head) {

while(head->next!=NULL){

	printf("%s\t",head->data);	
	head=head->next;
}
}
void search_value(list head,int value) {
	list temp;
	int flag=0;
	temp=head;
	while(temp->next!=NULL){
		if(temp->data==value){
			flag=1;
		}
		else
		temp=temp->next;
		
		if(flag=1){
			printf("The number %d is found :",value);
		}
		else
		printf("The number %d is not on there:",value);
		
	}
}
void bubblesort(list head){
	
	int temp;
	while(head->next!=NULL){
	
	if( (head->data)>(head->next->data) ){
     temp=head->next->data;
	 head->next->data=head->data;
	 head->data=temp;	
	}
	head=head->next;

}
}
	
main() {
	
	list head,head2;
	head=(struct node*)malloc(sizeof(node));
    head2=(struct node*)malloc(sizeof(node));
int a=1;
	int select=0,valuesel;
	int selectrem,number;
	head->next=NULL;
	head2->next=NULL;
	
	while(a==1){
			printf("choose an option  \n 1.Insert \n 2.Remove \n 3.Search \n 4.Sort \n 5.Exit \n ");
		scanf("%d",&select);
	if(select==1) {
		printf("Insert The Number: \n");
		scanf("%d",&valuesel);
		head=insert_node(head,valuesel);
		display(head);
	}
	if(select==2){
		printf("Enter the Remove number you want : \n");
		scanf("%d",&selectrem);
		
	   head=remove_node(head,selectrem);
	   display(head);
	}
	if(select==3) {
		printf("Enter the number you want to search \n");
		scanf("%d",&number);
		search_value(head,number);
	}
	if(select==4){
		bubblesort(head);
		display(head);
		
	}
	if(select==5)
	a=0;	
}
}



