void prepare_array(int buffer[], int *array[], int row, int column[])
{
    int *ptr = buffer;
    for ( int i = 0; i < row; i++) {
        array[i] = ptr;
        ptr += column[i];
    }
}
