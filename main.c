#include  "main.h"
/**
 * Demonstrating strtok and getline function
 */
int main(void)
{       
int i = 0;
char *content = NULL;
size_t buffsize = 0;
size_t bytereturned = 0;
char *token = NULL;
int interactive = 1;
extern char **environ;



while (1)
{
interactive = isatty(STDIN_FILENO);

char **args = malloc(10 * sizeof(char *));
if (interactive != 0)
	write(1, "$ ", 2);
i = 0;
bytereturned = getline(&content, &buffsize, stdin);
//  today is simple
token = strtok(content, " \n\t\r");
while (token != NULL)
{
  args[i] = malloc(sizeof(char) * (strlen(token) + 1));
  strcpy(args[i], token);
  i++;
  token = strtok(NULL, " \n\t\r");
}
if (i  == 0)
{
	free(args);
	continue;
}
args[i] = NULL;
if (strcmp(args[0], "exit") == 0)
{
	freemem(args);
	break;

}
if (strcmp(args[0], "env") == 0)
{

	env();
	freemem(args);
	continue;
}
if (interactive == 0)
	break;

_process(args);
if (bytereturned > 1)
{

if (args[0] != NULL)
{
freemem(args);
}
}
}
if (content != NULL)
	free(content);
}
