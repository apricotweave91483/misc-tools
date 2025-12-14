#include <stdio.h>
#include <stdlib.h>

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
