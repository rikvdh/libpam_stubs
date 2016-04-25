#ifndef __INCLUDE_PAM_STUBS_H__
#define __INCLUDE_PAM_STUBS_H__

/* pam_strerror.c */
void pamstub_set_pam_strerror_retval(const char *val);
size_t pamstub_get_pam_strerror_calls(void);

/* pam_get_data.c */
void pamstub_set_pam_get_data_retval(int val);
size_t pamstub_get_pam_get_data_calls();

/* pam_set_data.c */
void pamstub_set_pam_set_data_retval(int val);
size_t pamstub_get_pam_set_data_calls(void);

/* pam_get_item.c */
void pamstub_set_pam_get_item_retval(int val);
size_t pamstub_get_pam_get_item_calls();

/* pam_set_item.c */
void pamstub_set_pam_set_item_retval(int val);
size_t pamstub_get_pam_set_item_calls(void);

/* pam_get_item.c */
void pamstub_set_pam_get_user_retval(int val);
size_t pamstub_get_pam_get_user_calls();

#endif /* __INCLUDE_PAM_STUBS_H__ */
