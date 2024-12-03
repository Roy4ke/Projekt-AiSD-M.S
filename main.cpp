#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;
// funkcja znajdująca maksymalną długość szukanego podciągu
int znajdzMaxDlugosc(const vector<int>& tablica) {
    // deklaracja zmiennej ciąg
    vector<int> ciag;
    int maxDlugosc = 0;

    for (size_t i = 0; i < tablica.size(); i++) {
        if (ciag.empty() || tablica[i] < ciag.back()) {
            ciag.push_back(tablica[i]);
        } else {
            maxDlugosc = max(maxDlugosc, static_cast<int>(ciag.size()));
            ciag = {tablica[i]};
        }
    }
    maxDlugosc = max(maxDlugosc, static_cast<int>(ciag.size()));
    return maxDlugosc;
}
// fuknkcja wypisująca najdłużyszy znaleziony podciąg
void wypiszNajdluzszeCiagi(const vector<int>& tablica, int maxDlugosc, ofstream& plik) {
    vector<int> ciag;

    cout << "Najdluzsze ciagi malejace (dlugosc = " << maxDlugosc << "):" << endl;
    plik << "Najdluzsze ciagi malejace (dlugosc = " << maxDlugosc << "):" << endl;
    for (size_t i = 0; i < tablica.size(); i++) {
        if (ciag.empty() || tablica[i] < ciag.back()) {
            ciag.push_back(tablica[i]);
        } else {
            if (ciag.size() == maxDlugosc) {
                for (int num : ciag) cout << num << " ";
                cout << endl;
                for (int num : ciag) plik << num << " ";
                plik << endl;
            }
            ciag = {tablica[i]};
        }
    }
    // ostatni ciag malejacy
    if (ciag.size() == maxDlugosc) {
        for (int num : ciag) cout << num << " ";
        for (int num : ciag) plik << num << " ";
        // wpisanie wyniku działania do pliku oraz jego wyświetlenie w terminalu
        plik << endl;
        cout << endl;
    }
}

int main() {
    // rozpoczęcie pomiaru czasu działania programu
    auto start = high_resolution_clock::now();
    // zmienna określająca rozmiar tablicy
    int N;
    cout << "Podaj liczbe elementow tablicy" << endl;
    cin >> N;
    vector<int> tablica(10);
    for (int i = 0; i < N; i++) {
        cout << "Podaj liczbe: " << endl;
        cin >> tablica[i];
    }
    ofstream plik("wynik.txt");
    // sprawdzanie czy plik zostaje poprawnie odczytywany
    if (!plik) {
        cout << "Nie mozna otworzyc pliku do zapisu!" << endl;
        return 1; // Kod błędu
    }

    // znajdź maksymalną długość ciągu malejącego
    int maxDlugosc = znajdzMaxDlugosc(tablica);
    //stworzenie pliku wynik.txt w którym będą umieszczane wyniki programu


    // wypisz tylko te ciągi, które mają maksymalną długość
    wypiszNajdluzszeCiagi(tablica, maxDlugosc, plik);
    // zakończenie pracy na pliku tekstowym
    plik.close();
    // zakończenie oraz wypisanie pomiaru czasu działania programu
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Czas wykonania programu: " << duration.count() << " ms" << endl;
    return 0;
}
