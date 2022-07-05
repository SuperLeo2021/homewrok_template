//greedy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void package(float P[], float w[], int M, int n);
void RandomWeight(float* list, int n, int l, int r);
void RandomValue(float* list, int n, int l, int r);
void sort(float pw[], int index[], float w[], float v[], int M, int n);

void package(float P[], float w[], int M, int n)
{
    printf("%d\n", M);
    int i;
    float x[n];
    for (i = 0; i < n; i++)
    {
        x[i] = 0; 
    }
    float cu = M; 
    for (i = 0; i < n; i++)
    {
        if (w[i] > cu)
        {
            break;
        }
        x[i] = 1;
        cu = cu - w[i];
    }

    if (i < n) //
    {
        x[i] = cu / w[i];
    }
    printf("\n The optimal solution of the problem is the following:\n");
    for (i = 0; i < n; i++)
    {
        printf("%f ", x[i]);
    }
    float sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + x[i] * P[i];
    }
    printf("\n The value of the optimal solution is the following: f \n", sum);
}

void RandomWeight(float* list, int n, int l, int r) 
{
    int seed = time(NULL);
    srand(seed);
    for (int i = 0; i < n; i++)
    {
        list[i] = (float)(rand() % (r - l + 1) + l); 
    }
    printf("The randomly generated item weight was: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", list[i]);
    }
}

void RandomValue(float* list, int n, int l, int r) 
{
    int seed = 1;
    srand(seed); 
    for (int i = 0; i < n; i++)
    {
        list[i] = (float)(rand() % (r - l + 1) + l); 
    }
    printf("\nThe randomly generated item values were:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", list[i]);
    }
}

void sort(float pw[], int index[], float w[], float v[], int M, int n)
{
    for (int i = 0; i < n; i++)
    {
        pw[i] = v[i] / w[i];
        index[i] = i;
    }
    float temp = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pw[i] < pw[j])   
            {
                temp = pw[i];
                pw[i] = pw[j];
                pw[j] = temp;
                int x = index[i];    
                index[i] = index[j];
                index[j] = x;
            }
        }
    }
    float w1[n];
    float v1[n];
    for (int i = 0; i < n; i++)
    {
        w1[i] = w[index[i]];
        v1[i] = v[index[i]];
    }
    printf("\nValue / weight value of each item:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", pw[i]);
    }
    printf("\nThe corresponding weight array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", w1[i]);
    }
    printf("\n The corresponding value array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", v1[i]);
    }
    printf("%d\n", M);
    package(v1, w1, M, n);
}
int main() {
    int n;
    int M;
    clock_t begin, end;
    double cost;
    printf("Please enter the number of items ");
    scanf("%d", &n);
    printf("Please enter the maximum backpack capacity ");
    scanf("%d", &M);
    float v[n];
    float w[n];
    begin = clock();
    RandomWeight(w, n, 1, 100);
    RandomValue(v, n, 1, 100);
    float pw[n];
    int x[n];
    sort(pw, x, w, v, M, n);
    end = clock();
    cost = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
    printf("\n runtime: %lf ms", cost);
    printf("\n");
    return 0;
}