#include <signal.h>
#include <sys/types.h>
#include "../libft/libft.h"
#include <stdio.h>

char	*mex;

typedef struct s_md
{
	size_t	dim;
	int	count;
}	t_md;

void	ft_finish(t_md *pmd)
{
	pmd->dim = 0;
	pmd->count = 0;
//	if (mex != NULL)
//		free(mex);
	//kill client
}

void	ft_addLastByte(int c, t_md *pmd)
{
	static	size_t	nbytes;

	if (!mex || mex == NULL)
	{
		if (pmd->dim > 0)
			mex = malloc(pmd->dim);
		else
			mex = malloc(1);
		if (!mex)
			return ;
	}
	if (nbytes < pmd->dim - 1)
	{
		mex[nbytes] = c;
		nbytes++;
	}
	else
	{
		mex[nbytes] = c;
		printf("\ndim: %lu\n", pmd->dim);///
		write(1, mex, pmd->dim);
		//printf("%s\n", mex);
		nbytes = 0;
		ft_finish(pmd);
	}
}

void	ft_receiveChar(int sig, t_md *pmd)
{
	static int	nbits;
	static int	c;
	
	if (nbits < 7)
	{
		c += (sig == SIGUSR1) << nbits;
		nbits++;
	}
	else
	{
                c += (sig == SIGUSR1) << nbits;
		ft_addLastByte(c, pmd);
		nbits = 0;
		c = 0;
	}
}

void	ft_handler(int sig)
{
	static t_md	md;

	if (md.count > (int)(sizeof(size_t) * 8) - 1)
		ft_receiveChar(sig, &md);
	else if (md.count < (int)(sizeof(size_t) * 8) - 1)
	{
		md.dim += (sig == SIGUSR1) << md.count;
		md.count++;
	}
	else
	{
		md.dim += (sig == SIGUSR1) << md.count;
///		printf("\ndim: %lu\n", md.dim);///
		md.count++;
	}
}

int main()
{
	ft_printf("PID: %i\n", getpid());
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		usleep(1);
	return (0);
}
