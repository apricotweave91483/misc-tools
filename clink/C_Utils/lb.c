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
