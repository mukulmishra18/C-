#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1,s2,s3,ans;
	cout << "Enter two strings\n";
	cin >> s1 >> s2;        //Taking input
	int n=s1.size();        //size of string 1
	int m=s2.size();        //size of string 2
	int t[n+1][m+1];        // Creating an array of size 1 greater than size of string on both dimensions
	int max=0,i,j,x,y;
	for(i=0;i<=n;i++)
	{
		t[i][0]=0; //Intialising first column to 0
	}
	for(j=0;j<=m;j++)
	{
		t[0][j]=0; // Intialising first row to 0
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			// If current characters from both string is same then it contribute 1 to the length of longest
			// substring else it contribute 0
			if(s1[i-1]==s2[j-1])
				t[i][j]=t[i-1][j-1]+1;
			else
				t[i][j]=0;
		}
	}
	//finding max in gride because it is length of max substring
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
			if(t[i][j]>max)
			{
				max=t[i][j];
				x=i;
				y=j;
			}
	}	
	// common substring is from max to while we does not hit 0 as moving diagonally up
	while(t[x][y]!=0)
	{
		s3+=s1[x-1];
		x--;
		y--;
	}
	// Revering common substring
	for(i=s3.size()-1;i>=0;i--)
	{
		ans+=s3[i];
	}
	// Printing result
	cout << "Max length of common substring is: " << max << "\nlongest sudstring is "<< ans <<  endl;
	return 0;
}
