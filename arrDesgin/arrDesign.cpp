#include<iostream>
using namespace std;
class Arr{
	public:
		Arr();
		Arr(int size);
		Arr(Arr &arr);
		int &operator[](int i);
		Arr operator+(const Arr &arr);
		void operator=(const Arr &arr);
		~Arr();
		int len;
		int* data;
};
Arr::Arr(){
	len=10;
	data=new int[len];
}
Arr::Arr(int size){
	len=size;
	data=new int[len];
}
Arr::Arr(Arr &arr){
	this->len=arr.len;
	this->data=new int[len];
	for(int i=0;i<len;i++){
		this->data[i]=arr.data[i];
	}
}
Arr::~Arr(){
	delete(data);
}
int &Arr::operator[](int i){
	if(i+1>len){
		cout<<"数组越界"<<endl;
		exit(1);
	}
	return data[i];
}
Arr Arr::operator+(const Arr &arr){
	int size=min(arr.len,this->len);
	Arr temp(size);
	temp.data=new int[size];
	for(int i=0;i<size;i++){ 
		temp[i]=arr.data[i]+data[i];
	}
	return temp;
}
void Arr::operator=(const Arr &arr){
	this->len=arr.len;
	this->data=new int[len];
	for(int i=0;i<len;i++){
		this->data[i]=arr.data[i];
	}
}
int main(){
	Arr arr1(3);
	for(int i=0;i<arr1.len;i++){
		cin>>arr1[i];
	}
	Arr arr2(arr1);
	Arr arr3;
	arr3=arr1+arr2;
	for(int i=0;i<arr1.len;i++){
		cout<<arr3[i];
	}
}
