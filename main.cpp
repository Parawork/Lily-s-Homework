#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
void printVector(vector<int> arr);
int lilysHomework(vector<int> &arr) {
    int size = arr.size();
    vector<int> sortedArr = arr;
    vector<int> reverseSortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    int output1 = 0;
    int output2 = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == sortedArr[i]) {
            continue;
        } else {
            for (int j = i + 1; j < size; j++) {
                if (arr[j] == sortedArr[i]) {
                    swap(arr[j],arr[i]);

                    output1++;
                    break;
                }
            }
        }
    }
    arr = reverseSortedArr;

    sort(reverseSortedArr.begin(), reverseSortedArr.end());
    reverse(reverseSortedArr.begin(), reverseSortedArr.end());
    for (int i = 0; i < size; i++) {
        if (arr[i] == reverseSortedArr[i]) {
            continue;
        } else {
            for (int j = i + 1; j < size; j++) {
                if (arr[j] == reverseSortedArr[i]) {
                    int temp = arr[j];
                    swap(arr[j],arr[i]);
                    output2++;
                    break;
                }
            }
        }
    }
    return min(output1, output2);
}
//print the vector
void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void readIntegers(vector<int> &arr) {
    string input;
    getline(cin, input);

    istringstream iss(input);
    int number;

    while (iss >> number) {
        arr.push_back(number);
    }
    cout << 1;
    return;
}
int main() {
    vector<int> arr;
    readIntegers(arr);
    printVector(arr);
    int num = lilysHomework(arr);
    printVector(arr);
    cout << num << endl;
    return 0;
}

