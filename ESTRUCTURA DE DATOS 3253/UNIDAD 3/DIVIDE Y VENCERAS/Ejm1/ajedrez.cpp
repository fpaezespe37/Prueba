#include<stdio.h>

main()
{
int i,j,a,b,m;
char tabla[8][8];
printf("Ingrese la fila:n");
scanf("%d",&a);
printf("Ingrese la columna:n");
scanf("%d",&b);
printf("nn+--+--+--+--+--+--+--+--+n");
for(i=0;i<8;i++) 
{
m=a-i;
for(j=1;j<=8;j++)
{

if (a==i && b==j)
{
[i-1][j-1] ='A';
}
else
{
[i-1][j-1] =' ';
}
printf("| %c",[i-1][j-1] );
if (j+m==b || j-m==b)
{
printf("*");
}
else
{
printf(" ");
}
}

printf("|n");
printf("+--+--+--+--+--+--+--+--+n");
}
getc(stdin);
getc(stdin);
