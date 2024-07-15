#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> matrix_mult(const vector<vector<int>>& A, const vector<vector<int>>& B, int N) {
    vector<vector<int>> C(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] = (C[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }
    return C;
}

// Function to perform matrix exponentiation
vector<vector<int>> matrix_pow(vector<vector<int>> A, long long exp, int N) {
    vector<vector<int>> result(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) result[i][i] = 1;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = matrix_mult(result, A, N);
        }
        A = matrix_mult(A, A, N);
        exp /= 2;
    }

    return result;
}

int main() {
    int N;
    long long K;
    cin >> N >> K;

    vector<vector<int>> adj(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> adj[i][j];
        }
    }

    // Compute A^K
    vector<vector<int>> AK = matrix_pow(adj, K, N);

    int total_paths = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            total_paths = (total_paths + AK[i][j]) % MOD;
        }
    }

    cout << total_paths << endl;

    return 0;
}
