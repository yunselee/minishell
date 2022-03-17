#ifndef ENV_VARIABLE_H
#define ENV_VARIABLE_H

const char* get_env_variable_or_null(const char* key);
void register_env_variable(const char* key, const char* value);
void remove_env_variable(const char* key);

#endif /* ENV_VARIABLE_H */