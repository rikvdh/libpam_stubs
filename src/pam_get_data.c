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

static int pamstub_get_data_retval = 0;
static size_t pamstub_get_data_calls = 0;

int pam_get_data(const pam_handle_t *pamh, const char *module_data_name, const void **data) {
	(void)pamh;
	(void)module_data_name;
	(void)data;
	pamstub_get_data_calls++;
	return pamstub_get_data_retval;
}

void pamstub_set_pam_get_data_retval(int val) {
	pamstub_get_data_retval = val;
}

size_t pamstub_get_pam_get_data_calls() {
	size_t ret = pamstub_get_data_calls;
	pamstub_get_data_calls = 0;
	return ret;
}
