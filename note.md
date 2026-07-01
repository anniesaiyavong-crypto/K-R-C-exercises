## 2.9, bitwise Operators

## '>>' or Right shift operator

Shift the bit to the right by 'value' 
Essentially deviding it by 2 per value

For example: 40 >> 1 is 40/2 
40 >> 2 is 40/2 then 'result'/2

## '<<' or Left shift operator

Just as same as the Right shift but opposite 
Multiply by 2 per 'value'

Ex: 10 << 1 is 10 * 2
10 << 2 is 10 * 2 then 'result' * 2

## & or Bitwise AND

& is similar to && but at bit scale
Both bit have to be 1 in order to return 1
If there's a 1 and 0, the outcome is 0

For the context, it look like this

int n = 10

n = (n & 127)


0 0 0 0 1 0 1 0   <--- n 
0 1 1 1 1 1 1 1   <--- 127
---------------
0 0 0 0 1 0 1 0   <--- We got the same 10 as a result

## | or bitwise OR

Similar to & but opposite
Both bit have to be 0 or off in order to return 0

int n = 10

n = (n | 127)

0 0 0 0 1 0 1 0   <--- n 
0 1 1 1 1 1 1 1   <--- 127
---------------
0 1 1 1 1 1 1 1   <--- We got the same 127 as a result

## ^ or XOR

This one is quite weird
Both have to be different in order to return 1
Otherwise it will be 0

int n = 10

n = (n | 127)

0 0 0 0 1 0 1 0   <--- n 
0 1 1 1 1 1 1 1   <--- 127
---------------
0 1 1 1 0 1 0 1   <--- We got 117

## ~ or one's complement

It will turn the current bit state in to its opposite
e.g 1 to 0 and 0 to 1

int n = 10

n = ~n

0 0 0 0 1 0 1 0   <--- n 
---------------
1 1 1 1 0 1 0 1   <--- Signed value is -11
                       Unsigned value is 245 in 8 bit
                       Or 4294967285 in 32 bit 







