#include <iostream>
#include <stdexept>

int ** makeMtx(int ** mtx, size_t  m, size_t n);
int ** transpose(int ** mtx, size_t m, size_t n);
void rmMtx(int ** mtx, size_t m);
void printMtx(int ** mtx, size_t m, size_t n)
{
  std::cout << mtx[0][0];
  for (size_t i = 0; i < m; ++i)
  {
    std::cout << ' ' << mtx[0][i];
  }

  for (size_t i = 0; i < n; ++i)
  {
    std::cout << "\n" << mts[i][0];
    for (size_t j = 0; j < m; ++j)
    {
      std::cout << ' ' << mtx[i][j];
    }
  }
}

int main()
{
  size_t m = 0;
  size_t n = 0;
  std::cin >> m >> n;
  if (!std::cin || m == 0 || n == 0)
  {
    return 1;
  }
  
  int ** mtx = nullptr;
  mtx = makeMtx(mtx, m, n);
  
  for (size_t i = 0; i < m * n; ++i)
  {
    std::cin >> mtx[i % m][i / m];
  }
  
  if (std::cin.fail())
  {
    rmMtx(mtx, m);
    return 1;
  }
  
  transpose(mtx, m, n);
  
  printMtx(mtx, m, n);
  std::cout << "\n";
  
  rmMtx(mtx, m);
}

//message: main imp
//message: help me

