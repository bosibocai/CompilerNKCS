int main()
{
    int a = 2;
    int *p;
    p = a;
    int arraylist[10];
    arraylist[0] = a;
    a = arraylist[0];
    int *p = &a;
    *p = a;
    a = *p;
    printf(a);
}
