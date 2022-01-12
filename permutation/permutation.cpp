#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define SIZE 5

using namespace std;

void Swap_1(char &a,char &b){
	char temp=a;
	a=b;
	b=temp;
}

void Show_list(char* list){
	for(int i=0;i<SIZE;i++){
		cout<<list[i]<<" ";
	}
	cout<<endl;
}

void Permutation(char* a, int start, int end){
	if(start==end){
		Show_list(a);
	}
	else{
		for(int i=start;i<end;i++){
			Swap_1(a[start],a[i]);
			Permutation(a,start+1,end);
			Swap_1(a[start],a[i]);
		}
	}
}



int main(int argc, char** argv) {
	
	char* char_list=new char[SIZE];
	// put char in
	int start=97;
	for(int i=0;i<SIZE;i++){
		char_list[i]=start+i;
	}
	
	cout<<"Before Permutation...\n";
	Show_list(char_list);
	
	cout<<"After Permutation...\n";
	Permutation(char_list,0,SIZE);
	
	
	return 0;
}
