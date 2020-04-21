#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//int stack[100];
char cmd[10];
int last = 0, temp;
long long razmer = 0, r = 0,lb = 0;
int* ar;
int Nn = 0;

void plusb(int nov)
{
	r += 100;
	//razmer++;
	//Nn += razmer;
	int* mas = (int*)malloc(r * sizeof(int));
	for (int i = lb; i < razmer - 1; i++)
	{
		mas[i] = ar[i];
	}
	mas[razmer - 1] = nov;
	if (r > 100)
		free(ar);
	ar = mas;
	//free(mas);
}

void plusf(int nov)
{
	r += 100;
	razmer += 49;
	lb += 49;
	//Nn += razmer;
	int* mas = (int*)malloc(r * sizeof(int));
	for (int i = razmer - 1; i > lb; i--)
	{
		mas[i] = ar[i - 50];
	}
	mas[lb] = nov;
	if (r > 100)
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
		ar[i] = ar[i + 1];
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
				if (razmer != lb)
				{
					printf("%d\n", ar[lb]);
					lb++;
				}
				else printf("error\n");
			}
			else
			{
				if (razmer != lb)
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
				if (razmer < r - 2)
				{
					if (lb <= 0)
					{
						razmer++;
						for (int i = razmer - 1; i > 0; i--)
						{
							ar[i] = ar[i - 1];
						}
						ar[0] = temp;
					}
					else
					{
						lb--;
						ar[lb] = temp;
					}
				}
				else
				{
					if (lb <= 0)
					{
						razmer++;
						plusf(temp);
					}
					else
					{
						lb--;
						ar[lb] = temp;
					}
				}
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
			printf("%lld\n", razmer - lb);
		}
		else if (cmd[0] == 'f' && cmd[1] == 'r')
		{
			if (razmer != lb)
			{
				printf("%d\n", ar[lb]);
			}
			else printf("error\n");
		}
		else if (cmd[0] == 'b' && cmd[1] == 'a')
		{
			if (razmer != lb)
			{
				printf("%d\n", ar[razmer - 1]);
			}
			else printf("error\n");
		}
		else if (cmd[0] == 'c' && cmd[1] == 'l')
		{
			if (razmer > 100)
				free(ar);
			razmer = lb;
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
