/*
Given coins of different dominations and a sum, how many ways to form this sum
using given coins.


Basic Formula:
if(curr_total >= curr_coin)
	DP[i][j] = DP[i-1][j] + DP[i][j - coins[i]]
else
	DP[i][j] = DP[i-1][j-1]

*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i, j, n;
	cout << "Enter numbers of coins: ";
	cin >> n;

	int coins[n];
	cout << "Enter coins value: ";
	for(i=0; i<n; i++)
		cin >> coins[i];

	int total;
	cout << "Enter desired total: ";
	cin >> total;

	int DP[n][total+1];  // Container to hold intermediate sum.

	for(i=0; i<n; i++) // If total sum is zero than number of ways is 1 for all coins.
		DP[i][0] = 1;

	for(j=1; j<=total; j++)
	{
		if(j%coins[0] == 0)  // If there is only one coin than number of ways is 1 if current total is 
			DP[0][j] = 1;    // divisible by current coin,
		else				// else number of ways is 0.
			DP[0][j] = 0;
	}

	for(i=1; i<n; i++)
	{
		for(j=1; j<=total; j++)
		{
			if(j >= coins[i])
				DP[i][j] = DP[i-1][j] + DP[i][j - coins[i]];
			else
				DP[i][j] = DP[i-1][j];
		}
	}


	cout << "Numbers of ways to form " << total << " is " << DP[n-1][total] << endl;

	return 0;
}
