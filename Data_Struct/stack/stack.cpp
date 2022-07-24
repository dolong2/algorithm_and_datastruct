#include<iostream>
#include<string.h>
using namespace std;
typedef  struct stack{
	int top;
	int data[10000];
} stack_a;
void stack_chogihwa(stack_a *z) {
	z->top = 0;
}
void push(stack_a* z,int c) {
	z->data[(z->top)++] = c;
}
int pop(stack_a* z) {
  if(z->top==0)
    return -1;
  else  
	  return z->data[--(z->top)];
}
int size(stack_a *z) {
	return z->top;
}
int empty(stack_a *z) {
	if (z->top == 0)
		return 1;
	else
		return 0;
}
int top(stack_a *z) {
  if(z->top==0)
  return -1;
  else 
	return z->data[z->top-1];
}
int main() {
	int a,c;
	char b[100010];
	stack_a z;
	stack_chogihwa(&z);
	scanf("%d",&a);
	for (int i = 0; i < a;i++) {
		scanf("%s", b);
		if (strcmp(b,"push")==0) {
			scanf("%d",&c);
      push(&z,c);
		}
		else if (strcmp(b,"pop")==0) {
			printf("%d\n",pop(&z));
		}
		else if (strcmp(b,"size")==0) {
			printf("%d\n",size(&z));
		}
		else if (strcmp(b,"empty")==0) {
			printf("%d\n",empty(&z));
		}
		else if (strcmp(b,"top")==0) {
			printf("%d\n",top(&z));
		}
	}
	return 0;
}