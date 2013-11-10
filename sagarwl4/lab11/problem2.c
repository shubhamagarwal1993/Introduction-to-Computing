#include <stdio.h>
 
struct rawFloat {
  unsigned int mantissa;
  unsigned int exponent;
  char sign;
};
 
struct rawFloat convertToRawFloat(double d) {
  struct rawFloat ret = {0,0,0};
  if (d == 0) return ret;
 
  if (d < 0) {
    ret.sign = 1;
    d = -d;
  }
 
  /* 1.mantissa conversion when the value is [1,2)
   * d: 1.mantissa * 2^(exp-127)
   * ret.exponent = 127
   * KEEP INVARIANT
   * d * 2^(ret.exponent) is 1.mantissa*2^exp
   */
 
  ret.exponent = 127;
  while (d < 1.0) {
    d *= 2;
    ret.exponent--;
  }
 
  while (d >= 2.0) {
    d /= 2.0;
    ret.exponent++;
  }
 
  /* d = 1.(some stuff 23 bits long) 
   * d-1 = 0.(some stuff 23 bits long)
   * (d-1)*2^23 = (some stuff 23 bits long).(garbage)
   */
  ret.mantissa = (d-1) * 1024 * 1024 * 8;
  return ret;
}
 
int main() {
  struct rawFloat output;
  double d;
 
  scanf("%lf", &d);
  output = convertToRawFloat(d);
  printf("%lf: %d %08x %d\n", d, output.exponent, output.mantissa, output.sign);
}
 
/*  
  if (d < 1) {
    while (d < 1) {
      d *= 2;
      ret.exponent++;
    }
  } else if (d >= 2.0) {
    while (d >= 2.0) {
      d /= 2.0;
      ret.exponent--;
    }
  }
*/

