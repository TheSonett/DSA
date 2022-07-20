#include <iostream>
#include <cmath>

long int fibCache[100];

int fib(int n) 
{
  if(n <= 1)
    return n;

  if(fibCache[n] != 0) {
    return fibCache[n];
  } 

  fibCache[n] = fib(n-1) + fib(n-2);
  return fibCache[n];
}

int main() {
  std::cout << fib(50);
  return 0;
}