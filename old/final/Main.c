#include<stdio.h>

#include"Struct.h"
#include"Operation/Operation.h"
#include"UIOperation/UIOperation.h"
#include"Platform/Platform.h"

int main(void){
	link H=NULL;
	int options=0;
	Auth();

	PrintMenu();
	scanf("%d",&options);
        while(options!=0){
                switch(options){
			case 1: Cre(&H);  //why H not change? 
				printf("In Main:H=%p",H);  //
				break;
			case 2: Add(&H); break;
			case 3: Del(H); break;
			case 4: Chg(H); break;
			case 5: Ser(H); break; 
			case 6: Show(H); break;
			case 7: DelL(&H); break;
			case 8: Sort(H); break;
			case 9: Save(H); break;
			case 10: Read(H); break;
			default: printf("Plz input correct option\n");
		}
	printf("Press Enter to continue\n");
	while(getchar()!='\n');  //to keep the screen output;
	while(getchar()!='\n');  //

                PrintMenu();
                scanf("%d",&options);
                ClearScn();
	}
	
	printf("Good bye!\n");

	return 0;
}
