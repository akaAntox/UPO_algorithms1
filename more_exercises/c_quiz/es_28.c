#include <stdlib.h>
#include <stdio.h>

typedef struct Lista
{
    int dato;
    struct Lista *nextPtr;
} Lista;

void push(Lista **headPtr, int value);
void pop(Lista **headPtr);
void list_print(Lista *headPtr, FILE *fp);

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t sizea = sizeof(a)/sizeof(a[0]);

    Lista *pila = NULL;

    for(size_t i=0; i<sizea; i++)
        push(&pila, a[i]);
    
    list_print(pila, stdout);

    for(size_t i=0; i<3; i++)
        pop(&pila);
    
    list_print(pila, stdout);

    sizea = sizeof(a)/sizeof(a[0]);

    for(size_t i=0; i<sizea; i++)
        pop(&pila);

    list_print(pila, stdout);
    
    return 1;
}

void push(Lista **headPtr, int value)
{
    Lista *newPtr = malloc(sizeof(Lista));
    newPtr->dato = value;
    newPtr->nextPtr = *headPtr;

    *headPtr = newPtr;
}

void pop(Lista **headPtr)
{
    if(*headPtr == NULL)
        return;

    Lista *delPtr = *headPtr;
    *headPtr = delPtr->nextPtr;
    free(delPtr);
}

void list_print(Lista *headPtr, FILE *fp)
{
    fprintf(fp, "[");
    while (headPtr != NULL)
    {
        if (headPtr->nextPtr == NULL)
            fprintf(fp, "%d", headPtr->dato);
        else
            fprintf(fp, "%d, ", headPtr->dato);

        headPtr = headPtr->nextPtr;
    }
    fprintf(fp, "]\n");
}