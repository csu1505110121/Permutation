#include <stdio.h>
#include "permunation.h"
#include <time.h>
void permunation1_simple(int n, int * num);
void permunation1_optimize1(int n, int * num);
void permunation1_optimize2(int n, int * num);
void permunation1_optimize3(int n, int * num);
void permunation1_optimize4(int n, int * num);
void permunation1_optimize4Head(int n, int * num);
void permunation1_optimize4Mid(int * num, int n, int a);
void generatePermunationHead(int * num, int n);
void generatePermunationMid(int * num, int n, int m);
void generate(int n, int * A);
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
inline void swap(int*a, int *b);
int count = 0;
int strLen = 0;
int *str;
int * testN;
void way1(int *a, int *b, int *end, int *vb, int *vbb, int *vend);
void way2(int *a, int *b, int *end, int *vb, int *vbb, int *vend);
void way3(int *a, int *b, int *end, int *vb, int *vbb, int *vend);
void way4(int *a, int *b, int *end);
void testWay();

void print_permunation(int * str)
{

#ifdef _DEBUG
	char val[27];
	for (int i = 0; i < strLen; i++)
	{
		 val[i] = 'a' + *(str + i) - 1;
	}
	val[strLen] = '\0';
	printf("%s: %d \n", val, count);
	
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
	test6();
	//testWay();
}

void testWay()
{
	int num[27] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 0 };
	testN = num;
	num[12] = 0;
	way4(num, num + 4, num + 12);
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
	count = 0;
	clock_t t_start = clock();
	generate(strLen, num + 1);
	clock_t t_end = clock();
	printf("time consumed: %dms\n", (t_end - t_start));
	printf("total:%d\n", count);
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

void test6()
{
	int num[27] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 0 };
	count = 0;
	str = num;
	clock_t t_start = clock();
	permunation1_optimize4(strLen, num);
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

void permunation1_optimize4(int n, int * num)
{
	int a = n / 4;
	int b = n % 4;
	num[n] = 0;
	switch (b)
	{
	case 0:
		way4(num, num + 4, num + n);
		break;
	case 3:
		way3(num, num + 3, num + n, num+3, num+7, num+n);
		break;
	case 2:
		way2(num, num + 2, num + n, num + 2, num + 6, num + n);
		break;
	case 1:
		way1(num, num + 1, num + n, num + 1, num + 5, num + n);
	}
}


void generatePermunationHead(int * num, int n)
{
	int a = n % 4;
	int m = n / 4;
	switch (a)
	{
	case 0:
		generatePermunationMid(num, n, m);
		break;
	case 1:
		generatePermunationMid(num, n, m);
		break;
	case 2:
		generatePermunationMid(num, n, m);
		swap(num, num + 1);
		generatePermunationMid(num, n, m);
		break;
	case 3:
		generatePermunationMid(num, n, m);
		int* a1 = num;
		int* a2 = num + 1;
		int * a3 = num + 2;
		swap(a2, a3);
		generatePermunationMid(num, n, m);
		swap(a1, a2);
		generatePermunationMid(num, n, m);
		swap(a2, a3);
		generatePermunationMid(num, n, m);
		swap(a1, a2);
		generatePermunationMid(num, n, m);
		swap(a2, a3);
		generatePermunationMid(num, n, m);
		//swap(a1, a2);
		break;
	}
}



