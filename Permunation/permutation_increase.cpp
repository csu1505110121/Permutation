#include <stdio.h>
#include "permutation_increase.h"

void permutation_increase_way1(int count){
	int number = 1;
	int *permutation = new int[count];
	int *mid = new int[count - 1];
	for (int i = 2; i <= count; i++) {
		number *= i;
	}
	for (int i = 0; i < count - 1; i++) {
		mid[i] = 0;
	}
	int temp = 0;
	int *list = new int[count + 1];
	for (int i = 1; i < number; i++) {
		mid[count - 2]++;
		for (int i = count - 2; i >= 0; i--) {
			if (mid[i] >= count - i){
				mid[i] = 0;
				mid[i - 1]++;
			}
			else {
				break;
			}
		}
		for (int i = 0; i < count - 1; i++) {
			temp = mid[i] + 1;
			for (int j = 1; j < count + 1; j++) {
				if (list[j] != 1) {
					temp--;
				}
				if (temp == 0) {
					permutation[i] = j;
					list[permutation[i]] = 1;
					break;
				}
			}
		}
		for (int i = 1; i < count + 1; i++) {
			if (list[i] != 1) {
				permutation[count - 1] = i;
			}
			list[i] = 0;
			//printf("%d", permutation[i - 1]);
		}
		//printf("\n");
	}
};
void permutation_increase_way2(int count){
	int number = 1;
	int *permutation = new int[count];
	int *mid = new int[count - 1];
	for (int i = 2; i <= count; i++) {
		number *= i;
	}
	for (int i = 0; i < count - 1; i++) {
		mid[i] = 0;
	}
	for (int i = 0; i < count; i++) {
		permutation[i] = i + 1;
	}
	unsigned int list = ~0;
	int changebit = 0;
	int temp = 0;
	for (int i = 1; i < number; i++) {
		mid[count - 2]++;
		for (int i = count - 2; i >= 0; i--) {
			if (mid[i] >= count - i){
				mid[i] = 0;
				mid[i - 1]++;
			}
			else {
				changebit = i;
				break;
			}
		}
		for (int i = changebit; i < count; i++) {
			list ^= 1 << permutation[i];
		}
		for (int i = changebit; i < count - 1; i++) {
			temp = mid[i] + 1;
			for (int j = 1; j < count + 1; j++) {
				if ((list & 1 << j) == 0) {
					temp--;
				}
				if (temp == 0) {
					permutation[i] = j;
					list ^= 1 << permutation[i];
					break;
				}
			}
		}
		for (int i = 1; i < count + 1; i++) {
			if ((list & 1 << i) == 0) {
				permutation[count - 1] = i;
				list ^= 1 << i;
			}
			//printf("%d", permutation[i - 1]);
		}
		//printf("\n");
	}
};
void permutation_increase_way3(int count){
	int number = 1;
	int *permutation = new int[count];
	int *mid = new int[count - 1];
	int *list = new int[count + 1];
	for (int i = 2; i <= count; i++) {
		number *= i;
	}
	for (int i = 0; i < count - 1; i++) {
		mid[i] = 0;
	}
	for (int i = 0; i < count; i++) {
		permutation[i] = i + 1;
		list[i + 1] = 1;
	}
	int changebit = 0;
	int temp = 0;
	for (int i = 1; i < number; i++) {
		mid[count - 2]++;
		for (int i = count - 2; i >= 0; i--) {
			if (mid[i] >= count - i){
				mid[i] = 0;
				mid[i - 1]++;
			}
			else {
				changebit = i;
				break;
			}
		}
		for (int i = changebit; i < count; i++) {
			list[permutation[i]] = 0;
		}
		for (int i = changebit; i < count - 1; i++) {
			temp = mid[i] + 1;
			for (int j = 1; j < count + 1; j++) {
				if (list[j] == 0) {
					temp--;
				}
				if (temp == 0) {
					permutation[i] = j;
					list[permutation[i]] = 1;
					break;
				}
			}
		}
		for (int i = 1; i < count + 1; i++) {
			if (list[i] == 0) {
				permutation[count - 1] = i;
				list[i] = 1;
				break;
			}
		}
		for (int i = 0; i < count; i++) {
			//printf("%d", permutation[i]);
		}
		//printf("\n");
	}
};
void permutation_increase_way4(int count){
	int number = 1;
	int permutation[27];
	int mid[26];
	int list[28];
	int *p, *q;
	for (int i = 2; i <= count; i++) {
		number *= i;
	}
	for (p = mid; p < mid + count - 1; p++) {
		*p = 0;
	}
	for (int i = 0; i < count; i++) {
		*(permutation + i) = i + 1;
		*(list + i + 1) = 1;
	}
	int changebit = 0;
	int temp = 0;
	int *lastbit;
	lastbit = mid + count - 2;
	for (int i = 1; i < number; i++) {
		(*lastbit)++;
		int j = 0;
		for (j = 2, p = lastbit; p >= mid; p--, j++) {
			if (*p >= j){
				*p = 0;
				(*(p - 1))++;
			}
			else {
				changebit = count - j;
				break;
			}
		}
		for (p = changebit + permutation; p < permutation + count; p++) {
			*(list + *p) = 0;
		}
		for (p = list + *(permutation + changebit) + 1, q = permutation + changebit; p < list + count + 1; p++) {
			if (*p == 0) {
				*q = p - list;
				*p = 1;
				break;
			}
		}
		for (p = list + 1, q = permutation + changebit + 1; q < permutation + count; p++) {
			if (*p == 0) {
				*q = p - list;
				q++;
				*p = 1;
			}
		}
		for (p = list + 1; p < list + count + 1; p++) {
			if (*p == 0) {
				*(permutation + count - 1) = p - list;
				*p = 1;
				break;
			}
		}

		//        for (int i = 0; i < count; i++) {
		//            printf("%d", permutation[i]);
		//        }
		//        printf("\n");
	}
}

