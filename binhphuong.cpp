#include <stdio.h>
#include <math.h>

// Khai b�o h�m �? t�nh t?ng c�c ph?n t? trong m?t m?ng
float sum(float arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    int n;
    printf("Nh?p s? l�?ng �i?m d? li?u: ");
    scanf("%d", &n);

    float xi[n], yi[n];
    printf("Nh?p gi� tr? cho xi v� yi:\n");
    for (int i = 0; i < n; i++) {
        printf("xi[%d] = ", i);
        scanf("%f", &xi[i]);
        printf("yi[%d] = ", i);
        scanf("%f", &yi[i]);
    }

    // T�nh c�c t?ng c?n thi?t
    float sum_xi = sum(xi, n);
    float sum_xi_squared = 0;
    float sum_xi_yi = 0;
    float sum_yi_ln = 0;

    for (int i = 0; i < n; i++) {
        sum_xi_squared += xi[i] * xi[i];
        sum_xi_yi += xi[i] * log(yi[i]);
        sum_yi_ln += log(yi[i]);
    }

    // In ra b?ng qu� tr?nh ph��ng ph�p b?nh ph��ng b� nh?t
    printf("\nB?ng qu� tr?nh c?a ph��ng ph�p b?nh ph��ng b� nh?t:\n");
    printf("-----------------------------------------------------------------\n");
    printf("  i     xi       yi       xi^2      xi*yi    ln(yi)  xi*ln(yi)\n");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%3d  %7.4f  %7.4f  %7.4f  %7.4f  %7.4f  %7.4f\n", i+1, xi[i], yi[i], xi[i] * xi[i], xi[i] * yi[i], log(yi[i]), xi[i] * log(yi[i]));
    }
    printf("-----------------------------------------------------------------\n");

    // Gi?i h? ph��ng tr?nh t?m A v� B
    float A, B;
    float denominator = n * sum_xi_squared - sum_xi * sum_xi;

    if (denominator == 0) {
        printf("Kh�ng th? gi?i h? ph��ng tr?nh.\n");
        return 1;
    }

    A = (sum_yi_ln * sum_xi_squared - sum_xi * sum_xi_yi) / denominator;
    B = (n * sum_xi_yi - sum_xi * sum_yi_ln) / denominator;

    // T�nh a v� b t? A v� B
    float a = exp(A);
    float b = B;

    // In ra k?t qu?
    printf("\nPh��ng tr?nh t?t nh?t ph� h?p v?i d? li?u:\n");
    printf("y = %.4f * e^(%.4f * x)\n", a, b);

    return 0;
}

