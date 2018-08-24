#include <stdio.h>
#include <stdlib.h>

int len(char *s)
{
  int i = 0;
  int size = 0;
  
  while (s[i])
    {
      if (s[i] != ' ')
	size++;
      i++;
    }
  return (size);
}

void do_op(int *stack, int i, char c)
{
  if (c == '+')
    stack[i - 2] = stack[i - 2] + stack[i - 1];
  if (c == '-')
    stack[i - 2] = stack[i - 2] - stack[i - 1];
  if (c == '/')
    stack[i - 2] = stack[i - 2] / stack[i - 1];
  if (c == '*')
    stack[i - 2] = stack[i - 2] * stack[i - 1];
}

void calc(char *s)
{
  int *stack;
  int i;

  stack = 0;
  stack = malloc(sizeof(*stack) * len(s));
  i = 0;
  while (*s)
    {
      if (*s >= '0' && *s <= '9')
	{
	  stack[i] = *s - '0'; // push into stack
	  i++;
	}
      if (*s == '+' || *s == '-' || *s == '/' || *s == '*')
	{
	  do_op(stack, i, *s); // do operation and push the result into stack
	  i -= 1;
	  stack[i] = '\0';
	}
      s++;
    }
  if (stack[1] == '\0')
    printf("%d\n", stack[0]);
  else
    printf("Error\n");
}

int main(int ac, char **av)
{
  if (ac == 2)
    {
      calc(av[1]);
    }
  return(0);
}
