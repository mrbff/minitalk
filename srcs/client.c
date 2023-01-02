/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:42:11 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/02 20:39:31 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_send_char(int pid_receiver, unsigned char c)
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
		usleep(50);
	}
}

void	ft_send_pid(int pid_receiver, int pid_to_send)
{
	int	i;

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
		usleep(100);
	}
}

void	ft_exit(int sig)
{
	(void)sig;
	write(1, "The message was sent successfully!\n", 36);
	exit(0);
}

int	main(int ac, char **av)
{
	int	i;
	int	serverpid;
	int	cpid;

	if (ac != 3)
		return (ft_printf("Wrong number of arguments.\n"));
	signal(SIGUSR1, ft_exit);
	serverpid = ft_atoi(av[1]);
	cpid = getpid();
	ft_send_pid(serverpid, cpid);
	i = 0;
	while (av[2][i])
	{
		ft_send_char(serverpid, av[2][i]);
		i++;
	}
	ft_send_char(serverpid, 0);
	pause();
	return (0);
}
