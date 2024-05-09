void trasposta_matrice(int *Matrice, int *Trasposta, int righe, int colonne)
{
    for (int i = 0; i < colonne; i++)
    {
        for (int j = 0; j < righe; j++)
        {
            Trasposta[i * righe + j] = Matrice[j * righe + i];
        }
    }
}