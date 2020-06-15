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
	
	
	
		