#include <stdlib.h>
#include <stdio.h>

typedef struct Lista {
    int dato;
    struct Lista *nextPtr;
} Lista;

Lista* list_insert_head(Lista *headPtr, int value);
Lista* list_search(Lista *headPtr, int value);
Lista* list_delete(Lista *headPtr, int value);
void list_print(Lista *headPtr, FILE *fp);

int main()
{
    int a[] = {1,2,3,4,5,4,3,2,1};
    size_t n = sizeof(a) / sizeof(a[0]);
    int adel[] = {a[0], a[1], a[n-1], -10};
    size_t ndel = sizeof(adel) / sizeof(adel[0]);
    Lista *lista = NULL;

    for(size_t i=0; i<n; i++)
        lista = list_insert_head(lista, a[i]);

    list_print(lista, stdout);
    printf("\n");

    for(size_t i=0; i<ndel; i++)
    {
        lista = list_delete(lista, adel[i]);
        if(list_search(lista, adel[i]) != NULL)
            printf("Elemento %d eliminato e ritrovato!\n", adel[i]);
        else
            printf("Elemento %d eliminato e non trovato!\n", adel[i]);
    }

    list_print(lista, stdout);
    printf("\n");

    while (lista != NULL)
        lista = list_delete(lista, lista->dato);

    list_print(lista, stdout);
    printf("\n");

    return 1;
}

Lista* list_insert_head(Lista *headPtr, int value)
{
    Lista *newHeadPtr;
    newHeadPtr = malloc(sizeof(Lista));
    newHeadPtr->nextPtr = headPtr;
    newHeadPtr->dato = value;

    return newHeadPtr;
}

Lista* list_search(Lista *headPtr, int value)
{
    if(headPtr == NULL)
        return NULL;

    Lista *tmpPtr;
    tmpPtr = headPtr;
    
    while(tmpPtr != NULL)
    {
        if(tmpPtr->dato == value)
            return tmpPtr;
        
        tmpPtr = tmpPtr->nextPtr;
    }

    return NULL;
}

Lista* list_delete(Lista *headPtr, int value)
{
    if(headPtr == NULL)
        return NULL;
    
    if(headPtr->dato == value)
    {            
        Lista *newHeadPtr;
        newHeadPtr = headPtr->nextPtr;
        free(headPtr);

        return newHeadPtr;
    }
    
    Lista *prevPtr = headPtr;
    Lista *tmpPtr = headPtr->nextPtr;

    while(tmpPtr != NULL)
    {
        if(tmpPtr->dato == value)
        {
            prevPtr->nextPtr = tmpPtr->nextPtr;
            free(tmpPtr);
            break;
        }
        
        prevPtr = tmpPtr;
        tmpPtr = tmpPtr->nextPtr;
    }

    return headPtr;
}

void list_print(Lista *headPtr, FILE *fp)
{
    fprintf(fp, "[");
    while(headPtr != NULL)
    {
        if(headPtr->nextPtr == NULL)
            fprintf(fp, "%d", headPtr->dato);
        else
            fprintf(fp, "%d, ", headPtr->dato);
        
        headPtr = headPtr->nextPtr;
    }
    fprintf(fp, "]");
}