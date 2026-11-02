#include<stdio.h>
#include<conio.h>
#include<math.h>

float max(float arr[10], int n){
    float m = arr[0];

    for(int i=0; i<n; i++){
        if(fabs(arr[i]) > fabs(m)){
            m = arr[i];
        }
    }

    return m;
}

int main(){
    int i, j, n;
    printf("Enter order of matrix(n): ");
    scanf("%d", &n);

    float a[n][n], x[n], y[n], z[n], d[n], dmax, zmax;

    printf("Enter the square matrix(n*n): ");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter initial vector Xn:");
    for(i=0; i<n; i++){
        scanf("%f", &x[n]);
    }

    do{
        for(i=0; i<n; i++){
            z[i] = 0;
            for(j=0; j<n; j++){
                z[i] += a[i][j] * x[j];
            }
        }

        zmax = max(z, n);

        for(i=0; i<n; i++){
            y[i] = z[i]/zmax;
            d[i] = fabs(y[i] - x[i]);
        }

        dmax = max(d, n);

        for(i=0; i<n; i++){
            x[i] = y[i];
        }
    }while(dmax >= 0.0005);
    printf("\nThe eigen value is: %.3f", zmax);

    printf("\nThe vector is:\n");
    for(int i=0; i<n; i++){
        printf("%.4f\n", y[i]);
    }
}