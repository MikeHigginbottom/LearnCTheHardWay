#include <unistd.h>
#include <apr_errno.h>
#include <apr_file_io.h>

#include "db.h"
#include "bstrlib.h"
#include "dbg.h"

static FILE *db_open(const char *path, const char *mode) {
	return fopen(path, mode);
}

static void db_close(FILE *db) {
	fclose(db);
}

static bstring db_load() {
	FILE *db = NULL;
	bstring data = NULL;

	db = db_open(DB_FILE, "r");
	check(db, "Failed to open database %s", DB_FILE);
	data = bread((bNread)fread, db);
	check(data, "Failed to read from database %s", DB_FILE);
	db_close(db);
	return data;
error:
	if (db) db_close(db);
	if (data) bdestroy(data);
	return NULL;
}

int db_update(const char *url) {
	if (db_find(url)) {
		log_inf("%s is already recorded as being installed", url);
	}

	FILE *db = db_open(DB_FILE, "a+");
	check(db, "Failed to open DB file %s", DB_FILE);

	bstring line = bfromcstr(url);
	bconchar(line, '\n');
	int rc = fwrite(line->data, blength(line), 1, db);
	check(rc == 1, "Failed to append toi DB");
	return 0;

error:
	if (db) db_close(db);
	return -1;
}

int db_find(const char *url) {
	bstring data = NULL;
	bstring line = bfromcstr(url);
	int res = -1;

	data = db_load();
	check(data, "Failed to load %s", DB_FILE);
	if (binstr(data, 0, line) == BSTR_ERR) {
		res = 0;
	}
	else {
		res = 1;
	}

error:
	if (data) bdestroy(data);
	if (line) bdestroy(line);

	return res;
}

int db_init() {
	apr_pool_t *p = NULL;
	apr_pool_initialize();
	apr_pool_create(&p, NULL);

	if (access(DB_DIR, W_OK | X_OK) == -1) {
		apr_status_t rc = apr_dir_make_recursive(DB_DIR, APR_UREAD | APR_UWRITE | APR_UEXECUTE | APR_GREAD | APR_GWRITE | APR_GEXECUTE, p);
		check(rc == APR_SUCCESS, "Failed to make database directory %s", DB_DIR);
	}
	if (access(DB_FILE, W_OK) == -1) {
		FILE *db = db_open(DB_FILE, "w");
		check(db, "Cannot open database %s", DB_FILE);
	}

	apr_pool_destroy(p);
	return 0;

error:
	apr_pool_destroy(p);
	return 1;
}

int db_list() {
	bstring data = db_load();
	check(data, "Failed to load database %s", DB_FILE);

	printf("%s", bdata(data));
	bdestroy(data);
	return 0;

error:
	return -1;
}
