#ifndef COMMAND_H
#define COMMAND_H

void command_echo(const char* message, char option);
void command_cd(const char* path);
void command_pwd(void);
void command_export(void);
void command_env(void);
void command_unset(void);
void command_exit(void);

#endif /* COMMAND_H */
