#include<iostream>
#include<algorithm>
using namespace std;

bool canPlace(int c,int n,int *stalls,int sep){

	int cows=1;
	int loc = stalls[0];

	//remanining cows ko place krna hai
	for(int i=1;i<n;i++){
		int x = stalls[i];
		if(x-loc>=sep){
			cows++;
			loc = x;
			if(cows==c){
				return true;
			}
		}
	}

	return false;
}


int main(){
	int n,c;
	cin>>n>>c;

	int stalls[100];
	for(int i=0;i<n;i++){
		cin>>stalls[i];
	}
	//Sort Array upto N Elements
	sort(stalls,stalls+n);

	//Define Binary Search
	int s = 0;
	int e = stalls[n-1] - stalls[0];

	int mid;
	int ans = 0;
	while(s<=e){
		mid = (s+e)>>1;
		if(canPlace(c,n,stalls,mid)){
			ans = mid;
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}
	cout<<ans;

	return 0;
}