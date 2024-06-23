#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// Constants for the dimensions of the static arrays
const int MAXN = 50;
const int MAXD = 1000;

int N, M, D, S;
int p[MAXD], m[MAXD], t[MAXD], sickP[MAXN], sickT[MAXN];
int possible[MAXN][MAXN];

bool hasNoValue(int arr[], int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            return false;
        }
    }
    return true;
}

// Function to find the union of all elements in a static 2D array
vector<int> unionOf2DArray(int arr[MAXN][MAXN]) {
    unordered_set<int> unionSet;

    // Iterate through the 2D array and add elements to the set
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            if (arr[i][j] != 0) { // Assuming 0 is not a valid milk ID
                unionSet.insert(arr[i][j]);
            }
        }
    }

    // Convert the set to a vector
    vector<int> result(unionSet.begin(), unionSet.end());
    return result;
}

int main() {
    ifstream fin("badmilk.in");
    ofstream fout("badmilk.out");

    fin >> N >> M >> D >> S;

    for (int i = 0; i < D; i++) {
        fin >> p[i] >> m[i] >> t[i];
    }
    
    for (int i = 0; i < S; i++) {
        fin >> sickP[i] >> sickT[i];
    }

    // Initialize possible array
    memset(possible, 0, sizeof(possible));

    for (int i = 0; i < D; i++) {
        for (int j = 0; j < S; j++) {
            if (p[i] == sickP[j] && t[i] <= sickT[j]) {
                if (hasNoValue(possible[j], MAXN, m[i])) {
                    for (int k = 0; k < MAXN; ++k) {
                        if (possible[j][k] == 0) {
                            possible[j][k] = m[i];
                            break;
                        }
                    }
                }
            }
        }
    }

    vector<int> newVec = unionOf2DArray(possible);
    int maxCount = 0;

    // Iterate over the union of all possible contaminated milk types
    for (int milk : newVec) {
        int count = 0;
        for (int i = 0; i < D; i++) {
            if (m[i] == milk) {
                count++;
            }
        }
        maxCount = max(maxCount, count);
    }

    fout << maxCount << endl;

    return 0;
}
