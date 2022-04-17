

#include<iostream.h>
#include<conio.h>

int fib(int n)
{
	
/////             n=5           //////

if (n==1)	
	return 1;
else
if (n==2)
return 1;
else
return fib(n-1) + fib(n-2);

}
int main ()
{
	cout<<fib(5)<<"\n";
	return 0;
}
