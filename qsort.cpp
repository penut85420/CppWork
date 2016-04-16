void print(int arr[], int left, int right) {
    for (int i = left; i <= right; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}

void swap(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

void qsort(int arr[], int left, int right) {
    printf("Sort %d to %d\n", left, right);
    int i, tmp, div;
    if (left < right) {
        tmp = arr[right], div = left;
        for (i = left; i < right; i++) {
            if (arr[i] < tmp) swap(&arr[i], &arr[div++]);
            else swap(&arr[i], &arr[div]);
        }
        swap(&arr[right], &arr[div]);
        print(arr, left, right);
        qsort(arr, left, div - 1);
        qsort(arr, div + 1, right);
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 2, 0, 8, 6, 4};
    qsort(arr, 0, 9);
    print(arr, 0, 9);
    return 0;
}
