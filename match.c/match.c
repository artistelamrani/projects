void ft_putstr(char *s);

int cmp(char *s1, char *s2)
{
  int i;

  i = 0;
  while (s2[i] && s2[i] != '*')
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  return (1);
}

int check(char *s)
{
  int i;

  i = 0;
  while (s[i])
    {
      if (s[i] == '*')
	return (0);
      i++;
    }
  return (1);
}

int len(char *s)
{
  int i;

  i = 0;
  while (s[i])
    i++;
  return (i);
}

int match(char *s1, char *s2)
{
  while (*s1 != '\0' && *s2 != '\0')
    {
      while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
	  s1++;
	  s2++;
	}
      if (*s1 != *s2 && *s2 != '*')
	return (0);
      if (*s1 == '\0' || *s2 == '\0')
	break ;
      while (*s2 == '*')
	s2++;
      if (check(s2))
	{
	  while (*(s1 + len(s2)))
	    s1++;
	}
      while (cmp(s1 ,s2) == 0 && *s1 != '\0')
	s1++;
    }
  if (*s1 != '\0' || *s2 != '\0')
    return (0);
  return (1);
}

int main(int ac, char **av)
{
  if (ac == 3)
    {
      if (match(av[1], av[2]))
	ft_putstr("------match------\n");
      else
	ft_putstr("------No match------\n");
    }
  return (0);
}
