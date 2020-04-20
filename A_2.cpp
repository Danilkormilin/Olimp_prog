#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct kucha
{
	int end;
	int data[100000];
}kucha;

kucha K;

int sift_up(int n, kucha* k)
{
	int temp;
	while ((n - ((n % 2 != 0) ? (1) : (2))) / 2 >= 0 && k->data[(n - ((n % 2 != 0) ? (1) : (2))) / 2] < k->data[n])
	{
		temp = k->data[n];
		k->data[n] = k->data[(n - ((n % 2 != 0) ? (1) : (2))) / 2];
		k->data[(n - ((n % 2 != 0) ? (1) : (2))) / 2] = temp;
		n = (n - ((n % 2 != 0) ? (1) : (2))) / 2;
	}
	return n;
}

int sift_down(int n, kucha* k)
{
	int temp;
	while (n * 2 + ((k->data[n * 2 + 1] >= k->data[n * 2 + 2])?(1):(2)) <= k->end && k->data[n] < k->data[n*2 + ((k->data[n * 2 + 1] >= k->data[n * 2 + 2]) ? (1) : (2))])
	{
		temp = k->data[n];
		k->data[n] = k->data[n * 2 + ((k->data[n * 2 + 1] >= k->data[n * 2 + 2]) ? (1) : (2))];
		k->data[n * 2 + ((k->data[n * 2 + 1] >= k->data[n * 2 + 2]) ? (1) : (2))] = temp;
		n = n * 2 + ((k->data[n * 2 + 1] >= k->data[n * 2 + 2]) ? (1) : (2));
	}
	return n;
}

int uppr(int x,int nom, kucha* k)
{
	k->data[nom] += x;
	return (sift_up(nom, k));
}

int dopr(int x, int nom, kucha* k)
{
	k->data[nom] -= x;
	return (sift_down(nom, k));
}

int main()
{
	int n,n1, m, x;
	kucha K;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &K.data[i]);
		K.end = i;
	}
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++)
	{
		scanf("%d%d", &m,&x);
		printf("%d\n",uppr(x, m - 1, &K) + 1);
		//dopr(x, m - 1, &K);
	}
	for (int i = 0; i < n; i++)
		printf("%d ", K.data[i]);
}
