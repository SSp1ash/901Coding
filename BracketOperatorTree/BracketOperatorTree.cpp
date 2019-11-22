#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<char> s;
typedef struct BTNode{
	char val;
	struct BTNode *left,*right;
}BTNode;
BTNode* buildTree(string exp){
	if(exp.size()==0){
		return NULL;
	}
	if(exp[0]=='('){
		if(exp[exp.length()-1]==')')
		exp=exp.substr(1,exp.length()-2);
	}
	int index=0;int muldiv=0;
	int separate;
	for(int i=exp.length()-1;i>=0;i--){
		if(exp[i]==')'){
			s.push(exp[i]);
		}
		else if(exp[i]=='('){
			if(!s.empty()){
				s.pop();
			}
		}
		else if(exp[i]=='+'&&s.empty()||exp[i]=='-'&&s.empty()){
			index=i;
			break;
		}
		else if(exp[i]=='*'&&s.empty()||exp[i]=='/'&&s.empty()){
			muldiv=i;
		}
	}
	if(index!=0){
		separate=index;
	}else{
		separate=muldiv;
	}
	string left;
	string right;
	for(int t=0;t<separate;t++){
		left+=exp[t];
	}
	for(int t=separate+1;t<exp.length();t++){
		right+=exp[t];
	}
	BTNode *p=(BTNode *)malloc(sizeof(BTNode));
	p->val=exp[separate];
	p->left=buildTree(left);
	p->right=buildTree(right);
	return p;
}
void InOrder(BTNode *p){
	if(!p){
		return;
	}
	InOrder(p->left);
	cout<<p->val;
	InOrder(p->right);
}
int main(){
	string x="1+(2+3+9*(3-1)+8/(4-2))*5+8*(4-3)";
//	string x="1+(2*3)";
	BTNode *p=buildTree(x);
	InOrder(p);
}
