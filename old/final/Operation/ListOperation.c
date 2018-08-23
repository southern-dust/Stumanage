/*Link List Operations*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../Struct.h"
#include"Operation.h"

/*List Operations*/
link CreateList(void){
	link H=NULL;
	char name[MAX];

	printf("Plz type the name of the List you wanna to create:\n");
	scanf("%s",name);
	H=(link)malloc(sizeof(Student));
	printf("In CreateList() , H=%p\n",H);  //
	H->seriel=0;
	H->next=NULL;
	strcpy(H->name,name);

	return H;
}


void DelList(link H){
	for(int i=H->seriel-1;i>=0;i--){
		DelElem(H,i);
	}
}



/*Element Operations*/
link ListInsert(link H,int i,Student e){  //return inserted node;
	link p=NULL;
	
	/*get the prev node*/
	if(i==0){  //Insert node is the first one;
		p=H;
	}
	else{
		p=GetElem(H,i-1);
	}

	if(p){
		/*copy*/
		link q=(link)malloc(sizeof(Student));
		strcpy(q->name,e.name);
		q->seriel=e.seriel;
		q->sex=e.sex;
		q->score=e.score;

		/*insert*/
		q->next=p->next;  //Insert between q and q->next;
		p->next=q;

		H->seriel++;
		return q;
	}
	else{  //first node&& node to insert behind doesn't exist;
		return NULL;
	}
}


link GetElem(link H,int i){  //Search by seriel;
	int j=-1;
	link p=H;
	if(i<0){
		return(NULL);
	}
	while((p->next)&&(j<i)){
		p=p->next;
		j++;
	}

	if(i==j){
		return p;
	}
	else{
		return NULL;
	}
}


link LocateElem(link H,long long seriel){  //Search by Student's serielnum;
	link p=H->next;
	while(p&&(p->seriel!=seriel)){
		p=p->next;  //walk the list;
	}
	return p;  //if success, return p; if failed, return NULL;
}


int Addr2i(link H,link p){  //address convert to seriel;
	link q=H->next;
	int i=-1;
	while(q&&(i<=(H->seriel))){
		q=q->next;
		i++;
	}
	return i;
}


void DelElem(link H,int i){
	/*get the prev node*/
	link p=NULL;
	link q=NULL;
	if(!i){
		p=H;
	}
	else{
		p=GetElem(H,i-1);
	}
	if(p&&(p->next)){  //if has p and p->next(this);
		q=p->next;  //q->next is the node to be deleted;
		p->next=q->next;
		H->seriel--;
		free(q);
	}
}
