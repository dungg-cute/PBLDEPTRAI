#include <stdio.h>
#include <math.h>

// Khai báo hàm ð? tính t?ng các ph?n t? trong m?t m?ng
float sum(float arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    int n;
    printf("Nh?p s? lý?ng ði?m d? li?u: ");
    scanf("%d", &n);

    float xi[n], yi[n];
    printf("Nh?p giá tr? cho xi và yi:\n");
    for (int i = 0; i < n; i++) {
        printf("xi[%d] = ", i);
        scanf("%f", &xi[i]);
        printf("yi[%d] = ", i);
        scanf("%f", &yi[i]);
    }

    // Tính các t?ng c?n thi?t
    float sum_xi = sum(xi, n);
    float sum_xi_squared = 0;
    float sum_xi_yi = 0;
    float sum_yi_ln = 0;

    for (int i = 0; i < n; i++) {
        sum_xi_squared += xi[i] * xi[i];
        sum_xi_yi += xi[i] * log(yi[i]);
        sum_yi_ln += log(yi[i]);
    }

    // In ra b?ng quá tr?nh phýõng pháp b?nh phýõng bé nh?t
    printf("\nB?ng quá tr?nh c?a phýõng pháp b?nh phýõng bé nh?t:\n");
    printf("-----------------------------------------------------------------\n");
    printf("  i     xi       yi       xi^2      xi*yi    ln(yi)  xi*ln(yi)\n");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%3d  %7.4f  %7.4f  %7.4f  %7.4f  %7.4f  %7.4f\n", i+1, xi[i], yi[i], xi[i] * xi[i], xi[i] * yi[i], log(yi[i]), xi[i] * log(yi[i]));
    }
    printf("-----------------------------------------------------------------\n");

    // Gi?i h? phýõng tr?nh t?m A và B
    float A, B;
    float denominator = n * sum_xi_squared - sum_xi * sum_xi;

    if (denominator == 0) {
        printf("Không th? gi?i h? phýõng tr?nh.\n");
        return 1;
    }

    A = (sum_yi_ln * sum_xi_squared - sum_xi * sum_xi_yi) / denominator;
    B = (n * sum_xi_yi - sum_xi * sum_yi_ln) / denominator;

    // Tính a và b t? A và B
    float a = exp(A);
    float b = B;

    // In ra k?t qu?
    printf("\nPhýõng tr?nh t?t nh?t phù h?p v?i d? li?u:\n");
    printf("y = %.4f * e^(%.4f * x)\n", a, b);

    return 0;
}

