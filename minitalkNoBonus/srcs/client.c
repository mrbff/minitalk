#include "../minitalk.h"

void	ft_sendChar(int pid_receiver, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
        {
                if (c % 2)
			kill(pid_receiver, SIGUSR1);
                else
			kill(pid_receiver, SIGUSR2);
                if (c)
			c /= 2;
                i++;
		usleep(100);
        }
}
/*
void	ft_sendPid(int pid_receiver, int pid_to_send)
{
	int     i;

        i = 0;
        while (i < (int)(sizeof(int) * 8))
        {
                if (pid_to_send % 2)
			kill(pid_receiver, SIGUSR1);
                else
			kill(pid_receiver, SIGUSR2);
                if (pid_to_send)
                        pid_to_send /= 2;
		i++;
                usleep(1);
        }
}
*//*
void    ft_exit(int sig)
{
	(void)sig;
	write(1, "Message was sent correctly!", 27);
	sleep(1);
	exit(0);
}
*/
int	main(int ac, char **av)
{
	int	i;
	int	serverpid;
//	int	cpid;

	if (ac != 3)
		return (ft_printf("Wrong number of arguments.\n"));
//	signal(SIGUSR1, ft_exit);
	serverpid = ft_atoi(av[1]);
//	cpid = getpid();
//	ft_sendPid(serverpid, cpid);
	i = 0;
	while (av[2][i])
	{
		ft_sendChar(serverpid, av[2][i]);
		i++;
//		usleep(10);
	}
//	ft_sendChar(serverpid, 0);
//	pause();
	return (0);
}
