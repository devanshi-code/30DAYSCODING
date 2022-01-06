class Solution{   
public:
    string printMinNumberForPattern(string S){

        vector<int>num(S.size() + 1, 0);
        num[0] = 1;

        int max_int = 1;

        for(int i = 0; i < S.size(); ++i) {
            if(S[i] == 'I') {
                ++max_int;
                num[i + 1] = max_int;
            }

            int r = 0;
            while(i - r >= 0 && S[i - r] == 'D') {
                num[i - r + 1] = num[i - r];
                ++num[i - r];
                max_int = max(max_int, num[i - r]);
                ++r;
            }
        }

        for(auto n : num) {
            cout << n;
        }

        return "";
    }
};