/* Include file <algorithm>
 * std::sort, built-in function in a c++ STL, you can sort user defined data too
 * syntax 1 
 *  template <typename RandomAccessIterator>
 *      void sort(RandomAccessIterator first, RandomAccessIterator last)
 * syntax 2
 *  template <typename RandomAccessIterator>
 *      void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
 * 
 * Parallel execution policy - refer
 *  https://www.mygreatlearning.com/blog/sort-function-in-cpp/#:~:text=Selection%20Sort-,What%20is%20Sort%20Function%20in%20C%2B%2B%3F,in%20ascending%20or%20descending%20order.
 * 
 * <1> Sorting integral data types
 * <2> Sorting user-defined data types
 * <3> Sort using a function object (predicate, functor)
 * <4> Sort using the lambda expression
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cout << endl << "Sorting integral data types" << endl;
    vector<int> nums = {5, 3, 6, 2, 7, 4, 1, 8, 2, 9};
    sort(nums.begin(), nums.end());
    for(auto ele : nums)
        cout << ele << " ";
    cout << endl;

    cout << endl << "Sorting user-defined data types" << endl;
    class Point
    {
        public:
            int x, y;
            Point(int x=0, int y=0) : x(x), y(y) {} // constructor with parameters
            bool operator < (const Point& pt) const
            {
                return (x + y) < (pt.x + pt.y);
            }
    };
    vector<Point> userDefinedData = {{1,2},{3,1},{0,1}};
    sort(userDefinedData.begin(), userDefinedData.end());
    for(auto ele : userDefinedData)
        cout << ele.x << " " << ele.y << endl;
    Point p1(7, 4);
    Point p2(4, 5);
    if(p1 < p2)
        cout << "p1 is less than p2" << endl;
    else
        cout << "p1 is greater than p2" << endl;


    cout << endl << "Sort using a function object" << endl;
    // re-use the nums vector
    nums = {5, 3, 6, 2, 7, 4, 1, 8, 2, 9};
    struct
    {
        bool operator () (int a, int b) const
        {
            return a<b ;
        }
    } customLess;
    
    sort(nums.begin(), nums.end(), customLess);
    for(auto ele : nums)
        cout << ele << " ";
    cout << endl;

    cout << endl << "Sort using the Lambda expression" << endl;
    vector<int> vec = {5, 4, 7, 6, 2, 8, 9, 1, 3};
    /* In this type, you will directly inject the function into the places where 
     * the object is called. You can use the function body directly instead of 
     * creating a separate function block to do the expression and calling it in 
     * the main function. We can directly add them to the main function itself.
     */
    sort(vec.begin(), vec.end(), [](int a, int b){return a<b;});
    for(auto ele : vec)
        cout << ele << " ";
    cout << endl;

    return 0;
}
