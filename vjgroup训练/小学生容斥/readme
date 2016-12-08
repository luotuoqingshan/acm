A:
可以发现对于每个k，我们可以算出M的个数。但是会有重复，比如64＝4^3=8^2,所以这个时候就要使用容斥原理了。
B:
C:
观察后可以发现，题目就是求1<=x<=n,1<=y<=m,(x,y)=1的pair数，这可以用mobius反演轻松解决。
D:
同C题，设函数work(x,y)求1<=x<=n,1<=y<=m,(x,y)=k的满足条件的pair数(其中x != y时(x,y)与(y,x)相同)，
则原问题的答案就是work(b,d)-work(a,d)-work(b,c)+work(a,c)。 而
D:同C题，设函数work(x,y)求1<=x<=n,1<=y<=m,(x,y)=k的满足条件的pair数(其中x != y时(x,y)与(y,x)相同)，则原问题的答案就是work(b,d)-work(a,d)-work(b,c)+work(a,c)。
而如果没有限制条件的时候的函数设为solve(x,y),那么work(x,y) = solve(x,y) - solve(min(x,y),min(x,y)) / 2。于是同样mobs反演一下就解决了问题。
E:
这题可以用dp＋bignum解决。
dp[n][s]表示n位和为s的方案数。
dp[n][s] = sum(dp[n - 1][s - i])(0 <= i <= 9)
