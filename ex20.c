#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

void test_log_dbg() {
	log_dbg ("I have brown hair");
	log_dbg ("I am %d years old", 37);
}

void test_log_err() {
	log_err("I believe everything is broken");
	log_err("There are %d problems in %s", 0, "space");
}

void test_log_wrn() {
	log_wrn("You can safely ignore this");
	log_wrn("You might wanbt to check out %s", "/etc/passwd");
}

void test_log_inf() {
	log_inf("Well I did something mundane");
	log_inf("It happened %f times today", 1.3f);
}

int test_check(char *filename) {
	FILE *input = NULL;
	char *block = NULL;

	block = malloc(100);
	check_mem(block);

	input = fopen(filename, "r");
	check(input, "Failed to open %s", filename);

	free(block);
	fclose(input);
	return 0;

error:
	if (block) free(block);
	if (input) fclose(input);
	return -1;
}

int test_sentinel(int code) {
	char *temp = malloc(100);
	check_mem(temp);

	switch(code) {
		case 1:
			log_inf("It worked");
			break;
		default:
			sentinel("I shouldn't run");
	}
	free(temp);
	return 0;

error:
	if (temp) free(temp);
	return -1;
}

int test_check_mem() {
	char *test = NULL;
	check_mem(test);
	free(test);
	return 1;
error:
	return -1;
}

int test_check_debug() {
	int i = 0;
	check_debug(i == 0, "Oops I was zero.");
	return 0;
error:
	return -1;
}

int main(int argc, char *argv[]) {
	check (argc == 2, "Need an argument");

	test_log_dbg();
	test_log_err();
	test_log_wrn();
	test_log_inf();

	check(test_check("ex20.c") == 0, "failed with ex20.c");
	check(test_check(argv[1]) == -1, "failed with argv[1]");
	check(test_sentinel(1) == 0, "test_sentinel failed");
	check(test_sentinel(100) == -1, "test_sentinel failed");
	check(test_check_mem() == -1, "test_check_mem failed");
	check(test_check_debug() == -1, "test_check_debug failed");
	return 0;

error:
	return -1;
}