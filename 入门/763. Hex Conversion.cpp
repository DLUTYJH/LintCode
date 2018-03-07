class Solution {
private:
    vector<string> vec;
public:

    Solution() {
	//此部分代码如此实现，有点丑，但是这也是简洁的方式，使用循环的方式涉及基本数据类型转换
	//基本数据类型转换在C++中并不方便
        vec.push_back("0");
        vec.push_back("1");
        vec.push_back("2");
        vec.push_back("3");
        vec.push_back("4");
        vec.push_back("5");
        vec.push_back("6");
        vec.push_back("7");
        vec.push_back("8");
        vec.push_back("9");
        vec.push_back("A");
        vec.push_back("B");
        vec.push_back("C");
        vec.push_back("D");
        vec.push_back("E");
        vec.push_back("F");
    }

    /**
     * @param n: a decimal number
     * @param k: a Integer represent base-k
     * @return: a base-k number
     */
    string hexConversion(int n, int k) {
        // write your code here
        int tmp;
        string str;
        if (n == 0) { //使用除k取余数的方法，容易忽略掉0这个问题
            return str+="0";
        }
        while (n > 0) {
            tmp = n % k;
            n = n / k;
            str.append(vec[tmp]);
        }

        reverse(str.begin(), str.end());
        return str;
    }
};
