#include<iostream>
#include<string>
using namespace std;
int findBacket(string example,int i){
	int j=1;i++;
	while(j!=0){
		if(example[i]=='(') j++;
		if(example[i]==')') j--;
		i++;
	}
	return i;
}
void open(string input){
	int len=input.size();
	int i=0;
	while(i<len){
		if(input[i]=='('){
			int sum=1;
			int end=findBacket(input,i);
			if(i>0&&input[i-1]>='0'&&input[i-1]<='9'){
				sum=input[i-1]-'0';
			}
			while(sum--){
				open(input.substr(i+1,end-2-(i+1)+1));      //end为括号后一位下标，i为括号下标 
			}
			i=end;
			continue;
		}
		if(input[i]>='a'&&input[i]<='z'){
			int sum=1;
			if(i>0&&input[i-1]>='0'&&input[i-1]<='9'){
				sum=input[i-1]-'0';
			}
			while(sum--){
				cout<<input[i];
			}
			i++;
			continue;
		}
		i++;
		continue;
	}
}
int main(){
	int n;
	cin>>n;
	while(n--){
		string input;
		cin>>input;
		open(input);
		cout<<endl;
	}
}
