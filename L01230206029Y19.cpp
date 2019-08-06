#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TRUE 1
#define FALSE 0
void mat_display(int row,int col,double *A);
void mat_trnsps(int row,int col,double *C,double *B);
void mat_inverse(int row,int col,double *A,double *INV);
void is_mat_equal(int row,int col,double *B,double *INV);

int main()
{
	
	int i,j,row,col;
	double *A,*B,*C,*INV;
	
		#define A(I,J) (*(A +(I)*col + (J)))
		#define B(I,J) (*(B +(I)*col + (J)))
		#define C(I,J) (*(C +(I)*col + (J)))
		#define INV(I,J) (*(INV +(I)*col + (J)))
		printf("\nNumber of rows of the matrices:\n");
		scanf("%d",&row);
		printf("\nNumber of columns of the matrices:\n");
		scanf("%d",&col);
		
	if(row!=col){
		while(1){
			printf("\nPlease enter same number of rows and columns for square matrix!\n");
			printf("\nNumber of rows of the matrices:\n");
			scanf("%d",&row);
			printf("\nNumber of columns of the matrices:\n");
			scanf("%d",&col);

			if(row!=col){
				continue;
			}
			else
				break;
		}
		
	}
	A = (double*)malloc(row*col*sizeof(double));
	B = (double*)malloc(row*col*sizeof(double));
	C = (double*)malloc(row*col*sizeof(double));
	INV = (double*)malloc(row*col*sizeof(double));
	
	printf("\nEnter elements of the matrix:\n");
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				scanf("%lf",&A(i,j));
			}
		}
	
		printf("\nContent of the matrix\n");
		mat_display(row,col,A);
		
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				C(i,j) = A(i,j);
				
	mat_inverse(row,col,A,INV);
	printf("\nInverse of the matrix\n");
	mat_display(row,col,INV);
		

		mat_trnsps(row,col,C,B);
		printf("\n Transpose of the matrix:\n");
		mat_display(col,row,B);

	is_mat_equal(row,col,B,INV);
	
	free(A);
	#undef A 
	free(B);
	#undef B
	free(C);
	#undef C
	free(INV);
	#undef INV
	
	
}


#define A(I,J) (*(A + (I)*col +(J)))
#define B(I,J) (*(B +(I)*row + (J)))
#define C(I,J) (*(C +(I)*col + (J)))
#define INV(I,J) (*(INV +(I)*col + (J)))
void mat_display(int row,int col,double *A)
{
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++)
			printf("%.5lf ",A(i,j));	//
		printf("\n");
	}
}

void mat_trnsps(int row,int col,double *C,double *B)
{
	int i,j;
	
	for(i=0;i<col;i++){
		for(j=0;j<row;j++){
			B(i,j)=C(j,i);
		}
	}
}

void mat_inverse(int row,int col,double *A,double *INV)
{
	int i,j,k;
	double localVariable;
	
	for(i=0;i<row;i++)									
		for(j=0;j<col;j++)	{
			if(i==j)										
				INV(i,j)=1;									
			else											
				INV(i,j)=0;
		}						
	
	for(i=0;i<row;i++){
		localVariable=A(i,i);
		
		for(j=0;j<col;j++){
			A(i,j)/=localVariable;
			INV(i,j)/=localVariable;
		}
		for(k=0;k<row;k++){
			localVariable = A(k,i);	
			for(j=0;j<col;j++){
			if(k==i)
				break;
			A(k,j) -= A(i,j)*localVariable;
			INV(k,j) -= INV(i,j)*localVariable;
			}
		}
	}
}
void mat_multiply(int m,int n,int q,double *A,double *B,double *C)
{
	
		int i,j,k;
		double sum=0.0;
		for(i=0;i<m;i++)
			for(j=0;j<q;j++)
				for(k=0;k<n;k++)
					{
						sum=A(i,k)*B(k,j);
					}
						C(i,j)=sum;
}

void is_mat_equal(int row,int col,double *B,double *INV)
{
	int i,j,x;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			if(B(i,j)==INV(i,j))
			x=TRUE;
			else
			x=FALSE;
	if(x==1)
		printf("\nThis is an orthogonal matrix\n");
	if(x==0)
		printf("\nThis is not an orthogonal matrix\n");
}

#undef A
#undef C
#undef B
#undef INV
