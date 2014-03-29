/*
** xselect.c for Xfunctions in /home/wang_c//Zappy/Xfunctions
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Thu Jun  9 19:11:11 2011 christophe wang
** Last update Tue Jun 21 17:20:21 2011 christophe wang
*/

#include <errno.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "serveur.h"

int		xselect(int n, fd_set *readfds, fd_set *writefds,
			fd_set *exceptfds, struct timeval *timeout)
{
  int		i;

  if ((i = select(n, readfds, writefds, exceptfds, timeout)) == -1)
    {
      if (errno != EINTR)
	perror("Select");
      if (errno == ENOMEM || errno == EBADF || errno == EINVAL)
	exit(EXIT_FAILURE);
      return (-1);
    }
  return (0);
}
