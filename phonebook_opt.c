#include <stdlib.h>
#include <string.h>

#include "phonebook_opt.h"

entry *findName(char lastName[], entry *pHead)
{

    int hashNumber=hash(lastName);
    entry *find;
    find=hashTable[hashNumber].pNext;

    while (find != NULL) {
        if (strcasecmp(lastName, find->lastName) == 0) {
            return find;
        }
        find = find->pNext;
    }

    return NULL;
}

entry *append(char lastName[], entry *e)
{

    int hashNumber=hash(lastName);
    temp = (entry *) malloc(sizeof(entry));

    //check hash table and insert to corresponding hash bukket
    if (hashTable[hashNumber].pNext == NULL) {   //empty
        hashTable[hashNumber].pNext=temp;
    } else {
        temp->pNext = hashTable[hashNumber].pNext;
        hashTable[hashNumber].pNext=temp;
    }

    strcpy(temp->lastName, lastName);

    return e;
}

int hash (char lastName[])
{
    int seed=26;
    long long hashNum=0;

    while (*lastName)
        hashNum=hashNum*seed+(*lastName++);

    return hashNum%8192;
}