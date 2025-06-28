
#include<cstdlib>
#include<cstdio>
#include <stdint.h>
#include <array>

using namespace std;

int compute_fudge(uint64_t peprime, uint64_t pe)
{
  double eps = 0;

  if (peprime > 1) {

    if (peprime % 2 == 0) {
    
      eps = 1;

      // The exact variance in this case is at most the variance
      // of a random variable that is distributed over
      //    -N..+N
      // where N = 2^{e'}/2.
      // Each endpoint occurs with probability 1/(4*N),
      // and the remaining values each occur with the same probability
      // 1/(2*N)

      // This variance is exactly computed as
      //    (N^2)/3 + 1/6 = ((N^2)/3)*(1 + 1/(2*N^2)), where N = 2^{e'}/2
      // So the std dev is at most
      //    N/sqrt(3)*(1 + 1/(4*N^2))

    } else {
      eps = 1 / double(pe);

      // We are computing X + Y mod p^{e'}, where
      // X and Y are independent.
      // Y is uniformly distributed over
      //    -floor(p^{r}/2)..floor(p^{r}/2)
      // X is distributed over
      //    -floor(p^e/2)-1..floor(p^e/2)+1,
      // where each endpoint occurs with probability 1 / (2*(p^e+1)),
      // and the remaining p^e values are equally likely

      // The variance in this case is bounded by
      //   (N^2)/3*(1-eps) + (N^2)*eps = (N^2)/3*(1+2*eps),
      //       where N = p^{e'}/2 and eps < 1/p^e
      // So the std dev is bounded by
      //    N/sqrt(3)*sqrt(1+2*eps) <= N/sqrt(3)*(1+eps)
    }
  }

  return 1;
}
