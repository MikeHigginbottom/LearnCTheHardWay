#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("Only one argument.\n");
	} else if (argc > 1 && argc < 3) {
		printf("Correct. That's two.\n");
	} else {
		printf("Way too many.\n");
	}

	return 0;
}