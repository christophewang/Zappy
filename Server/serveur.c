/*
** serveur.c for serveur in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:16:51 2011 christophe wang
** Last update Sun Jul 10 15:16:53 2011 christophe wang
*/

#include <stdlib.h>
#include <stdio.h>
#include "serveur.h"

int			main(int argc, char **argv)
{
  t_serv		serveur;

  (void)argc;
  if (!init_serveur(&serveur, argv))
    start_serveur(&serveur);
  else if (!serveur.nb_team)
    printf("%s", USAGE);
  return (EXIT_SUCCESS);
}
