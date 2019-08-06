#include <stdio.h>
#include <math.h>
double f(double R,double L,double C,double t,double q,double q0)
{

	return (exp((-R*t)/(2*L))*cos(sqrt(1/(L*C)-(R/(2*L)*R/(2*L)))*t)-(q/q0));
	
}
double bisection(double (*f)(double,double,double,double,double,double),double xstart,double xend,double stepsize,double L,double C,double t,double q,double q0)
{
	double y;
	for(y=(xstart+xend)/2.0; fabs(xstart-y)>stepsize; y=(xstart+xend)/2.0)
{
	if(f(xstart,L,C,t,q,q0)*f(y,L,C,t,q,q0)<=0.0)
		{
			xend=y;
		}
			else
			xstart=y;
}
				return y;	
	
}
main()
{
	double R,L,C,t,q,q0;
	printf("R,L,C,t,q,q0\n");
	scanf("%lf %lf %lf %lf %lf %lf",&R,&L,&C,&t,&q,&q0);
	double xstart,xend,upperbound;
	
	double eps=0.01;
	printf("Enter any interval for finding the roots:\n");			
	scanf("%lf %lf",&xstart,&xend);
	printf("%lf\n",f(R,L,C,t,q,q0));
	upperbound=(2*L*(sqrt(1/(L*C))));
    if(upperbound>=0)
	{
	printf("Result with bisection:%lf\n",bisection(f,xstart,xend,eps,L,C,t,q,q0));
	printf("Upperbound:%lf\n",upperbound);
	}
	else
	printf("Upperbound do not supply condition \n");
	printf("Upperbound:%lf\n",upperbound);
	printf("Enter a new interval\n");
	scanf("%lf %lf",&xstart,&xend);
	printf("Result with bisection:%lf\n",bisection(f,xstart,xend,eps,L,C,t,q,q0));
	
}
