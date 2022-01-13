class Solution {
public:
    int strStr(string haystack, string needle) {
      // KMP solution in O(m+n) linear time as opposed to the brute-force O(mn) time
      //return strStr_bf(haystack, needle);
      return strStr_rk(haystack, needle);
    }
  
  
private:
  int strStr_bf(string txt, string pat) {
    // Brute-force solution in O(mn)
    if (pat.empty()) return 0;
    int n = txt.size();
    int m = pat.size();
    if (n < m) return -1;
    for (int i = 0; i <= n-m; i++) {
      int j{0};
      for (j = 0; j < m; j++) {
        if (txt[i+j] != pat[j]) break;
      }
      if (j == m) return i;
    }
    return -1;
  }
  
  
  int hash(string key, int m) {
    // Robin-Karp style hashing function of a string with M length
    // use large prime number Q
    int constexpr Q{7919};
    int constexpr R{256};
    long h = 0;
    for (int j = 0; j < m; j++) {
      h = (R * h + key[j]) % Q;
    }
    return h; 
  }
  
  int strStr_rk(string txt, string pat) {
    // Robin-Karp solution in O(mn) with a correct answer of probability 1/Q, where Q is a large prime number
    if (pat.empty()) return 0;
    int n = txt.size();
    int m = pat.size();
    if (n < m) return -1;

    // pre-compute R^{M-1} mod Q, used later for rolling has function to speed up
    int constexpr Q{7919};
    int constexpr R{256};
    int RM = 1;
    for (int i = 1; i <= m-1; i++) {
      RM = (R * RM) % Q;
    }
    
    int patHash = hash(pat, m);
    int txtHash = hash(txt, m);
    if (txtHash == patHash) return 0;  
    for (int i = m; i < n; i ++) {
      txtHash = (txtHash + Q - RM*txt[i-m] % Q) % Q;
      txtHash = (txtHash*R + txt[i]) % Q; 
      if (txtHash == patHash) return i - m + 1;
    }
    return -1;
  }
};
