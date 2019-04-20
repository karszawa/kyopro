#include <iostream>
#include <algorithm>
#include <vector>

const long long int MOD = 1000000007;

int main()
{
  int N, X;

  std::cin >> N >> X;

  std::vector<int> S(N);

  for (int i = 0; i < N; i++)
  {
    std::cin >> S[i];
  }

  std::sort(S.begin(), S.end());

  std::vector<std::vector<long long int>> dp(N, std::vector<long long int>(X + 1));

  for (int i = 0; i <= X; i++)
  {
    dp[0][i] = i % S[0];
  }

  for (int i = 1; i < N; i++)
  {
    for (int j = 0; j <= X; j++)
    {
      dp[i][j] = (1ll * dp[i - 1][j] * i + dp[i - 1][j % S[i]]) % MOD;
    }
  }

  std::cout << dp[N - 1][X] << std::endl;
}
