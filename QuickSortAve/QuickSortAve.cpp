#include<iostream>
#include<vector>
using namespace std;
void quickSort(vector<int> &arr,int begin,int end){
	if(begin>=end){
		return;
	}
	int i=begin;
	int j=end;
	int sum=0;
	for(int i=begin;i<=end;i++){
		sum+=arr[i];
	}
	int pivot=sum/(end-begin+1);
	int temp=arr[begin];
	while(i<j){
		while(i<j&&arr[j]>pivot)
			j--;
		if(i<j)
			arr[i++]=arr[j];
		while(i<j&&arr[i]<pivot)
			i++;
		if(i<j)
			arr[j--]=arr[i];
	}
	arr[i]=temp;
	if(temp<pivot){
		quickSort(arr,begin,i);
		quickSort(arr,i+1,end);
	}else if(temp>pivot){
		quickSort(arr,begin,i-1);
		quickSort(arr,i,end);
	}else if(temp==pivot){
		quickSort(arr,begin,i-1);
		quickSort(arr,i+1,end);
	}
	
}
int main(){
	vector<int> a={3,2,3,0,8};
	quickSort(a,0,a.size()-1);
	for(auto it=a.begin();it!=a.end();it++){
		cout<<*it;
	}
}
