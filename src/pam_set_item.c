#include <config.h>
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

SET_CALLBACK(pam_set_item, pam_handle_t *pamh, int item_type, const void *item);
SET_RETVAL(pam_set_item, int);
GET_NCALLS(pam_set_item);

int pam_set_item(pam_handle_t *pamh, int item_type, const void *item) {
	(void)pamh;
	(void)item_type;
	(void)item;
	if (_callback) {
		_callback(pamh, item_type, item);
		_callback = NULL;
	}
	_ncalls++;
	return _retval;
}
