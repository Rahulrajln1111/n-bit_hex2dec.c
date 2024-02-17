#include<stdio.h>
#include<string.h>
#include<math.h>
#include<openssl/bn.h>
#include<openssl/crypto.h>
int hex2dec(char b){
//printf("%c,%c ",a,b);
int k=0;

    if(b=='a') k=10;
    if(b=='b') k=11;
    if(b=='c') k=12;
    if(b=='d') k=13;
    if(b=='e') k=14;
    if(b=='f') k=15;
    if(k==0) k=b-48;
return k;
}

int sl(char a[]){

    int k=0;
    while (a[k]!='\n')k++;

    return k;
}

int main(){

char str[1000],pr[1000],re[100];
    char a[1000];
char *b;
    printf("Eneter Hex:");
    fgets(a,1000,stdin);
int len=sl(a);
//printf("len=%d\n0",len);
BIGNUM *p=NULL;
p=BN_new();
BIGNUM *q=NULL;
q=BN_new();

BIGNUM *n1,*n2;
n1=NULL;
n2=NULL;

int k=0;
long long int sum=0;
    for(int i=len-1;i>=0;i--){
//sum=hex2dec(a[i])*pow(16,k);
        sprintf(pr,"%f",pow(16,k));
        sprintf(re,"%d",hex2dec(a[i]));
//sprintf(str,"%lld",sum);
k++;
//printf("cahr a[%d]=%c\nsum=%s\n",i,a[i],pr);
BN_dec2bn(&n1,pr);
BN_dec2bn(&n2,re);

BN_CTX *ctx=BN_CTX_new();
BN_mul(q,n1,n2,ctx);
//BN_dec2bn(&q,str);
   BN_CTX_free(ctx);
BN_add(p,p,q);
    }


b=BN_bn2dec(p);

printf("Decimal IS:  %s",b);

OPENSSL_free(b);
BN_free(p);
BN_free(q);
BN_free(n1);
BN_free(n2);

}








  