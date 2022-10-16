#include <iostream>
#include <vector>

using namespace std;

int shiftedBinarySearch(vector<int> array, int target)
{
    int left = 0, right = array.size() - 1;
    while(left <= right)
    {
        int middle = left + (right - left) / 2;
        cout << "middle: " << middle << " " << array[middle] << endl;
        cout << "left: " << left << " " << array[left] << endl; 
        cout << "right: " << right << " " << array[right] << endl;
        cout <<"********************************************************" << endl;
        if(array[middle] == target)
        {
            return middle;
        }
        else if(array[middle] >= array[left])
        {
            if(target < array[middle] && target >= array[left])
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        else
        {
            if(target > array[middle] && target <= array[right])
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
    }

    cout << "No esta" << endl;
    return -1;
}

int main(){
    int num = 11;
    vector<int> arr = { 9, 11, 13, -2, 3, 4, 7, 8};
    cout << " Index del numero " << num << ": " << shiftedBinarySearch(arr, 8) << endl;
}