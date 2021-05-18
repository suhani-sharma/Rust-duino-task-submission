#include <stdio.h>
int main(){
    char a[100];
    int year;
    printf("What is your name?\n");
    scanf("%[^\n]%*c", a);
    printf("Hello, %s!\n",a);
    printf("What year were you born?\n");
    scanf("%d",&year);
    if(year<=2021) printf("Congratulations, you are %d years old!",2021-year);
    else printf("Oh, you haven't taken birth yet :(");
    return 0;
}