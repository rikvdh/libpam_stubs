#ifndef __INCLUDE_PAM_STUBS_H__
#define __INCLUDE_PAM_STUBS_H__

/* pam_strerror.c */
void pamstub_set_pam_strerror_retval(const char *val);
size_t pamstub_get_pam_strerror_calls(void);
void pamstub_set_pam_strerror_callback(void(*cb)(pam_handle_t *pamh, int errnum));

/* pam_get_data.c */
void pamstub_set_pam_get_data_retval(int val);
size_t pamstub_get_pam_get_data_calls();
void pamstub_set_pam_get_data_callback(void(*cb)(const pam_handle_t *pamh, const char *module_data_name, const void **data));

/* pam_set_data.c */
void pamstub_set_pam_set_data_retval(int val);
size_t pamstub_get_pam_set_data_calls(void);
void pamstub_set_pam_set_data_callback(void(*cb)(pam_handle_t *pamh, const char *module_data_name, void *data,
						 void (*cleanup)(pam_handle_t *pamh, void *data, int error_status)));

/* pam_get_item.c */
void pamstub_set_pam_get_item_retval(int val);
size_t pamstub_get_pam_get_item_calls();
void pamstub_set_pam_get_item_callback(void(*cb)(const pam_handle_t *pamh, int item_type, const void **item));

/* pam_set_item.c */
void pamstub_set_pam_set_item_retval(int val);
size_t pamstub_get_pam_set_item_calls(void);
void pamstub_set_pam_set_item_callback(void(*cb)(pam_handle_t *pamh, int item_type, const void *item));

/* pam_get_item.c */
void pamstub_set_pam_get_user_retval(int val);
size_t pamstub_get_pam_get_user_calls();
void pamstub_set_pam_get_user_callback(void(*cb)(pam_handle_t *pamh, const char **user, const char *prompt));

#endif /* __INCLUDE_PAM_STUBS_H__ */
