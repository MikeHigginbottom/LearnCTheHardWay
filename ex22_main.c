#include "ex22.h"
#include "dbg.h"

const char *MY_NAME = "Mike Higginbottom";

void scope_demo(int count) {
	log_inf("Count is %d", count);
	if (count > 10) {
		int count = 100;
		log_inf("Count in this scope is %d", count);
	}
	log_inf("Count at exit is %d", count);

	count = 3000;

	log_inf("Count after assign is %d", count);
}

int main(int argc, char *argv[]) {
	log_inf("My name is %s and my age is %d", MY_NAME, get_age());
	set_age(100);
	log_inf("My age is now %d", get_age());
	log_inf("The size is %d", THE_SIZE);
	print_size();
	THE_SIZE = 9;
	log_inf("The size is now %d", THE_SIZE);
	print_size();

	log_inf("Ratio at first is %f", update_ratio(2.0));
	log_inf("Ratio again is %f", update_ratio(10.0));
	log_inf("Ratio is finally %f", update_ratio(300.0));

	int count = 4;
	scope_demo(count);
	scope_demo(count * 20);
	log_inf("Count after calling scope_demo function is %d", count);

	return 0;
}