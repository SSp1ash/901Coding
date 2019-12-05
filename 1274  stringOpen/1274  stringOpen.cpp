#include<iostream>
#include<string>
using namespace std;
int getOpPosition(int n,string x){
	int temp=1;
	int i=n+1;
	while(i<x.size()&&temp!=0){
		if(x[i]==')'){
			temp--;
			i++;
			continue;
		}
		if(x[i]=='('){
			temp++;
			i++;
			continue;
		}
		i++;
	}
	i--;
	return i;
}
void get(string x){
	for(int i=0;i<x.size();i++){
		if(x[i]=='('){
			int end=getOpPosition(i,x);
			get(x.substr(i+1,end-i-1));
			if(i==0||x[i-1]>='9'||x[i-1]<='0'){
				
			}else{
				for(int t=1;t<(x[i-1])-'0';t++){
					get(x.substr(i+1,end-i-1));
				}
			}
			i=end;
			continue;
		}
		if(x[i]>='0'&&x[i]<='9'&&x[i+1]>='a'&&x[i+1]<='z'){
			for(int t=0;t<x[i]-'0';t++){
				cout<<x[i+1];
			}
			i++;
			continue;
		}
		else if(x[i]>='a'&&x[i]<='z'){
			cout<<x[i];
			if(i==x.size()-1) return;
		}
	}
}
int main(){
	int n;
	cin>>n;
	while(n--){
		string example;
		cin>>example;
		get(example);
		cout<<endl;
	}
}
