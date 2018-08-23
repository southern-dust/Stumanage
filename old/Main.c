/*************************************************************************
    > File Name: stumanage.c
    > Author: southern-dust
    > Mail: 972106614@qq.com 
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Struct.h"
#include"ListOperation.h"
#include"Platform/Platform.h"


///////////////////////////////////////////////////
int main(void){
	int options;
	link H=NULL;

	if(Passwd()==0){

	ClearScn();
	PrintMenu();

	scanf("%d",&options);
	while(options!=0){  //use "CTRL + D" ended;
		switch(options){
			case 1: 
				H=CreateList();
				printf("H=%p H->next=%p\n",H,H->next);  //
				break;

			case 2:
				if(H){
					AddInfo(H);
					printf("p=H->next=%p H->name=%s H->seriel=%d\n",H->next,H->name,H->seriel);  //
					printf("OK! Do you want to save it to file?(0/1):\n");
					_Bool chosen=0;
                			if((scanf("%d",&chosen)==1)&&(chosen)){
                        			SaveFile(H);
					}
				}
				else{
					printf("No List yet,please Add Info to Create the list\n");
				}
				break;

			case 3:
				if(H){
					DelInfo(H);
				}
				else{
					printf("No List yet,please Add Info to Create the list\n");
				}
				break;

			case 4:
				if(H){
					printf("Plz type the seriel num of the student who you wanna to Change:('0' to quit)\n");
					long long seriel=0;
					while((scanf("%lld",&seriel)==1)&&(seriel)){
						ChgInfo(H,seriel);
					printf("Plz type the seriel num of the student who you wanna to Change:('0' to quit)\n");
					}
				}
				else{
					printf("No List yet,please Add Info to Create the list\n");
				}
				break;
				


			case 5:
				ShowInfo(H);
				break;

			case 6:
				//SearInfo(H);
				if(H){
					printf("Plz type the seriel num of the student who you wanna to search:('0' to quit)\n");
					long long seriel=0;
					while((scanf("%lld",&seriel)==1)&&(seriel)){
						if(SearInfo(H,seriel)!=0){
							printf("No such student whose seriel num is %lld\nPlease input again\n",seriel);
						}
					printf("Plz type the seriel num of the student who you wanna to search:('0' to quit)\n");
					}
				}
				else{
					printf("No List yet,please Add Info to Create the list\n");
				}
				break;

			case 7:
				if(H){
					DelList(H);
					H=NULL;
					printf("H in main() is %p\n",H);  //
					printf("List already Deleted\n");
				}
				else{
					printf("No List yet,please Add Info to Create the list\n");
				}
				break;

			case 8:
				if(H){  //
					SortList(H);
				}
				else{
					printf("No List yet,please Add Info to Create the list\n");
				}
				break;

			case 9:
				if(H){
					SaveFile(H);
				}
				else{
					printf("No List yet,please Add Info to Create the list\n");
				}
				break;

			case 10:
				if(H){
					ReadFile(H);
				}
				else{
					printf("No List yet,please Add Info to Create the list\n");
				}
				break;
			
			default:
				printf("Plz input correct option\n");
		}
		printf("Press Enter to continue\n");
		while(getchar()!='\n');  //to keep the screen output;
		while(getchar()!='\n');  //

		
		PrintMenu();
		scanf("%d",&options);
		ClearScn();
	}

	printf("Good bye!\n");
	}

	return 0;
}
