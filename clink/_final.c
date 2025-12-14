#include <stdlib.h>
#include <stdio.h>
int icmp(const void* x, const void* y) {
	int a = *(int*)x;
	int b = *(int*)y;
	return (a > b) - (b > a);
}
int ccmp(const void* x, const void* y) {
	unsigned char a = *(unsigned char*)x;
	unsigned char b = *(unsigned char*)y;
	return (a > b) - (b > a);
}
int lb(int* arr, int len, int target){
	int l = 0, r = len - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (arr[m] >= target)
			r = m - 1;
		else
			l = m + 1;
	}
	return l;
}

int main() {
	int t;
	scanf("%d", &t);
	int arr[t];
	for (int x = 0; x < t; ++x) scanf("%d", arr + x);

	qsort(arr, t, sizeof(int), icmp);
	printf("target: ");
	int target;
	scanf("%d", &target);

	int i = lb(arr, t, target);
	
	if (i < t)
		if (arr[i] == target)
			printf("target found\n");

	return 0;
}
