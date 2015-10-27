#include <stdio.h>
#include "permunation.h"
#include <time.h>
void permunation1_simple(int n, int * num);
void permunation1_optimize1(int n, int * num);
void permunation1_optimize2(int n, int * num);
void permunation1_optimize3(int n, int * num);
void generate(int n, int * A);
void test1();
void test2();
void test3();
void test4();
void test5();
inline void swap(int*a, int *b);
int count = 0;
int strLen = 0;

void print_permunation(int * str)
{

#ifdef _DEBUG
	char val[27];
	for (int i = 0; i < strLen; i++)
	{
		 val[i] = 'a' + *(str + i) - 1;
	}
	val[strLen] = '\0';
	printf("%s\n", val);
	
#endif
	
	count++;
}

void permunation(int n)
{
	strLen = n;
	test1();
	//test2();
	//test3();
	test4();
	//test5();
}

void test1()
{
	int num[27] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 0 };
	count = 0;
	clock_t t_start = clock();
	permunation1_simple(strLen, num);
	clock_t t_end = clock();
	printf("time consumed: %dms\n", (t_end - t_start));
	printf("total:%d\n", count);
}

void test2()
{
	int num[27] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 0 };
	count = 0;
	clock_t t_start = clock();
	permunation1_optimize1(strLen, num);
	clock_t t_end = clock();
	printf("time consumed: %dms\n", (t_end - t_start));
	printf("total:%d\n", count);
}

void test3()
{
	int num[27] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 0 };
	clock_t t_start = clock();
	generate(strLen, num);
	clock_t t_end = clock();
	printf("time consumed: %dms", (t_end - t_start));
}

void test4()
{
	int num[27] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 0 };
	count = 0;
	clock_t t_start = clock();
	permunation1_optimize3(strLen, num);
	clock_t t_end = clock();
	printf("time consumed: %dms\n", (t_end - t_start));
	printf("total:%d\n", count);
}

void test5()
{
	int num[27] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 0 };
	count = 0;
	clock_t t_start = clock();
	permunation1_optimize2(strLen, num);
	clock_t t_end = clock();
	printf("time consumed: %dms\n", (t_end - t_start));
	printf("total:%d\n", count);
}


void permunation1_simple(int n, int * num)
{
	//generate the first permunation
	int i, j, t;
	int *v, *w;
	print_permunation(num);
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
						print_permunation(num);
						goto there;
					}
				}
				
			}
		}
		break;
	}
}

void permunation1_optimize1(int n, int * num)
{
	//generate the first permunation
	int i, j, t;
	int *v, *w;
	print_permunation(num);
	num[n] = 0;
	//
	int l, r, * m;
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
				if (n - i < 10){
				for (j = i + 1; j <= n; j++, w++)
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
						print_permunation(num);
						goto there;
					}
				}
				}
				else
				{
				
				//使用二分法来寻找最小的那个N
				l = i + 2;
				r = n - 1;
				*v = *w;
				m = w;
				while (l <= r)
				{
					j = (l + r) >> 1;
					w = num + j;
					if (*w > t)
					{
						m = w;
						l = j + 1;
					}
					else
					{
						r = j - 1;
					}
				}
				*v = *m;
				*m = t;
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
				print_permunation(num);
				goto there;
				}

			}
		}
		break;
	}
}

void permunation1_optimize2(int n, int * num)
{
	//generate the first permunation
	int i, j, t;
	int *v, *w;
	print_permunation(num);
	num[n] = 0;
	if (n == 1)
	{
		return;
	}
	swap(num + n - 1, num + n - 2);
	print_permunation(num);
	
	while (true)
	{
	there:
		//
		i = n - 2;
		v = num + n - 2;
		for (; i >= 0; i--, v--)
		{

			if (*v < *(v + 1))
			{
				t = *v;
				w = v + 1;
				for (j = i + 1; j <= n; j++, w++)
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
						print_permunation(num);
						swap(num + n - 1, num + n - 2);
						print_permunation(num);
						goto there;
						
						
					}
				}

			}
		}
		break;
	}
}

inline void swap(int*a, int *b)
{
	/**a ^= *b;
	*b ^= *a;
	*a ^= *b;*/
	int t = *a;
	*a = *b;
	*b = t;
}

//一半一半
void permunation1_optimize3(int n, int * num)
{
	//generate the first permunation
	int i, j, t;
	int *v, *w;
	print_permunation(num);
	num[n] = 0;
	int *a1, *a2, *a3, *a4;
	while (true)
	{
	there:
		//
		
			a1 = num + n - 4;
			a2 = a1 + 1;
			a3 = a2 + 1;
			a4 = a3 + 1;
			swap(a1, a2);
			print_permunation(num);
			swap(a3, a4);
			print_permunation(num);
			swap(a2, a3);
			print_permunation(num);
			swap(a1, a2);
			print_permunation(num);
			swap(a3, a4);
			print_permunation(num);
			swap(a1, a2);
			print_permunation(num);
			swap(a2, a3);
			print_permunation(num);
			swap(a3, a4);
			print_permunation(num);
			swap(a1, a2);
			print_permunation(num);
			swap(a3, a4);
			print_permunation(num);
			swap(a2, a3);
			print_permunation(num);
			swap(a1, a2);
			print_permunation(num);
			swap(a3, a4);
			print_permunation(num);
			swap(a1, a2);
			print_permunation(num);
			swap(a2, a3);
			print_permunation(num);
			swap(a3, a4);
			print_permunation(num);
			swap(a1, a2);
			print_permunation(num);
			swap(a3, a4);
			print_permunation(num);
			swap(a2, a3);
			print_permunation(num);
			swap(a1, a2);
			print_permunation(num);
			swap(a3, a4);
			print_permunation(num);
			swap(a1, a2);
			print_permunation(num);
			swap(a2, a3);
			print_permunation(num);
			swap(a1, a3);
			swap(a2, a4);
			swap(a3, a4);
			i = n - 5;
			v = num + i;
		
		
		for (; i >= 0; i--, v--)
		{

			if (*v < *(v + 1))
			{
				t = *v;
				w = v + 1;
				for (j = i + 1; j <= n; j++, w++)
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
						print_permunation(num);
						goto there;
					}
				}

			}
		}
		break;
	}
}



void generate(int n, int * A)
{
	int swap;
	if (n == 1)
	{
		print_permunation(A);
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			generate(n - 1, A);
			if (n % 2 == 0)
			{
				swap = A[i];
				A[i] = A[n - 1];
				A[n - 1] = swap;
			}
			else
			{
				swap = A[0];
				A[0] = A[n - 1];
				A[n - 1] = swap;
			}
		}
		generate(n - 1, A);
	}
}

