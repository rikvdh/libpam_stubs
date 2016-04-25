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

SET_CALLBACK(pam_get_user, pam_handle_t *pamh, const char **user, const char *prompt);
SET_RETVAL(pam_get_user, int);
GET_NCALLS(pam_get_user);

int pam_get_user(pam_handle_t *pamh, const char **user, const char *prompt) {
	(void)pamh;
	(void)user;
	(void)prompt;
	if (_callback) {
		_callback(pamh, user, prompt);
		_callback = NULL;
	}
	_ncalls++;
	return _retval;
}
