#include <stdio.h>
#include <ctype.h>

int is_printable(char c) {
	return isalpha(c) || isblank(c);
}

void print_letters(char *str) {
	int ch = 0;
	for (ch = 0; str[ch] != '\0'; ch++) {
		if (is_printable(str[ch])) {
			printf("%c", str[ch]);
		}
	}
}

void print_args(int argc, char *args[]) {
	int i = 0;
	for (i = 0; i < argc; i++) {
		print_letters(args[i]);
		printf("\n");
	}
}

int main (int argc, char *argv[]) {
	print_args(argc, argv);
	return 0;
}