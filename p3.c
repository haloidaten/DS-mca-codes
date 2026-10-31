#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
int stack[MAX];
int top=-1;
int max=100;
 
bool isEmpty(){
 if(top<=-1){
 return 1;
 }
 else{
 return 0;
 }
}
bool isfall(){
 if(top>=max){
 return 1;
 }
 else{
 return 0;
 }
}
void push(){
int value;
 if(isfall()){
 printf("Stack is Full\n");
 }
 else{
 printf("Enter push item:");
 scanf("%d",&value);
 top=top+1;
 stack[top]=value;
 printf("\n %d pushed to stack",value);
 }
}
void pop(){
 if(isEmpty()){
 printf("stack is empty");
 }
 else{
 printf("%d is poped out :",stack[top]);
 top=top-1;
 }
}
void display(){
 if(!isEmpty()){
 for(int i=0;i<=top;i++){
 printf("Stack[%d]=%d\n",i+1,stack[i]);
 } 
 }
 else{
 printf("Stack is empty");
     }
}
void peek(){
 if(!isEmpty()){
 printf("top ele is:%d",stack[top]);
 }
 else{
 printf("Stack is empty");
 }
}
int main(){
 int opt;
 do{
 printf("\n ........\n");
 printf("1)PUSH\n");
 printf("2)POP\n");
 printf("3)PEEk\n");
 printf("4)Display\n");
 printf("5)Quit\n");
 printf("\n.......\n");
 printf("Choose ur option:");
 scanf("%d",&opt);
 
 switch(opt){
 
 case 1:
 push();
 break;
 
 case 2:
 pop();
 break;
 
 case 3:
 peek();
 break;
 
 case 4:
 display();
 break;
 
 case 5:
 exit(0);
 
 default:
 printf("/n Invalid operation! Try Again:");
 }
 }while(1);
 return 0;
 }
 