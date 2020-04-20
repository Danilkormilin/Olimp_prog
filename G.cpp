#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//int stack[100];
char cmd[10];
int last = 0, temp;
long long razmer = 0,r = 0;
int* ar;
int Nn = 0;

void plusb(int nov)
{
	r += 10;
	//razmer++;
	//Nn += razmer;
	int* mas = (int*)malloc(r * sizeof(int));
	for (int i = 0; i < razmer - 1; i++)
	{
		mas[i] = ar[i];
	}
	mas[razmer - 1] = nov;
	if (r > 10)
		free(ar);
	ar = mas;
	//free(mas);
}

void plusf(int nov)
{
	r += 10;
	//razmer++;
	//Nn += razmer;
	int* mas = (int*)malloc(r * sizeof(int));
	for (int i = razmer - 1; i > 0; i--)
	{
		mas[i] = ar[i-1];
	}
	mas[0] = nov;
	if (r > 10)
		free(ar);
	ar = mas;
	//free(mas);
}

void minus()
{
	razmer--;
	//int* mas = (int*)malloc(razmer * sizeof(int));
	for (int i = 0; i < razmer; i++)
	{
		ar[i] = ar[i+1];
	}
	//if(razmer > 20)
	//free(ar);
	//ar = mas;
}
int main()
{
	while (1)
	{
		scanf("%s", &cmd);
		if (cmd[0] == 'p' && cmd[1] == 'o')
		{
			if (cmd[4] == 'f' && cmd[5] == 'r')
			{
				if (razmer != 0)
				{
					printf("%d\n", ar[0]);
					minus();
				}
				else printf("error\n");
			}
			else
			{
				if (razmer != 0)
				{
					printf("%d\n", ar[razmer - 1]);
					razmer--;
				}
				else printf("error\n");
			}
		}
		else if (cmd[0] == 'p' && cmd[1] == 'u')
		{
			if (cmd[5] == 'f' && cmd[6] == 'r')
			{
				scanf("%d", &temp);
				razmer++;
				if (razmer < r - 2)
				{
					for (int i = razmer - 1; i > 0; i--)
					{
						ar[i] = ar[i - 1];
					}
					ar[0] = temp;
				}
				else
					plusf(temp);
				printf("ok\n");
			}
			else
			{
				scanf("%d", &temp);
				razmer++;
				if (razmer < r - 2)
				{
					ar[razmer - 1] = temp;
				}
				else
					plusb(temp);
				printf("ok\n");
			}
		}
		else if (cmd[0] == 's' && cmd[1] == 'i')
		{
			printf("%lld\n", razmer);
		}
		else if (cmd[0] == 'f' && cmd[1] == 'r')
		{
			if (razmer != 0)
			{
				printf("%d\n", ar[0]);
			}
			else printf("error\n");
		}
		else if (cmd[0] == 'b' && cmd[1] == 'a')
		{
			printf("%d\n", ar[razmer - 1]);
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
			//if (razmer > 1)
			//	free(ar);
			return(0);
		}
	}
	return (0);
}
