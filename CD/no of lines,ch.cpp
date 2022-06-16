#include<stdio.h>
int main()
{  
FILE *fp;
char f[50];
char ch;
int c=0,w=0,l=0;

printf("enter the file name\n");
gets(f);


fp=fopen(f,"r");

if(fp)
{
 while((ch=getc(fp))!=EOF)
{
if(ch!=' ' &&ch!='\n')
{  c++;
}
if(ch==' ')
{ w++;
}
if(ch=='\n')
{ l++;
}

}
if(c>0)
{ 
w++;
} }
else
{ printf("failed to open");

}
printf("lines=%d",l);
printf("word=%d",w);
printf("character=%d",c);

return 0;


}
