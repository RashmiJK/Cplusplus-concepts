#include <iostream>

using namespace std;

/* Not the best, but better than selection sort and bubble sort
 * Hole concept
 */
void insertionSort(int A[], int n)
{
    for(int i = 1; i < n ; i++ )
    {   
        int Heldvalue = A[i]; // placeholder for th evalue extracted from hole position
        int hole = i; // acting as index   
        
        while(hole > 0 && A[hole-1]>Heldvalue) // this loop moves all the values greater than HeldValue to the right
        {
            A[hole] = A[hole-1];
            hole = hole -1;
        }
        A[hole] = Heldvalue;
    }

}

int main()
{
    int A[] = {5, 2, 3, 1, 6, 4};
    insertionSort(A, 6);
    for(auto ele : A)
        cout << ele << " ";
    return 0;
}
