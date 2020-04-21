#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char cmd[10];
int last = 0, temp;
long long razmer = 0,r = 0;
int* ar;
int Nn = 0;

void plus(int nov)
{
	r += 10;
	int* mas = (int*)malloc(r * sizeof(int));
	for (int i = 0; i < razmer - 1; i++)
	{
		mas[i] = ar[i];
	}
	mas[razmer - 1] = nov;
	if (r > 10)
		free(ar);
	ar = mas;
}
int main()
{
	while (1)
	{
		scanf("%s", &cmd);
		if (cmd[0] == 'p' && cmd[1] == 'o')
		{
			if (razmer != 0)
			{
				printf("%d\n", ar[razmer - 1]);
				razmer--;
			}
			else printf("error\n");

		}
		else if (cmd[0] == 'p' && cmd[1] == 'u')
		{
			scanf("%d", &temp);
			razmer++;
			if (razmer < r - 2)
			{
				ar[razmer -1] = temp;
			}
			else
			plus(temp);
			printf("ok\n");
		}
		else if (cmd[0] == 's' && cmd[1] == 'i')
		{
			printf("%lld\n", razmer);
		}
		else if (cmd[0] == 'b' && cmd[1] == 'a')
		{
			if (razmer != 0)
			{
				printf("%d\n", ar[razmer - 1]);
			}
			else printf("error\n");
		}
		else if (cmd[0] == 'c' && cmd[1] == 'l')
		{
			if (razmer > 100)
				free(ar);
			razmer = 0;
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
