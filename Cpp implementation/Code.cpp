#include <iostream>
#include <fstream>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void combSort(int arr[], int n) {
    int gap = n;
    float shrink = 1.3;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = (int)(gap / shrink);
        if (gap < 1)
            gap = 1;

        swapped = false;

        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}
void printArrayToFile(int arr[], int size, const string& filename) {
    ofstream outFile(filename, ios::app);

    if (!outFile) {
        cerr << "Error: Unable to open the file " << filename << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        outFile << arr[i] << " ";
    }
    outFile << endl;
    outFile.close();

}
void readTestCases(const string& filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Error: Unable to open the file " << filename << endl;
        return;
    }

    int n;

    while (inFile >> n) {
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            inFile >> arr[i];
        combSort(arr, n);
        printArrayToFile(arr, n, "output.txt");
        delete[] arr;
    }
    cout<<"Sorted array has been written to output.txt"<<endl;

    inFile.close();
}

int main() {
    readTestCases("input.txt");

    return 0;
}
