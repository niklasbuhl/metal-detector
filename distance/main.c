#include <math.h>
#include <stdio.h>

int main() {

  float volt;

  printf("\n");
  printf("\n");

  for(int i = 1024; i > 0; i--) {
    volt = (5000/1024)*i;
    printf("%i, ",(int)(61.573*pow(volt/1000, -1.1068)));
  }

  printf("\n");
  printf("\n");

  for(int i = 1024; i > 0; i--) {
    volt = (5000/1024)*i;
    printf("%i, ",(int)(27.728*pow(volt/1000, -1.2045)));
  }

  printf("\n");
  printf("\n");
}
