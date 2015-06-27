#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
	printf("%d\n", INT8_MAX);
	printf("%d\n", UINT8_MAX);
	printf("%d\n", INT16_MAX);
	printf("%ld\n", sizeof(intmax_t));
	return 0;
}