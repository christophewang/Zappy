/*
** manage_command.c for manage_command in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:15:11 2011 christophe wang
** Last update Sun Jul 10 19:42:29 2011 christophe wang
*/

#include <stdio.h>
#include <string.h>
#include "serveur.h"

t_cmd		cmd_tab[13] = {
  {"avance", avance},
  {"droite", droite},
  {"gauche", gauche},
  {"voir", voir},
  {"inventaire", inventaire},
  {"prend", prend},
  {"pose", pose},
  {"expulse", expulse},
  {"broadcast", broadcast},
  {"connect_nbr", connect_nbr},
  {"incantation", incantation},
  {"fork", fork_cmd},
  {NULL, NULL},
};

t_graph		graph_tab[10] = {
  {"msz", msz},
  {"bct", cmd_bct},
  {"mct", bct},
  {"tna", tna},
  {"ppo", cmd_ppo},
  {"plv", cmd_plv},
  {"pin", cmd_pin},
  {"sgt", sgt},
  {"sst", cmd_sst},
  {NULL, NULL},
};

void		init_commandlist(t_client *client, int cs)
{
  int			i;

  i = 0;
  while (i < 10)
    {
      memset(client[cs].request[i], 0, BUFF_SIZE);
      client[cs].request[i][0] = '\n';
      i++;
    }
}

void		delete_command(t_client *client, int cs)
{
  int		i;

  i = 0;
  while (i < 10)
    {
      memset(client[cs].request[i], 0, BUFF_SIZE);
      if (i == 9)
	client[cs].request[i][0] = '\n';
      else
	strncpy(client[cs].request[i], client[cs].request[i + 1],
		strlen(client[cs].request[i + 1]));
      i++;
    }
  client[cs].flag = 0;
}

void		get_command(t_client *client, int cs)
{
  int		i;
  int		j;
  int		h;

  i = 0;
  h = 0;
  while (i < 10)
    {
      j = strlen(client[cs].request[i]) - 1;
      if (client[cs].request[i][j] != '\n')
	{
	  j = strlen(client[cs].request[i]);
	  while (client[cs].buffer[h] != '\n' && client[cs].buffer[h] != '\0')
	    client[cs].request[i][j++] = client[cs].buffer[h++];
	}
      else if (client[cs].request[i][0] == '\n')
	{
	  while (client[cs].buffer[h] != '\n' && client[cs].buffer[h] != '\0')
	    client[cs].request[i][j++] = client[cs].buffer[h++];
	}
      if (client[cs].buffer[h] == '\n')
	client[cs].request[i][j] = '\n', h++;
      i++;
    }
}

int		check_commandlist(t_serv *serveur, t_client *client, int cs)
{
  int		i;
  int		n;
  char		**tab;

  i = 0;
  tab = str_to_wordtab(client[cs].request[0], " \t\r\n");
  memset(client[cs].buffer, 0, BUFF_SIZE);
  while (cmd_tab[i].cmd != NULL)
    {
      if (tab[0] && !strcmp(cmd_tab[i].cmd, tab[0]))
	{
	  xgettimeofday(&client[cs].delay);
	  n = cmd_tab[i].ptr_func(serveur, client, cs, tab);
	  free_tab(tab);
	  return (n);
	}
      i++;
    }
  free_tab(tab);
  return (-1);
}

int		check_graphlist(t_serv *serveur, t_client *client, int cs)
{
  int		i;
  char		**tab;

  i = 0;
  tab = str_to_wordtab(client[cs].request[0], " \t\r\n");
  while (graph_tab[i].cmd != NULL)
    {
      if (tab[0] && !strcmp(graph_tab[i].cmd, tab[0]))
	{
	  graph_tab[i].ptr_func(serveur, client, cs, tab);
	  free_tab(tab);
	  return (0);
	}
      i++;
    }
  free_tab(tab);
  return (-1);
}
