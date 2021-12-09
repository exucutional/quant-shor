#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <ctime>

uint64_t fact(uint64_t t, uint64_t M)
{
    uint64_t result = t;
    uint64_t r      = 1;

    while (true)
    {
        if (result % M == 1)
            return r;
        else
        {
            result = result * t % M;
            ++r;
        }
    }
}

struct Pair
{
    uint64_t p1;
    uint64_t p2;
};

uint64_t gcd(uint64_t a, uint64_t b)
{
    uint64_t temp = 0;
    while (b) {
        a %= b;
        temp = a;
        a = b;
        b = temp;
    }
    return a;
}

uint64_t pow(uint64_t base, uint64_t power)
{
    uint64_t result = 1;
    uint64_t factor = base;

    while (power)
    {
        if (power & 1)
            result *= factor;

        power  >>= 1;
        factor *=  factor;
    }

    return result;
}

Pair Factorize(uint64_t N)
{
    // step 1 - pick random number and try gcd()
    uint64_t a = rand() % N;

    uint64_t p = gcd(a, N);
    if (p != 1)
        return {p, N / p};

    // step 2 - get even r
    uint64_t r = fact(a, N);

    while (r & 1)
    {
        a = rand();
        r = fact(a, N);
    }

    // step 3 - gcd check
    uint64_t p1 = gcd(N, pow(a, r >> 1) - 1);
    uint64_t p2 = gcd(N, pow(a, r >> 1) + 1);

    if ((p1 == 1) || (p2 == 1))
        // retry
        return Factorize(N);

    return {p1, p2};
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    Pair pair = Factorize(15);
    printf("%lu %lu\n", pair.p1, pair.p2);
}
