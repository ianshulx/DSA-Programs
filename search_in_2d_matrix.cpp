//Given 2D matrix (elements are sorted)
#include <bits/stdc++.h>
using namespace std;

bool binarySearchModified(vector<vector<int>> &a, int l, int u, int n, int target)
{

    int mid = l + (u - l) / 2;
    int i_mid = mid / n;
    int j_mid = mid % n;

    if (l <= u)
    {
        if (target < a[i_mid][j_mid])
            return binarySearchModified(a, l, mid - 1, n, target);
        if (target > a[i_mid][j_mid])
            return binarySearchModified(a, mid + 1, u, n, target);
        return true;
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    return binarySearchModified(matrix, 0, m * n - 1, n, target);
}

int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout<<searchMatrix(matrix,target);
}
