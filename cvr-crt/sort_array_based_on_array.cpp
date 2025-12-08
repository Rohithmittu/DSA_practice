#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int M;
    cin >> M;
    vector<int> B(M);
    int maxB = 0;

    for (int i = 0; i < M; i++) {
        cin >> B[i];
        maxB = max(maxB, B[i]);
    }

    // Sort only the last maxB elements
    sort(A.end() - maxB, A.end());

    // Output result
    for (int x : A)
        cout << x << " ";
    cout << endl;
    return 0;
}
