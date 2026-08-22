class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int y = n;
        while(n > 0){
            int x = n%10;
            n = n / 10;
            sum = sum + x;
            product = product * x;
        }
        int div = sum + product;
        if(y % div == 0){
            return true;
        }
        return false;
    }
};