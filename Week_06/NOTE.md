动态规划：
动态规划和递归或者分治 没有根本上的区别（关键看有无最优的子结构）
共性：找到重复子问题
差异性：最优子结构，中途可以淘汰次优解

递归fib:
int fib(int n) {
	if(n <= 0) {
		return 0;
	} else if (n == 1){
		return 1;
	} else {
		return fib(n - 1) + fib(n - 2);
	}
}

简洁写法：
int fib(int n) {
	return n <= 1 ? n : fib(n - 1) + fib(n - 2);
}
算法复杂度 O(2^n) 指数级

int fib(int n) {
	int a[0] = 0, a[1] = 1, an = 0;
	for(int i = 2; i <= n; i++){
		a[i] = a[i - 1] + a[i - 2];
		a[i - 1] = a[i];
		a[i - 2] = a[i - 1];
	}
	return a[i];
}

算法复杂度 O(n)

路径计数，状态转移方程（DP方程）
opt[i, j] = opt[i+1, j] + opt[i, j + 1]
完整逻辑：
if a[i, j] = '空地' :
	opt[i, j] = opt[i + 1, j] + opt[i, j + 1]
else
	opt[i, j] = 0
	
动态规划的的四个解题步骤是：
定义子问题
写出子问题的递推关系
确定 DP 数组的计算顺序
空间优化（可选）
简单的一些还可以，复杂的就有点力不从心，应该是练得不够，理解不到位。继续训练，配合五毒神掌。