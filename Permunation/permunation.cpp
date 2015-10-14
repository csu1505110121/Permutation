#include <stdio.h>
#include "permunation.h"
void permunation1_simple(int n);
int count = 0;
void print_permunation(int * str, int n)
{
	char val[27];
	for (int i = 0; i < n; i++)
	{
		 val[i] = 'a' + *(str + i) - 1;
	}
	val[n] = '\0';
	printf("%s\n", val);
	count ++;
}

void permunation1(int n)
{
	permunation1_simple(n);
	
}

void permunation1_simple(int n)
{
	//generate the first permunation
	int num[27] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 0};
	int i, j, t, min;
	int *v, *w;
	print_permunation(num, n);
	num[n] = 0;
	
	while (true)
	{
	there:
		i = n - 2;
		v = num + n - 2;
		for (; i >= 0; i--, v--)
		{
			
			if (*v < *(v + 1))
			{
				t = *v;
				w = v + 1;
				for (j = i + 1; j <= n; j++, w ++)
				{
					if (*w < t)
					{
						*v = *(w - 1);
						*(w - 1) = t;
						v = v + 1;
						w = num + n - 1;
						while (v < w)
						{
							t = *v;
							*v = *w;
							*w = t;
							v++;
							w--;
						}
						print_permunation(num, n);
						goto there;
					}
				}
				
			}
		}
		break;
	
	}
	printf("%d", count);

}


