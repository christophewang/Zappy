/*
** check_signal.c for check_signal in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:12:33 2011 christophe wang
** Last update Sun Jul 10 15:12:37 2011 christophe wang
*/

#include <signal.h>
#include <stdio.h>
#include "serveur.h"

static void		handler(int sig)
{
  if (sig == SIGINT)
    printf("%s%s", B, SIGC);
  if (sig == SIGQUIT)
    printf("%s%s", B, SIGQ);
  g_exit = 0;
}

void		check_signal(void)
{
  xsignal(SIGINT, handler);
  xsignal(SIGHUP, handler);
  xsignal(SIGQUIT, handler);
}

