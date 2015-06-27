#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Person *create_person(char *name, int age, int height, int weight) {
	struct Person *who = malloc (sizeof(struct Person));
	assert (who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;
	return who;
}

void destroy_person(struct Person *who) {
	assert (who != NULL);
	free(who->name);
	free(who);
}

void print_person(struct Person *who) {
	assert (who != NULL);

	printf("Name: %s\n", who->name);
	printf("Age: %d\n", who->age);
	printf("Height: %d\n", who->height);
	printf("Weight: %d\n", who->weight);
}

int main(int argc, char *argv[]) {
	struct Person *mike = create_person("Mike", 46, 180, 85);
	print_person(mike);
	printf("%p\n", mike);
	printf("%p\n", &(mike->name));
	printf("%p\n", mike->name);
	printf("%p\n", &(mike->age));
	printf("%p\n", &(mike->weight));
	printf("%p\n", &(mike->height));
	destroy_person(mike);
	return 0;
}