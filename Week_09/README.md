学习笔记
不同路径2：dp方程：
dp[i][j]=obstacleGrid[i][j]==0?dp[i−1,j]+dp[i,j−1]:0;