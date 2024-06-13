# include <iostream>

using namespace std;

int n;

void findmin(int arr[], int l, int r, int *min){
    *min = arr[l];
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

void findmax(int arr[], float hfs[], int l, int r, int min, float *max){
    *max = 0;
    int i;
    for(i = 0; i < l; i++){
        if (*max < arr[i]){
            *max = arr[i];
        }
    }
    // cout << *max << endl;
    for(; i <= r; i++){
        if(*max < hfs[i] - min/2.0){
            *max = hfs[i] - min/2.0;
        }
    }
    //  cout << *max << endl;
    for(; i < n; i++){
        if (*max < arr[i]){
            *max = arr[i];
        }
    }
}

int main(){
    int q, l, r;
    cin >> n;
    int arr[n];
    float hfs[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        hfs[i] = arr[i]/2.0;
    }
    
    // for(int i = 0; i < n; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     cout << hfs[i] << ' ';
    // }
    // cout << endl;
    

    cin >> q;
    int minm;float maxm;
    for(int i = 0; i < q; i++){
        cin >> l >> r;
        findmin(arr, l, r, &minm);
        // cout << minm << endl;
        findmax(arr, hfs, l, r, minm, &maxm);
        // cout << maxm << endl;

        cout << minm + maxm << endl;
    }
}