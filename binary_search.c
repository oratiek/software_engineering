#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 20

int main() {
    int i;
    // const int N = 20;
    int data[N] = {5, 7, 15, 18, 22, 35, 40, 48, 50, 54, 60, 62, 68, 70, 77, 80, 85, 88, 90, 96};
    int key = 4;

    // search
    // 真ん中を確認する
    int m; // mid
    m = N/2;
    int cnt = 1;
    int max = log2(N);
    while (1) {
        if (cnt > max) {
            //printf("not found\n");
            break;
        }
        printf("m=%d data[m]=%d\n",m,data[m]);
        if (key == data[m]) {
            //printf("found\n");
            break;
        } else if (key >= data[m]) { // keyがdata[m]以上
            m = m + (N-m)/2;
        } else if (key < data[m]) // keyがdata[m]より小さい
            m = m/2;
        cnt++;
    }
    printf("step=%d\n", cnt);

    return 0;
}
