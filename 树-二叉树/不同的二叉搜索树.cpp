class Solution {
public:
     int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};


// 用的是 一个公式： C(n+1) = 2*(2n+1)*C(n) / (n + 2)

class Solution {
public:
     int numTrees(int n) {
        long long llSum = 1;

        for (int i = 0; i < n; i++)
        {
            llSum = 2 * (2 * i + 1) * llSum / (i + 2);
        }

        return llSum;
    }
};