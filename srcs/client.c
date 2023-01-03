/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:42:11 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/03 11:35:44 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_send(int pid_receiver, unsigned int c, int nbits)
{
	int	i;

	i = 0;
	while (i < nbits)
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
	ft_send(serverpid, cpid, sizeof(int) * 8);
	i = 0;
	while (av[2][i])
	{
		ft_send(serverpid, av[2][i], sizeof(char) * 8);
		i++;
	}
	ft_send(serverpid, 0, sizeof(char) * 8);
	pause();
	return (0);
}
