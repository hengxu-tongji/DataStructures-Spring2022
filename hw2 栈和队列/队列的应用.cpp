#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int a[1000][1000];
int check(int i, int j, int n, int m) {
	if (i < 0 || j < 0 || i >= n || j >= m);
	if (i - 1 >= 0 && a[i - 1][j] == 1)
	{
		a[i - 1][j] = -1;
		check(i - 1, j, n, m);
	}
	if (j - 1 >= 0 && a[i][j - 1] == 1)
	{
		a[i][j - 1] = -1;check(i, j - 1, n, m);
	}
	if (i + 1 < n && a[i + 1][j] == 1)
	{
		a[i + 1][j] = -1;check(i + 1, j, n, m);
	}
	if (j + 1 < m && a[i][j + 1] == 1)
	{
		a[i][j + 1] = -1; check(i, j + 1, n, m);
	}
	return 0;
}
int main() {
	int i, j, m, n, k = 0;
	cin >> n >> m;
	for (i = 0;i < n;i++)
		for (j = 0;j < m;j++)
			cin >> a[i][j];
	for (i = 1;i < n - 1;i++)
		for (j = 1;j < m - 1;j++)
			if (a[i][j] == 1) {
				check(i, j, n, m);
				a[i][j] = -1;
				k++;
			}
	cout << k << endl;
	return 0;
}