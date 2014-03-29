/*
** init_select.c for init_select in /home/wang_c//Desktop/Zappy_Final/Serveur
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 19:48:27 2011 christophe wang
** Last update Sun Jul 10 19:56:04 2011 christophe wang
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur.h"

long		timer_egg(t_serv *serv, long tmp)
{
  int		i;

  i = 0;
  while (i < serv->nb_eggs)
    {
      if (serv->egg[i].state == ACTIVE)
	{
	  if (!tmp || (tmp > serv->egg[i].hatch && serv->egg[i].hatch > 0))
	    tmp = serv->egg[i].hatch;
	}
      i++;
    }
  return (tmp);
}

void		check_fd(t_serv *serv, t_client *client, fd_set *rd, fd_set *wr)
{
  int		cs;
  int		i;

  i = 0;
  while (i < serv->limit)
    {
      if (FD_ISSET(i, rd))
	{
	  if ((cs = serv->fct_read[i](serv, client, i)) < serv->limit)
	    FD_SET(i, wr);
	}
      if (FD_ISSET(i, wr))
	serv->fct_write[i](serv, client, cs);
      i++;
    }
}

void		init_select(t_serv *serv, t_client *client, fd_set *rd, fd_set *wr)
{
  int			i;
  long			tmp;

  i = 0;
  tmp = 0;
  while (i < serv->limit)
    {
      if (serv->fd_type[i] == FD_CLIENT)
	{
	  if (!tmp || (tmp > client[i].timelaps && client[i].timelaps > 0))
	    tmp = client[i].timelaps;
	  if (!tmp || (tmp > client[i].timelife && client[i].timelife > 0))
	    tmp = client[i].timelife;
	}
      i++;
    }
  tmp = timer_egg(serv, tmp);
  serv->timeout.tv_sec = tmp / 1000000;
  serv->timeout.tv_usec = tmp - (serv->timeout.tv_sec * 1000000);
  printf(TIMEOUT, W, serv->timeout.tv_sec, serv->timeout.tv_usec, D);
  FD_ZERO(rd);
  FD_ZERO(wr);
}
