#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define COUNT 8

struct btree
{
    int valore;
    struct btree *leftPtr;
    struct btree *rightPtr;
};

typedef struct btree BST;

void init(BST **ptrPtr);
void print_rec(BST *ptr);
void ordinsert_rec(BST **ptrPtr, int val);

// funzione che genera un albero binario "random" (non BST)
void weirdinsert_rec(BST **ptrPtr, int val);

// DA SVILUPPARE: restituisce 1 se l'albero è un BST, 0 altrimenti
int isbst(BST *ptr);

void print_bst2D_uil(BST *root, int space);
void print_bst2D(BST *root);
void remove_node(BST **root, int val);
int trova_profondita(BST *albero);
// int trova_profondita(BST *albero, int prof);
int isBilanciato(BST *albero);

int main(void)
{
    BST *albero;
    init(&albero);

    // creazione di un BST
    ordinsert_rec(&albero, 2);
    ordinsert_rec(&albero, 1);
    ordinsert_rec(&albero, 0);
    ordinsert_rec(&albero, 2);
    ordinsert_rec(&albero, 6);
    ordinsert_rec(&albero, 6);
    ordinsert_rec(&albero, 5);
    // print_bst2D(albero);
    // printf("\nL'albero è un BST? %d\n", isbst(albero));

    // creazione di un btree non BST
    // inizializza generatore random
    time_t t;
    srand((unsigned)time(&t));
    BST *albero2;
    init(&albero2);

    weirdinsert_rec(&albero2, 2);
    weirdinsert_rec(&albero2, 1);
    weirdinsert_rec(&albero2, 0);
    weirdinsert_rec(&albero2, 3);
    weirdinsert_rec(&albero2, 7);
    weirdinsert_rec(&albero2, 5);
    weirdinsert_rec(&albero2, 9);
    // print_bst2D(albero2);
    // printf("\nL'albero è un BST? %d\n", isbst(albero2));

    // verifichiamo se il primo albero è un BST
    // printf("%d ", isbst(albero));
    // verifichiamo se il secondo albero è un BST
    // printf("%d ", isbst(albero2));
    BST *albero_eliminazione;
    init(&albero_eliminazione);
    ordinsert_rec(&albero_eliminazione, 100);
    ordinsert_rec(&albero_eliminazione, 150);
    ordinsert_rec(&albero_eliminazione, 170);
    ordinsert_rec(&albero_eliminazione, 120);
    ordinsert_rec(&albero_eliminazione, 180);
    ordinsert_rec(&albero_eliminazione, 170);
    ordinsert_rec(&albero_eliminazione, 50);

    // print_rec(albero_eliminazione);
    // printf("\n");
    // remove_node(&albero_eliminazione, 150);
    // print_rec(albero_eliminazione);
    // printf("\n");
    // printf("\nL'albero_eliminazione è un BST? %d\n", isbst(albero_eliminazione));
    // print_bst2D(albero);
    // printf("La profondita è: %d\n", trova_profondita(albero));
    // printf("La profondita è: %d\n", trova_profondita(albero, 0));

    // print_bst2D(albero2);
    // printf("La profondita è: %d\n", trova_profondita(albero2));
    // printf("La profondita è: %d\n", trova_profondita(albero2, 0));

    BST *test_profondita;
    init(&test_profondita);
    weirdinsert_rec(&test_profondita, 2);
    weirdinsert_rec(&test_profondita, 1);
    weirdinsert_rec(&test_profondita, 0);
    // weirdinsert_rec(&test_profondita, 3);
    // weirdinsert_rec(&test_profondita, 7);
    // weirdinsert_rec(&test_profondita, 5);
    // weirdinsert_rec(&test_profondita, 9);
    print_bst2D(albero);

    printf("L'albero è bilanciato: %d\n", isBilanciato(albero));
    return 0;
}

void init(BST **ptrPtr)
{
    *ptrPtr = NULL;
}

int isbstconfirmed(BST *ptr, int minVal, int maxVal)
{
    if (ptr != NULL)
    {
        if (ptr->valore > maxVal)
            return 0;
        if (ptr->valore < minVal)
            return 0;
        return isbstconfirmed(ptr->leftPtr, minVal, ptr->valore) && isbstconfirmed(ptr->rightPtr, ptr->valore, maxVal);
    }
    return 1;
}

// restituisce 1 se l'albero è un BST, 0 altrimenti
int isbst(BST *ptr)
{
    return isbstconfirmed(ptr, INT_MIN, INT_MAX);
}

// visita ricorsiva
void print_rec(BST *ptr)
{
    if (ptr != NULL)
    {
        // printf("%d ", ptr->valore); // visita in pre-ordine
        print_rec(ptr->leftPtr);
        printf("%d ", ptr->valore); // visita simmetrica (in ordine)
        print_rec(ptr->rightPtr);
        // printf("%d ", ptr->valore); // visita in post-ordine (in profondità / "depth-first")
    }
}

// inserimento in ordine (con ricorsione)
void ordinsert_rec(BST **ptrPtr, int val)
{
    if ((*ptrPtr) != NULL)
    {
        if (val <= (*ptrPtr)->valore)
            ordinsert_rec(&((*ptrPtr)->leftPtr), val);
        else
            ordinsert_rec(&((*ptrPtr)->rightPtr), val);
    }
    else
    {
        (*ptrPtr) = (BST *)malloc(sizeof(BST));
        (*ptrPtr)->valore = val;
        (*ptrPtr)->leftPtr = NULL;
        (*ptrPtr)->rightPtr = NULL;
    }
}

