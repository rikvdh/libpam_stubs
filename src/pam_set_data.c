#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pam_stubs.h>

#ifdef HAVE_PAM_APPL_H
#include <pam_appl.h>
#elif defined(HAVE_SECURITY_PAM_APPL_H)
#include <security/pam_appl.h>
#endif

#ifdef HAVE_PAM_MODULES_H
#include <pam_modules.h>
#elif defined(HAVE_SECURITY_PAM_MODULES_H)
#include <security/pam_modules.h>
#endif

static int pamstub_set_data_retval = 0;
static size_t pamstub_set_data_calls = 0;

int pam_set_data(pam_handle_t *pamh, const char *module_data_name, void *data,
		 void (*cleanup)(pam_handle_t *pamh, void *data, int error_status)) {
	(void)pamh;
	(void)module_data_name;
	(void)data;
	(void)cleanup;
	pamstub_set_data_calls++;
	return -1;
}

void pamstub_set_pam_set_data_retval(int val) {
	pamstub_set_data_retval = val;
}
size_t pamstub_get_pam_set_data_calls(void) {
	size_t ret = pamstub_set_data_calls;
	pamstub_set_data_calls = 0;
	return ret;
}
