class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n; ; i++){
            int ne = i;
            int  x = 1;
            while(ne > 0){
                x = x * (ne%10);
                ne = ne/10;
            }
            if(x%t == 0){
                return i;
            }
        }
        return 0;
    }
};