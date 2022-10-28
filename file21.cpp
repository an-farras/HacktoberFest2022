bool isMatch(string s, string p) {
        int n = p.size(),m = s.size();
        vector<bool>prev(m+1,0),curr(m+1,0);
        // case 1
        prev[0] = true;
        // case 2
        for(int j=1;j<=m;j++){
            prev[j] = false;
        }
        for(int i=1;i<=n;i++){
	        // case 3
            bool flag = true;
            for(int k=1;k<=i;k++){
                if(p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
            for(int j=1;j<=m;j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?'){
                    curr[j] = prev[j-1];
                }else if(p[i-1] == '*'){
                    curr[j] = curr[j-1] || prev[j];
                }else{
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
