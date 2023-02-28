#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int max_n = 101;
void matrixBlockSum(int mat[][max_n], int m, int n, int k);

int main()
{
    int m, n, k, i = 0, j;
    cin >> m;
    cin >> n;
    cin >> k;

    int mat[m][max_n];
    
    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    
    matrixBlockSum(mat, m, n, k);

    return 0;
}

void matrixBlockSum(int mat[][max_n], int m, int n, int k) 
{
    int i = 0, j, sum[(m + 1)][(n + 1)], row_1, row_2, col_1, col_2; 
    vector<vector<int>> answer(m , vector<int> (n));
    memset(sum, 0, sizeof(sum));

    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            sum[(i + 1)][(j + 1)] = mat[i][j] + sum[(i)][j + 1] + sum[(i + 1)][j] - sum[i][j];
        }
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            row_1 = max(0, (i - k));
            row_2 = min((m - 1), (i + k));
            col_1 = max(0, (j - k));
            col_2 = min((n - 1), (j + k));

            row_1++;
            row_2++;
            col_1++;
            col_2++;

            answer[i][j] = sum[row_2][col_2] - sum[row_2][(col_1 - 1)] - sum[(row_1 - 1)][col_2] + sum[(row_1 - 1)][(col_1 - 1)];
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }    
}