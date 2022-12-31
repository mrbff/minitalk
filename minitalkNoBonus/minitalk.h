#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <sys/types.h>
#include "libft/libft.h"

typedef struct s_clpid
{
        int	pid;
        int	count;

}       t_clpid;

void    f_printbits(unsigned char c);
void    f_printbytes(char *s);

#endif
/*
 * f_printbits and f_printbytes
 * are just for debugging purpose
 */
