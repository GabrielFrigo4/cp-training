class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> count(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            count[edges[i][1]]++;
        }

        int max = -1;
        for (int i = 0; i < count.size(); i++) {
            if (count[i] == 0 && max == -1) {
                max = i;
                continue;
            }
            if (count[i] == 0 && max != -1) {
                max = -1;
                break;
            }
        }

        return max;
    }
};
