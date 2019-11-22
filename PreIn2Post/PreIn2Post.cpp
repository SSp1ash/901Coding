#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
stack<char> s;
void CCpostVisit(char pre[],char in[]){
	int n=strlen(pre);
	if(n<1){
		return;
	}
	char x=pre[0];
	s.push(x);
	char lpre[100]="";
	char rpre[100]="";
	char lin[100]="";
	char rin[100]="";
	for(int i=0;i<n;i++){
		if(in[i]==x){
			for(int k=0,j=1;j<i+1;j++)
				lpre[k++]=pre[j];
			for(int k=0,j=i+1;j<n;j++)
				rpre[k++]=pre[j];
			for(int k=0,j=0;j<i;j++)
				lin[k++]=in[j];
			for(int k=0,j=i+1;j<n;j++)
				rin[k++]=in[j];
		}
	}
	CCpostVisit(rpre,rin);
	CCpostVisit(lpre,lin);
}
int main(){
	char a[10]="DBACEGF";
	char b[10]="ABCDEFG";
	CCpostVisit(a,b);
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
}
