#include <stdio.h>
#include "dbg.h"
#include <dlfcn.h>

typedef int (*lib_function)(const char *data);


int call(void *lib, const char *func_to_run, const char *data) {
	lib_function func = dlsym(lib, func_to_run);
	check(func != NULL, "Did not find %s function in the library: %s", func_to_run, dlerror());

	int rc = func(data);
	check(rc == 0, "Function %s return %d for data: %s", func_to_run, rc, data);

	return 0;

error:
	return 1;
}

int main(int argc, char *argv[])
{
	int rc = 0;
	char *lib_file = "libex29.so";

	void *lib = dlopen(lib_file, RTLD_NOW);
	check(lib != NULL, "Failed to open the library %s: %s", lib_file, dlerror());

	char *func_to_run = "print_a_message";
	char *data = "hello world";
	rc = call(lib, func_to_run, data);
	check(rc == 0, "Test case failed");

	rc = dlclose(lib);
	check(rc == 0, "Failed to close %s", lib_file);

	return 0;

error:
	return 1;
}