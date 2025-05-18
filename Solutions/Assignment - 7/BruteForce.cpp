#include<iostream>
#include<vector>
using namespace std;

int idxReturner(vector<int>& txt, vector<int>& pat) {
    int n = txt.size();
    int m = pat.size();
    
    for(int i = 0; i <= n - m; i++) {
        int j;
        for(j = 0; j < m; j++) {
            if(txt[i + j] != pat[j])
                break;
        }
        if(j == m)
            return i;  // Pattern found at index i
    }
    return -1;  // Pattern not found
}

int main() {
    vector<int> text = {1, 2, 3, 4, 5, 2, 3};
    vector<int> pattern = {2, 3};
    
    int result = idxReturner(text, pattern);
    
    if(result != -1)
        cout << "Pattern found at index: " << result + 1 << endl;
    else
        cout << "Pattern not found" << endl;
        
    return 0;
}