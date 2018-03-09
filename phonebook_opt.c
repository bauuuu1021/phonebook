#include <stdlib.h>
#include <string.h>

#include "phonebook_opt.h"

entry *findName(char lastName[], entry *pHead)
{

    entry *find;
    find=prefix[lastName[0]-97].pNext;

    while (find != NULL) {  //the lastname can be found
        if (strcasecmp(lastName, find->lastName) == 0)
            return find;
        find = find->pNext;
    }

    //can't find, fuzzy search
    entry *bestFit, *current;
    int i=0;
    int sameLetterMax=0, sameLetter=0;
    current=prefix[lastName[0]-97].pNext;

    while (current!=NULL) {
        while (lastName[i]!='\0' && current->lastName[i]!='\0') {   //check if ith letter is the same
            if (lastName[i] == current->lastName[i])
                sameLetter++;
            i++;
        }
        if (sameLetter>sameLetterMax) { //if new bestfit appear, switch current and max
            bestFit = current;
            sameLetterMax=sameLetter;
        }
        sameLetter=0;
        current=current->pNext;
        i=0;
    }

    printf("Couldn't find '%s', did you mean '%s'??\n", lastName, bestFit);

    return lastName;
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