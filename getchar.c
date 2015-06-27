#include <stdio.h>

int main(void) {
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("You entered: %d\n", num);
	getchar(); //Returns immediately due to newline entered after digit chars not being consumed by scanf
	return 0;
}