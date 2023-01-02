#include "../minitalk.h"
/*
void	ft_finish(t_clpid *pcpid)
{
	kill(pcpid->pid, SIGUSR1);
	pcpid->count = 0;
	pcpid->pid = 0;
}
*/
void	ft_receiver(int sig)
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
		write(1, &c, 1);
		nbits = 0;
                c = 0;
	}
}
/*
void	ft_handler(int sig)
{
	static t_clpid	cpid;

	if (cpid.count > (int)(sizeof(int) * 8) - 1)
		ft_receiveChar(sig, &cpid);
	else if (cpid.count < (int)(sizeof(int) * 8) - 1)
	{
		cpid.pid += (sig == SIGUSR1) << cpid.count;
		cpid.count++;
	}
	else
	{
		cpid.pid += (sig == SIGUSR1) << cpid.count;
		cpid.count++;
	}
}
*/
int main()
{
	ft_printf("PID: %i\n", getpid());
	signal(SIGUSR1, ft_receiver);
	signal(SIGUSR2, ft_receiver);
	while (1)
		pause();//usleep(1);
	return (0);
}
