# include <iostream>

using namespace std;

void merge(int arr[],int index[], int start, int mid, int end){
    int l = start;
    int r = mid + 1;
    int ind, tmp, idxtmp;
    while (l <= mid && r <= end){
        while(arr[l] <= arr[r] && l <= mid){
            l++;
        }
        if(l > mid) return;
        ind = r;
        tmp = arr[r];
        idxtmp = index[r];
        while(ind != l){
            arr[ind] = arr[ind - 1];
            index[ind] = index[ind - 1];
            ind--;
        }
        arr[l] = tmp;
        index[l] = idxtmp;
        l++; r++; mid++;
    }
}

void mergesort(int arr[],int ind[], int start, int end){
    if (start >= end){
        return;
    }
    int mid = start + (end - start)/2;
    mergesort(arr,ind, start, mid);
    mergesort(arr,ind, mid + 1, end);
    merge(arr,ind, start, mid, end);
    
}

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void findInd(int arr[],int ind[], int target, int n){
    int twol, sum, r;
    for(int onel = 0; onel < n; onel++){
        twol = onel + 1;
        r = n - 1;
        while (twol < r){
            sum = arr[onel] + arr[twol] + arr[r];
            if(sum == target){
                cout << ind[onel]  << ' ' << ind[twol]  << ' ' << ind[r] << endl;
                return;
            }
            if (sum > target){
                r--;
            } else {
                twol++;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main(){
    int n, target;
    cin >> n >> target;
    int arr[n];
    int ind[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ind[i] = i+1;
    }
    // print(ind, n);
    mergesort(arr, ind, 0, n-1);
    // print(arr, n);
    // print(ind, n);
    findInd(arr, ind, target, n);
}
