#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"Struct.h"
#include"Platform/Platform.h"


void clearScn(void){
	system(CLEAR_SCREEN);
}


void printMenu(void){
	clearScn();
        printf("**************************************************\n");
        printf("Welcome to our Student Management System\n");
        printf("Please input a method(q to quit):\n");
        printf("1. Add students' Informations\n");
        printf("2. Delete students' Information\n");
        printf("3. Show students' Informations\n");
        printf("4. Search students' Informations\n");
        printf("5. Delete Information List\n");
        printf("**************************************************\n");
}


//////////////////////////////////////////////


void delList_sub(link H){

}

void delList(link H){

}




//////////////////////////////////////////////


link createList_sub(void){
        link H=(link)malloc(sizeof(Student));
        H->next=NULL;
        
        return(H);
}


/*This function get a List Head as parameter to create List, return a link Head if has old List whith has the same name*/
/*fixing neded*/
link createList(link H){        //STD_INPUT Version;
        char name[MAX];
        scanf("%s",name);
	_Bool has_old=0;
	link link_old=NULL;
        if(strcmp(name,H->name)==0){    //already exist such list;
                printf("Found list named \"%s\",do you want to continue it?(0/1):\n",name);
                _Bool choosen;
                if((scanf("%d",&choosen)==1)&&(choosen==1)){
                        delList(H);     //
		}
	}
        else{  //need to deal with list "H" and other;
		//save the old list, then creat the new one;
		link_old=H;
		has_old=1;
        }

        H=createList_sub();
        strcpy(H->name,name);
	if(has_old) return link_old;
}


//////////////////////////////////////////////


void addInfo(link H){   //Bug fixing...
        char input[MAX];
        _Bool sex;
        int score;

        link p=H->next;
        link current=NULL;

        puts("Enter student's name,sex(is male? 1/0),and score:\n");
        while((fgets(input,MAX,stdin)!=NULL)&&(input[0]!='\0')&&(input[0]!='\n')){      //fgets() will eat the '\n', so we need a strchr to catch it;
                //

                char *find=strchr(input,'\n');
                if(find) *find='\0';

                scanf("%d%d",&sex,&score);
                while(getchar()!='\n'); //clear input line;

                current=(link)malloc(sizeof(Student));
                strcpy(current->name,input);
                current->sex=sex;
                current->score=score;
                current->next=NULL;     //end;

                while((p)&&(p->next)){  //walk the list;
                        p=p->next;
                }


                if(!p){
                        p=current;      //the first node;
                }
                else if(!p->next){
                        p->next=current;        //add as last node;
                }

                printf("name=%s\nsex=%d,score=%d\n",input,score,sex);   //

        }
}
//////////////////////////////////////////////

void delInfo_sub(link H,int n){ //the munber of will del element;
        link p=H->next;
        link current=NULL;

        if(!p){
                printf("Opps! Student Info does NOT exists!\n");
                return;
        }

        for(int i=0;(i<n)&&(p->next);i++){      //there I should judge if the node to del exists;
                p=p->next;
        }

        current=p->next;        //p->next is the element to be delete;
        p->next=current->next;
        current->next=NULL;     //debug;
        free(current);
        current=NULL;
}


void delInfo(link H){
        int n;
        printf("please input the num you want to remove(q to quit):\n");
        if(scanf("%d",&n))
                delInfo_sub(H,n);       //?
}

////////////////////////////////////////////////////

void showInfo(link H){  //search by step.

        link p=H->next;
        link current=NULL;

        if(!H)
                printf("No Info yet!\n");
        else
                while(p->next!=NULL){
                        printf("Found:\nName=%s\nSex=%s\nScore=%d\n\n",p->name,p->sex?"male":"female",p->score);
                        p=p->next;
                }
}

/////////////////////////////////////////////////////

void searInfo(link H){  //search by name.

        char name[MAX];
        puts("Please input student's name you want to search:\n");
        fgets(name,MAX,stdin);

        link p=H->next;
        link current=NULL;

        if(!H)
                printf("No Info yet!\n");
	else{
		while((p->next!=NULL)){
                	p=(p)->next;
                	if(strcmp(p->name,name)==0){    /////Here compare two strings;
                        	printf("Found:\nName=%s\nSex=%s\nScore=%d\n\n",p->name,p->sex?"male":"female",p->score);
                	}
        	}
	}
}

