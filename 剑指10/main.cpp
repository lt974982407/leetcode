int fib(int n) {
        /*if (n == 0){
            return 0;
        }
        if (n == 1){
            return 1;
        }
        return (fib(n - 1) + fib (n - 2)) % (1000000007);*/
        if(n == 1 || n == 0)
            return n;
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        for (int i = 2; i <= n; i ++){
            int tmp = (dp[i - 1] + dp [i - 2]) % (1000000007); 
            dp.push_back(tmp);
        }
        return dp[n];
    }