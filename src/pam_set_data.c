#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

#include <pam_stubs.h>
#include "pam_generic_stubs.h"

SET_CALLBACK(pam_set_data, pam_handle_t *pamh, const char *module_data_name, void *data,
                 void (*cleanup)(pam_handle_t *pamh, void *data, int error_status));
SET_RETVAL(pam_set_data, int);
GET_NCALLS(pam_set_data);

int pam_set_data(pam_handle_t *pamh, const char *module_data_name, void *data,
		 void (*cleanup)(pam_handle_t *pamh, void *data, int error_status)) {
	(void)pamh;
	(void)module_data_name;
	(void)data;
	(void)cleanup;
	if (_callback) {
		_callback(pamh, module_data_name, data, cleanup);
		_callback = NULL;
	}
	_ncalls++;
	return _retval;
}
