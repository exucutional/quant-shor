# quant-shor
Quantum Shor's algorithm

main.cpp is a realization of Shor algorithm on non quantum computer.  
In code we suppose that taken number is a product of 2 prime numbers p1 and p2. Function `Factorize(uint64_t)` try to get these p1 and p2 by using fucntion `fact`. Function `fact(uint64_t a, uint64_t m)` tries to find a power `r` such that `(a ^ r) mod m == 1`. This function we can solve on quantum computer and it will give us polynomial running time instead of exponential running time on normal (non quantum) computer. This is what Shor's quantum algorithm is based on. 

Quantum_Shor.ipynb is a quantum realization of Shor algorithm.
The solution uses quantum phase estimation for operator `U|y> = |ay mod m>` to find the period r.