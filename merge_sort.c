//sablona pro programovani tridicich algoritmu v C
//ALGO1 2022/2023

// pouzivame zakladni knihovny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//nastavte si, jak velke chcete pole (kolik cisel budete tridit)
#define VELIKOST 10             //TADY UPRAVIT
//nastavte si rozsah cisel ke trideni
#define CISLA_OD 0             //TADY UPRAVIT
#define CISLA_DO 1000          //TADY UPRAVIT

//nahodne naplni pole nachystane pro VELIKOST prvku hodnotami v zadanem rozsahu
void napln_pole(int pole[]){
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < VELIKOST; i++){
      pole[i] = CISLA_OD + rand() % CISLA_DO;  
    }
}

//vypise pole obshaujici VELIKOST prvku
void vypis_pole(int pole[]){
    for (int i  =  0; i < VELIKOST; i++){
        printf("%d, ", pole[i]);
    }
}

//funkce provadejici trideni pomoci algoritmu selection sort
void selection_sort(int pole[]){
  int delka = VELIKOST;
  for(int j = 0; j < delka - 1; j++){
    int iMin  = j;
    for (int i = j + 1; i < delka; i++){
      if (pole[i] < pole[iMin]){
	iMin = i;

      }
    }
    int t = pole[j];
    pole[j] = pole[iMin];
    pole[iMin] = t;
  }
}

void insertion_sort(int pole[]){

     for (int x = 0; x < VELIKOST - 1; x++)
    {
        int aktualni = pole[x];
        int z = x - 1;
        while (z >= 0 && pole[z] > aktualni)
        {
            pole[z+1] = pole[z];
            z = z - 1;
        }
        pole[z + 1] = aktualni;
        
    }

}

int partition(int pole[], int L, int R){
    int x = pole[R];
    int i = L - 1;
    for (int j = L; j < R; j++)
    {
        if (pole[j] <= x)
        {
            i = i + 1;
            int vymena = 0;
            vymena = pole [i];
            pole [i] = pole[j];
            pole[j] = vymena;
        }
        
    }
    int vymena2 = 0;
    vymena2 = pole[i + 1];
    pole [i + 1] = pole[R];
    pole[R] = vymena2;
    return (i + 1);
}
void quicksort (int pole[], int L, int R){
    if (L < R){
        int q = partition(pole, L, R);
        quicksort(pole, L, q-1);
        quicksort(pole, q+1, R);
    }
}

int merge (int pole[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = pole[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = pole[q + 1 + j];
    }
    L[n1] = 1001;
    R[n2] = 1001;
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j]){
            pole[k] = L[i];
            i++;
        }
        else{
            pole[k] = R[j];
            j = j + 1;
        }
    }
    
    
    
}

void mergesort_ (int pole[], int p, int r){
    if (p < r){
        int q = (p+r)/2;
        mergesort_(pole, p , q);
        mergesort_(pole, q + 1, r);
        merge(pole, p, q ,r);
    }
}

void bubble_sort(int pole[]){
    for (int i = 0; i < VELIKOST - 2; i++)
    {
        for (int j = VELIKOST - 1;j > i ; j--)
        {
            if (pole[j] >= pole[j - 1]){
                int menic = 0;
                menic = pole[j];
                pole[j] = pole[j - 1];
                pole[j - 1] = menic;
            }
        }
        
    }
    
}

int main(void){
    //vytvorime, naplnime a vypiseme pole
    int pole[VELIKOST];
    int L = pole[0];
    int R = pole[VELIKOST - 1];
    napln_pole(pole);
    vypis_pole(pole);

   
    
    mergesort_(pole, 0, 9);
    
    
    //<--- dale kod nemente

    //vypiseme pole po vykonani uprav
    printf("\n");
    vypis_pole(pole);
    getchar(); //pockame na "enter" a skoncime
    return 0;
}
