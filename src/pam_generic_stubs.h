#ifndef __SRC_PAM_GENERIC_STUBS_H__
#define __SRC_PAM_GENERIC_STUBS_H__

#define SET_RETVAL(name, t)  \
	static t _retval; \
	void pamstub_set_##name##_retval(t val) { \
		_retval = val; \
	}

#define GET_NCALLS(name) \
	static size_t _ncalls; \
	size_t pamstub_get_##name##_calls(void) { \
		size_t ret = _ncalls; \
		_ncalls = 0; \
		return ret; \
	}


#endif /* __SRC_PAM_GENERIC_STUBS_H__ */
