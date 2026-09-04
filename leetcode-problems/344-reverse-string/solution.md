
344. Reverse String
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.


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
