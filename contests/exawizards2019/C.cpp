#include <iostream>
#include <string>
#include <vector>

bool left(const std::string S, const std::vector<char> ts, const std::vector<char> ds, int pos)
{
  // std::cout << pos << std::endl;

  if (pos < 0)
  {
    return true;
  }

  if (pos >= S.size())
  {
    return false;
  }

  for (int i = 0; i < ts.size(); i++)
  {
    if (S[pos] == ts[i])
    {
      pos += (ds[i] == 'L' ? -1 : +1);
    }

    // std::cout << pos << std::endl;

    if (pos < 0)
    {
      return true;
    }

    if (pos >= S.size())
    {
      return false;
    }
  }

  return false;
}

bool right(const std::string S, const std::vector<char> ts, const std::vector<char> ds, int pos)
{
  // std::cout << pos << std::endl;

  if (pos < 0)
  {
    return false;
  }

  if (pos >= S.size())
  {
    return true;
  }

  for (int i = 0; i < ts.size(); i++)
  {
    if (S[pos] == ts[i])
    {
      pos += (ds[i] == 'L' ? -1 : +1);
    }

    // std::cout << pos << std::endl;

    if (pos < 0)
    {
      return false;
    }

    if (pos >= S.size())
    {
      return true;
    }
  }

  return false;
}

int main()
{
  int N, Q;
  std::string S;

  std::cin >> N >> Q >> S;

  std::vector<char> ts(Q, 0), ds(Q, 0);

  for (int i = 0; i < Q; i++)
  {
    std::cin >> ts[i] >> ds[i];
  }

  // for (int i = 0; i < S.size(); i++)
  // {
  //   std::cout << (left(S, ts, ds, i) ? 'x' : 'o') << " " << (right(S, ts, ds, i) ? 'x' : 'o') << std::endl;
  // }

  int lm = -1, rm = N;

  for (int l = -1, r = N; r - l > 1;)
  {
    int mid = l + (r - l) / 2;

    if (left(S, ts, ds, mid))
    {
      l = mid;
    }
    else
    {
      r = mid;
    }

    lm = l;
  }

  for (int l = -1, r = N; l + 1 != r;)
  {
    int mid = l + (r - l) / 2;

    if (right(S, ts, ds, mid))
    {
      r = mid;
    }
    else
    {
      l = mid;
    }

    rm = r;
  }

  std::cout << rm - lm - 1 << std::endl;
}
