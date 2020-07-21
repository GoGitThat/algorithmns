#include "list.cpp"
#include <math.h>

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

inline void bubbleSort(List mylist) {
    bool noSwap = true;
    while (noSwap) {
        bool swapped = false;
        for (int i = 0; i < mylist.getSize();i++) {
            if (i > 0) {
                if (mylist[i] < mylist[i-1]) {
                    mylist.swap(i, i - 1);
                    swapped = true;
                }
            }
        }
        noSwap = swapped;
    }
}

inline List insertionSort(List mylist) {
    for (int i = 1;i < mylist.getSize();i++) {
        for (int j = 0;j < i;j++) {
            if (mylist[i] < mylist[j]) {
                int k = mylist.pop(i);
                mylist.insert(j, k);
            }
        }
    }
    return mylist;
}

inline List slice(List a, int b, int c) {
    List d = List();
    for (int e = b;e < c;e++) {
        d.append(a[e]);
    }
    return d;
}

inline List merge(List a, List b) {
    List c = List();
    while ((a.getSize() && b.getSize()) != 0) {
        if (a[0] > b[0]) {
            c.append(b.pop(0));
        }
        else {
            c.append(a.pop(0));
        }
    }
    while (a.getSize() > 0) {
        c.append(a.pop(0));
    }
    while (b.getSize() > 0) {
        c.append(b.pop(0));
    }
    return c;
}

inline List mergeSort(List a) {
    if (a.getSize() == 1) {
        return a;
    }
    List a1 = mergeSort(slice(a, 0, floor(a.getSize() / 2)));
    List a2 = mergeSort(slice(a, floor(a.getSize() / 2), a.getSize()));

    return merge(a1, a2);
}

inline void quickSort(List a, int left, int right) {
    int b = left;
    int c = right;
    int pivot = a[(left + right) / 2];

    while (b <= c) {
        while (a[b] < pivot) {
            b++;
        }
        while (a[c] > pivot) {
            c--;
        }
        if (b <= c) {
            a.swap(b, c);
            b++;
            c--;
        }
    }
    if (left < c) {
        quickSort(a, left, c);
    }
    if (b < right) {
        quickSort(a, b, right);
    }
}