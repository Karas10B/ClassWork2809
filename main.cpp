#include <iostream>

void rmMtx(int ** mtx, size_t m)
{
  for (size_t i = 0; i < m; ++i)
  {
    delete [] mtx[i];
  }
  delete [] mtx;
}

int ** makeMtx(size_t  m, size_t n)
{
  int ** mtxR = new int * [m];
  try
  {
    for (size_t i = 0; i < m; ++i)
    {
      mtxR[i] = new int [n];
    }
  }
  
  catch (const std::bad_alloc & e)
  {
    rmMtx(mtxR, m);
    throw;
  }

  return mtxR;
}

int ** transpose(int ** mtx, size_t m, size_t n)
{
  int ** mtxT = makeMtx(m, n);
  
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      mtxT[i][j] = mtx[j][i]
    }
  }
  
  return mtxT;
}

void printMtx(int ** mtx, size_t m, size_t n)
{
  std::cout << mtx[0][0];
  for (size_t i = 1; i < m; ++i)
  {
    std::cout << ' ' << mtx[0][i];
  }

  for (size_t i = 1; i < n; ++i)
  {
    std::cout << "\n" << mtx[i][0];
    for (size_t j = 1; j < m; ++j)
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
  mtx = makeMtx(m, n);
  
  for (size_t i = 0; i < m * n; ++i)
  {
    std::cin >> mtx[i / m][i % m];
  }
  
  if (std::cin.fail())
  {
    rmMtx(mtx, m);
    return 1;
  }
  
  printMtx(mtx, m, n);
  std::cout << "\n";
  
  mtxT = transpose(mtx, m, n);
  std::cout << "-----\n";
  printMtx(mtxT, n, m);
  std::cout << "\n";
  
  rmMtx(mtx, m);
  rmMtx(mtxT, n)
}

//message: main imp
//message: help me

