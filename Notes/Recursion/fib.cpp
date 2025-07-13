//Write a function to find fibonacci numbers
int fib(int n, int an0, int an1) {
    if (n == 0) 
        return 1;
    else if (n == 1)
        return 1;
    else 
        return fib(n - 1, an0, an1) + fib(n - 2, an0, an1);
}