
int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
int startIndex;
int n = A.size();
for(int i = 0; i<n; i++) {
startIndex = i;
int gasleft = A[i] -B[i];
while(gasleft >= 0 && (i - startIndex) < n) {
gasleft += A[++i%n]-B[i%n];
}
if(gasleft >= 0 )
return startIndex;
}// end for
return -1;
}
//Time O(n) Space: O(1)
