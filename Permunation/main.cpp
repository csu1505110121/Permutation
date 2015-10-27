#include <stdio.h>
#include <time.h>
#include "permunation.h"

int main()
{
	int n;
	printf("请输入要测试的数：");
	scanf_s("%d", &n);

	
	permunation(n);
	
	return 0;
}