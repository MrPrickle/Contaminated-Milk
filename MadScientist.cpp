#include<bits/stdc++.h>
using namespace std;
int N;
char A[1000];
char B[1000];
int counter;
bool consecutive = false;

int solve(char A[], char B[], int i) {
    if (i == N) { // Base case: Reached the end of the strings
        return counter;
    }

    if (A[i] != B[i]) { // Characters are different
        if (!consecutive) { // Start of a new segment
            counter++;
            consecutive = true;
        }
    }
    else { // Characters are the same
        consecutive = false; // End of the segment
    }

    return solve(A, B, i + 1); // Move to the next character
}

int main() {
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");

    fin >> N;

    for (int i = 0; i < N; i++) {
        fin >> A[i];
    }
    for (int j = 0; j < N; j++) {
        fin >> B[j];
    }

    fout << solve(A, B, 0);

    return 0;
}