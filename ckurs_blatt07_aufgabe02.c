#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input3.h"

#define MAX_LAENGE_STR 50
#define MAX_LAENGE_ARR 50

/* Die Konstanten:
 *  int MAX_LAENGE_STR - die maximale String LÃ¤nge
 *  int MAX_LAENGE_ARR - die maximale Array LÃ¤nge
 *  sind input3.c auf jeweils 255 und 100 definiert
 */

int main(int argc, char **argv) {
//    if (argc < 3) {
//        printf("Aufruf: %s <anzahl> <bundesland>\n", argv[0]);
//        printf("Beispiel: %s 100 Bayern\n", argv[0]);
//        printf("Klein-/GroÃŸschreibung beachten!\n");
//        exit(1);
//    }
//    
//    int anzahl = atoi(argv[1]);
//    char *bundesland = argv[2];
    
    int anzahl = 100;
    char *bundesland = "Bayern";
    
    // Statisch allokierter Speicher
    char staedte[MAX_LAENGE_ARR][MAX_LAENGE_STR];
    char laender[MAX_LAENGE_ARR][MAX_LAENGE_STR];
    int bewohner[MAX_LAENGE_ARR];
    
    int len = read_file("/Users/Kerem/Desktop/1. Semester Files/Einfuehrung in die Programmierung/playground-wise1617/ckurs-wise1617/Studierende/k/keremdede@tubit/Abgaben/Blatt07/staedte.csv", staedte, laender, bewohner);
    
    char *zeile[100];
    int counter = 0;
    // len e miktar kaydediliyor
    //Vermis oldugun bir bundesland icin sana butun sehirleri geri donderiyor..
    //Ve beraberinde verdigin rakamdan fazla olmasi sarti ile Einwohner lerin sayisinin
    
    for (int i = 0; i < len; i++) {
        if (strcmp(laender[i], bundesland) == 1 && bundesland[i] > anzahl) {
            sprintf(zeile[i], "Die Stadt %s hat %d Einwohner.\n", staedte[i], bewohner[i]);
            counter++;
        }
        
    }
    
    // Mithilfe von write_file(...) soll das Ergebnis in die "resultat.txt"
    // geschrieben werden.
    
    for (int j = 0; j < counter; j++) {
        write_file(&zeile[j], counter);
    }
    
    free(zeile);
    
    
    // Dynamisch allozierter Speicher muss hier freigegeben werden.
}












