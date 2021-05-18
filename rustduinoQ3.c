#include <stdio.h>
int main(){
    char a,y[2];
    int x[3];
    float ans;
    int i;
    printf("Enter an expression: ");
    scanf("%c",&a);
    while(a==' ') {scanf("%c",&a);}   //to ignore the whitespaces(if there) at starting of input
 for(i=0;i<3;i++){    
    if (!((a>='0')&&(a<='9'))) {
        printf("incorrect input: first character/character after operator should be a number, try again"); //self explanatory
        return 0;
    } 
    x[i]=0;
    while((a>='0')&&(a<='9')){  
        x[i]=10*x[i] +a-'0';      //finding the 1st number of the input and storing it in x[i]
        a=getchar();
       while(a==' ') {
           while(a==' ') {a=getchar();} //to ignore the whitespaces(if there) between a no. and a operator 
           break;
       }
        if (a==EOF) break;
    }
    if(i==2) break;  //i=2 means we have got all the 3 numbers and 2 operators, now loop can break
    if(!(a=='+'||a=='-'||a=='*'||a=='/')){
         printf("incorrect input: a number should be followed by a operator(and have 3 numbers), try again");  //self explanatory
        return 0;
    }
    else  y[i]=a;   //store the operator in char y[i]
    scanf("%c",&a);
    while(a==' ') {scanf("%c",&a);}  //to ignore the whitespaces(if there) between a operator and a no.
 }  //closing bracket of the for loop


for(i=0;i<3;i++){
      if ((x[i]<0)||(x[i]>1000)) {printf("numbers cannot exceed 1000. Program terminated, please try again."); return 0;} //self explanatory
}
  if ((y[0]=='/')&&(x[1]==0)){printf("can't divide by 0, try again"); return 0;}  //self explanatory
  if ((y[1]=='/')&&(x[2]==0)){printf("can't divide by 0, try again"); return 0;}
  if(y[0]=='*'){              //final calculations
      if(y[1]=='+') ans=x[0]*x[1]+x[2];
      if(y[1]=='-') ans=x[0]*x[1]-x[2];
      if(y[1]=='*') ans=x[0]*x[1]*x[2];
      if(y[1]=='/') ans=x[0]*(float)x[1]/x[2];
  }
  if(y[0]=='/'){
      if(y[1]=='+') ans=(float)x[0]/x[1]+x[2];
      if(y[1]=='-') ans=(float)x[0]/x[1]-x[2];
      if(y[1]=='*') ans=(float)x[0]/x[1]*x[2];
      if(y[1]=='/') ans=(float)x[0]/(float)x[1]/x[2];
  }
  if(y[0]=='+'){
      if(y[1]=='+') ans=x[0]+x[1]+x[2];
      if(y[1]=='-') ans=x[0]+x[1]-x[2];
      if(y[1]=='*') ans=x[0]+x[1]*x[2];
      if(y[1]=='/') ans=x[0]+(float)x[1]/x[2];
  }
  if(y[0]=='-'){
      if(y[1]=='+') ans=x[0]-x[1]+x[2];
      if(y[1]=='-') ans=x[0]-x[1]-x[2];
      if(y[1]=='*') ans=x[0]-x[1]*x[2];
      if(y[1]=='/') ans=x[0]-(float)x[1]/x[2];
  }
  printf("\nResult: %.5f",ans);  //my calculator will give output upto 5 decimals
  return 0;
}