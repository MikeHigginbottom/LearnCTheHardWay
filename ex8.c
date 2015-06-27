#include <stdio.h>

int main (int argc, char* argv[]) {
	char full_name[] = {'Z', 'e', 'd', ' ', 'A', '.', ' ', 'S', 'h', 'a', 'w', '\0'};
	int areas[] = {10,12,13,14,20};
	char name[] = "Zed";

	printf("The size of an int is %ld\n", sizeof(int));
	printf("The size of areas(int[]): %ld\n", sizeof(areas));
	printf("The number of elements in areas: %ld\n", sizeof(areas) / sizeof(int));
	printf("The first area is %d. The second area is %d\n", areas[0], areas[1]);

	printf("The size of a char: %ld\n", sizeof(char));
	printf("The size of name(char[]): %ld\n", sizeof(name));
	printf("The number of chars in name: %ld\n", sizeof(name) / sizeof(char));
	printf("The size of full name(char[]): %ld\n", sizeof(full_name));
	printf("The number of chars in full name: %ld\n", sizeof(full_name) / sizeof(char));

	printf("name=\"%s\" fullname=\"%s\"\n", name, full_name);

	return 0;
}