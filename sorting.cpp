#include "list.cpp"

inline bool testSort(List mylist) {
    for (int j = 0; j < mylist.getSize();j++) {
        if (j != 0) {
            if (mylist[j-1] > mylist[j]) {
                return false;
            }
        }
    }
    return true;
}

inline int getMinimum(List mylist, int start, int end) {
    int min = mylist[start];
    int idx = start;
    for (int k = start;k < end;k++) {
        if (mylist[k] <= min) {
            min = mylist[k];
            idx = k;
        }
    }
    return idx;
}

inline void selectionSort(List mylist) {
    int lSize = mylist.getSize();
    for (int i = 0;i < lSize;i++) {
        mylist.swap(i, getMinimum(mylist, i, lSize));
    }
}