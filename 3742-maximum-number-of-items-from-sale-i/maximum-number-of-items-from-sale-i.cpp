class Solution {
public:
int t[1001][1501];
    int solve(int n, int budget, int minprice, vector<int>& copies,vector<vector<int>>& items) {

        if(n == 0){
            return budget/minprice;
        }
        if(t[n][budget] != -1){
            return t[n][budget];
        }
        int take = 0;
        int price = items[n-1][1];
        if(price <= budget){
            take = 1 + copies[n-1] + solve(n-1,budget-price,minprice,copies,items);
        }

        int skip = solve(n-1,budget,minprice,copies,items);

        return t[n][budget] = max(take,skip);

     }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> copies(n, 0);
        int minprice = INT_MAX;
        for (int i = 0; i < n; i++) {
            minprice = min(minprice, items[i][1]);
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    copies[i]++;
                }
            }
        }
        memset(t,-1,sizeof(t));
        return solve(n, budget, minprice,copies,items);
    }
};