class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10) {
            return false;
        }
        int a = 1;
        int b = 0;
        int div = 10;
        while (n != 0) {
            if (a == 1) {
                if (div > n) {
                    return false;
                }
                n = n - div;
                if(n == 0){
                    return true;
                }
                div = div - 1;
                b = 1;
                a = 0;
            }
            if (b == 1) {
                if (div > n) {
                    return true;
                }
                n = n - div;
                if(n == 0){
                    return false;
                }
                div = div - 1;
                a = 1;
                b = 0;
            }
        }
        return true;
    }
};