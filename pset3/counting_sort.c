// counting sort

int main(void)
{
    int array1[7] = {23, 45, 122, 233, 56, 12, 42};
    int length = 7;
    int array_counter[234] = { 0 };
    int store;
    int q = 0;
    
    for (int i = 0; i < length; i++) {
        store = array1[i];
        array_counter[store] += 1;
    }
    
    for (int i = 0; i < 234; i++) {
        for (int j = 0; j < array_counter[i]; j++) {
            array1[q] = i;
            q += 1;
        }
    }
}