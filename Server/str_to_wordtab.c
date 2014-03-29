/*
** str_to_wordtab.c for str_to_wordtab in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:17:24 2011 christophe wang
** Last update Sun Jul 10 15:17:25 2011 christophe wang
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur.h"

static int		is_char(char c, char *lim)
{
  int		i;

  i = 0;
  while (lim[i] != '\0')
    {
      if (lim[i] == c)
	return (1);
      i++;
    }
  return (0);
}

static int		count_word(char *str, char *lim)
{
  int		i;
  int		word;

  i = 0;
  word = 0;
  while (str[i] != '\0')
    {
      if (is_char(str[i], lim) == 0)
	{
	  while (is_char(str[i], lim) == 0 && str[i] != '\0')
	    i++;
	  word++;
	}
      else
	i++;
    }
  return (word);
}

static int		my_strlen_tab(char *str, char *lim)
{
  int		i;
  int		len;

  i = 0;
  len = 0;
  while (str[i] != '\0')
    {
      while (is_char(str[i], lim) == 0 && str[i] != '\0')
	{
	  i++;
	  len++;
	}
      return (len);
    }
  return (len);
}

char		**str_to_wordtab(char *str, char *lim)
{
  char		**tab;
  int		word;
  int		i;
  int		j;
  int		len;

  i = 0;
  j = 0;
  word = count_word(str, lim);
  tab = xmalloc(sizeof(*tab) * (word + 1));
  while (str[i] != '\0')
    {
      if (is_char(str[i], lim) == 0)
	{
	  len = my_strlen_tab(str + i, lim);
	  tab[j] = xmalloc(sizeof(**tab) * len + 1);
	  tab[j] = strncpy(tab[j], str + i, len);
	  tab[j][len] = '\0';
	  i += len;
	  j++;
	}
      i++;
    }
  tab[j] = NULL;
  return (tab);
}
