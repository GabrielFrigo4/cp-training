class Solution {
private:
    void dfs(map<string, map<string, double>> &graph, string var, string key, double val) {
        if (used.contains(key)){
            return;
        }
        used.insert(key);
        graph[var][key] = val;

        for (auto it = graph[key].begin(); it != graph[key].end(); it++) {
            string key1 = get<0>(*it);
            double val1 = get<1>(*it);
            dfs(graph, var, key1, val * val1);
        }
    }
public:
    set<string> used;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, map<string, double>> graph;
        set<string> vars;
        for (int i = 0; i < equations.size(); i++) {
            vars.insert(equations[i][0]);
            vars.insert(equations[i][1]);
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1/values[i];
        }

        for (string var : vars) {
            used.clear();
            for (auto it = graph[var].begin(); it != graph[var].end(); it++) {
                string key = get<0>(*it);
                double value = get<1>(*it);
                dfs(graph, var, key, value);
            }
        }

        vector<double> ans;
        for (vector<string> query : queries) {
            if (query[0] == query[1] && vars.contains(query[0])){
                ans.push_back(1);
                continue;
            }
            if (graph.contains(query[0])) {
                if (graph[query[0]].contains(query[1])) {
                    ans.push_back(graph[query[0]][query[1]]);
                    continue;
                }
            }
            ans.push_back(-1);
        }
        return ans;
    }
};