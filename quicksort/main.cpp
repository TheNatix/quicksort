#include <iostream>
#include <iomanip>
#include <random>

void quicksort(int* tab, int left, int right) {
    if (left >= right) return;

    int pivotIndex = (int)((left + right) / 2);
    int pivot = tab[pivotIndex];
    int i = left;
    int j = right;

    std::cout << "Wybrany pivot: " << pivot << " na indexsie " << pivotIndex << "\n";

    tab[pivotIndex] = tab[right];
    tab[right] = pivot;

    while (i < j) {
        while (i < j && tab[i] < pivot) {
            std::cout << "i: " << i << ", tab[i]: " << tab[i] << " < pivot: " << pivot << "\n";
            i++;
        }
        while (i < j && tab[j] >= pivot) {
            std::cout << "j: " << j << ", tab[j]: " << tab[j] << " >= pivot: " << pivot << "\n";
            j--;
        }
        if (i < j) {
            std::swap(tab[i], tab[j]);
            std::cout << "Wymieniamy tab[" << i << "]: " << tab[i] << " z tab[" << j << "]: " << tab[j] << "\n";
        }
    }

    tab[right] = tab[j];
    tab[j] = pivot;
    std::cout << "Wybrany pivot: " << pivot << " na indexsie " << j << "\n";

    if (left < j - 1) {
        std::cout << "Wchodzimy na rekurencje na lewa strone: lewa = " << left << ", j - 1 = " << (j - 1) << "\n";
        quicksort(tab, left, j - 1);
    }

    if (j + 1 < right) {
        std::cout << "Wchodzimy na rekurencje na prawa strone: j + 1 = " << (j + 1) << ", right = " << right << "\n";
        quicksort(tab, j + 1, right);
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 100);

    int n = 10;
    int tab[10];

    for (int i = 0; i < n; i++)
        tab[i] = distr(gen);

    std::cout << "Startowa tablica:\n";
    for (int i = 0; i < n; i++)
        std::cout << std::setw(4) << tab[i];
    std::cout << std::endl;

    quicksort(tab, 0, n - 1);

    std::cout << "Po quicksorcie:\n\n";
    for (int i = 0; i < n; i++)
        std::cout << std::setw(4) << tab[i];
    std::cout << std::endl;

    return 0;
}

