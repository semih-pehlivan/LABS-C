#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50
struct Stack{
	char entry[SIZE];
	int count;
};

void init(struct Stack *s)
{
	s->count=0;
}
void push(struct Stack *s,char c)
{
	if(s->count<SIZE)
	{
		s->entry[s->count] = c;
		s->count++;
	}
	else
	{
	printf("Error-Attempt to psuh on full stack\n");
	exit(-1);
	}
}
char pop(struct Stack *s)
{
	if(s->count>0)
	{
		s->count--;
		return(s->entry[s->count]);
	}	
	else
	{
		printf("Error-Attempt to pop empty stack\n");
		exit(-2);
	}
} 
char peek(struct Stack *s)
{
	return s->entry[s->count];
}

int main()
{
	int choose;
	char word;
	struct Stack s;
	init(&s);
	while(1)
{
	
	printf("\n1-PUSH");
	printf("\n2-POP");
	printf("\n3-PEEK");
	printf("\nChoose Process");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
				
				printf("\n Enter a word");
				scanf(" %[^\n]s",&word);
				push(&s,word);
				printf("%s",s->entry);
				break;
		case 2:
				pop(&s);
				
				break;
		case 3:
			printf("\nTop Value => %s",peek(&s));
			break;
	}
}
	return 0;
}
