#include <stdio.h>
#include <Windows.h>
#define buf_size 4096
#define IS_OUTPUT
char print_str[buf_size];
int cur_index = 0;
char* p = print_str;
FILE * output = NULL;
int len = 0;
int num[27] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 0 };

void my_fflush();
void permunation_opt1(int n, int * num);
void permunation1_opt2(int n, int * num);
void way1(int *a, int *b, int *end, int *vb, int *vbb, int *vend);
void way2(int *a, int *b, int *end, int *vb, int *vbb, int *vend);
void way3(int *a, int *b, int *end, int *vb, int *vbb, int *vend);
void way4(int *a, int *b, int *end);
void generatePermunationMid(int * num, int n, int m);
void init();
void terminate();

int main()
{
	init();
	//permunation_dic(len, num);
	//permunation_opt1(len, num);
	permunation1_opt2(len, num);
	terminate();
	return 0;
}
void init()
{
	freopen_s(&output, "output.txt", "w", stdout);
	int n = 0;
	scanf_s("%d", &n);
	len = n;
}

void terminate()
{
	my_fflush();
}

inline void swap(int*a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//打印时使用缓冲
void print_permunation()
{
	if (len + cur_index * 3 >= buf_size)
	{
		print_str[cur_index] = 0;
		printf("%s", print_str);
		//fwrite(print_str, cur_index, 1, output);
		cur_index = 0;
	}
	for (int i = 0; i < len; i++)
	{
		int x = num[i];
		if (x >= 10)
		{
			print_str[cur_index++] = (x / 10) + '0';
		}
		print_str[cur_index++] = (x % 10) + '0';
		if (i != len - 1)
		{
			print_str[cur_index++] = ' ';
		}
	}
	print_str[cur_index++] = '\n';
}

void my_fflush()
{
	print_str[cur_index] = 0;
	printf("%s", print_str);
	//printf(print_str, cur_index, 1, output);
	cur_index = 0;
}

//字典序算法实现
void permunation_dic(int n, int * num)
{
	//generate the first permunation
	int i, j, t;
	int *v, *w;
#ifdef IS_OUTPUT
	print_permunation();
#endif
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
						print_permunation();
						goto there;
					}
				}

			}
		}
		break;
	}
}



void permunation_opt1(int n, int * num)
{
	//generate the first permunation
	int i, j, t;
	int *v, *w;
#ifdef IS_OUTPUT
	print_permunation();
#endif
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
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a2, a3);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a2, a3);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a2, a3);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a2, a3);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a2, a3);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a2, a3);
#ifdef IS_OUTPUT
		print_permunation();
#endif
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
#ifdef IS_OUTPUT
						print_permunation();
#endif
						goto there;
					}
				}

			}
		}
		break;
	}
}

void permunation1_opt2(int n, int * num)
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
		way3(num, num + 3, num + n, num + 3, num + 7, num + n);
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
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a2, a3);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a2, a3);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a2, a3);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a2, a3);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a2, a3);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a3, a4);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a1, a2);
#ifdef IS_OUTPUT
		print_permunation();
#endif
		swap(a2, a3);
#ifdef IS_OUTPUT
		print_permunation();
#endif
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
		generatePermunationHead(num, len);
		return;
	}
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

}

