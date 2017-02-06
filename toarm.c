/* === INTROPROG ABGABE ===
 * Blatt 11, Aufgabe 2
 * Tutorium: tXX
 * Gruppe: gXX
 * Gruppenmitglieder:
 *  - Erika Mustermann
 *  - Rainer Testfall
 * ========================
 */

#include <stdlib.h>
#include <stdio.h>    //Ein- / Ausgabe
#include <math.h>     //Für die Berechnungen der Ausgabe
#include "avl.h"

// Gibt den gesamten AVL Baum in "in-order" Reihenfolge aus.
/*void AVL_in_order_walk(AVLTree* avlt)
{
    //Hier Code implementieren!
    if (avlt != NULL) {
        AVL_in_order_walk_node(avlt->root);
        printf("\n");
    }
}
// This is extra funtion for AVL_in_order_walk, i want to reuse my code.
    void AVL_in_order_walk_node(AVLNode* avl_node) {
        if (avl_node != NULL) {
            AVL_in_order_walk_node(avl_node->left);
		    printf("%d ", avl_node->value);
            AVL_in_order_walk_node(avl_node->right);
        }
    } 
    */
// End extra funtion.    
                
                    void AVL_in_order_walk_node(AVLNode* node) {
                        if (node != NULL)
                        {
                            AVL_in_order_walk_node(node->left);
                            printf("%d,",	 node->value);
                            AVL_in_order_walk_node(node->right);
                        }
                        
                    }
                    // Gibt den gesamten AVL Baum in "in-order" Reihenfolge aus.
                    void AVL_in_order_walk(AVLTree* avlt)
                    {
                        if (avlt != NULL)
                        {
                            AVL_in_order_walk_node(avlt->root);
                        }
                    }
// Diese Funktion führt eine Linksrotation auf dem angegebenen Knoten aus.
// Beachtet: Die Höhen der entsprechenden Teilbäume müssen (lokal) 
// angepasst werden.
void AVL_rotate_left(AVLTree* avlt, AVLNode* x)
{
    //Hier Code implementieren!
}

// Diese Funktion führt eine Rechtsrotation auf dem angegebenen Knoten aus.
// Beachtet: Die Höhen der entsprechenden Teilbäume müssen (lokal) 
// angepasst werden.
void AVL_rotate_right(AVLTree* avlt, AVLNode* y)
{
    //Hier Code implementieren!
}

//Balanciere den Teilbaum unterhalb von node.
void AVL_balance(AVLTree* avlt, AVLNode* node)
{
    //Hier Code implementieren!
}


// Fügt der Wert value in den Baum ein.
// Die Implementierung muss sicherstellen, dass der Baum nach dem Einfügen
// immer noch balanciert ist!
void AVL_insert_value(AVLTree* avlt, int value)
{
    //Hier Code implementieren!
    AVLNode* temp_root = NULL;
    if (avlt->root == NULL) {
        // If == NULL then the tree now contain only one node: new_node
        AVLNode* new_node = malloc(sizeof(AVLNode));
        new_node->value = value;
        new_node->parent = temp_root;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->height = 1;
        avlt->root = new_node;
        avlt->numberOfNodes++;

    } else if (value < avlt->root->value) {
        temp_root = avlt->root;
        avlt->root = avlt->root->left;
        AVL_insert_value(avlt, value);
    } else if (value > avlt->root->value) {
        temp_root = avlt->root;
        avlt->root = avlt->root->right;
        AVL_insert_value(avlt, value);
    } else {
        return;     // cause the value existiert
    }
    // We go back to root and change the height of each node if we need:
    if (avlt->root->left->height >= avlt->root->right->height) {
        avlt->root->height = avlt->root->left->height +1;
    } else {
        avlt->root->height = avlt->root->right->height +1;
    }
    AVL_balance(avlt, avlt->root);
}


// Löscht den gesamten AVL-Baum und gibt den Speicher aller Knoten frei.
void AVL_remove_all_elements(AVLTree* avlt)
{
    //Hier Code implementieren!
}


