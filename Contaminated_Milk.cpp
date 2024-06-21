#include<bits/stdc++.h>
using namespace std;
int N, M, D, S, p[1000], m[1000], t[1000], sickP[50], sickD[50];

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

    


}