var res []int

func preorder(root *Node) []int {
	res = []int{}
	dfs(root)
	return res
}

func dfs(root *Node)  {
	if root != nil {
		res = append(res, root.Val)
        for _,n := range root.Children {
		    dfs(n)      
        }
	}
}