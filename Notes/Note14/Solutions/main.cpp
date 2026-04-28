#include "AdvanceSorting.h"

int main()
{
    srand(time(nullptr));
    dsn::Array<int> A(10), B, C;

    for(int i = 0;i < 10;i += 1)
    {
        A[i] = rand() % 100;
    }

    B = A;
    C = A;
    std::cout << A << "\n";
    dsn::MergeSort(A,0,9);

    std::cout << "\nQuick Sort\n";
    dsn::QuickSort(B,0,9);

    std::cout << "\nRandomized Quick Sort\n";
    dsn::RandomizeQuickSort(C,0,9);

    return 0;
}