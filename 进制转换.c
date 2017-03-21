#include<stdio.h>
int Bianary(int no, int a[]);
int Octal(int no, int a[]);
int Hexadecimal(int no, int a[]);
void print(int a[], int);
int main()
{
	int i;
	int a[10]={0};
	i=Bianary(7, a);
	print(a, i);
	i=Octal(9, a);
	i=Hexadecimal(15, a);
	print(a, i);
}
int Bianary(int no, int a[])
{
	int i = 0;
	while (no != 0)
	{
		a[i] = no % 2;
		no = no / 2;
		i++;
	}
	return i-1;
}
int Octal(int no,  int a[])
{
	int i = 0;
	while (no != 0)
	{
		a[i] = no % 8;
		no = no / 8;
		i++;
	}
	return i-1;
}
int Hexadecimal(int no, int a[])
{
	int i = 0;
	while (no != 0)
	{
		a[i] = no % 16;
		no = no / 16;
		i++;
	}
	return i-1;
}
void print(int a[], int i)
{
	for (int j = i; j > -1; j--)
	{
		switch (a[j])
		{
		case 10:printf("A"); break;
		case 11:printf("B"); break;
		case 12:printf("C"); break;
		case 13:printf("D"); break;
		case 14:printf("E"); break;
		case 15:printf("F"); break;;
		default:printf("%d", a[j]);

		

		}
	}
}
