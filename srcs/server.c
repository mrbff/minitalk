/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:43:48 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/02 20:08:55 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_finish(t_clpid *pcpid)
{
	kill(pcpid->pid, SIGUSR1);
	pcpid->count = 0;
	pcpid->pid = 0;
}

void	ft_receive_char(int sig, t_clpid *pcpid)
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
		if (c)
			write(1, &c, 1);
		else
			ft_finish(pcpid);
		nbits = 0;
		c = 0;
	}
}

void	ft_handler(int sig)
{
	static t_clpid	cpid;

	if (cpid.count > (int)(sizeof(int) * 8) - 1)
		ft_receive_char(sig, &cpid);
	else
	{
		cpid.pid += (sig == SIGUSR1) << cpid.count;
		cpid.count++;
	}
}

int	main(void)
{
	ft_printf("PID: %i\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
	}
	return (0);
}
