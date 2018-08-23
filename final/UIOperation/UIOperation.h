#ifndef UI_OPERATION
#define UI_OPERATION


/*Interface Operations*/
void ClearScn(void);
void PrintMenu(void);


/*Main Operations*/
void Cre(link *H);
void Add(link *H);
void Del(link H);
void Chg(link H);
void Ser(link H);
void Show(link H);
void Sort(link H);  //
void DelL(link *H);
void Save(link H);
void Read(link H);

/*Auth Operations*/
int Auth(void);


#endif
