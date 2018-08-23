#ifndef STRUCT_H
#define STRUCT_H

#define MAX 1024

typedef struct Student_Info{
        char name[MAX];
	long long seriel;  //long long?char[];
        int sex;      //is male?1:0;
        float score;

        struct Student_Info *next;
}Student,*link; //Student is notation of node, *link is node's point notation.

/* H->name is the List's name,
 * H->seriel is the num of Element, for some time use,
 * H->next is the first Elem
 */


#endif
