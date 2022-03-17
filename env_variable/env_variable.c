#include "env_variable.h"

#define MAX_ENV (512)

typedef struct s_env_variable
{
	const char* key;
	const char* value;
}				t_env_variable;

static t_env_variable* get_instance(void)
{
	static t_env_variables[MAX_ENV];

	return t_env_variables;
}

const char* get_env_variable_or_null(const char* key)
{

}

void register_env_variable(const char* key, const char* value);
void remove_env_variable(const char* key);