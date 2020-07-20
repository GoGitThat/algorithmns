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