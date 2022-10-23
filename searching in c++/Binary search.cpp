bool binSearch(vector<int> &v, int t){
  int lo=0,hi=v.size()-1;
  bool ans=false;
  while(hi>=lo){
    int mid=lo+(hi-lo)/2;
    if(v[mid]==t){
      return true;
    }
    else if(v[mid]>t){
      hi=mid-1;
    }
    else {
      lo=mid+1;
    }
  }
  return ans;
}
