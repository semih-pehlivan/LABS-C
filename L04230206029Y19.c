#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
double f(double i)
{
	return((1/(1+exp(i)))-(0.5));
}
double f_prime(double i)
{
	return(-(exp(i)/(1+exp(i)*(1+exp(i)))));
}
double f_prime_prime(double i)
{
	return(((-exp(i)*pow(1+exp(i),2))-(-exp(i)*2*(1+exp(i))*exp(i)))/(pow(1+exp(i),4)));
}
double cyclic_func(double i,double(*f)(double i),double(*f_prime)(double i))
{
	return(((2*i)-((f(i))/(f_prime(i)))));
}
double cyclic_func_prime(double i,double(*f)(double i),double(*f_prime)(double i),double(*f_prime_prime)(double i))
{
	return((2-((pow(f_prime(i),2)-(f(i)*f_prime_prime(i)))/(pow(f_prime(i),2)))));
}

double newton(double(*f)(double i),double(*f_prime)(double i),double dmin,double epsilon,double t,int *error)
{	double i;
	double deltax;
	deltax=2*epsilon;
	*error=FALSE;
		while(!(*error)&&fabs(deltax)>epsilon)
		
			if(fabs(f_prime(i))>dmin)
			 {
			 deltax=(f(i)/f_prime(i));
				t=exp(i)-deltax;}
				else
				*error=TRUE;
		
	
		return t;
}
int find_interval(
double (*f)(double), 
double start_point,  
double end_point,    
double stepsize,     
double *left_int,    
double *right_int,
double i)   
{
	int found_root = TRUE; 														/* initialize indicator */
	*left_int=start_point;        												/* initialize interval */
	*right_int=*left_int+stepsize;
	while( *left_int < end_point && f(i)*f(i)>0.0 )
	{			                                                                /* Search interval */
		*left_int = *right_int;
		*right_int += stepsize;
		if(*right_int > end_point)
			*right_int = end_point;
	}
	                                                                            /* Check if root found */
	if(f(i)*f(i)>0.0)	
	found_root = FALSE;

	return(found_root);
}
main()
{	double i,t;
	double initial_boundary, final_boundary,xleft,xright,root,x,stepsize,epsilon;
	int error;
	printf ("\nPlease enter the input initial boundary: ");
	scanf("%lf",&initial_boundary);
	printf ("\nPlease enter the input final boundary: ");
	scanf("%lf",&final_boundary);
	printf ("\nPlease enter the stepsize: ");
	scanf("%lf",&stepsize);
	printf ("\nPlease enter the convergence tolerance: ");
	scanf("%lf",&epsilon);
	printf ("\nPlease enter the input: ");
	scanf("%lf",&x);
	
	if(find_interval(f,initial_boundary,final_boundary,stepsize,&xleft,&xright,i) )       					
		printf("interval is [%.12f, %.12f]\n", xleft, xright);	
	else
		printf("There is no interval\n");
		while(xleft<final_boundary)
	{										                        
		if( find_interval(f,xright,final_boundary,stepsize,&xleft,&xright,i) )
			printf("interval is [%.12f, %.12f]\n", xleft, xright);
																	
	}
	printf("%lf",newton(f,f_prime,x, epsilon,t,&error));
	
}
