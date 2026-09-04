
void reverseString(char* s, int sSize) {
    char temp;
    int i=0;
    int j=sSize-1;
    while(i<sSize/2){
        temp=s[j];
        s[j]=s[i];
        s[i]=temp;
        i++;
        j--;
    }
}
