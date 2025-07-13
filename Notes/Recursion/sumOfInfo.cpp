int SumOfInfo(nodeType *current) {
    if (current != NULL)
        return current->info + SumOfInfo(current->link);
    else 
        return 0;
}