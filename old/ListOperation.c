#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"Struct.h"
#include"ListOperation.h"
#include"Platform/Platform.h"


/*Interface Operations*/
void ClearScn(void){  //All of the ClearScn() call should at begin of the funcion;
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
        printf("5. Show students' Informations\n");
        printf("6. Search students' Informations\n");
        printf("7. Delete Information List\n");
        printf("8. Sort Information List  //\n");
        printf("9. Save to File\n");
        printf("10. Read from File\n");

        printf("**************************************************\n");
}

/*Link List Operations*/
void DelList(link H){
	link p=H->next;
	
	while(p){
		link q=p;
		while(q){
			if(!q->next){
				free(q);
			}
			q=q->next;
		}
		p=p->next;
	}
	free(H);
	H=NULL;  //
	printf("H in DelList =%p\n",H);
}

link CreateList_sub(void){
	link H=NULL;
	H=(link)malloc(sizeof(Student));
	H->seriel=0;  //has no elem yet;
	H->next=NULL;
	return H;
}


link CreateList(void){
	char name[MAX];
	printf("Plz type the name of the list you wanna as List's name\n");
	scanf("%s",name);
	link H=CreateList_sub();
	strcpy(H->name,name);
	
	H->next=NULL;
	return H;
}


void SortList(link H){  //
	;
}


/*Element Operations*/
link GetElem(link H,int i){  //no use?
	int j=-1;
	link p=H;
	if(i<0){
		return NULL;
	}
	while((p->next)&&(j<i)){
		p=p->next;
		j++;
	}
	if(i==j) return p;
	else{
		return NULL;
	}
}


link LocateElem(link H,long long i){  //because AddInfo() made a sort;
	link p=H->next;
	while(p){
		//printf("p->seriel=%lld\n",p->seriel);  //
		if(p&&((p->seriel)==i)){  //i<=(p->seriel)
			return p;
		}
		p=p->next;
	}
	return NULL;  //Not found;
}


int ListInsert(link H,link p,Student e){  //what does link e mean?

	link q=NULL;
	if(!(H->next)){  //The first one; //not executed
		p=H;
		printf("H->next==NULL: p=H is %p\n",H);  //
	}
	if(!p){
		return 0;  //error;
	}
	else{
		q=(link)malloc(sizeof(Student));
		/*store data*/
		strcpy(q->name,e.name);
		q->seriel=e.seriel;
		q->sex=e.sex;
		q->score=e.score;
		q->next=NULL;  //no difference;


		q->next=p->next;  //if it is the 'first' or'last' node, it'll be NULL; NO DIFFERENCE;
		p->next=q;

		printf("q:name=%s\tseriel num=%lld\tsex=%d\tscore=%f\n",q->name,q->seriel,q->sex,q->score);  //
		printf("H=%p\tH->next=%p\tH->next->next=%p\np=%p\tp->next=%p\tp->next->next=%p\n\t\tq=p->next=%p\tq->next=%p\n",H,H->next,H->next->next,p,p->next,p->next->next,q,q->next);   //
		printf("Insert OK\n");   //
	}
	return 1;  //success!
}


void AddInfo(link H){  //based sort & ListInsert();
	
	link p=H;  //from H;
	Student current;

	puts("Enter student's name,seriel num,sex(is male? 1/0),and score:('quit' to quit)\n");
	while((scanf("%s",current.name)==1)&&(current.name[0]!='\n')&&(current.name[0]!='q')&&(strcmp(current.name,"quit"))){
		scanf("%lld%d%f",&current.seriel,&current.sex,&current.score);
		while(getchar()!='\n');  //clear input line;
		
		//printf("current.name:%s current.seriel:%lld current.sex:%d current.score:%f\n",current.name,current.seriel,current.sex,current.score);  //
		

		if((!(p->next))||(p->seriel!=current.seriel)){  //(!(p->next))? Insert at next or the last.
			if(ListInsert(H,p,current)){
				p=p->next;
				H->seriel++;
			}
			p->next=NULL;  //
			printf("name=%s\tseriel num=%lld\tsex=%d\tscore=%f\n",p->name,p->seriel,p->sex,p->score);  //sgment fault!  //
			//printf("p->name=%p p->seriel=%p p->sex=%p p->score=%p\n",p->name,p->seriel,p->sex,p->score);  //sgment fault!
			}
		else{
			printf("%lld %s already exist.\nDo you want to change it or give up to next input?(0/1):\n");
			_Bool chosen=0;
			if((scanf("%d",&chosen)==1)&&(chosen==1)){
				ChgInfo(H,current.seriel);
			}
		}

		printf("H->seriel=%d\n",H->seriel);  //
		puts("Enter student's name,seriel num,sex(is male? 1/0),and score:('quit' to quit)\n");
	}
}


