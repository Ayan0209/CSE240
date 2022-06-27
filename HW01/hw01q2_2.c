#include<stdio.h>
int main(){
char ch;
int a=10;
int b=20;
int f;
int i;
for(i = 0; i < 5; i++){

    printf("Enter math operation: ");
    ch = getchar();                 
    printf("ch = %c\n", ch);
    switch(ch){
        case '+': f = a + b;
        printf("f = %d\n", f);
        break;
        case '-': f = a - b;
        printf("f = %.d\n", f);
        break;
        case '*': f = a * b;
        printf("f = %.d\n", f);
        break;
        case '/': f = a / b;
        printf("f = %.d\n", f);
        break;
        default: printf("Invalid operator\n");
    }
    ch = getchar();
}
}