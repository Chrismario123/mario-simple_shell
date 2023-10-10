#include "main.h"
void freemem(char **args)
{
        if (args == NULL)
                return;
for (int j = 0;  args[j]; j++)
{
        if (args[j] != NULL)
        {
                free(args[j]);
        }
}
if (args != NULL)
        free(args);
}
