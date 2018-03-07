
//注意： 使用递归实现超时
public class Solution {
    /*
     * @param : an integer
     * @return: an ineger f(n)
     */
    public:
	int fibonacci(int n) {
        	// 递归超时
       		// if(n == 0 || n == 1 ) return 0 ;
       		//  else if(n == 2) return 1 ;
       		// return fibonacci(n-1) +fibonacci(n-2);
       
       		if(n == 0 || n == 1 ) return  0;
       		if(n == 2 ) return 1 ;
       
       		int arr[] = new int[n+1];
 
       		arr[1] = 0 ;
       		arr[2] = 1 ;
       
       		int i = 3;
       		for(  ; i < n+1 ; i++ ){
           			arr[i] =  arr[i-1]+ arr[i-2];
       		}
    
     		return arr[n];
    	}
};
