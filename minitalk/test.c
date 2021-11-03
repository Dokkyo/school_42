#include <stdio.h>

int main()
{
	int a = 1;
	int b = 0;
	int i = 0;

	while (i < 8)
	{
		printf("1 << %d = %d | ", i, (1 << i));
		++i;
	}
	i = 0;
	printf("\n");
	while (i < 8)
	{
		printf("0 << %d = %d", i, (1 << i));
		++i;
	}
	printf("\n");
	while (i < 8)
		printf("%d\n", (a |= (1 << i++)));
	i = 0;
	while (i < 8)
		printf("%d\n", (b |=  (0 << i++)));
/*	printf("%d\n", a);
	i = 0;
	while (i < 8)
	{
		if (b << i)
			a |= (1 << i);
		else
			a |= (0 << i);
		++i;
	}
	printf("%d\n", a);*/
	return (0);
}
