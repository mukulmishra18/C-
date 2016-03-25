/*

Given set of coins of infinite supply we have to find minimum coins to make 
given sum.

Basic formula:
if(coin[i] >= sum)
	DP[i][j] = max(DP[i-1][j], 1+DP[i-coin[i]][j])
else
	DP[i][j] = DP[i-1][j]

*/


#include <bits/stdc++.h>
using namespace std;

#define MAX_VALUE 1000000007  // Defining maximum value 

int min(int a, int b)
{
	return(a<b?a:b);
}

int main()
{
	int n;
	cout << "Enter number of coins: ";
	cin >> n;

	int coins[n], i, sum, j;

	cout << "Enter values of coins: ";
	for(i=0; i<n; i++)
		cin >> coins[i];

	cout << "Enter sum: ";
	cin >> sum;

	int DP[n][sum+1];

	// Populating DP to find sum using minimum coins
	for(i=0; i<n; i++)
		DP[i][0] = 0;

	for(i=1; i<=sum; i++)
	{
		if(i >= coins[0] && i%coins[0] == 0)
			DP[0][i] = i/coins[0];
		else
			DP[0][i] = MAX_VALUE;
	}

	for(i=1; i<n; i++)
	{
		for(j=1; j<=sum; j++)
		{
			if(j >= coins[i])
				DP[i][j] = min(DP[i-1][j], 1 + DP[i][j-coins[i]]);
			else
				DP[i][j] = DP[i-1][j];
		}
	}

	vector<int> ans; // Container to hold coins
	i = sum;
	j = n-1;

	// Finding coins that are used
	while(i > 0)
	{
		if(DP[j][i] == DP[j-1][i])
			j--;
		else
		{
			ans.push_back(coins[j]);
			i -= coins[j];
		}
	}

	cout << "Minimum numbers of coins required to make given sum is: " << DP[n-1][sum] << endl;
	cout << "Coins that are taken are: " << endl;

	for(i=0; i<ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;

	return 0;	
}
