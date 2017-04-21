
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <openssl/md5.h>
int MD5_Init(MD5_CTX *c);
int MD5_Update(MD5_CTX *c, const void *data, unsigned long len);
int MD5_Final(unsigned char *md, MD5_CTX *c);
int main(int argc,char **argv)
{
unsigned char decrypt[16];
int i;
char fileName[] = {'\0'};
char temp[100];
printf("input file name:");
scanf("%s",fileName);


FILE *fptr;
fptr = fopen(fileName,"rb+");

if (!fptr) {
  freopen(fileName, "wb", fptr);
}

if(fptr){
fgets(temp,100,fptr);
printf("success open the file \n");
MD5_CTX md5;
MD5_Init(&md5);
while(!feof(fptr))
{
MD5_Update(&md5,temp,strlen((char *)temp));
fgets(temp,100,fptr);
}
MD5_Final(decrypt,&md5);
}
else{
printf("fail open,this is not a file \n");
MD5_CTX md5;
MD5_Init(&md5);
MD5_Update(&md5,fileName,strlen((char *)fileName));
MD5_Final(decrypt,&md5);
printf("before:%s\nafter:",fileName);
}


/* MD5_CTX md5;
*   MD5_Init(&md5);
*     MD5_Update(&md5,fptr,strlen((char *)fptr));
*       MD5_Final(decrypt,&md5);*/


for(i=0;i<16;i++)
{
printf("%02x ",decrypt[i]);
}
printf("\n");
return 0;
}
