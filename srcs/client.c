#include <signal.h>
#include <sys/types.h>
#include "../libft/libft.h"

void	ft_sendChar(int pid, int c)
{
	int	i;

	i = 0;
	while (i < 8)
        {
                if (c % 2)
                {       kill(pid, SIGUSR1);
      //                  write(1, "1", 1);
                }
                else
                {       kill(pid, SIGUSR2);
        //                write(1, "0", 1);
                }
                if (c > 0)
                        c /= 2;
                i++;
                usleep(1);
        }
}

void	ft_sendDim(int pid, size_t dim)
{
	int     i;

        i = 0;
        while (i < (int)(sizeof(size_t) * 8))
        {
                if (dim % 2)
                {       kill(pid, SIGUSR1);
      //                  write(1, "1", 1);
                }
                else
                {       kill(pid, SIGUSR2);
        //                write(1, "0", 1);
                }
                if (dim > 0)
                        dim /= 2;
                i++;
                usleep(1);
        }
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;
	size_t	dim;

	if (ac != 3)
		return (ft_printf("Wrong number of arguments.\n"));
	pid = ft_atoi(av[1]);
	dim = ft_strlen(av[2]);
	ft_sendDim(pid, dim);
	i = 0;
	while (av[2][i])
	{
		ft_sendChar(pid, av[2][i]);
		i++;
		usleep(1);
	}
/*	write(1, "\n", 1);*/
	return (0);
}
