#include <stdio.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void ozelSirala(int arr[], int n) {
    int temp[n];
    int sol = 0, sag = n - 1;
    int k = 0;

    while (sol <= sag) {
        if (sol != sag) {
            temp[k++] = arr[sag--];
            temp[k++] = arr[sol++];
        } else {
            temp[k++] = arr[sol++];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {60,80,3,9,57,11};
    int n = 6;

    sort(arr, n);
    ozelSirala(arr, n);

    printf("Sonuc: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
