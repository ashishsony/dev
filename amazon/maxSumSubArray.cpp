/*The function maxSumSubArraytakes an array as it's parameter. Complete the function to return the maximum
sum of the subarray. The array contains +ve and -ve integers
*/
/*Write your own custom functions here*/
#include<iostream>
using namespace std;
int maxSumSubArray(int *a, int N ) {
/* N is the size of the array */
int i=0,sum=0;
while(i<N)
{
	if(a[i]>0)
		sum+=a[i];
	i++;
}
return sum;
}
int main()
{
	int ar[]={1,2,3,45,-987,1,1,1,1,1,23,45};
	cout<<"maxx::"<<maxSumSubArray(ar,12);
}