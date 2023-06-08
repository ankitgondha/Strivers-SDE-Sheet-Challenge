#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int sr=0, sc=0, er= n-1, ec = m-1;
     if(er==0 or ec ==0)return ;
    while(sr< er && sc < ec){
        int temp= mat[sr][sc];
        for(int i=sc+1; i<=ec; i++){
            swap(temp, mat[sr][i]);
        }
        for(int i=sr+1; i<=er;i++){
            swap(temp, mat[i][ec]);
        }
        for(int i=ec-1; i>=sc;i--){
            swap(temp, mat[er][i]);
        }
        for(int i=er-1; i>=sr;i--){
            swap(temp, mat[i][sc]);
        }
        
        sr++;
        sc++;
        er--;
        ec--;
    
    }
}