#include<stdio.h>
#include<string.h>

void main()
{
	int i,j;
	char PT[100]={'\0'},CT[100]={'\0'},key[100]={'\0'},DT[100]={'\0'};
	
	printf("Enter the PLAINTEXT : ");
	scanf("%s",PT);
	printf("Enter the KEY : ");
	scanf("%s",key);
	
	j=0;
	for(i==strlen(key);i<strlen(PT);i++){
		if(j==strlen(key)){
			j=0;
		}
		key[i]=key[j];
		j++;
	}
	printf("\nPLAINTEXT: %s",PT);
	printf("\nNew Key : %s",key);
	printf("\n");
	
	//Encryption
	for(i=0;i<strlen(PT);i++){
		CT[i]=(((PT[i]-97)+(key[i]-97))%26)+97;
	}
	printf("\nCipher Text(Encrypt): %s",CT);
	
	//Dencryption
	for(i=0;i<strlen(CT);i++){
		if(CT[i]<key[i]){
			DT[i]=26+((CT[i]-97)-(key[i]-97))+97;
		}
		else{
			DT[i]=(((CT[i]-97)-(key[i]-97))%26)+97;
		}
	}
	printf("\nPlain Text(Decrypt) : %s",DT);
	
	
}
