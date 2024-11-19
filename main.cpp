#include <iostream>
using namespace std;
void najdluzszypodciag(int A[], int n) {
    if(n==0)return;
    int* dlugosc = new int[n];      // Tablica do przechowywania długości najdłuższego malejącego podciągu
    int* popr = new int[n];        // Tablica do przechowywania poprzedników w podciągu
    int maxdlugosc = 1;             // Maksymalna długość znalezionego podciągu
    int* indk = new int[n];  // Tablica przechowująca indeksy końcowe podciągów o długości maxLength
    int ilosc = 0;              //ilości podciągów
    for (int i = 0; i < n; i++) { // tablice pomocnicze do wyznaczania długości podciągu
        dlugosc[i] = 1;
        popr[i] = -1;
    }
}
int main(){
    int a;
    int c[4];
    cout << "podaj rozmiar tablicy: "<< endl;
    cin >> a;
    int tab[a];
    for(int i= 0;i <a; i++) {
     cout << "podaj wartosci tablicy : " << endl;
        cin >> tab[i];
    }
    for(int i = 0; i < a; i++) {
        cout << tab[i] << " ";
    }

cout << "najdluzszy malejacy podciag to: " << endl;
    return 0;
}
