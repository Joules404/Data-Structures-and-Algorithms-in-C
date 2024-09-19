#include <stdio.h>

int func1(int num){
    if(num == 0) return 0;
    printf("%d\n",num);
    return func1(num-1) + num;
}


int main(){
    printf("%d\n",func1(10));
    return 0;
}