

#include <iostream.h>
#include<stdio.h>
#include<conio.h>

void maghloob(int x){
	  if (x)
	  {
    printf("%d",x%10);
	 maghloob(x/10);
     }
}

void main(void)
{
     int x;
	  clrscr();
	  printf("======= SAMAVi =========");
	  printf("\nPlease enter a five-digit number==>:");
	  scanf("%d",&x);
	  while (x%10==0)
	  x=x/10;

	  printf("\n===product by SAMAVi===>>>>");
	  maghloob(x);
	  getch();
}
