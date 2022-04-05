#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // map<int,int> mp;
        // int first = -1, second = -1;
        // for(int i=0;i<n;i++){
        //     mp[arr[i]]++;
        // }
        // for(int i=1;i<=n;i++){
        //     if(mp.find(i)==mp.end()){
        //         first = i;
        //     }
        //     if(mp[i] == 2){
        //         second = i;
        //     }
        // }
        // int *res = new int[2];
        // res[0] = second;
        // res[1] = first;
        // return res;
        
     
        int xorval = 0;
        for(int i=0;i<n;i++){
            xorval = xorval^arr[i];
            xorval = xorval^(i+1);
        }
        int *res = new int[2];
        res[0] = 0; // repeating
        res[1] = 0; // missing
        
        int sn = xorval & (~(xorval-1));
        for(int i=0;i<n;i++){
            if(arr[i]&sn){
                res[0]= res[0]^arr[i];
                
            }
            else{
                res[1] = res[1]^arr[i];
            }
            if((i+1)&sn){
                res[0] = res[0]^(i+1);
            }
            else{
                res[1] = res[1]^(i+1);
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[i] == res[0]) break;
            if(arr[i] == res[1]){
                int temp = res[0];
                res[0] = res[1];
                res[1] = temp;
            }
        }

        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
