#include <bits/stdc++.h> 
using namespace std; 

int ceilIndex(int arr[], vector<int> &t, int lo, int hi, int key){ 
	while (hi - lo > 1){
		int mid = lo + (hi - lo)/2; 
		if (arr[t[mid]] >= key) 
			hi = mid; 
		else
			lo = mid;
    }
    return hi; 
}

void solve(int arr[], int n){ 
    vector<int> tailIndices(n, 0);  
    vector<int> prevIndices(n, -1); 
    
	int len = 1;
    for (int i = 1; i < n; i++){ 
        if (arr[i] < arr[tailIndices[0]]){ 
            tailIndices[0] = i; 
        } 
        else if (arr[i] > arr[tailIndices[len-1]]){
            prevIndices[i] = tailIndices[len-1]; 
            tailIndices[len++] = i; 
        } 
        else{
            int pos = ceilIndex(arr,tailIndices,-1,len-1, arr[i]); 
            prevIndices[i] = tailIndices[pos-1]; 
            tailIndices[pos] = i; 
        }
    }
    cout << len << endl; 
    vector<int> tmp;
	for (int i = tailIndices[len-1]; i >= 0; i = prevIndices[i]) 
		tmp.push_back(i);

	if (tmp.size() == 2 and tmp[0] == tmp[1]){
		cout << tmp[0] << endl; return;
	}
	reverse(tmp.begin(), tmp.end());
	for (int x : tmp)	cout << x << " ";
    cout << endl; 
  
} 
  
int main(){ 
	int n;
	while (cin >> n){
		int arr[n];
		for (int i = 0; i < n; ++i)	cin >> arr[i];
		solve(arr, n);
	}
	

	return 0; 
} 

