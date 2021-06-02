#include <cstdio>
#include <iostream>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_const.h>
int main ()
{
    int i,n;
    /* Setup the Random number generator*/
    const gsl_rng_type * T;
    gsl_rng * r;
    gsl_rng_env_setup();
    T = gsl_rng_default;
    r = gsl_rng_alloc (T);

    n=3;

    gsl_vector * v = gsl_vector_alloc (n);

    for (i = 0; i < n; i++)
    {
        gsl_vector_set (v, i, gsl_rng_uniform (r));
    }

    for (i = 0; i < n; i++)
    {
       std::cout<<"v_"<<i << "=" << gsl_vector_get (v, i)<<std::endl;
    }

    gsl_vector_free (v);

    return 0;
}
