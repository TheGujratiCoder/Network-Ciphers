#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

char* CaesarCipher(int n,int k,char* s)
{
    for(int i=0;i<n;++i){
        if(islower(s[i]))
            s[i]='a'+(s[i]-'a'+k)%26;
        else if(isupper(s[i]))
            s[i]='A'+(s[i]-'A'+k)%26;
    }
    return s;
}

int main(int argc, char const *argv[])
{
    int n,k;
    //char* fname = malloc(1000);
    char str[1000];
    // printf("Enter name of file : ");
    // scanf("%s",fname);
    printf("Enter the number key : ");
    scanf("%d",&k);
    FILE *ptr,*ptr1;
    char ch;
    ptr=fopen("./input.txt","r");
    if(ptr==NULL){
        printf("Some Error Occurred");
        return 0;
    }
    int i=0;
    do{
        ch=fgetc(ptr);
        str[i++]=ch;
    }while(ch!=EOF);
    fclose(ptr);
    n=strlen(str);
    char* modifiedstr;
    modifiedstr=CaesarCipher(n,k,str);
    ptr1=fopen("./output.txt","a");
    fputs(modifiedstr,ptr1);
    printf("Output written to the file");
    fclose(ptr1);
    // printf("the modified string is : %s",modifiedstr);
    // free(fname);
    return 0;
}
