#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// approach 1 :

#include <iostream>

using namespace std;

void rotateArray(int arr[], int n, int k)
{
    for (int i = 0; i < k; i++)
    {
        int temp = arr[0];
        for (int j = 0; j < n - 1; j++)
            arr[j] = arr[j + 1];

        arr[n - 1] = temp;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int n; // Size of array
    cin >> n;
    int arr[n];
    // initializing array elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k; // No. of times to rotate
    cin >> k;
    rotateArray(arr, n, k);

    return 0;
}

// approach 2 :

// #include<iostream>
// using namespace std;

// void rotateArray(int arr[], int n, int k) {
//     // storing 1st k elements in temporary array
//     int temp[k];
//     for (int i = 0; i < k; i++) {
//         temp[i] = arr[i];
//     }
//     // shifting remaining elements of the array

//     for (int i = k; i < n; i++) {
//         arr[i - k] = arr[i];
//     }

//     //storing back the k elements to the orignal array
//     for (int i = 0; i < k; i++) {
//         arr[n - k + i] = temp[i];
//     }
//     //printing array
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
// }

// int main() {
//     int n; // Size of array
//     cin >> n;
//     int arr[n];
//     //initializing array elements
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int k; // No. of times to rotate
//     cin >> k;
//     rotateArray(arr, n, k);

//     return 0;
// }