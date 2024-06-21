#include<bits/stdc++.h>
using namespace std;
int N, M, D, S, p[1000], m[1000], t[1000], sickP[50], sickD[50];
int possible[1000];

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

    int k = 0;
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < S; j++) {
            if (p[i] == sickP[j] && t[i] <= sickD[j]) {
                possible[k] = m[i];
                k++;
            }
        }
    }
    
    int maxCount = 0;
    int count = 0;
    for (int i = 0; i < (sizeof(possible) / sizeof(possible[0])); i++) {
        for (int j = 0; j < D; j++) {
            if (m[j] == possible[i]) {
                count++;
            }
        }
        maxCount = max(maxCount, count);
        count = 0;
    }

    fout << maxCount;


}