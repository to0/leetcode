class Solution {
public:
    bool isMatch(string s, string p) {
      // match[i][j] == true iff s.substr[0, i) matches p.substr[0, j)
      std::vector<std::vector<bool>> match(s.size() + 1, std::vector<bool>(p.size() + 1, false));

      for (int j = 0; j <= p.size(); j++) {  
        for (int i = 0; i <= s.size(); i++) {
          if (i == 0 && j == 0) {
            match[i][j] = true;
            continue;
          }
          
          if (j == 0 /* i != 0*/) {
            match[i][j] = false;
            continue;
          }

          char p_char = p[j - 1];

          if (i == 0 /* && j != 0*/) {
            match[i][j] = match[i][j - 1] && p_char == '*';
            continue;
          }
          
          char s_char = s[i - 1];
          
          if (p_char == '*') {
            // matches zero chars
            // matches one or more chars
            // any true in match[0 - i)[j]
            match[i][j] = match[i][j - 1] | match[i - 1][j];

          } else if (p_char == '?') {
            match[i][j] = match[i - 1][j - 1];
          } else {
            match[i][j] = match[i - 1][j - 1] && s_char == p_char;
          }
        }
      }
      return match[s.size()][p.size()];

    }
};