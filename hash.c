#include <stdio.h>
#include <stdlib.h>


// キーに対してインデックスが計算される:
// インデックスでデータにアクセスする

#define N 9

int main() {
    int bucket[N];
    int data[N] = {15,13,14,1,7,0,9,2,3};
    int already[N] = {0,0,0,0,0,0,0,0,0}; // 値がセットされたら1にする
    int delta = 2;
    int i,j;
 
    // ハッシング
    int index;
    for (i=0; i<N; i++) {
        index = data[i] % N;
        // 衝突判定
        while (already[index] == 1) { // 衝突判定を喰らわなくなるまでdelta分indexを増やす
            index += delta;
        }
        // 衝突判定終了後値を入れる
        //printf("%d:%d\n",data[i], index);
        bucket[index] = data[i];
        // データの入ったインデックスを1にする
        already[index] = 1;
    }

    // キーを受け取る
    int key;
    printf("Key?");
    scanf("%d", &key);
    printf("key=%d\n", key);


    // キーからハッシュを求める
    index = key % N;
    //printf("index=%d\n", index);
    int val = bucket[index];
    printf("%d\n",val);
    
    return 0;
}
