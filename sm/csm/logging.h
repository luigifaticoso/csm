#ifndef SM_LOGGING_H
#define SM_LOGGING_H

extern const char * sm_program_name;

void sm_set_program_name(const char*);
void sm_abort(const char *msg, ...);
void sm_debug(const char *msg, ...);
void sm_error(const char *msg, ...);
void sm_info(const char *msg, ...);

#endif
