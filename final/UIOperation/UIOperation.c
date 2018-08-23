/*User Interface Operations*/

#include<stdio.h>
#include<stdlib.h>

#include"../Operation/Operation.h"
#include"../Platform/Platform.h"


/*Interface Operations*/
void ClearScn(void){
	system(CLEAR_SCREEN);
}


void PrintMenu(void){
	 ClearScn();
        printf("**************************************************\n");
        printf("Welcome to our Student Management System\n");
        printf("Please input a method(type '0' to quit):\n");
        printf("1. Create Infomation List\n");
        printf("2. Add students' Informations\n");
        printf("3. Delete students' Information\n");
        printf("4. Change students' Informations\n");
        printf("5. Search students' Informations\n");
        printf("6. Show students' Informations\n");
        printf("7. Delete Information List\n");  //
        printf("8. Sort Information List  //\n");  //
        printf("9. Save to File\n");
        printf("10. Read from File\n");
        printf("**************************************************\n");
}


/*Main Operations--working for main interface*/
void Cre(link *H){
	if(*H){
		printf("List %s already exist, remove and build a new one?(0/1):\n");
		int options=0;
		if((scanf("%d",&options)==1)&&options){
			*H=CreateList();
			printf("In Cre, H=%p\n",*H);  //
			AddInfo(*H);
		}
	}
	else{
		*H=CreateList();
		printf("In Cre, H=%p\n",*H);  //
		AddInfo(*H);
	}
}


void Add(link *H){
	if(*H){
		AddInfo(*H);
	}
	else{
		Cre(H);
	}
		printf("OK! Do you want to save it to file?(0/1):\n");
                int chosen=0;
		if((scanf("%d",&chosen)==1)&&(chosen)){
			SaveFile(*H);
		}
}


void Del(link H){
	if(H){
		DelInfo(H);

        }
        else{
                printf("No List yet,please Add Info to Create the list\n");
        }
}


void Chg(link H){
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
}


void Ser(link H){
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
}


void Show(link H){
	if(H){
		ShowInfo(H);
        }
        else{
                printf("No List yet,please Add Info to Create the list\n");
        }
}


void Sort(link H){
	if(H){
		SortInfo(H);
        }
        else{
                printf("No List yet,please Add Info to Create the list\n");
        }
}


void DelL(link *H){
	if(*H){
		DelList(*H);
                *H=NULL;
                printf("List already Deleted\n");
        }
        else{
                printf("No List yet,please Add Info to Create the list\n");
        }
}


void Save(link H){
	if(H){
		SaveFile(H);
        }
        else{
                printf("No List yet,please Add Info to Create the list\n");
        }
}


void Read(link H){
	if(H){
		ReadFile(H);
        }
        else{
                printf("No List yet,please Add Info to Create the list\n");
        }
}


/*Auth Operations*/
int Auth(void){
}
