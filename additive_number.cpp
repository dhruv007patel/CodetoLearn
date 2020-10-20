#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
class Solution {
   public:
   bool ok(string s, int idx, lli prev1, lli prev2){
      if(idx >= s.size()) return true;
      lli req = prev1 + prev2;
      string num = to_string(req);
      string x = "";
      for(int i = idx; i < s.size(); i++){
         x += s[i];
         if(x == num && ok(s, i + 1, prev2, stol(x))) return true;
      }
      return false;
   }
   bool isAdditiveNumber(string num) {
      int n = num.size();
      for(int i = 1; i < n - 1; i++){
         for(int j = 1; j <= i; j++){
            string s1 = num.substr(0, j);
            string s2 = num.substr(j, i - j + 1);
            int x = max((int)s1.size(), (int)s2.size());
            if(x > n - i) continue;
            if((s1[0] == '0' && s1.size() > 1) || (s2[0] == '0' && s2.size() > 1)) continue;
            if(ok(num, i + 1, stol(s1), stol(s2))) return true;
         }
      }
      return false;
   }
};
main(){
   Solution ob;
   cout << (ob.isAdditiveNumber("112358"));
}
