#include<stdio.h>
#include<math.h>
int stack[100];
char cmd[10];
int last = 0;
int main()
{
	while (1)
	{
		scanf("%s", &cmd);
		if (cmd[0] == 'p' && cmd[1] == 'o')
		{
			printf("%d\n", stack[last]);
			last--;
		}
		else if (cmd[0] == 'p' && cmd[1] == 'u')
		{
			last++;
			scanf("%d", &stack[last]);
			printf("ok\n");
		}
		else if (cmd[0] == 's' && cmd[1] == 'i')
		{
			printf("%d\n", last);
		}
		else if (cmd[0] == 'b' && cmd[1] == 'a')
		{
			printf("%d\n", stack[last]);
		}
		else if (cmd[0] == 'c' && cmd[1] == 'l')
		{
			last = 0;
			printf("ok\n");
		}
		else
		{
			printf("bye");
			return(0);
		}

	}
	return (0);
}
