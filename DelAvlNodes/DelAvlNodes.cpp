#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef struct BTNode{
	int val;
	struct BTNode *left,*right;
}BTNode;
void Inorder(BTNode *t){
	if(!t){
		return;
	}
	Inorder(t->left);
	cout<<t->val;
	Inorder(t->right);
}
void createAVL(BTNode *&t){
	int x;
	while(cin>>x){
		if(x==-1){
			return;
		}
		if(!t){
			t=(BTNode *)malloc(sizeof(BTNode));
			t->val=x;
			t->left=NULL;
			t->right=NULL;
			continue;
		}
		BTNode *insert=(BTNode *)malloc(sizeof(BTNode));
		insert->left=NULL;
		insert->right=NULL;
		insert->val=x;
		BTNode *p=t;
		while(p!=NULL){
			if(x>p->val){
				if(p->right!=NULL){
					p=p->right;
				}else{
					p->right=insert;
					break;
				}
			}else{
				if(p->left!=NULL){
					p=p->left;
				}else{
					p->left=insert;
					break;
				}
			}
		}
		
	}
}
void delAll(BTNode *t){
	if(!t) return;
	delAll(t->left);
	delAll(t->right);
	free(t);t=NULL;
}
void delDetail(BTNode *&t){
	delAll(t->left);
	t->left=NULL;
	if(t->right){
		BTNode *p=t->right;
		BTNode* prio;
		prio=p;
		while(p->left){
			prio=p;
			p=p->left;
		}
		t->val=p->val;
		if(t->right==p){
			t->right=p->right;
		}else{
			prio->left=p->right;
		}
		free(p);
	}else{
		free(t);
		t=NULL;
	}
	
}
void delNodes(BTNode *&t,int x){
	BTNode *p=t;
	BTNode *prior=p;
	while(p->left){
		if(x<p->val){
			prior=p;
			p=p->left;
		}else{
			break;
		}
	}
	while(p&&x>=p->val){
		delDetail(p);
	}
	return;
}

int main(){
	BTNode *t=NULL;;
	createAVL(t);
	Inorder(t);
	delNodes(t,5);
	cout<<endl;
	Inorder(t);
}
