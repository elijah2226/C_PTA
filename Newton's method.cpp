#include <stdio.h>

double ntsqrt(int x, double eps);

int main()
{
  int x;
  double eps;

  scanf("%d %lf", &x, &eps);

  printf("%.4f", ntsqrt(x, eps));

  return 0;
}

/* 请在这里填写答案 */
// 牛顿迭代法 
double ntsqrt(int x, double eps){
	double guess = 1.0;
	while((x>=guess*guess?x-guess*guess:guess*guess-x) >= eps){
  	guess -= (x-guess*guess)/(-2*guess);
  }
  return guess;
}
