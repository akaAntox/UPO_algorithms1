#include <stdlib.h>
#include <stdio.h>

typedef struct Lista
{
    int dato;
    struct Lista *nextPtr;
} Lista;

void list_insert(Lista **headPtr, int value);
Lista *list_search(Lista **headPtr, int value);
void list_delete(Lista **headPtr, int value);
void list_print(Lista *headPtr, FILE *fp);

int main()
{
    int a[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    size_t n = sizeof(a) / sizeof(a[0]);
    int adel[] = {a[0], a[1], a[n - 1], -10};
    size_t ndel = sizeof(adel) / sizeof(adel[0]);
    Lista *lista = NULL;

    for (size_t i = 0; i < n; i++)
        list_insert(&lista, a[i]);

    list_print(lista, stdout);
    printf("\n");

    for (size_t i = 0; i < ndel; i++)
    {
        list_delete(&lista, adel[i]);
        if (list_search(&lista, adel[i]) != NULL)
            printf("Elemento %d eliminato e ritrovato!\n", adel[i]);
        else
            printf("Elemento %d eliminato e non trovato!\n", adel[i]);
    }

    list_print(lista, stdout);
    printf("\n");

    while (lista != NULL)
        list_delete(&lista, lista->dato);

    list_print(lista, stdout);
    printf("\n");

    return 1;
}

void list_insert(Lista **headPtr, int value)
{
    Lista *newPtr = malloc(sizeof(Lista));
    newPtr->dato = value;
    newPtr->nextPtr = NULL;

    Lista *prevPtr = NULL;
    Lista *tmpPtr = *headPtr;

    while (tmpPtr != NULL && tmpPtr->dato < value)
    {
        prevPtr = tmpPtr;
        tmpPtr = tmpPtr->nextPtr;
    }

    if (prevPtr == NULL)
    {
        newPtr->nextPtr = tmpPtr;
        *headPtr = newPtr;
    }
    else
    {
        newPtr->nextPtr = tmpPtr;
        prevPtr->nextPtr = newPtr;
    }
}

Lista *list_search(Lista **headPtr, int value)
{
    Lista *tmpPtr = *headPtr;

    if (tmpPtr == NULL)
        return NULL;

    while (tmpPtr != NULL)
    {
        if (tmpPtr->dato == value)
            return tmpPtr;

        tmpPtr = tmpPtr->nextPtr;
    }
}

void list_delete(Lista **headPtr, int value)
{
    Lista *tmpPtr = *headPtr;

    if (tmpPtr->dato == value)
    {
        *headPtr = tmpPtr->nextPtr;
        free(tmpPtr);
        return;
    }

    Lista *prevPtr = *headPtr;
    tmpPtr = prevPtr->nextPtr;

    while (tmpPtr != NULL)
    {
        if (tmpPtr->dato == value)
        {
            prevPtr->nextPtr = tmpPtr->nextPtr;
            free(tmpPtr);
            break;
        }
        prevPtr = tmpPtr;
        tmpPtr = tmpPtr->nextPtr;
    }
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
    fprintf(fp, "]");
}