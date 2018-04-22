/*Lab 1.  The purpose of this lab is to familiarize you with bit-level operations in C, radix conversions, and endianness.
You conversion code in this lab will mimic the way you would manually perform conversions.
You are to complete the functions in the program below. The main function is completed for you.
You are not allowed to call any built-in or library functions within your code. You may refer to constant values built into the limits.h library.
*/
#include <stdio.h>
#include <limits.h>

/*function dec2bin is to convert an unsigned 8-bit decimal value to binary value using the manual procedure explained in the 
text on page 36 (adapted for base 2) and also on slide 10 of the archived lecture notes on Data Representation.
No built-in or library C functions may be used.
*/
unsigned dec2bin(unsigned char x){
        unsigned char d;
        unsigned  rslt, newrslt;
        int i = 0;;
        rslt = 0;
        d = x;
        while (d != 0){
          newrslt = d%2;
          d = d/2;
          rslt = rslt | (newrslt << i);
          printf("%x\n", rslt);
          i++;


        }
        return rslt;
}

/*function bin2dec is to convert an unsigned 8-bit binary value to decimal by expanding the polynomial as depicted
on slide 5 of the archived lecture notes on Data Representation. No built-in or library C functions may be used.
*/
unsigned bin2dec(unsigned x){
        unsigned rslt = 0;
        unsigned digitval = 0;
        int i;
        for (i=0;i<32;i++){
           digitval = x & (0x1 <<i);
           rslt = rslt + digitval;
        }
        return rslt;
}

void printranges(){
/*this function is to print the possible range of values (in decimal) for char, unsigned char, int, and unsigned
on the current machine.  Use the constant values in library limits.h
*/
        printf("Range of unsigned char is 0 to %u\n",UCHAR_MAX);
        printf("Range of  char is %d to %d\n",SCHAR_MIN,SCHAR_MAX);
        printf("Range of unsigned (int)is 0 to %u\n",UINT_MAX);
        printf("Range of int is %d to %d\n",INT_MIN,INT_MAX);
return;
}
/*function chkendian is to determine if the current machine has a little endian or a big endian architecture.
No built-in or library functions may be used. Your code should store a multi-byte value into memory and then
examine it byte-by-byte to determine endianness. The function should print out "I'm Big Endian" or "I'm Little Endian" 
as appropriate before returning.
*/
void chkendian(){
        union
        {char Array[4];
         long Chars;
        }TestUnion;
        char c = 'a';
        int x;
        /*Test platform Endianness*/
        for(x=0;x<4;x++)
            TestUnion.Array[x] = c++;
        if (TestUnion.Chars == "abcd")
                printf("I'm Big Endian\n");
        else
                printf("I'm Little Endian\n");

        return;

}

/*function le2be should convert a little endian int and return it as a bit endian int.
Your code should do this using shift and logical operations only.
No built-in or library functions can be used.*/
int le2be(int x){
        int d;
        d= ( ((x >>24) & 0x000000FF) | ((x >> 8) & 0x0000FF00) | \
                ((x << 8) & 0x00FF0000) | ((x <<24) & 0xFF000000) );
return d;
}

/*function le2bep should convert a little endian int and return it as a big endian int.
Your code should do this using pointers. No built-in or library functions may be used.*/
int le2bep(int x){
        int d = x;
        char *dptr = &d;
        int bed;
        char *bedptr = &bed;
        *(bedptr + 3) = *dptr;
        printf("%x\n", *(bedptr+3));
        *(bedptr + 2) = *(dptr + 1);
        printf("%x\n", *(bedptr+2));
        *(bedptr + 1) = *(dptr + 2);
        printf("%x\n", *(bedptr+1));
        *bedptr = *(dptr + 3);
        printf("%x\n", *bedptr);
        return bed;
}

int main(){
        unsigned char  h = 165;
        unsigned  i = 0x0000ffff;
        unsigned   hrslt;
        int irslt;

        hrslt = dec2bin(h);
        printf("calculated hex value of %d is: 0x%x\n",h,hrslt);
        printf("actual hex value of %d is: 0x%x\n", h,h);

        irslt = bin2dec(i);
        printf("calculated decimal value of 0x%x is: %d\n",i,irslt);
        printf("actual decimal value of 0x%x is: %d\n",i,i);

        printranges();
        chkendian();
        unsigned le = 0x12345678;
        printf("Using logical ops:\n");
        printf("Little Endian = 0x%x,Big Endian = 0x%x\n", le,le2be(le));
        printf("Using pointers:\n");
        printf("Little Endian = 0x%x,Big Endian = 0x%x\n",le,le2bep(le));
}

