#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;
int N, M, D, S, p[1000], m[1000], t[1000], sickP[50], sickD[50];
int possible[50][50];

bool hasNoValue(int arr[], int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            return false;
        }
    }
    return true;
}

vector<int> unionOf2DArray(int arr[50][50]) {
    std::unordered_set<int> unionSet;

    // Iterate through the 2D array and add elements to the set
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            unionSet.insert(arr[i][j]);
        }
    }

    // Convert the set to a vector
    std::vector<int> result(unionSet.begin(), unionSet.end());
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
        fin >> sickP[i] >> sickD[i];
    }

    for (int i = 0; i < D; i++) {
        for (int j = 0; j < S; j++) {
            if (p[i] == sickP[j] && t[i] <= sickD[j]) {
                int k = 0;
                if (hasNoValue(possible[j], 50, m[i])) {
                    possible[j][k] = m[i];
                    k++;
                }
            }
        }
    }
    
    vector<int> newVec = unionOf2DArray(possible);
    int maxCount = 0;
    int count = 0;
    for (int i = 0; i < newVec.size(); i++) {
        for (int j = 0; j < D; j++) {
            if (m[j] == newVec[i]) {
                count++;
            }
        }
        maxCount = max(maxCount, count);
        count = 0;
    }

    fout << count;


}