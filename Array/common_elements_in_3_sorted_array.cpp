 #include<bits/stdc++.h>
 using namespace std;
 
 
 vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            // using set 
        //     vector<int> ans;
        //     set<int> s;
        //   int i=0, j=0, k=0;
        //   while(i<n1 && j<n2 && k<n3){
        //       if(A[i] == B[j] && B[j] == C[k]){
        //             s.insert(A[i]);
        //             i++, j++, k++;
        //         }else if(A[i] < B[j])
        //             i++;
        //         else if(B[j] < C[k])
        //             j++;
        //         else // c has the smallest elm
        //             k++;
        //   }
        //         for(auto itr : s){
        //             ans.push_back(itr);
        //         }
        //     return ans;
        
        
            // without using set(extra space)
            // using small variable to counter cases like A=[3,3,3], B=[3,3,3], C=[3,3,3]
            // so that 3 will be inserted only once
         vector<int> ans;
          int i=0, j=0, k=0, small = INT_MIN;
          while(i<n1 && j<n2 && k<n3){
              if(A[i] == B[j] && B[j] == C[k]){
                    if(A[i] > small){
                        ans.push_back(A[i]);
                        small = A[i];
                    }
                    i++, j++, k++;
                }else if(A[i] < B[j])
                    i++;
                else if(B[j] < C[k])
                    j++;
                else // c has the smallest elm
                    k++;
          }
            return ans;
        }

        int main(){
            int A[] = {1,2,3};
            int B[] = {0,2,3};
            int C[] = {1,2,3};

            vector<int> ans;
            ans = commonElements(A, B, C, 3, 3, 3);
            for(int i=0;i<ans.size();i++){
                cout << ans[i] << " ";
            } 
        }