void permutation_increase_way5(int count) {
	int number = 1;
	int permutation[27];
	int mid[26];
	int *p, *q;
	for (int i = 2; i <= count; i++) {
		number *= i;
	}
	for (p = mid; p < mid + count - 1; p++) {
		*p = 0;
	}
	for (int i = 0; i < count; i++) {
		*(permutation + i) = i + 1;
	}
	int changebit = 0;
	int temp = 0;
	int *lastbit, *last_per_bit;
	lastbit = mid + count - 2;
	last_per_bit = permutation + count - 1;
	for (int i = 1; i < number; i++) {
		(*lastbit)++;
		int j = 0;
		for (j = 2, p = lastbit; p >= mid; p--, j++) {
			if (*p >= j){
				*p = 0;
				(*(p - 1))++;
			}
			else {
				changebit = count - j;
				break;
			}
		}

		temp = *(permutation + changebit);
		for (p = last_per_bit; p > permutation; p--) {
			if (*p > temp){
				*(permutation + changebit) = *p;
				*p = temp;
				break;
			}
		}
		for (p = permutation + changebit + 1, q = last_per_bit; p < q; p++, q--) {
			temp = *p;
			*p = *q;
			*q = temp;
		}

		//        for (int i = 0; i < count; i++) {
		//            printf("%d", permutation[i]);
		//        }
		//        printf("\n");

	}
}

void permutation_decrease(int count){
	int number = 1;
	int permutation[2][27];
	int mid[28];
	int *p;
	for (int i = 2; i <= count; i++) {
		number *= i;
	}
	for (p = mid; p < mid + count + 1; p++) {
		*p = 0;
	}
	for (int i = 0; i < count; i++) {
		*(permutation[0] + i) = i + 1;
	}
	int changebit = 0, changenum = 0;
	int temp = 0, temp1 = 0;
	int *lastbit, *head, *head1;
	head = permutation[0];
	lastbit = mid + count;
	for (int i = 1; i < number; i++) {
		(*lastbit)++;
		int j = 0;
		for (j = count, p = lastbit; p >= mid; p--, j--) {
			if (*p >= j){
				*p = 0;
				(*(p - 1))++;
			}
			else {
				changenum = count - *p;
				changebit = j;
				break;
			}
		}
		if (changebit == count)
		{
			temp = *(head + changenum);
			*(head + changenum) = *(head + changenum - 1);
			*(head + changenum - 1) = temp;
		}
		else {
			temp = *(head + changenum);
			*(head + changenum) = *(head + changenum - 1);
			*(head + changenum - 1) = temp;
			temp1 = (temp1 ^ 1);
			head1 = permutation[temp1];
			for (int *i = head + count - changebit, *j = head1; i < count + head; i++, j++)
			{
				*j = *i;
			}
			for (int *i = head, *j = head1 + count - 1; i < count + head - changebit; i++, j--)
			{
				*j = *i;
			}
			head = head1;

		}

		/*for (int *i = head; i < head + count; i++) {
		printf("%d", *i);
		}
		printf("/n");*/
	}
}