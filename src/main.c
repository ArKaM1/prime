#include <stdio.h>
#include <gmp.h>

//Gobally declared for reusage
mpz_t root; 
mpz_t divisor;
mpz_t mod;

int isPrime(mpz_t *n){
  mpz_sqrt(root, *n);
  mpz_set_ui(divisor, 3);

  while(mpz_cmp(root,divisor) >= 0){
     mpz_mod(mod, *n, divisor);
     if(mpz_cmp_ui(mod,0) == 0){
      gmp_printf ("%Zd\n", *n); //print out any number that nextprime misses!
      return 0;
     }
     mpz_add_ui(divisor, divisor, 2);
  }

  return 1;
}

int main()
{
  mpz_init(root);
  mpz_init(divisor);
  mpz_init(mod);

  mpz_t prime;
  mpz_init_set_ui(prime, 2);

  char buffer[256 * sizeof(char)];
  FILE *fp = fopen("primes.txt", "w");
  while(1){
    mpz_get_str(buffer, 10, prime);
    fprintf(fp, "%s\n", buffer);
    do{ 
      mpz_nextprime(prime, prime);
    }while(isPrime(&prime) != 1);
  }

  return 0;
}
