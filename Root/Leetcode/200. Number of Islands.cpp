int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

class Solution {
public:
	void dfs(int u, int v, int& r, int& c, vector<vector<char>>& grid, vector<vector<bool>>& mark) {
		mark[u][v] = true;
		for (int k = 0; k < 4; k++) {
			int nu = u + dx[k];
			int nv = v + dy[k];
			if (nu >= 0 && nu < r && nv >= 0 && nv < c && grid[nu][nv] == '1' && mark[nu][nv] == false) 
				dfs(nu, nv, r, c, grid, mark);
		}
		return;
	}

    int numIslands(vector<vector<char>>& grid) {
  		int r = grid.size();
  		if (r == 0) return 0;
  		int c = grid[0].size();
  		vector<vector<bool>> mark(r, vector<bool>(c, false));
  		int ans = 0;
  		for (int i = 0; i < r; i++) {
  			for (int j = 0; j < c; j++) {
  				if (grid[i][j] == '1' && mark[i][j] == false) {
  					dfs(i, j, r, c, grid, mark);
  					ans++;
  				}
  			}
  		}      
  		return ans;
    }
};

