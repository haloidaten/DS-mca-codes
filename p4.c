#include<stdio.h>
#include<stdlib.h>
int main(){
int array_1[100],array_2[100];
int a1_size,a2_size;
int i ,j;
int temp;
int total;
int size=0;
printf("\n Enter how much ele in 1st arr:");
scanf("%d",&a1_size);
printf("\n enter %d ele :\n",a1_size);
for(i=0;i<a1_size;i++){
printf("\n array_1[%d]:",i+1);
scanf("%d",&array_1[i]);
}
printf("\n Enter how much ele in 2nd arr:");
scanf("%d",&a2_size);
printf("\n Enter array_2[%d] ele \n:",a2_size);
for(i=0;i<a2_size;i++)
{
printf("\n Enter %d ele \n:",i+1);
scanf("%d",&array_2[i]);
}
total=a1_size+a2_size;
for(i=a1_size;i<total;i++)
{
array_1[i]=array_2[size];
size=size+1;
}
for(i=0;i>0;i--)
{
for(j=0;j<total-1;j++)
{
if(array_1[j]>array_1[j+1]){
temp=array_1[j];
array_1[j]=array_1[j+1];
array_1[j+1]=temp;
}
}
}
printf("\n.....\n");
printf("Araay ele are:\n");
for(i=0;i<total;i++)
{
printf("Array_[%d] is :%d \n",i,array_1[i]);
}
return 0;
}