/*

Problem: Given a set of coins and a sum, find minimum numbers of coins that is needed to make 
given sum.

This problem is solved by Top Down DP.
We calculate for any x, and store it in map<int, int>
ans whenever it is required we can use it. 

*/


#include <bits/stdc++.h>
using namespace std;

#define MAX_VALUE INT_MAX   // Maximum value of an Integer


// Function calculating minimum number of coins required recursively.
int CoinsChange(int n, int coins[], int sum, map<int, int> mp)
{
	if(sum == 0) // If current sum is 0, return 0.
		return 0;

	if(mp.find(sum) != mp.end()) // If solution for current sum is present in map, return it.
		return mp[sum];

	int i, val, min = MAX_VALUE;

	// Calculating for all coins that are smaller that current sum.
	for(i=0; i<n; i++)	
	{
		if(coins[i] <= sum)
			val = CoinsChange(n, coins, sum-coins[i], mp);

		if(val < min)
			min = val;
	}

	// If min == MAX_VALUE then there is no solution for current sum.
	min = (min==MAX_VALUE)?min:(min+1);

	mp[sum] = min;	// Mapping current solution.

	return min;
}

int main()
{
	int n;
	cout << "Enter numbers of coins: ";
	cin >> n;

	int i, coins[n];
	cout << "Enter coins value: ";

	for(i=0; i<n; i++)
		cin >> coins[i];

	int sum;
	cout << "Enter sum: ";
	cin >> sum;

	map<int, int> mp;
	mp[0] = 0;

	cout << "Minimum number of coins required: " << CoinsChange(n, coins, sum, mp) << endl;
	
	return 0;
}
