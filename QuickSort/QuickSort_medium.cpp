#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int sum;

inline void SWAP(long long int& a, long long int& b){
	long long int temp;
	temp=a;
	a=b;
	b=temp;
}

inline long long int Median(long long int& a,long long int& b,long long int& c){
	long long int ans;
	
	if((a<=b && a>=c) || (a<=c && a>=b))
		ans=a;
	if((b<=a && b>=c) || (b<=c && b>=a))
		ans=b;
	if((c<=a && c>=b) || (c<=b && c>=a))
		ans=c;
	
	long long int a1=1,a2=2,a3=3;
	
	if(ans==a)
	{return a1;}
	else if(ans==b)
	{return a2;}
	else
	{return a3;}
}

inline void ShowList(long long int* list, int start, int end){
	for(int i=0;i<(end-start);i++)
		cout<<list[i]<<" ";
	cout<<endl;
}

inline	int Partition(long long int* list,int start,int end){
	
	if(start==end-1)return start;
	
	long long int pivot = Median(list[start],list[(int)(start+end)/2],list[end-1]);
	
	switch(pivot){
		case 1:
			pivot=start;
			SWAP(list[pivot],list[end-1]);
			pivot=end-1;
			break;
		case 2:
			pivot=(start+end)/2;
			SWAP(list[pivot],list[end-1]);
			pivot=end-1;
			break;
		case 3:
			pivot=end-1;
			break;
	}

	int j=start-1;
	for(int i=start;i<end;i++){
	
		if(list[i]<=list[pivot] && i!=pivot){
			j++;
			SWAP(list[j],list[i]);
			sum++;
		}
	}
	
	j++;
	SWAP(list[pivot],list[j]);
	pivot=j;
	
	return pivot;
	
}

inline void QuickSort(long long int* list,int start,int end){
	if(start==end-1)return;
	
	int pivot;

	pivot=Partition(list,start,end);
	QuickSort(list,start,pivot);
	QuickSort(list,pivot,end);
}



int main(void){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;cin>>n;

	long long int* seq;
	seq = new long long int[n];
	
	for(int i=0;i<n;i++)
		cin>>seq[i];
	
	QuickSort(seq,0,n);
	ShowList(seq,0,n);
	
	
	
	return 0;
}

