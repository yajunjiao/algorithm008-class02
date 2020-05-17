学习笔记
本周主要学习了几个算法：
广度优先
深度优先
贪心
二分查找

广度优先模板：
c++

std::queue<node *> visited, unvisited;
node nodes[9];
node *current;

unvisited.push(&nodes[0]);

while(!unvisited.empty()) {
	current = (unvisited.front());
	if(current->left != nullptr) {
		unvisited.push(current->left);
	}
	if(current->right != nullptr) {
		unvisited.push(current->right);
	}
	visited.push(current);
	unvisited.pop();
}

深度优先模板:
c++

const int TREE_SIZE = 9;
std::stack<Node *> unvisited;
Node nodes[TREE_SIZE];
Node *current;
//初始化樹
for (int i = 0; i < TREE_SIZE; i++) {
	nodes[i].self = i;
	int child = i * 2 + 1;
	if (child < TREE_SIZE) // Left child
		nodes[i].left = &nodes[child];
	else
		nodes[i].left = NULL;
	child++;
	if (child < TREE_SIZE) // Right child
		nodes[i].right = &nodes[child];
	else
		nodes[i].right = NULL;
} 
unvisited.push(&nodes[0]); //先把0放入UNVISITED stack
// 樹的深度優先搜索在二叉樹的特例下，就是二叉樹的先序遍歷操作（這裡是使用循環實現)
// 只有UNVISITED不空
while (!unvisited.empty()) {
	current = (unvisited.top()); //當前應該訪問的
	unvisited.pop();
	if (current->right != NULL)
	unvisited.push(current->right );
	if (current->left != NULL)
	unvisited.push(current->left);
}

二分查找模板：

golang 非递归：
func binarySearch(arr []int, low, high, hkey int) int {
	for low <= high {
		mid := low + (high-low)/2
		if arr[mid] == hkey {
			return mid
		} else if hkey < arr[mid] {
			high = mid - 1
		} else if hkey > arr[mid] {
			low = mid + 1
		}
	}
	return -1
}

golang递归：
func binary_search(arr []int, low, high, hkey int) int {
	if low > high {
		return -1
	}
	mid := low + (high-low)/2

	if arr[mid] > hkey {
		return binary_search(arr, low, mid-1, hkey)
	} else if arr[mid] < hkey {
		return binary_search(arr, mid+1, high, hkey)
	}

	return mid
}
