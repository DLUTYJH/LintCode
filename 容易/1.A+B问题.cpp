class Solution {
public:
    /*
     * @param a: An integer
     * @param b: An integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here
           if(b==0){
            return a;
        }else{
            int c = a^b;//先异或得到c
            int d = (a&b)<<1;//再与，然后左移一位得到d
            return aplusb(c,d);
        }
        
        
    }
};