// inserimento che genera un albero binario non BST (con ricorsione)
void weirdinsert_rec(BST **ptrPtr, int val)
{

    int rand_val = rand();

    if ((*ptrPtr) != NULL)
    {
        if (rand_val % 2 == 0)
            weirdinsert_rec(&((*ptrPtr)->leftPtr), val);
        else
            weirdinsert_rec(&((*ptrPtr)->rightPtr), val);
    }
    else
    {
        (*ptrPtr) = (BST *)malloc(sizeof(BST));
        (*ptrPtr)->valore = val;
        (*ptrPtr)->leftPtr = NULL;
        (*ptrPtr)->rightPtr = NULL;
    }
}

//! Rimuovi nodo da albero

//? *****************************************************
//? ----- tecninca dell'inserimento del sottoalbero -----
//? *****************************************************
// versione scorrimento intero albero
// void inserisci_albero(BST **albero, BST *daInserire)
// {
//     if (daInserire != NULL)
//     {
//         ordinsert_rec(albero, daInserire->valore);
//         inserisci_albero(albero, daInserire->leftPtr);
//         inserisci_albero(albero, daInserire->rightPtr);
//     }
// }

// void inserisci_albero(BST **albero, BST *daInserire)
// {
//     if (*albero == NULL)
//     {
//         *albero = daInserire;
//         return;
//     }
//     if (daInserire->valore > (*albero)->valore)
//         inserisci_albero(&(*albero)->rightPtr, daInserire);
//     if (daInserire->valore <= (*albero)->valore)
//         inserisci_albero(&(*albero)->leftPtr, daInserire);
// }

// void remove_node(BST **root, int val)
// {
//     if (*root == NULL)
//         return;
//     if (val > (*root)->valore)
//         remove_node(&((*root)->rightPtr), val);
//     if (val < (*root)->valore)
//         remove_node(&((*root)->leftPtr), val);
//     if (val == (*root)->valore)
//     {
//         BST *appoggio_sinistra = (*root)->leftPtr; // sotto albero a partire dal figlio sinistro
//         BST *appoggio_destra = (*root)->rightPtr;  // sotto albero a partire dal figlio destro
//         free(*root);
//         if (appoggio_sinistra == NULL && appoggio_destra == NULL)
//             *root = NULL;
//         else if (appoggio_destra == NULL)
//             *root = appoggio_sinistra;
//         else
//         {
//             if (appoggio_sinistra == NULL)
//                 *root = appoggio_destra;
//             else
//             {
//                 *root = appoggio_sinistra;
//                 inserisci_albero(root, appoggio_destra);
//             }
//         }
//         return;
//     }
// }

//? ******************************************************************************
//? ----- tecnica del numero maggiore del sottoalbero di sinistra (del prof) -----
//? ******************************************************************************
int trova_maggiore(BST **root)
{
    if ((*root)->rightPtr == NULL)
    {
        int return_value = (*root)->valore;
        if ((*root)->leftPtr != NULL)
        {
            BST *left_tree = (*root)->leftPtr;
            free(*root);
            *root = left_tree;
        }
        else
        {
            free(*root);
            *root = NULL;
        }
        return return_value;
    }
    return trova_maggiore(&((*root)->rightPtr));
}

void remove_node(BST **root, int val)
{
    if (*root == NULL)
        return;
    if (val > (*root)->valore)
        remove_node(&(*root)->rightPtr, val);
    if (val < (*root)->valore)
        remove_node(&(*root)->leftPtr, val);
    if (val == (*root)->valore)
    {
        if ((*root)->leftPtr == NULL && (*root)->rightPtr == NULL)
        {
            free(*root);
            *root = NULL;
            return;
        }
        else if ((*root)->leftPtr == NULL || (*root)->rightPtr == NULL)
        {
            BST *appoggio = (*root)->rightPtr == NULL ? (*root)->leftPtr : (*root)->rightPtr;
            free(*root);
            *root = appoggio;
            return;
        }
        else
        {
            (*root)->valore = trova_maggiore(&((*root)->leftPtr));
            return;
        }
    }
}

// funzione di stampa/visualizzazione dell'albero
void print_bst2D_util(BST *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print_bst2D_util(root->rightPtr, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->valore);

    // Process left child
    print_bst2D_util(root->leftPtr, space);
}

void print_bst2D(BST *root)
{
    // Pass initial space count as 0
    print_bst2D_util(root, 0);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int trova_profondita(BST *albero)
{
    if (albero == NULL)
        return -1;
    int pSinistra = 1 + trova_profondita(albero->leftPtr);
    int pDestra = 1 + trova_profondita(albero->rightPtr);
    return max(pDestra, pSinistra);
}

// int trova_profondita(BST *albero, int prof)
// {
//     if (albero == NULL)
//         return prof;
//     return max(trova_profondita(albero->leftPtr, prof + 1), trova_profondita(albero->rightPtr, prof + 1));
// }

// valore assoluto
int abs(int a)
{
    if (a >= 0)
        return a;
    return -a;
}

int isBilanciato(BST *albero)
{
    if (albero == NULL)
        return 1;
    if (abs(trova_profondita(albero->leftPtr) - trova_profondita(albero->rightPtr)) > 1)
        return 0;
    return isBilanciato(albero->leftPtr) &&
           isBilanciato(albero->rightPtr);
}
