#include <iostream>
#include <algorithm>

using namespace std;
template<typename T>
void selectionSort(T arr[], T n){

	int minIndex = 0;
    for(int i = 0 ; i < n ; i ++){
        // 寻找[i, n)区间里的最小值
        minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;

		std::swap(arr[i], arr[minIndex]);
        //swap( arr[i] , arr[minIndex] );
    }

}

int main() {

    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    selectionSort(a,10);
    for( int i = 0 ; i < 10 ; i ++ )
        std::cout<<a[i]<<" ";
	std::cout<<endl;

    return 0;
}