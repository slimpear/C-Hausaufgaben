/* === INTROPROG ABGABE ===
 * Blatt 10, Aufgabe 1
 * Tutorium: t23
 * Gruppe: g11
 * Gruppenmitglieder:
 *  - Ammer Ayach
 *  - Amir Alchikh
 * ========================
 */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "quicksort.h"
#define READ_SIMPLE "r"


/*****************************************************
 * Die benoetigten structs findet Ihr in quicksort.h *
 *****************************************************/


list_element *list_take_first(list *mylist) {
    list_element *le = mylist->first;
    if (le != NULL) {
        mylist->first = le->next;
        le->next = NULL;
        if (mylist->first == NULL) {
            mylist->last = NULL;
        }
    }
    return le;
}

// Diese Funktion fügt Listenelemente an die Liste an
void insert_list(list_element* le, list* mylist)
{
    if (mylist->first == NULL) {
        mylist->first = le;
        mylist->last = le;

        le->next = NULL;
    } else {
        mylist->last->next= le;
        mylist->last=le;

        le->next = NULL;
    }
}


// Liste teilen. Teillisten werden in left und right zurück gegeben
/*list_element* partition( list* input, list* left, list* right )
{
    // HIER Code einfügen:
    // parition() Funktion implementieren
    list_element *pivot = input->first;         // take first element in list and set it pivot.
    // Greater element to right
    list_element *temp = pivot->next;
    list_element *temp2;
    while (temp != NULL) {
        temp2 = temp->next;
        if (temp->count < pivot->count) {
            temp->next = NULL;
            // i know here is problem but just do it!
            insert_list(temp, left);
        } else {
            temp->next = NULL;
            // i know here is problem but just do it!
            printf("*****     I AM FUCKING HERE     *****\n");
            insert_list(temp, right);
        }
        temp = temp2;
    }
    return pivot;
}*/


list_element *partition(list *input, list *left, list *right) {
   // list_element *pivot = list_take_first(input);
   
    list_element* pivot;
    if (input->first == NULL)
    {
        input->last = NULL;
        pivot = NULL;
        
    }else{
        pivot = input->first;
        input->first = pivot->next;
        pivot->next=NULL;
    }
    if (pivot != NULL) {
        list_element *tmp = list_take_first(input);
        while (tmp != NULL) {
            if (tmp->count >= pivot->count) {
                insert_list(tmp, right);
            } else {
                insert_list(tmp, left);
            }
            tmp = list_take_first(input);
        }
    }
    return pivot;
}

// Hauptfunktion des quicksort Algorithmus
void qsort_list(list* mylist)
{
    // HIER Code einfügen
    if (mylist->first == mylist->last) {
        //list 0/1 length
    } else {
        list left; 
        list right;
        init_list(&left);
        init_list(&right);

        list_element *pivot = partition(mylist, &left, &right);
        //printf("***     I AM qsort_list     ***\n");
        qsort_list(&left);
        qsort_list(&right);
        // THIS SHIT IS FOR JOINING TWO PARTITIONS WITH PIVOT IN MITTLE:
        // Why the hell they didnt write some comments here????
        if (left.first == NULL) {
            mylist->first = pivot;
        } else {
            mylist->first = left.first;
            left.last->next = pivot;
        }

        if (right.first == NULL) {
            pivot->next = NULL;
            mylist->last = pivot;
        } else {
            pivot->next = right.first;
            mylist->last = right.last;
        }
        // END JOINING.
    }
}

// Liste ausgeben
void print_list(list* mylist)
{
    // HIER Code einfügen:
    // * Laufe über die list_element in mylist und gebe sie aus.
    list_element* current = mylist->first;
    if(current == NULL) {
        return;
    }

    while(current != NULL) {
        printf("%s, %d\n",current->password, current->count);
        current = current->next;
    }
}

// Speicher für Listenelemente wieder freigeben
void free_list(list* mylist)
{
    // HIER Code einfügen
    if (mylist == NULL || mylist->first == NULL) {
        return;
    } else {
        list_element* current = mylist->first;
        list_element* temp = NULL;

        while(current->next != NULL) {
            temp = current;
            current= current->next;
            free(temp->password);
            free(temp);
        }

        free(current->password);
        free(current);
    }
}


// Namen, Zahlen Paare in Liste einlesen
void read_data(char* filename, list* mylist)
{
    // HIER Code einfügen:
    // * Speicher allozieren
    // * Daten in list_element einlesen
    // * insert_front benutzen um list_element in Liste einzufügen
    FILE *fp_in = fopen(filename, READ_SIMPLE);
    if (fp_in == NULL) {
        perror("Could not open input file!");
        return;
    }
    char buffer[1000];
    char pass[100];
    int number;
    while(fgets(buffer, sizeof(buffer), fp_in) != NULL){
        if((sscanf(buffer, "%s %d", pass, &number)) != 2) {
            break;
        }
        list_element* new = (list_element*) malloc(sizeof(list_element));    
        new->password = malloc(strlen(pass)+1);
        strcpy(new->password, pass);
        new->count = number;
        new->next = NULL;
        insert_list(new, mylist);
    }
    // CHECKEN: 
    printf("=>>>----------Original list--------\n");
    print_list(mylist);
    printf("----------Original list--------<===\n");
    fclose(fp_in);
}



void init_list(list* mylist)
{
    // HIER Liste initialisieren
    mylist->first = NULL;
    mylist->last = NULL;
}
