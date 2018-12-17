#include <algorithm>
#include <climits>
#include <cstdio>
 
using namespace std;
 
int m, n, mat[11][110], cost[11][110], path[11][110];
 
/* Recursive DP approach with memoization. */
int dp (int i, int j) {
  if (j >= n) return 0;
  if (cost[i][j] != INT_MAX) return cost[i][j];
 
  int p[3] = { i - 1, i, i + 1 };
  if (i == 0) p[0] = m - 1;
  if (i == m - 1) p[2] = 0;
 
  for (int k = 0; k < 3; k++) {
    int val = mat[i][j] + dp(p[k], j + 1);
    // Second argument is to preserve lexicographical output.
    if (cost[i][j] > val || (cost[i][j] == val && path[i][j] > p[k])) {
      cost[i][j] = val;
      // Store direction when cost matrix is updated.
      path[i][j] = p[k];
    }
  }
  return cost[i][j];
}
 
int main () {
  while (scanf("%d %d\n", &m, &n) == 2) {
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        scanf("%d", &mat[i][j]);
        cost[i][j] = INT_MAX;
      }
 
    /* 
     * DP problem, relation is the minimum cost length to current cell from
     * cell to left and cell to above left.
     */
    int best = INT_MAX;
    int r = 0;
    for (int i = 0; i < m; i++) {
      dp(i, 0);
      if (cost[i][0] < best) {
        best = cost[i][0];
        r = i;
      }
    }
    // Print path.
    for (int j = 0; j < n; j++) {
      printf(j == 0? "%d" : " %d", r + 1);
      r = path[r][j];
    }
    printf("\n%d\n", best);
  }
}