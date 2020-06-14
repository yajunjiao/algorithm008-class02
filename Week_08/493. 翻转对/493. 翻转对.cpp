class Solution {
//改进归并排序
    int res=0;
    public void sortFind(int[] nums,int left,int right){
        if(left==right)return;
        int mid= (left+right) / 2;
        sortFind(nums,left,mid);
        sortFind(nums,mid+1,right);
        int []helper=new int[right-left+1];
        int p=left,q=mid+1;
        //二分查找
        while(p<=mid){
            if(q>right)res+=(right-mid);
            //二分查找找到插入位置使得nums[p]==2*nums[q]
            else{
                int l=q,r=right;
                while(l<=r){
                    int m=(l+r)/2;
                    long a=nums[m],b=nums[p];
                    if(2*a>b)r=m-1;
                    else if(2*a<b)l=m+1;
                    else break;
                }
                //注意这时候需要找到最前的位置
                if(l<=r){
                    int temp=(l+r)/2;
                    while(temp>=left&&2*nums[temp]==nums[p])temp--;
                    q=temp+1;
                }
                else q=l;
                res+=(q-mid-1);
            }
            p++;
        }
        //合并有序数组
        p=left;q=mid+1;
        int now=0;
        while(p<=mid&&q<=right){
            if(nums[p]>nums[q])helper[now++]=nums[q++];
            else helper[now++]=nums[p++];
        }
        while(p<=mid)helper[now++]=nums[p++];
        while(q<=right)helper[now++]=nums[q++];
        for(int i=0;i<=right-left;i++)nums[i+left]=helper[i];
    }
    public int reversePairs(int[] nums) {
        int size=nums.length;
        if(size<=1)return 0;
        sortFind(nums,0,size-1);
        //for(int i=0;i<size;i++)System.out.println(nums[i]);
        return res;
    }
}