int main(){
    int a=1,b=2;
    int c=2;
    int i=0;
    for(i=0;i<10;i=i+1){
        if(a<5)a=a+1;
        if(a>=5){
            a=a+2;
        }
    }
    //输出i
    printf(i);
    while(a<40){
        a=a+1;
    }
    //输出a
    printf(a);
    return 0;
}