//Input IP header
//Calc checksum (endian machine independent)
//Display result of each step and final result.

/* 
 Psuedo Code
 
 The IP checksum is the 16 bit one's complement of the one's complement sum of all 16 bit words in the header.
 
 The reason of using 1's complement on 2's complement machines is that it is ""endian independent"" .
 
 Little Endian computers store hex numbers with the LSB last (Intel processors for example). Big Endian computers put the LSB first (IBM mainframes for example). When carry is added to the LSB to form the 1's complement sum (see the example) it doesn't matter if we add 03 + 01 or 01 + 03. The result is the same.
 Other benefits include the easiness of checking the transmission and the checksum calculation plus a variety of ways to speed up the calculation by updating only IP fields that have changed.
 
 */
// The following is an example.
/*
 0100 f203 f4f5 f6f7 0000 0000 0000 0000 0000 0000
 The 1's complement sum is 2deef
 The carry is 2
 Final sum on which one's complement is to be applied is def1
 The checksum is 210e
*/

#include <iostream>
using namespace std;

int main() {
	// my code goes here
    // Expecting fixed size IP header in 4 digit grouping
    
    unsigned int ip[10];
    unsigned int sum= 0x00;
    int carry = 0x0;
    
    cout << "Enter 10 groups of 4 digits in hexadecimal" << endl;
    
    for(int i=0;i!=10;i++){
        cin >> hex >> ip[i] ;
        sum+=ip[i];
    }
    
    cout << "The 1's complement sum is ";    
    cout << hex << sum << endl;
    
    carry = sum/0x10000;
    sum = sum + carry  ;
    sum = sum % 0x10000;
    
    cout << "The carry is " << carry << endl;
    cout << "Final sum on which one's complement is to be applied is ";
    cout << hex << sum <<endl ;
    
    unsigned int checksum = ~sum;
    checksum = checksum % 0x10000;
    cout << "The checksum is ";
    cout << hex << checksum <<endl ; 
    
	return 0;
} 
