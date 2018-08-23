/*Info Operations*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../Struct.h"
#include"Operation.h"
#include"../UIOperation/UIOperation.h"

void AddInfo(link H){
	link p=NULL;
	Student current;

	puts("Enter student's name,seriel num,sex(is male? 1/0),and score:('quit' to quit)\n");
	while((scanf("%s",current.name)==1)&&(current.name[0]!='\n')&&(current.name[0]!='q')&&(strcmp(current.name,"quit"))){
		scanf("%lld%d%f",&current.seriel,&current.sex,&current.score);
		while((current.sex!=0)&&(current.sex!=1)){
			printf("invalid student sex, Plz input a correct one(0=female,1=male):\n");
			scanf("%d",&current.sex);
		}
                while(getchar()!='\n');  //clear input line;
		if((p=ListInsert(H,H->seriel,current))){  //ListInsert() return the inserted node;
			printf("In AddInfo(), H=%p,H->next=%p,p=%p,p->next=%p\n",H,H->next,p,p->next);  //
			p->next=NULL;  //set the tail node next to NULL;
                	puts("Enter student's name,seriel num,sex(is male? 1/0),and score:('quit' to quit)\n");
		}
		else{
			break;
		}
        }
	printf("In AddInfo(), H=%p,H->next=%p,p=%p,p->next=%p\n",H,H->next,p,p->next);  //
}


int DelInfo(link H){
        link current=NULL;
        long long seriel=0;

        printf("Plz input seriel num which the student has to Delete('0' to quit):\n");
        while(scanf("%lld",&seriel)==1&&(seriel)&&(H->seriel)){
                current=LocateElem(H,seriel);

                if(current){
                        printf("name=%s\tseriel num=%lld\tsex=%d\tscore=%f\nDo you Really want to Delete it?(0/1):\n",current->name,current->seriel,current->sex,current->score);

                        _Bool chosen=0;
                        if((scanf("%d",&chosen)==1)&&(chosen==1)){
				DelElem(H,Addr2i(H,current));
                                printf("OK!Already Deleted\n");
                        }
                }
                else
                {
                        printf("No such Element\n");
                }
        printf("Plz input seriel num which the student has to Delete('0' to quit):\n");
        }
}


//int SearInfo(link H,long long seriel){  //Search by student's seriel num;
//}

int ChgInfo(link H,long long seriel){
        link p=LocateElem(H,seriel);
        if(p){
                ClearScn();
                printf("1.name=%s\n2.seriel num=%lld\n3.sex=%d\n4.score=%f\nPlz select item to change(0 to quit):\n",p->name,p->seriel,p->sex,p->score);
                int choice=0;
                while((scanf("%d",&choice)==1)&&choice){
                        while(getchar()!='\n');  //clear input line;
                        switch(choice){
                                case 1: scanf("%s",p->name); break;
                                case 2: scanf("%lld",&p->seriel); break;
                                case 3: scanf("%d",&p->sex); break;
                                case 4: scanf("%f",&p->score); break;
                                default: break;
                        }
                        ClearScn();
                printf("1.name=%s\n2.seriel num=%lld\n3.sex=%d\n4.score=%f\nPlz select item to change(0 to quit):\n",p->name,p->seriel,p->sex,p->score);
                }
                return 0;
        }
        else{
                return -1;
        }

}



void ShowInfo(link H){
	if(H){
                link p=H->next;
                while(p){
                        printf("name=%s\tseriel num=%lld\tsex=%d\tscore=%f\n",p->name,p->seriel,p->sex,p->score);
                        p=p->next;
                }
                printf("Summary: List name:%s\n%d Student Info record\n",H->name,H->seriel);
        }
        else{
                printf("No List yet,please Add Info to Create the list\n");
        }
}

int SearInfo(link H,long long seriel){
        link p=LocateElem(H,seriel);

        ClearScn();
        if(p){
                printf("name=%s\tseriel num=%lld\tsex=%d\tscore=%f\n",p->name,p->seriel,p->sex,p->score);
        }
        else{
                printf("No such student who has this seriel num\nPlz input again\n");
        }
}

void swap_int(int *a,int *b){
	int tmp=0;
	tmp=*a;
	*a=*b;
	*b=tmp;
}


void swap_long(long long *a,long long *b){
        long long tmp=0;
        tmp=*a;
        *a=*b;
        *b=tmp;
}


void swap_float(float *a,float *b){
	float tmp=0;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

void SortInfo(link H){  //Bubble_sort;
	link p=NULL;
	link q=NULL;
	int flag=0;
	for(int i=0;i<(H->seriel);i++){
		flag=0;
		for(int j=0;j<(H->seriel)-i;j++){
			p=GetElem(H,i);
			q=GetElem(H,j);
			if((p->seriel)<(q->seriel)){  //swap p,q;
				//it maybe stupid, but it make sense;
				char tmp[MAX];
				strcpy(tmp,p->name);
				strcpy(p->name,q->name);
				strcpy(q->name,tmp);
				
				swap_long(&(p->seriel),&(q->seriel));
				swap_int(&(p->sex),&(q->sex));
				swap_float(&(p->score),&(q->score));
			}
		}
		if(!flag){
			break;
		}
	}
}
