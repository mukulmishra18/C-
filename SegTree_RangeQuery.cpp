#include <bits/stdc++.h>
using namespace std;

#define MAX_VALUE 1000007;

//Construction of segmented tree
void ConstructTree(int SegTree[], int input[], int low, int high, int root)
{
	if(low > high)
		return;    // Out of bound

	if(low == high)
	{
		SegTree[root] = input[low];
		return;
	}

	int mid = (low + high)/2;

	ConstructTree(SegTree, input, low, mid, 2*root + 1);
	ConstructTree(SegTree, input, mid + 1, high, 2*root + 2);

	SegTree[root] = min(SegTree[2*root + 1], SegTree[2*root + 2]);

}

//Range Query function for search of minimum in given range
int RangeQuery(int SegTree[], int qlow, int qhigh, int low, int high, int root)
{
	if(qlow <= low && qhigh >= high)
		return SegTree[root];       // Overlapping case

	if(qlow > high || qhigh < low)
		return MAX_VALUE;        // No overlap

	int mid = (low + high)/2;

	return min(RangeQuery(SegTree, qlow, qhigh, low, mid, 2*root + 1), RangeQuery(SegTree, qlow, qhigh, mid + 1, high, 2*root + 2));
}

int main()
{
	int n, i;
	cout << "Number of elements in array: ";
	cin >> n;

	int input[n];

	cout << "Enter elements of array:" << endl;
	for(i=0; i<n; i++)
	{
		cin >> input[i];
	}

	int size, x;

	x = ceil(log2(n));
	size = 2*(pow(2, x)) - 1;

	int SegTree[size];

	ConstructTree(SegTree, input, 0, n-1, 0);

	int query, qlow, qhigh;

	cout << "Enter number of queries:" << endl;
	cin >> query;

	for(i=0; i<query; i++)
	{
  	    cout << "Enter range for search of min:" << endl;
		cin >> qlow >> qhigh;
		cout << "Minimum in given range is " << RangeQuery(SegTree, qlow, qhigh, 0, n-1, 0) << endl;
	}


	return 0;
}