void generatePermunationMid(int * num, int n, int m)
{
	if (m == 1)
	{
		int* a1 = num + n - 4;
		int * a2 = a1 + 1;
		int* a3 = a2 + 1;
		int* a4 = a3 + 1;
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
		return;
	}
	int* a1 = num + n - 4 * m;
	int * a2 = a1 + 1;
	int* a3 = a2 + 1;
	int* a4 = a3 + 1;
	generatePermunationMid(num, n, m - 1);
	swap(a1, a2);
	generatePermunationMid(num, n, m - 1);
	swap(a3, a4);
	generatePermunationMid(num, n, m - 1);
	swap(a2, a3);
	generatePermunationMid(num, n, m - 1);
	swap(a1, a2);
	generatePermunationMid(num, n, m - 1);
	swap(a3, a4);
	generatePermunationMid(num, n, m - 1);
	swap(a1, a2);
	generatePermunationMid(num, n, m - 1);
	swap(a2, a3);
	generatePermunationMid(num, n, m - 1);
	swap(a3, a4);
	generatePermunationMid(num, n, m - 1);
	swap(a1, a2);
	generatePermunationMid(num, n, m - 1);
	swap(a3, a4);
	generatePermunationMid(num, n, m - 1);
	swap(a2, a3);
	generatePermunationMid(num, n, m - 1);
	swap(a1, a2);
	generatePermunationMid(num, n, m - 1);
	swap(a3, a4);
	generatePermunationMid(num, n, m - 1);
	swap(a1, a2);
	generatePermunationMid(num, n, m - 1);
	swap(a2, a3);
	generatePermunationMid(num, n, m - 1);
	swap(a3, a4);
	generatePermunationMid(num, n, m - 1);
	swap(a1, a2);
	generatePermunationMid(num, n, m - 1);
	swap(a3, a4);
	generatePermunationMid(num, n, m - 1);
	swap(a2, a3);
	generatePermunationMid(num, n, m - 1);
	swap(a1, a2);
	generatePermunationMid(num, n, m - 1);
	swap(a3, a4);
	generatePermunationMid(num, n, m - 1);
	swap(a1, a2);
	generatePermunationMid(num, n, m - 1);
	swap(a2, a3);
	generatePermunationMid(num, n, m - 1);
	swap(a3, a4);
}

//生成4种
void way1(int *a, int *b, int *end, int *vb, int *vbb, int *vend)
{
	
	way4(vb, vbb, end);
	while (b != end)
	{
		swap(a, b);
		way4(vb, vbb, end);
		b++;
	}
}
//
void way2(int *a, int *b, int *end, int *vb, int *vbb, int *vend)
{

	way1(a + 1, b, end, vb, vbb, vend);
	int *start = b;
	int *end1 = end - 1;
	int *p;
	int *a1 = a + 1;
	while (start != end)
	{
		//case 1:
		
		p = end1;
		swap(a, start);
		way4(vb, vbb, vend);
		while (p != start)
		{
			swap(p, a1);
			way4(vb, vbb, vend);
			p--;
		}
		//case 2:
		start++;
		if (start == end)
		{
			break;
		}
		swap(a, start);
		way4(vb, vbb, vend);
		p = start + 1;
		while (p != end)
		{
			swap(p, a);
			way4(vb, vbb, vend);
			p++;
		}
		//case 3:
		start++;
		if (start == end)
		{
			break;
		}
		swap(a1, start);
		way4(vb, vbb, vend);
		p = end1;
		while (p != start)
		{
			swap(p, a);
			way4(vb, vbb, vend);
			p--;
		}
		//case 4:
		start++;
		if (start == end)
		{
			break;
		}
		swap(a1, start);
		way4(vb, vbb, vend);
		p = start + 1;
		while (p != end)
		{
			swap(p, a1);
			way4(vb, vbb, vend);
			p++;
		}
		start++;
	}
	
}

