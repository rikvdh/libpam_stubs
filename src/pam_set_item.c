#include <config.h>
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

static int pamstub_set_item_retval;
static size_t pamstub_set_item_calls = 0;

int pam_set_item(pam_handle_t *pamh, int item_type, const void *item) {
	(void)pamh;
	(void)item_type;
	(void)item;
	pamstub_set_item_calls++;
	return pamstub_set_item_retval;
}

void pamstub_set_pam_set_item_retval(int val) {
        pamstub_set_item_retval = val;
}
size_t pamstub_get_pam_set_item_calls(void) {
        return pamstub_set_item_calls;
}
