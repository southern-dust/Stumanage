#ifndef OPERATION_H
#define OPERATION_H

#include<stdio.h>
#include"../Struct.h"


/*Link List Operations*/
link CreateList(void);
void DelList(link H);


link ListInsert(link H,int i,Student e);
link GetElem(link H,int i);
int Addr2i(link H,link p);
link LocateElem(link H,long long seriel);
void DelElem(link H,int i);



/*Info Operations*/
void AddInfo(link H);

int DelInfo(link H);

int ChgInfo(link H,long long seriel);

int SearInfo(link H,long long seriel);

void ShowInfo(link H);

void SortInfo(link H);  //

/*File Operations*/

void SaveFile(link H);

void ReadFile(link H);

//int Auth(void);  //Add to UIOperations;

#endif
