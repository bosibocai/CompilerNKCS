int main() {
    int a,b=0;
    while(a<5){
        printf(a);
        for(int i=0;i<5;i=i+1){
            b=b+a+(10/4)*3;
        }
        a=a+1;
    }
    return b;
}