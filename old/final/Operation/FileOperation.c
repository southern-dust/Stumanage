/*File Operations*/

#include<stdio.h>
#include<stdlib.h>

#include"../Struct.h"
#include"Operation.h"

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
                        if(ListInsert(H,Addr2i(H,p),current)){
                                p=p->next;
                                H->seriel++;
                        }
                }
                num++;
        }
                        p->next=NULL;
        fclose(fp);
}
