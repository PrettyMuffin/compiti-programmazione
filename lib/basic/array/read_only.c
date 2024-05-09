int confronta_array(int *X, int *Y, int dim)
{
    if (dim <= 0)
        return 1;

    for (int i = 0; i <= dim / 2; i++)
    {
        if (X[i] != Y[i] || X[(dim - 1) - i] != Y[(dim - 1) - i])
            return 0;
    }
    return 1;
}