void way3(int *a, int *b, int *end, int *vb, int *vbb, int *vend)
{
	
	int *a1 = a + 1;
	int *a2 = a + 2;
	way2(a1, b, end, vb, vbb, vend);
	int *end1 = end - 1;
	int * start;
	int *p;
	
	while (b != end){
		swap(a, b);
		
		way4(vb, vbb, vend);
	
		if (b == end1)
		{
			break;
		}
		//
		//倒序交换a2 和 b_n
		p = end1;
		start = b;
		while (p != start)
		{
			swap(p, a1);
			way4(vb, vbb, vend);
			p--;
		}
		// 倒序交换a1 和b_n;
		
		p = end1;
		while (p != start)
		{
			swap(p, a2);
			way4(vb, vbb, vend);
			p--; 
		}
		end = end - 1;
		end1 = end - 1;
		while (true)
		{
			//step 1
			start = start + 1;
			if (start == end)
			{
				break;
			}
			swap(start, a1);
			way4(vb, vbb, vend);
			p = start + 1;
			while (p != end)
			{
				swap(p, a1);
				way4(vb, vbb, vend);
				p++;
			}
			start = start + 1;
			
			if (start == end)
			{
				break;
			}
			swap(a2, start);
			way4(vb, vbb, vend);
			p = end1;
			while (p != start)
			{
				swap(p, a1);
				way4(vb, vbb, vend);
				p--;
			}
			start = start + 1;
			if (start == end)
			{
				break;
			}
			swap(start, a2);
			way4(vb, vbb, vend);
			p = start + 1;
			while (p != end)
			{
				swap(p, a2);
				way4(vb, vbb, vend);
				p++;
			}
			start = start + 1;
			if (start == end)
			{
				break;
			}
			swap(start, a1);
			way4(vb, vbb, vend);
			p = end1;
			while (p != start)
			{
				swap(p, a2);
				way4(vb, vbb, vend);
				p--;
			}
			//step 2
		}
		if (*a1 < *a2)
		{
			swap(a1, a2);
		}
		end = end + 1;
		end1 = end1 + 1;
		swap(a2, end1);
		b++;
		
	}
	if (*a1 < *a2)
	{
		swap(a1, a2);
	}
}
void way4(int *a, int *b, int *end)
{
	if (b >= end)
	{
		generatePermunationHead(str, strLen);
		//print_permunation(str);
		return;
	}
	//print_permunation(str);
	int * a1 = a + 1;
	int * a2 = a + 2;
	int * a3 = a + 3;
	int *end1 = end - 1;
	way3(a + 1, b, end, b, b + 4, end);
	int * start = 0;
	int *p;
	int *vb = b;
	int *vbb = b + 4;
	int *vend = end;
	
	while (b < end - 3)
	{
		//
		swap(a, b);
		//way4(b, b + 4, end);
		int t1 = *a1, t2 = *a2, t3 = *a3;
		
		*a1 = *(b + 1);
		*a2 = *(b + 2);
		*a3 = *(b + 3);
		int *p = b + 4;
		while (p < end)
		{
			*(p - 3) = *p;
			p++;
		}
		*(end - 3) = t1;
		*(end - 2) = t2;
		*(end - 1) = t3;
		
		way3(a + 1, b + 1, end, vb, vbb, vend);
		b = b + 1;
	}
	swap(a, b);
	//way4(b, b + 4, end);
	int t1 = *a1, t2 = *a2, t3 = *a3;
	*a1 = *(b + 1);
	*a2 = *(b + 2);
	*a3 = t1;
	*(b + 1) = t2;
	*(b + 2) = t3;
	//print_permunation(str);
	way3(a + 1, b + 1, end, vb, vbb, vend);
	b = b + 1;
	swap(a, b);
	way4(vb, vbb, vend);
	int *b1 = b + 1;
	swap(a1, b1);
	way4(vb, vbb, vend);
	swap(a2, b1);
	way4(vb, vbb, vend);
	swap(a3, b1);
	way4(vb, vbb, vend);
	//
	//这两句话是生成一种
	swap(a, a1);
	swap(a1, b1);
	swap(a1, a2);
	way4(vb, vbb, vend);

	//恢复原状
	t1 = *a, t2 = *a1, t3 = *a2;
	int t4 = *a3;
	b = vb;
	while (b < vend - 3)
	{
		*(b - 4) = *b;
		*(b - 3) = *(b + 1);
		*(b - 2) = *(b + 2);
		*(b - 1) = *(b + 3);
		b = b + 4;
	}
	*(vend - 4) = t1;
	*(vend - 3) = t2;
	*(vend - 2) = t3;
	*(vend - 1) = t4;
	//print_permunation(str);

}




