#include<iostream>
#include<stack>
using namespace std;
class calculator{
	stack<int> numStack;
	stack<char> opStack;
	public:
		void getTwoNum(int &x1,int &x2){
			if(numStack.size()>1){
				x2=numStack.top();
				numStack.pop();
				x1=numStack.top();
				numStack.pop();			
			}
		}
		void reduction(){
			int x1,x2;
			getTwoNum(x1,x2);
			int T;
			if(opStack.top()=='+') T=x1+x2;
			if(opStack.top()=='-') T=x1-x2;
			if(opStack.top()=='*') T=x1*x2;
			if(opStack.top()=='/') T=x1/x2;
			numStack.push(T);
			opStack.pop();
		}
		void cal(){
			string exp;
			while(cin>>exp){
				if(exp[0]=='c'){
					while(!numStack.empty()){
						numStack.pop();
					}
					continue;
				}
				if(exp[0]=='z'){
					return;
				}
				string temp;
				int i=0;
				while(i<exp.size()){
					if(exp[i]>='0'&&exp[i]<='9'){		//°ÑÊý×Ö´æÈëtemp 
						temp+=exp[i];
						i++;
						while(exp[i]>='0'&&exp[i]<='9'){
							temp+=exp[i];
							i++;
						}
						numStack.push(atoi(temp.c_str()));
						temp="";
					}
					else if(exp[i]=='='){
						reduction();
						break;
					}
					else
						if(opStack.empty()||(opStack.top()=='-'||opStack.top()=='+'&&exp[i]=='*'||exp[i]=='/')){
							temp+=exp[i];
							opStack.push(temp[0]);
							temp="";
							i++;
						}else{
							reduction();
							opStack.push(exp[i]);
						}
					}
				cout<<numStack.top();
			}
		}
};
int main(){
	calculator c;
	c.cal();
}
