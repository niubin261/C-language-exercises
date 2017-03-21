#include <stdio.h>
#include <math.h>
int Reserve(int);
bool Prime(int);
int main()
{
	int no=113;
	if (Prime(no) == 1 && Prime(Reserve(no)) == 1)
	{
		printf("XXX");
		
	}
	return 0;
}
bool Prime(int no)
{
	for (int i = 1; i<no/2 ;i++){
		if (no / i == 0)
			return false;

	}
	return true;
}
int Reserve(int no)
{
	int i = 0;
	int a[10] = { 0 };
	while (no != 0)
	{
		a[i] = no % 10;
		no = no / 10;
		i++;
	}
	int num = 0;

	for (int j = i-1; j >-1 ; j--)
	{
		for (int k = 0; k < j; k++)
		{
			a[k] = a[k] * 10;
		}
	}
	for (int n = 0; n < i ; n++)
	{
		num += a[n];
	}
	printf("%d\n", num);
	return  num;
}
