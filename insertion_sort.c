#include <stdio.h>
#include <stdlib.h>

// キーを左の要素と比較する
// 比較してキーの方が小さいなら入れ替える
// 上の動作を左の値がなくなるか、自分より小さくなるまで続ける


#define N 1000000

void printArray(int* list, int size) {
    int i;
    for (i=0; i<size; i++) {
        if (i != size-1) {
            printf("%d,", *list);
        } else {
            printf("%d", *list);
        }
        list++;
    }
    printf("\n");
}

int main() {
    int A[N];
    int i,j, tmp;
    
    for (i=0; i<N; i++) {
        A[i] = rand();
    }

    for (i=1; i < N; i++) {
        j = i;
        while (1) {
            // jが0より大きく、キー要素が左の要素よりも小さいなら入れ替える
            if ( (j > 0) && (A[j-1] > A[j]) ) {
                // 入れ替える
                tmp = A[j-1];
                A[j-1] = A[j];
                A[j] = tmp;
                j--;
            } else {
                break;
            }
        }

    }
    printArray(A,N);

    return 0;
}
