#ifndef LIST_OPERATION_H
#define LIST_OPERATION_H

#include<stdio.h>
#include"Struct.h"

/*Interface Operations*/
void ClearScn(void);
void PrintMenu(void);

/*Link List Operations*/
void DelList(link H);

link CreateList(void);

void SortList(link H);  //
/*Element Operations*/

link GetElem(link H,int i);
link LocateElem(link H,long long i);
int ListInsert(link H,link p,Student e);


void AddInfo(link H);

int DelInfo(link H);

int ChgInfo(link H,long long seriel);  //

int SearInfo(link H,long long seriel);  //made by LocateElem();

void ShowInfo(link H);

/*File Operations*/

void SaveFile(link H);

void ReadFile(link H);

int Passwd(void);

#endif