void permunation1_optimize4Head(int n, int * num)
{
	generatePermunationHead(num, n);
	int a = n / 4;
	int b = n % 4;
	int * end = num + n;
	int * end1 = end - 1;
	int * end2 = end1 - 1;
	int * l0 = num;
	int * l1 = l0 + 1;
	int * l2 = l1 + 1;
	int * r0, *r1, *r2;
	switch (b)
	{
	case 0:
		permunation1_optimize4Mid(num, n, b);
		break;
	case 1:
		r0 = l0 + 1;
		while (r0 != end)
		{
			swap(num, r0);
			permunation1_optimize4Mid(num, n, b);
			r0++;
		}
		
		break;
	case 2:
		r0 = l1 + 1;
		while (r0 != end)
		{
			swap(l1, r0);
			permunation1_optimize4Mid(num, n, b);
			r0++;
		}
		r0 = l0 + 1;
		while (r0 != end1)
		{
			swap(r0, l0);
			r1 = r0 + 1;
			while (r1 != end)
			{
				swap(r1, l1);
				permunation1_optimize4Mid(num, n, b);
				r1++;
			}
			r0++;
		}
		break;
	case 3:
		r0 = l2 + 1;
		while (r0 != end)
		{
			swap(l2, r0);
			permunation1_optimize4Mid(num, n, b);
			r0++;
		}
		r0 = l1 + 1;
		while (r0 != end1)
		{
			swap(r0, l1);
			r1 = r0 + 1;
			while (r1 != end)
			{
				swap(r1, l2);
				permunation1_optimize4Mid(num, n, b);
				r1++;
			}
			r0++;
		}
		r0 = l0 + 1;
		while (r0 != end2)
		{
			swap(r0, l0);
			r1 = r0 + 1;
			while (r1 != end1)
			{
				swap(r1, l1);
				r2 = r1 + 1;
				while (r2 != end)
				{
					swap(r2, l2);
					permunation1_optimize4Mid(num, n, b);
					r2++;
				}
				r1++;
			}
			r0++;
		}
		break;
	}

}
void permunation1_optimize4Mid(int * num, int n, int a)
{
	
	if (a <= 1)
	{
		if (a == 0)
		{
			return;
		}
		generatePermunationHead(num, n);
		return;
	}
	int * l0 = num + n - 4 * a;
	int * l1 = l0 + 1;
	int * l2 = l1 + 1;
	int * l3 = l2 + 1;		
	int * r1, *r2, *r3;
	int * end = num + n;
	int * end1, *end2, *end3;
	int * r0 = l3 + 1;
	while (r0 != end)
	{
		swap(l3, r0);
		r0++;
	}
	
	r1 = l3;
	end1 = end - 1;
	while (r1 != end1)
	{
		swap(r1, l2);
		r0 = r1 + 1;
		while (r0 != end)
		{
			swap(l3, r0);
			permunation1_optimize4Mid(num, n, a - 1);
			r0++;
		}
		r1++;
	}
	
	r2 = l2;
	end2 = end1 - 1;
	while (r2 != end2)
	{
		swap(r2, l1);
		r1 = r2 + 1;
		while (r1 != end1)
		{
			swap(r1, l2);
			r0 = r1 + 1;
			while (r0 != end)
			{
				swap(r0, l3);
				permunation1_optimize4Mid(num, n, a - 1);
				r0++;
			}
			r1++;
		}
		r2++;
	}
	
	r3 = l1;
	end3 = end2 - 1;
	while (r3 != end3)
	{
		swap(r3, l0);
		r2 = r3 + 1;
		while (r2 != end2)
		{
			swap(r2, l1);
			r1 = r2 + 1;
			while (r1 != end1)
			{
				swap(r1, l2);
				r0 = r1 + 1;
				while (r0 != end)
				{
					swap(r0, l3);
					permunation1_optimize4Mid(num, n, a - 1);
					r0++;
				}
				r1++;
			}
			r2++;

		}
		r3++;
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
		for (int i = 1; i <= n; i++)
		{
			generate(n - 1, A);
			if (n % 2 == 0)
			{
				swap = A[i];
				A[i] = A[n];
				A[n] = swap;
			}
			else
			{
				swap = A[1];
				A[1] = A[n];
				A[n] = swap;
			}
		}
		//generate(n - 1, A);
	}
}

