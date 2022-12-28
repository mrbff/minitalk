#include <signal.h>
#include <sys/types.h>
#include "../libft/libft.h"
#include <stdio.h>

void ft_handler(int sig)
{
	static int	n;
	static int	c;
	
	if (n < 8)
	{
		c += (sig == SIGUSR1) << n;
		n++;
	}
	else
	{
		ft_putchar_fd(c, 1);
		n = 0;
		c = 0;
	}
}

int main()
{
	ft_printf("PID: %i\n", getpid());
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		usleep(1000000);
	return (0);
}
