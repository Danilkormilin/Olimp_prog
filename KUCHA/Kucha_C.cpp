#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct kucha
{
	int end;
	int data[500000];
}kucha;

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
	int temp,tt;
	while (n < k->end && n * 2 + ((k->data[n * 2 + 1] <= k->data[n * 2 + 2] && n*2 + 2 <= k->end)?(2):(1)) <= k->end && k->data[n] < k->data[n*2 + ((k->data[n * 2 + 1] <= k->data[n * 2 + 2] && n * 2 + 2 <= k->end) ? (2) : (1))])
	{
		temp = k->data[n];
		tt = n * 2 + ((k->data[n * 2 + 1] <= k->data[n * 2 + 2] && n * 2 + 2 <= k->end) ? (2) : (1));
		k->data[n] = k->data[tt];
		k->data[tt] = temp;
		n = tt;
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

int Ext_max(kucha* k)
{
	k->data[0] = k->data[k->end];
	k->end--;
	return (sift_down(0, k));
}
kucha K;
int main()
{
	int n,n1, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &K.data[i]);
		K.end = i;
	}
	for (int i = 0; i < n - 1; i++)
	{
		m = K.data[0];
		printf("%d %d\n",Ext_max(&K) +1 ,m);
	}
}
