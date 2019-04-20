#include <iostream>
#include <string>

int main()
{
  int N;
  std::string S;

  std::cin >> N >> S;

  int wc = 0, bc = 0;

  for (int i = 0; i < N; i++)
  {
    if (S[i] == '#')
    {
      bc++;
    }
    else
    {
      wc++;
    }
  }

  int wc_ = 0, bc_ = 0, ans = 1 << 30;

  for (int i = 0; i < N; i++)
  {
    ans = std::min(ans, bc_ + wc - wc_);

    if (S[i] == '#')
    {
      bc_++;
    }
    else
    {
      wc_++;
    }

    // i_ <= i を白にして i < _i を黒にする
    ans = std::min(ans, bc_ + wc - wc_);
  }

  std::cout << ans << std::endl;
}