int DelInfo(link H){
	link p=NULL;
	link current=NULL;

	long long seriel=0;

	printf("Plz input seriel num which the student has to Delete('0' to quit):\n");
	while(scanf("%lld",&seriel)==1&&(seriel)&&(H->seriel)){
		//walk the list;
		//and p->next is the Elem to be Deleted;


		printf("Del Pre: H->seriel=%d\n",H->seriel);  //
		current=LocateElem(H,seriel);
		/*To find the prev of current*/
		p=H->next;
		while(p->next){  //problem here;
			if(p&&(p->next==current)||(p==current)){
				break;
			}
			p=p->next;
		}/*now find prev*/

		printf("p=%p current=%p\n",p,current);  //
		
		
		if(current){
			printf("name=%s\tseriel num=%lld\tsex=%d\tscore=%f\nDo you Really want to Delete it?(0/1):\n",current->name,current->seriel,current->sex,current->score);

			_Bool chosen=0;
			if((scanf("%d",&chosen)==1)&&(chosen==1)){
				if(current->next){
					current=p->next;
				}
				p->next=current->next;
				if(p==current){  //it is the last lasted node;
					p=H;  //clean poiter for free(current);
					p->next=NULL;
				}

				free(current);
				H->seriel--;
				printf("OK!Already Deleted\n");
			}
		}
		else
		{
			printf("No such Element\n");
		}
		printf("Del after: H->seriel=%d\n",H->seriel);  //
	printf("Plz input seriel num which the student has to Delete('0' to quit):\n");
	}

}


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
				case 2: scanf("%lld",&p->seriel); break;  //sort...
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


int SearInfo(link H,long long seriel){  //based LocateElem(); //no use?
	link p=LocateElem(H,seriel);
	
	ClearScn();
	if(p){
		printf("name=%s\tseriel num=%lld\tsex=%d\tscore=%f\n",p->name,p->seriel,p->sex,p->score);
	}
	else{
		printf("No such student who has this seriel num\nPlz input again\n");
	}
}


void ShowInfo(link H){  // is LocateElem();
	if(H){
		link p=H->next;
		while(p){
			printf("p=%p p->next=%p H=%p H->next=%p\n",p,p->next,H,H->next);  //
			printf("name=%s\tseriel num=%lld\tsex=%d\tscore=%f\n",p->name,p->seriel,p->sex,p->score);
			p=p->next;
		}
		printf("Summary: List name:%s\n%d Student Info record\n",H->name,H->seriel);
	}
	else{
		printf("No List yet,please Add Info to Create the list\n");
	}
}



/*File Operations*/
void SaveFile(link H){
	link p=H->next;
	FILE *fp;

	fp=fopen("data.txt","w");
	printf("%s %lld\n",H->name,H->seriel);  //
	fprintf(fp,"%s %lld\n",H->name,H->seriel);
	while(p){
		printf("%s\t%lld\t%d\t%f\n",p->name,p->seriel,p->sex,p->score);  //
		fprintf(fp,"%s\t%lld\t%d\t%f\n",p->name,p->seriel,p->sex,p->score);
		p=p->next;
		}
	fclose(fp);
}


void ReadFile(link H){
	link p=H;
	Student current;
	FILE *fp;

	fp=fopen("data.txt","r");
	
	fscanf(fp,"%s %lld\n",H->name,&H->seriel);

	int num=0;
	while((fscanf(fp,"%s",current.name)==1)&&(num<(H->seriel))){
                fscanf(fp,"%lld%d%f",&current.seriel,&current.sex,&current.score);


		if((!(p->next))||(p->seriel!=current.seriel)){  //(!(p->next))? Insert at next or the last.
			if(ListInsert(H,p,current)){
				p=p->next;
				H->seriel++;
			}
		}
		num++;
	}
			p->next=NULL;  //

		
	fclose(fp);
}


/*Passwd*/
int Passwd(void){
	FILE *fp=fopen("passwd.txt","r");

	char passwd[MAX],username[MAX];
	char passwd_old[MAX],username_old[MAX];
	int time=0,auth=0;

	ClearScn();
	printf("Plz input your USERNAME:\n");
	printf("Plz input your PASSWD:\n");
	
	fscanf(fp,"%s%s",username_old,passwd_old);
	while((scanf("%s%s",username,passwd)!=1)&&(auth=((strcmp(passwd,passwd_old)&&(strcmp(username,username_old)))))){
		printf("Authentication failure\n");
		printf("Plz input your passwd CORRECTLY:\n");
		time++;
		if(time==3){
			printf("Do you forgot your passwd?\nWe can help you find your passwd");
			printf("Plz input your seriel num\n");
			
			fclose(fp);
			fp=fopen("passwd.txt","w");
			
			scanf("%s",passwd_old);
			fprintf(fp,"%s %s",username_old,passwd_old);

			fclose(fp);
			fp=fopen("passwd.txt","w");
			fscanf(fp,"%s%s",username_old,passwd_old);
			
			printf("Okay.Passwd changed to your seriel num.plese try again\n");
		}
		else if(time>3){
			printf("Too many Failures\n");
			return -1;
		}
	}
	if(!auth){  //it is okay;
		fclose(fp);
		return 0;
	}

}
