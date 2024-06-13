# include <iostream>

using namespace std;

int main() {
    int n, qry;
    cin >> n >> qry;
    int arr[n];
    int sumTill[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sumTill[i] = (i)? sumTill[i-1] ^ arr[i]: arr[i];
        // cout << sumTill[i] << ' ';
    }
    // cout << endl;
    int a, b;
    
    for(int i = 0; i < qry; i++){
        cin >> a >> b;
        if (a == 1){
            cout << sumTill[b-1] << endl;
        } else {
            cout << (sumTill[a-2] ^ sumTill[b-1]) << endl;
        }
    }
}