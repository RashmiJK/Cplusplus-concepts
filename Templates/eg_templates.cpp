/* Generic functions that can be used for different data types. 
 * Two keywords to notice are template and typename.
 * The second keyword can also be replaced by class
 */

#include <iostream>

using namespace std;

/* function templates */
template <typename T>
T find_max(T x, T y)
{
	return (x > y)? x : y;
}

//template <class C>
template <typename T>
void sort(T a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = n-1; i < j; j--)
		{
			if(a[j] < a[j-1])
				swap(a[j], a[j-1]);
		}
	}
	cout << "Output - " << endl;
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

/* when class defines something that is independent of the data type
 */
template <typename F>
class Array
{
	private:
		F *ptr;
		int size;	
	public:
		Array(F arr[], int s);
		void print();
};

template <typename F>
Array<F>::Array(F arr[], int s)
{
	ptr = new F[s];
	size = s;
	for(int i=0 ; i < size; i++)
		ptr[i] = arr[i];
}

template <typename F>
void Array<F>::print()
{
	for(int i = 0; i < size; i++)
		cout << " " << *(ptr+i);
	cout << endl;
}

int main()
{
	int a[5] = {10, 50, 30, 40, 20};
	int n = sizeof(a) / sizeof(a[0]);
	int arr[5] = {1, 2, 3, 4, 5};
	Array<int> test(arr, 5);

	cout << find_max<int>(3, 7) << endl;
	cout << find_max<double>(3.0, 7.0) << endl;
	cout << find_max<char>('g' , 'e') << endl;

	sort(a, n);

	test.print();
	
	return 0;
}
