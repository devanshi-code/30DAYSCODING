class Solution {
  public:
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string, int> votes;

        for(int i = 0; i < n; ++i) {
            ++votes[arr[i]];
        }

        unordered_map<int, vector<string>> rank;

        int max_vote = 0;
        for(auto candidate: votes) {
            if(candidate.second >= max_vote) {
                max_vote = candidate.second;
                rank[max_vote].push_back(candidate.first);
            }
        }

        sort(rank[max_vote].begin(), rank[max_vote].end());

        return {rank[max_vote][0], to_string(max_vote)};
    }
};