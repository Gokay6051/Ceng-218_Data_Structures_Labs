#include <iostream>
#include <chrono>
#include <vector>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::nanoseconds;


void insertionSort(std::vector<int> arr) {

    int key, j;

    for (int i = 1; i < arr.size(); i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

void Clock(std::vector<int> vec)
{
    auto t1 = high_resolution_clock::now();
    insertionSort(vec);
    auto t2 = high_resolution_clock::now();

    auto nanoint1 = duration_cast<nanoseconds>(t2 - t1);
    std::cout << nanoint1.count() << "ns" << std::endl;
}

int main() {
    std::vector<int> vec1 = { 5, 4, 3, 2, 1 };
    std::vector<int> vec2 = { 4, 3, 2, 1 };
    std::vector<int> vec3 = { 3, 2, 1 };
    std::vector<int> vec4 = { 2, 1 };
    std::vector<int> vec5 = { 1 };

    Clock(vec1);
    Clock(vec2);
    Clock(vec3);
    Clock(vec4);
    Clock(vec5);

    return 0;
}