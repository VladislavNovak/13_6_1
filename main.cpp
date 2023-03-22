#include <iostream>
#include <algorithm> // count
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Информационный отчет
void printReport(vector<int> &arr, const std::string &title = "Report") {
    cout << "-----------\n" << title << ": ";
    for (auto &item: arr) cout << item << " ";
    cout << "\n-----------" << endl;
}

// фильтрация посредством удаления методом erase
void filterOriginal(vector<int> &arr, int deflected) {
    for (int i = (int) (arr.size() - 1); i >= 0; --i) {
        if (arr[i] == deflected) {
            arr.erase(arr.begin() + i);
        }
    }
}

// фильтрация. По заданию, нельзя создавать доп.структуры и для удаления использовать только метод pop_back()
// в задании нет критерия, чтобы в итоговом массиве числа выводились в первоначальном порядке
void filterOriginal2(vector<int> &arr, int deflected) {
    int occurCount = (int)std::count(arr.cbegin(), arr.cend(), deflected);
    int position = (int) (arr.size() - 1);

    while (occurCount > 0) {
        if (arr[position] == deflected) {
            arr.pop_back();
            --position;
            --occurCount;
        } else {
            arr.insert(arr.cbegin(), arr.back());
            arr.pop_back();
        }
    }
}

int main() {
    vector<int> list;
    int deflected = 0;
    int listSize = 0;

    cout << "Enter size of list:";
    std::cin >> listSize;

    for (int i = 0; i < listSize; ++i) {
        int currentValue = 0;
        cout << "Enter " << (i + 1) << " value:";
        std::cin >> currentValue;
        list.push_back(currentValue);
    }

    printReport(list, "List");

    cout << "Enter the number to be removed from the list:";
    std::cin >> deflected;

    filterOriginal(list, deflected);

    printReport(list, "Report");
}