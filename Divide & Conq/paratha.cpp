#include<iostream>
using namespace std;

void canMakeParatha(int C,int *cook,int T,int P){

	int total_paratha = 0;
	for(int i=0;i<C;i++){
		int current_paratha = 0;
		int current_time = 0;
		while(current_time + cook[i]*(current_paratha+1)<=T){
			current_paratha++;
			current_time += cook[i]*(current_paratha);
		}
		total_paratha += current_paratha;
		if(total_paratha>=P){
			return true;
		}

	}
	return false;
}

int main(){

	int cook[] = {1,2,3,4};
	int C = 4;
	int P  = 10;
	int T = 0;

	int s = 0;
	int e = INT_MAX; // R*(P)*(P+1)/2;

	while(s<=e){
		int mid = (s+e)/2;
		if(canMakeParatha(C,cook,mid,P)){
			T = mid;
			e = mid -1;
		}
		else{
			s = mid+1;
		}
	}




	return 0;
}