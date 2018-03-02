#include <stdlib.h>
#include <string.h>

#include "phonebook_opt.h"

entry *findName(char lastName[], entry *pHead)
{

    entry *find;
    find=prefix[lastName[0]-97].pNext;

    while (find != NULL) {
        if (strcasecmp(lastName, find->lastName) == 0)
            return find;
        find = find->pNext;
    }

    return NULL;
}

entry *append(char lastName[], entry *e)
{

    temp = (entry *) malloc(sizeof(entry));

    //check what prefix is and insert into prefix array
    if (prefix[lastName[0]-97].pNext == NULL) {   //empty

        prefix[lastName[0]-97].pNext=temp;
    } else {
        temp->pNext = prefix[lastName[0]-97].pNext;
        prefix[lastName[0]-97].pNext=temp;
    }

    strcpy(temp->lastName, lastName);

    return e;
}
