---
created: 2023-09-13T12:18
updated: 2023-09-14T11:31
---
# Inhoudsopgave
```toc
```

## Optellen van binaire getallen
$$
\begin{align}
0011 1011\\
\underline{+0001 1010}\\
0101 0101
\end{align}
$$

## Bits en Bytes
- Een [[bit]] is een 0 of een 1
- Een [[byte]] bestaat uit 8 bits
- Een [[int]] bestaat uit twee of vier of acht bytes

### Negatieve getallen
Hoe groot kan ene [[int]] worden?

- Stel je hebt a acht bits
	- 255 ($2^{8}-1$)

## Sign magnitude
- Je gebruikt het eerste bit als teken ([[sign]])
- Gebruik de rest voor de grote ([[magnitude]])

Uitgaande van acht bits:
- Bereik : -127, 127

## [[Ones compliment]]
- Gebruik alle getallen die met een 0 beginnen voor positief
	- 0 t/m 127
- Inverse van die getallen is negatief
	- -127 t/m -1

## [[Two's compliment]] 

## EN in de logica
| p   | q   | p EN q |
| --- | --- | ------ |
| T   | T   | T      |
| T   | F   | F      |
| F   | T   | F      |
| F   | F   | F      | 

## OR in de logica
| p   | q   | p OR q |
| --- | --- | ------ |
| T   | T   | T      |
| T   | F   | T      |
| F   | T   | T      |
| F   | F   | F      | 

## XOR in de logica
| p   | q   | p XOR q |
| --- | --- | ------ |
| T   | T   | F      |
| T   | F   | T      |
| F   | T   | T      |
| F   | F   | F      |

## Bitwise AND
```C
int a = 16; // 00010000
int b = 21; // 00010101
int c = 4;  // 00000100
int d;
d = a & b ; // 00010000 = 16
```

## Bitwise OR
```C
int a = 16; // 00010000
int b = 21; // 00010101
int c = 4;  // 00000100
int d;
d = a | b ; // 00010101 = 21
```

## Inverse
```C
int a = 16; // 00010000
int b = 21; // 00010101
int c = 4;  // 00000100
int d;
d = ~c ; // 111111011 = 239
```

## Exclusive OR
```C
int a = 16; // 00010000
int b = 21; // 00010101
int c = 4;  // 00000100
int d;
d = a ^ b ; // 00000101 = 5
```

## Shift left
```c
int a = 8; // 00001000
int b = 2; // 00000010

int d;
d = a << b; // 00100000
```

## Shift right
```c
int a = 32; // 00100000
int b = 3; // 00000011

int d;
d = a >> b; // 00000100
```

#Huiswerk 