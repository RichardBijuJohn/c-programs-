#include <stdio.h>
#define MAX 50
typedef struct {
    int row, clm, val;
} Triplet;
void inputMatrix(int spr[MAX][MAX], int r, int c) {
    printf("Enter elements of matrix(%d x %d):\n", r, c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &spr[i][j]);
}
int a(int spr[MAX][MAX], int r, int c, Triplet t[MAX]) {
    int k = 1; 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (spr[i][j] != 0) {
                t[k].row = i;
                t[k].clm = j;
                t[k].val = spr[i][j];
                k++;
            }
        }
    }
    t[0].row = r;
    t[0].clm = c;
    t[0].val = k - 1;  
    return k;          
}
void b(Triplet t[MAX], int size) {
    printf("Row clm Val\n");
    for (int i = 0; i < size; i++)  
        printf("%3d %3d %3d\n", t[i].row, t[i].clm, t[i].val);
}
int add(Triplet a[MAX],Triplet b[MAX], Triplet result[MAX]){
    if (a[0].row != b[0].row || a[0].clm != b[0].clm) {
        printf("Matrix dimensions do not match!\n");
        return 0;
    }
    int i = 1, j = 1, k = 1;  
    result[0].row = a[0].row;
    result[0].clm = a[0].clm;
    while (i <= a[0].val && j <= b[0].val) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].clm < b[j].clm)) {
            result[k++] = a[i++];
        } else if (b[j].row < a[i].row || (a[i].row == b[j].row && b[j].clm < a[i].clm)) {
            result[k++] = b[j++];
        } else {  
            int sum = a[i].val + b[j].val;
            if (sum != 0) {
                result[k].row = a[i].row;
                result[k].clm = a[i].clm;
                result[k].val = sum;
                k++;
            }
            i++; j++;
        }
    }
    while (i <= a[0].val) result[k++] = a[i++];
    while (j <= b[0].val) result[k++] = b[j++];
    result[0].val = k - 1;
    return k;
}
int trsppose(Triplet prv[MAX], Triplet trsp[MAX]) {
    int k = 1;
    trsp[0].row = prv[0].clm;
    trsp[0].clm = prv[0].row;
    trsp[0].val = prv[0].val;

    for (int c = 0; c < prv[0].clm; c++) {
        for (int i = 1; i <= prv[0].val; i++) {
            if (prv[i].clm == c) {
                trsp[k].row = prv[i].clm;
                trsp[k].clm = prv[i].row;
                trsp[k].val = prv[i].val;
                k++;
            }
        }
    }
    trsp[0].val = k - 1;
    return k;
}
int main() {
    int r, c;
    int first[MAX][MAX], second[MAX][MAX];
    Triplet t0[MAX], t2[MAX], sum[MAX], trsp[MAX];
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("\nMatrix 0:\n");
    inputMatrix(first, r, c);
    int s0 = a(first, r, c, t0);
    printf("\nMatrix 2:\n");
    inputMatrix(second, r, c);
    int s2 = a(second, r, c, t2);
    printf("\nTriplet of Matrix 0:\n");
    b(t0, s0);
    printf("\nTriplet of Matrix 2:\n");
    b(t2, s2);
    int fnl_sum = add(t0, t2, sum);
    if (fnl_sum == 0) return 0;
    printf("\nTriplet after Addition:\n");
    b(sum, fnl_sum);
    int fnl_trsp = trsppose(sum, trsp);
    printf("\nTranspose of Result (Triplet):\n");
    b(trsp, fnl_trsp);
    return 0;
}
