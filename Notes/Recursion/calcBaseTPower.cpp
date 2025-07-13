//A number to the power
int BtoP(int base, int power) {
    if (power == 0)
        return 1;
    else 
        return base * BtoP(base, power - 1);
}