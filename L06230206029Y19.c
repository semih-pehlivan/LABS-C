#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double x)
{ 
	return(exp(-x*x));
}
double f4(double x)
{
	return((16*x*x*x*x-48*x*x+12)*exp(-x*x));
}
double simpson(double(*f)(double),double start,double end,double n)
{
double result,h,x;
int i;
h=(end-start)/n;
result=f(start);
for(i=1;i<=n;i++)
{
	x=start+i*h;
	result+=4*f(x-h/2)+2*f(x);
}
	result-=f(end);
	return(h*result/6);
}
double adapt(double(*f)(double),double start,double end,double n,double tolerance)
{
	double val,check;
	val=simpson(f,start,end,2*n);
	check=fabs((simpson(f,start,end,n)-val)/val);
	if(check > tolerance)
	
		val=adapt(f,start,(start+end)/2.0,n,tolerance)+adapt(f,(start+end)/2.0,end,n,tolerance);
		return(val);
}
double findmax(double(*f4)(double),double start,double end)
{
		double y,h;
		double i;
		h=(end-start)/1000;
		for(i=start;i<=end;i+=h)
		{
			if(fabs(f4(i))<fabs(f4(i+h)))
				y=fabs(f4(i+h));			
		}
		return(y);
}
double error (double(*f4)(double),double start, double end,double n,double x)
{
	double y=0;
	y=(pow((end-start),5))/(180*pow(n,4))*f4(x);
	return y;	
}
int main()
{
	
	double start,end,n,tolerance,x,start1,end1;
	printf("Enter start,end,n,tolerance\n");
	scanf("%lf %lf %lf %lf",&start,&end,&n,&tolerance);
	printf("Enter x input\n");
	scanf("%lf",&x);
	printf("Result of  f(x)=%lf\n",f(x));
	printf("Result of f4(x)=%lf\n",f4(x));
	printf("Result with Simpson=%lf\n",simpson(f,start,end,n));
	printf("Enter start1,end1\n");
	scanf("%lf %lf",&start1,&end1);
	printf("findmax=%lf\n",findmax(f4,start1,end1));
	printf("error=%lf\n",error(f4,0,1,4,x));
	printf("adapt=%lf\n",adapt(f,start,end,n,tolerance));
}
