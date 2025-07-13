void printInDiffBase(int number, int base) {
    if (number > 0) {
        printInDiffBase(number / base, base);
        cout << number % base;
    }
}