/*
Jacob Rowan 19038609
Assignment 1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BintoDec(char *x);
void DectoBin(int x);

int stlen;

int main (){
	char strn1[20], ch1;
	int indx, check;
	
	ch1 = '?';
	while(1){
		printf("\nEnter a number between 0 and 255 (inclusive)\n");
		gets(strn1);
		
		check = atoi(strn1);
		
		stlen = strlen(strn1);
		
		for (indx=0; indx<stlen; indx++){
			if ((strn1[indx]!='1')&&(strn1[indx]!='0')){
				ch1 = 'd';
				break;
			}
		}
		
		
		
		for (indx=0; indx<stlen; indx++){
			if ((strn1[indx]>'9')||(strn1[indx]<'0')){
				printf("The number you have entered is invalid. Farewell traveler");
				exit(5);
			}
		}
		
		if (strn1[0] == '0'){
			for (indx=0; indx<stlen-1; indx++){
				if((strn1[indx]!='0')&&(strn1[indx]!='1')){
					printf("The number you have entered is invalid. Farewell traveler.");
					exit(10);
				}
			}
			ch1 = 'b';
		}
		
		
		if (check == 0){
			ch1 = '?';
		}
		
		while ((ch1!='d')&&(ch1!='b')){
			printf("What base was the number you entered? \n b - binary \n d - decimal\n");
			ch1 = getchar();
			getchar();
			if ((ch1!='d')&&(ch1!='b')){
				printf("Sorry that was not one of the options.\n");
			}
		}
		
		if ((ch1=='b')&&(stlen>8)){
			printf("The number you have entered is invalid. Farewell traveler.");
			exit(16);
		}
		
		if ((ch1=='d')&&((check>255)||(check<0))){
			printf("The number you have entered is invalid. Farewell traveler.");
			exit(17);
		}
		
		if (ch1=='b'){
			BintoDec(strn1);
		}
		
		if (ch1=='d'){
			DectoBin(check);
		}
	}
}
	
	
	
void BintoDec(char *x){
	int indx, temp, pos, decnum;
	pos = 1;
	decnum = 0;
	
	for (indx=stlen-1; indx>=0; indx--){
		if (x[indx] == '0'){
			temp = 0;
		}
		if (x[indx] == '1'){
			temp = 1;
		}
		if (temp==1){
			decnum = decnum + pos;
		}
		pos = pos*2;
	}
	printf("Converting binary to decimal. Answer is: %d", decnum);
	//exit(25);
}

void DectoBin(int x){
	char binstr[20];
	int temp, indx, len;
	indx = 0;
	temp = 0;

	while (x!=0){
		temp = x%2;
		if (temp==1){
			binstr[indx] = '1';
		}
		if (temp==0){
			binstr[indx] = '0';
		}
		x = x/2;
		indx++;
	}
	len = strlen(binstr);
	while (len<8){
		binstr[indx] = '0';
		indx++;
		len = strlen(binstr);
	}
	binstr[indx] = '\0';
	printf("Converting decimal to binary. Answer is:");
	for (indx=len-1; indx>=0; indx--){
		printf("%c", binstr[indx]);
	}
	//exit(30);
}