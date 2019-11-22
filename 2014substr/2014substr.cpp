#include<iostream>
using namespace std;
#include<string>
bool isSub(string a,string b){
	int i=0,j=0;
	while(i<a.size()&&j<b.size()){
		if(a[i]==b[j]){
			i++;
			j++;
			continue;
		}else{
			j++;
		}
	}
	if(i==a.size()){
		return true;
	}else{
		return false;
	}
}
int main(){
	int i;
	cin>>i;
	string a,b;
	while(i--&&cin>>a>>b){
		if(isSub(a,b)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}
