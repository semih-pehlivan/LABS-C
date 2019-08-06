#include <stdio.h>
#include <math.h>
double f_exact(double V,double L,double R,double t)
{
	return((V/R)*(1-exp((-R/L)*t)));
}
double f(double V,double L,double R,double i)
{
	return((V/L)-((R*i)/L));
}
double f_euler(double(*f)(double,double,double,double),double x0,double y0,double h, double xlast,double V,double L,double R)
{
	
	for(;x0<=xlast-h/10;x0+=h)
	{
		y0=y0+h*f(V,L,R,y0);	
	}
	return y0;
}
double error (double ex, double app)
{
	double y=0;
	y=fabs((ex-app)/ex)*100;
	return y;	
}


int main()
{
	double V,L,R,t,h,x0,y0,res;
	double exact=0.453;
	printf("enter V,L,R,t: \n");
	 scanf("%lf %lf %lf %lf",&V,&L,&R,&t);
	 printf("exact=%lf\n",f_exact(V,L,R,t));
	
	printf("enter x0,y0,h: \n");
	 scanf("%lf %lf %lf",&x0,&y0,&h);
	 printf("euler=%lf\n",f_euler(f,x0,y0,h,t,V,L,R));
	res=f_euler(f,x0,y0,h,t,V,L,R);
	printf("error=%lf\n",error(exact,res));

	
	
}
