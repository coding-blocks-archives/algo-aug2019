#include<iostream>
#include<vector>
using namespace std;
//n^2
int lis(int* arr, int n) {
	int memo[100] = {0};
	for (int i = 0; i < 100; ++i)
	{
		memo[i] = 1;
	}
	int maxLength = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i]) {
				memo[i] = max(memo[i], memo[j] + 1);
				maxLength = max(maxLength, memo[i]);
			}

		}
	}

	return maxLength;
}

//nlogn
int lisOptimized(int* arr, int n) 
{ 
	if (n == 0) 
		return 0; 

	vector<int> temp(n,0);
	int maxLength = 1;  

	temp[0] = arr[0]; 
	
	for (int i = 1; i < n; i++) { 
		auto start = temp.begin();
		auto end = temp.begin() + maxLength; 
		auto it = lower_bound(start, end, arr[i]); // it will give just greater element than arr[i]
			
		
		if (it == end) { // if it give last index then append arr[i] at end
            temp[maxLength] = arr[i]; 
            maxLength++;
        }
		
		else{ // otherwise replace that just greater element in temp vector
            *it = arr[i]; 
        }	
	} 
	return maxLength; 
} 


int main(int argc, char const *argv[])
{
	int arr[7] = {5, 9, 2, 4, 3, 6, 1};
	cout << lis(arr, 7) << endl;

	int arr1[2] = {5, 9};
	cout << *lower_bound(arr1, arr1 + 2, 2) << endl;
	cout<<lisOptimized(arr,7)<<endl;

	return 0;
}