#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float recursion(int k, float x);
float summary(float *b, int n,float x);
float stepen(float x1, float step);
void generatearray(float ** b,int *n) {
    int i;
    scanf("%d",&*n);
    *b = malloc(sizeof(float)*(*n));
    for (i=0;i<*n;i++){
        (*b)[i] = rand()%10;
        printf("%f ",(*b)[i]);
    }
}

int main()
{
    float* a;
    int n;
    float x;

    scanf("%f",&x);
    generatearray(&a,&n);
    printf("\n%f",summary(a,n,x));

    free(a);
}

float stepen(float x1, float step){
    int res;
    if(step==0){return 1;}
    if(step==1){return x1;}
    res=x1*stepen(x1,--step);
}

float recursion(int k, float x){
    int vidp;

    if(k==0){return 1;}
    if(k==1){return x;}
    vidp=x*recursion(k-1,x)-(k-1)*recursion(k-2,x);
    return vidp;
}

float summary(float *b, int n,float x){
    float res=0,sum;
    if(n==0){return 1;}
    res=stepen(b[n]*(-1),n)*recursion(n,x);
    sum=summary(b,--n,x)+res;
    return(sum);
}
