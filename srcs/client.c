#include <signal.h>
#include <sys/types.h>
#include "../libft/libft.h"

int main(int ac, char **av)
{
	if (ac != 3)
		return (-1);
	while (av[2][0] >= 0)
	{
		if (av[2][0] % 2)
			kill(ft_atoi(av[1]), SIGUSR1);
		else
			kill(ft_atoi(av[1]), SIGUSR2);
		if (av[2][0] != 0)
			av[2][0] /= 2;
		else
			av[2][0] = -1;
	}
	return (0);
}
