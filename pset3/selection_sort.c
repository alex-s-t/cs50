// an implementation of selection sort (O^2 complexity! yuck! ;))

int main (void)
{
    int min_value;
    int holder_min;

    for (int j = 0; j < n; j++) {
        
        min_value = values[j];
        for (int i = 0 + j; i < n; i++) {
            if (values[i] <=  min_value) {
                min_value = values[i];
                holder_min = i;
        }
        }
        values[holder_min] = values[j];
        values[j] = min_value;
        
    }
    return;

}
