class Solution {
public:
    bool isPowerOfTwo(int n) {
            if(n <= 0)
                return false;
            //n & (n-1) flips the rightmost SET bit
            return (n & (n-1)) == 0;
    }
};