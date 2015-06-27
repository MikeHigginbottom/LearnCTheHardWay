#include <stdio.h>

int main(int argc, char *argv[]) {
	int i;
	for (i=0; i < argc; i++) {
		printf("Argument %d = '%s'\n", i+1, argv[i]);
	}

	char *states[4] = {"California", "Oregon", "Washington", "Texas"};
	int state;
	for (state = 0; state < sizeof(states)/sizeof(char*); state++) {
		printf("%s\n", states[state]);
	}
	return 0;
}