/*
** check_view.c for check_view in /home/wang_c//Desktop/Zappy_Final/Serveur
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 20:15:39 2011 christophe wang
** Last update Sun Jul 10 20:16:27 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serveur.h"

void	north_view(t_serv *serv, t_client *client, int cs, t_view *v)
{
  v->line = 1;
  v->x = client[cs].drone->posx;
  v->y = client[cs].drone->posy;
  v->max = client[cs].drone->posx;
  show_res(v->buffer, serv, v->y, v->x);
  while (v->line <= client[cs].drone->level)
    {
      v->x--;
      v->max++;
      v->delta = v->x;
      if (--v->y < 0)
	v->y = serv->world_y - 1;
      while (v->delta <= v->max)
	{
	  strcat(v->buffer, ",");
	  if (v->delta < 0)
	    show_res(v->buffer, serv, v->y, serv->world_x - abs(v->delta));
	  else if (v->delta > serv->world_x - 1)
	    show_res(v->buffer, serv, v->y, 0 + v->delta - serv->world_x);
	  else
	    show_res(v->buffer, serv, v->y, v->delta);
	  v->delta++;
	}
      v->line++;
    }
}

void	east_view(t_serv *serv, t_client *client, int cs, t_view *v)
{
  v->line = 1;
  v->x = client[cs].drone->posx;
  v->y = client[cs].drone->posy;
  v->max = client[cs].drone->posy;
  show_res(v->buffer, serv, v->y, v->x);
  while (v->line <= client[cs].drone->level)
    {
      v->y--;
      v->max++;
      v->delta = v->y;
      if (++v->x > serv->world_x - 1)
	v->x = 0;
      while (v->delta <= v->max)
	{
	  strcat(v->buffer, ",");
	  if (v->delta < 0)
	      show_res(v->buffer, serv, serv->world_y - abs(v->delta), v->x);
	  else if (v->delta > serv->world_x - 1)
	      show_res(v->buffer, serv, 0 + v->delta - serv->world_y, v->x);
	  else
	      show_res(v->buffer, serv, v->delta, v->x);
	  v->delta++;
	}
      v->line++;
    }
}

void	south_view(t_serv *serv, t_client *client, int cs, t_view *v)
{
  v->line = 1;
  v->x = client[cs].drone->posx;
  v->y = client[cs].drone->posy;
  v->max = client[cs].drone->posx;
  show_res(v->buffer, serv, v->y, v->x);
  while (v->line <= client[cs].drone->level)
    {
      v->x++;
      v->max--;
      v->delta = v->x;
      if (++v->y > serv->world_y - 1)
	v->y = 0;
      while (v->delta >= v->max)
	{
	  strcat(v->buffer, ",");
	  if (v->delta < 0)
	    show_res(v->buffer, serv, v->y, serv->world_x - abs(v->delta));
	  else if (v->delta > serv->world_x - 1)
	    show_res(v->buffer, serv, v->y, 0 + v->delta - serv->world_x);
	  else
	    show_res(v->buffer, serv, v->y, v->delta);
	  v->delta--;
	}
      v->line++;
    }
}

void	west_view(t_serv *serv, t_client *client, int cs, t_view *v)
{
  v->line = 1;
  v->x = client[cs].drone->posx;
  v->y = client[cs].drone->posy;
  v->max = client[cs].drone->posy;
  show_res(v->buffer, serv, v->y, v->x);
  while (v->line <= client[cs].drone->level)
    {
      v->y++;
      v->max--;
      v->delta = v->y;
      if (--v->x < 0)
	v->x = serv->world_x - 1;
      while (v->delta >= v->max)
	{
	  strcat(v->buffer, ",");
	  if (v->delta < 0)
	      show_res(v->buffer, serv, serv->world_y - abs(v->delta), v->x);
	  else if (v->delta > serv->world_x - 1)
	      show_res(v->buffer, serv, 0 + v->delta - serv->world_y, v->x);
	  else
	      show_res(v->buffer, serv, v->delta, v->x);
	  v->delta--;
	}
      v->line++;
    }
}
