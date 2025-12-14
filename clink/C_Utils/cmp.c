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
