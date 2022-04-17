


double <b>integral</b>(double (*f)(double),double a,double b,int n)

{
            double s=0,dx=fabs((b-a)/n);
            for(double i=0;i<n;i++)
                        s+=(f(a+i*dx)+f(a+(i+1)*dx));
            return dx*s/2;
}  