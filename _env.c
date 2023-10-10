#include "main.h"
void env(void)
{
              int i;
	      char newline = '\n';
              for (i=0; environ[i]!=NULL; i++)
	      {	      
		      write(1, environ[i], strlen(environ[i]));
              }
	       write(1, &newline, 1);
}
