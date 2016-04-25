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

static const char *pamstub_strerror_retval = NULL;
static size_t pamstub_strerror_calls = 0;

const char *pam_strerror(pam_handle_t *pamh, int errnum) {
	pamstub_strerror_calls++;
	return pamstub_strerror_retval;
}

void pamstub_set_strerror_retval(const char *val) {
	pamstub_strerror_retval = val;
}
size_t pamstub_get_strerror_calls(void) {
	return pamstub_strerror_calls;
}
