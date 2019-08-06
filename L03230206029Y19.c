#include<stdio.h> 
#include<math.h> 
double deter(double[20][20], double);
void cofactors(double[20][20],double);
void inverse(double[20][20], double[20][20], double);
main() {
 double a[20][20], n, d,fac[20][20];
 int i, j;
 printf("Enter the order of the matrix:\n");
 scanf("%lf", &n);
 printf("Enter the elemnts into the matrix:\n");
 for (i = 0; i < n; i++) {
  for (j = 0; j < n; j++) {
   scanf("%lf", &a[i][j]);
  }
 }
 d = deter(a, n);
 printf("\nTHE DETERMINANT IS=%2f ", d);
 if (d == 0)
  printf("\nMATRIX IS NOT INVERSIBLE\n");
 else
  cofactors(a,n);
}

double deter(double a[20][20], double k) {
	 double s = 1, det = 0, b[20][20];
 	int i, j, m, n, c;
 	if (k == 1) 
	 {
 	 return (a[0][0]);
 	} else {
 		 det = 0;
  	for (c = 0; c < k; c++) {
   		m = 0;
  		 n = 0;
   		for (i = 0; i < k; i++) 
		   {
    		for (j = 0; j < k; j++)
			 {
     			b[i][j] = 0;
     			if (i != 0 && j != c) 
				 {
      				b[m][n] = a[i][j];
      				if (n < (k - 2))
       				n++;
      				else 
					  {
       					n = 0;
       					m++;
      					}
     			}				
    		}
   		}
   det = det + s * (a[0][c] * deter(b, k - 1));
   s = -1 * s;
  }
 }
 return (det);
}
void cofactors(double num[20][20], double f) {
 double b[20][20], fac[20][20];
 	int p, q, m, n, i, j;
 		for (q = 0; q < f; q++) 
		 {
  			for (p = 0; p < f; p++)
			   {
   			m = 0;
   			n = 0;
   				for (i = 0; i < f; i++)
				    {
    				for (j = 0; j < f; j++) 
					{
     					b[i][j] = 0;
     					if (i != q && j != p)
						  {
      						b[m][n] = num[i][j];
      						if (n < (f - 2))
      						 n++;
      						else 
							{
       							n = 0;
       							m++;
      						}
     				}
   				 }			
   			}
   			fac[q][p] = pow(-1, q + p) * deter(b, f - 1);
  }
 }
  inverse(num, fac, f);
}
void inverse(double num[20][20],double fac[20][20], double r)
{
 int i, j;
 double b[20][20], inv[20][20], d;
 for (i = 0; i < r; i++) {
  for (j = 0; j < r; j++) {
   b[i][j] = fac[j][i];
  }
 }
 d = deter(num, r);
 inv[i][j] = 0;
 for (i = 0; i < r; i++) {
  for (j = 0; j < r; j++) {
   inv[i][j] = b[i][j] / d;
  }
 }
 printf("\nTHE INVERSE OF THE MATRIX:\n");
 for (i = 0; i < r; i++) {
  for (j = 0; j < r; j++) {
   printf("\t%2lf ", inv[i][j]);
  }
  printf("\n");
 }
}
