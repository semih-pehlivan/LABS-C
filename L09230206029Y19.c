#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 30



typedef struct list {
    char c_node[N];
    char courses[N];
    struct list *sonraki;
} liste;
liste *ilk = NULL, *son = NULL, *yeni, *gecici;

const char *c[N];
const char *d[N];

/*struct Node 
{
	char c_node[N];
	char courses[N];
	struct Node *next;
}*/

void insert_front(int c_select)
{
	
    yeni = (liste *) malloc(sizeof (liste));
	strcpy(yeni->c_node,c[c_select-1]);
	strcpy(yeni->courses,d[c_select-1]);
    yeni->sonraki = NULL;
 
    if (ilk == NULL) { 
        ilk = yeni;
        son = ilk;
    } else { 
        son->sonraki = yeni;
        son = son->sonraki;
    }
}
void insert_rear(int c_select)
{
	
    yeni = (liste *) malloc(sizeof (liste));
    strcpy(yeni->c_node,c[c_select-1]);
	strcpy(yeni->courses,d[c_select-1]);
    yeni->sonraki = NULL;
 
    if (son == NULL) { 
        son = yeni;
        ilk = son;
    } else { 
        ilk->sonraki = yeni;
        ilk = ilk->sonraki;
    }
}
void print_cl() {
	gecici = ilk;
    while (gecici != NULL) {
        printf("%s\n", gecici->sonraki);
        gecici = gecici->sonraki;
 
    }
    
}



int main(){	

	c[0]="EE311";				d[0]="Digital Electronics";				
	c[1]="EE411";				d[1]="Fundamentals of Photonics";		
	c[2]="EE425";				d[2]="Microwave Engineering";		
	c[3]="EE443";				d[3]="Embedded Systems";			
	c[4]="EE455";				d[4]="Mobile Communication";			
	c[5]="EE461";				d[5]="Nonlinear Control Systems";		
	int i;
	
	int oSel, CSel;
     while(1){
		printf("\nChoose operation:\n");
		printf("1. Add a course at the front of the CourseList\n");
		printf("2. Add a course at the end of the CourseList\n");
		scanf("%d",&oSel);
		printf("Select a course:\n");
		for(i=0; i<6; i++){
		    printf("%d. %s-%s\n", i+1, c[i], d[i]);
		}
		scanf("%d", &CSel);
	
		switch(oSel){
		case 1:
			insert_front(CSel-1);
			break;
		case 2:
			insert_rear(CSel-1);
			break;
		default:
			printf("Please select either insert_front or insert_rear option (1 or 2)");
			break;		
		}
		printf("\nThe updated CourseList is:\n");
		print_cl();
	}
    return 0;
}
