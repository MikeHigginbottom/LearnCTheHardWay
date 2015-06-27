#ifndef _dbg_h
#define _dbg_h

#include <stdio.h>
#include <string.h>
#include <errno.h>

#ifdef NDEBUG
#define log_dbg(N, ...)
#else
#define log_dbg(N, ...) fprintf(stderr, "[DBG] (%s:%d) " N "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clear_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, "[ERR] (%s:%d:errno:%s) " M "\n", __FILE__, __LINE__, clear_errno(), ##__VA_ARGS__)
#define log_wrn(M, ...) fprintf(stderr, "[WRN] (%s:%d:errno:%s) " M "\n", __FILE__, __LINE__, clear_errno(), ##__VA_ARGS__)
#define log_inf(M, ...) fprintf(stderr, "[INF] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if (!(A)) { log_err(M, ##__VA_ARGS__); errno = 0; goto error; }

#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); errno = 0; goto error; }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) if (!(A)) { log_dbg(M, ##__VA_ARGS__); errno = 0; goto error; }

#endif