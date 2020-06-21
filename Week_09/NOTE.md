高级动态规划
	递归代码模板：
	public void recur(int level, int param) {
		//terminator
		if(level > MAX_LEVEL){
			//process result
			return;
		}
		
		//process current logic
		process(level, param);
		
		//drill down
		recur(level+1, newParam);
		
		//restore current status
		
	}
	
	分治代码模板：
	def divide_conquer(problem, param1, param2, ...):
		#recursion terminator
		if problem is None:
			print_result
			return
		
		#prepare data
		data = prepare_data(problem)
		subproblems = split_problem(problem, data)
		
		#conquer subproblems
		subresult1 = self.divide_conquer(subproblems[0], p1, ...)
		subresult2 = self.divide_conquer(subproblems[1], p1, ...)
		subresult3 = self.divide_conquer(subproblems[1], p1, ...)
		...
		
		#process and generate the final result
		result = process_result(subresult1, subresult2, subresult3, ...)
		
		#revert the current level states
		
	DP 顺推模板
	function DP():
		dp = [][] #二维情况 状态定义
		
		for i = 0.. M {
			for j = 0 .. N {
				dp[i][j] = _Function(dp[i'][j']) # 注意：状态转移方程
			}
		}
		
		return dp[M][N];
关键点：
	动态规划和递归分治 没有根本上的区别（关键看有无最优的子结构）
	拥有共性：找到重复子问题
	
	差异性：最优子结构，中途可以淘汰次优解
	
不同路径II:
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m < 1) return 0;
        int n = obstacleGrid[0].size();
        if (n < 1) return 0;
        long dp[m][n];  //　使用int提交出现溢出错误，就改为long
        if (1 == obstacleGrid[0][0]) return 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (0 == i && 0 == j) {     //上面判断过(０,０)为１的情况了，这里必定是没有障碍物，因此路径为１
                    dp[i][j] = 1;
                } else if (0 == i && j != 0) {  //　最上面一行网格，如果该点是障碍物，则这一点必定不可达，否则路径和达到其左侧的路径一样
                    dp[i][j] = (1 == obstacleGrid[i][j] ? 0 : dp[i][j - 1]);
                } else if (0 != i && j == 0) {　//　最左侧一列网格，如果该点是障碍物，则这一点必定不可达，否则路径和达到其上侧的路径一样
                    dp[i][j] = (1 == obstacleGrid[i][j] ? 0 : dp[i - 1][j]);
                } else {    //　对于坐标均不为０的点，仅在该点为障碍物的时候不可达
                    dp[i][j] = (1 == obstacleGrid[i][j] ? 0 : dp[i][j - 1] + dp[i - 1][j]);
                }
            }
        }
        return static_cast<int>(dp[m - 1][n - 1]);
    }
};
	
	
	
		