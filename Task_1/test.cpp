#include <iostream>
#include <gtest/gtest.h>


void sort(long double arr[], int l, int r) ;

void merge(long double arr[], int l, int m, int r);

TEST(SortTest, HandlesNegativeAndPositive) {
    long double arr[] = {3.0, -1.0, 2.0, -4.0, 5.0, -2.0};
    int size = sizeof(arr) / sizeof(arr[0]);

    sort(arr, 0, size - 1);

    EXPECT_EQ(arr[0], -1.0);
    EXPECT_EQ(arr[1], -4.0);
    EXPECT_EQ(arr[2], -2.0);
    EXPECT_EQ(arr[3], 3.0);
    EXPECT_EQ(arr[4], 2.0);
    EXPECT_EQ(arr[5], 5.0);
}

TEST(SortTest, HandlesAllPositive) {
    long double arr[] = {1.0, 3.0, 2.0, 5.0, 4.0};
    int size = sizeof(arr) / sizeof(arr[0]);

    sort(arr, 0, size - 1);

    EXPECT_EQ(arr[0], 1.0);
    EXPECT_EQ(arr[1], 3.0);
    EXPECT_EQ(arr[2], 2.0);
    EXPECT_EQ(arr[3], 5.0);
    EXPECT_EQ(arr[4], 4.0);
}

TEST(SortTest, HandlesAllNegative) {
    long double arr[] = {-1.0, -3.0, -2.0, -5.0, -4.0};
    int size = sizeof(arr) / sizeof(arr[0]);

    sort(arr, 0, size - 1);

    EXPECT_EQ(arr[0], -1.0);
    EXPECT_EQ(arr[1], -3.0);
    EXPECT_EQ(arr[2], -2.0);
    EXPECT_EQ(arr[3], -5.0);
    EXPECT_EQ(arr[4], -4.0);
}

TEST(SortTest, HandlesEmptyArray) {
    long double arr[] = {};
    int size = sizeof(arr) / sizeof(arr[0]);

    sort(arr, 0, size - 1);

    EXPECT_EQ(size, 0);
}

TEST(SortTest, HandlesSingleElement) {
    long double arr[] = {5.0};
    int size = sizeof(arr) / sizeof(arr[0]);

    sort(arr, 0, size - 1);

    EXPECT_EQ(arr[0], 5.0);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


void merge(long double arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int* L = new int[n1];
    int* R = new int[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if ((L[i] >= 0) && ( R[j] < 0)) {
            arr[k] = R[j];
            j++;
        } else {
            arr[k] = L[i];
            i++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    delete[] L;
    delete[] R;
}

void sort(long double arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        sort(arr, l, m);
        sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
