---
created: 2023-09-13T11:02
updated: 2023-09-26T13:13
---
# Inhoudsopgave
```toc
```

---

## Terugblik
1. Hoe weet ik aan welke Arduino-pin de led zit?
	- Je kan dit in het [[Schema]] van de shield vinden
2. Hoe weet ik of de [[Spanning]] hoog of laag moet zijn?
	- Dit kan je in het [[Schema]] zien er staat een [[Spanning]]  aangegeven
3. Hoe weet ik aan welke AVR-pin de led zit?
	- Dit kan je vinden op de [[Pinout]] 
4. Hoe weet ik welk bitje in welke bank daabij hoort?
	- 
5. Hoe maken we een pin een [[Output pin]] ?
	- Dit staat in de datasheet van de [[Microcontroller]] 
6. Hoe maken we die pin hoog of laag?
	- Dit kan je vinden in de datasheet van de [[Microcontroller]] 
7. Hoe ziet de werking er schematisch uit?
	-  Dit doe je door je code te ontwerpen
8. Hoe ziet de code eruit?
	- Dit doe je door je code te schrijven 

---

## Operators met een operand
- Een **adresoperator** heeft een operand, namelijk een [[Variabele]] 
- De **minoperator** heeft één of twee operanden, dit is omdat je de min kan gebruiken om een [[int]] negatief te maken of om twee [[int]] van elkaar af te halen.

## Operator met drie operanden
#GeenToetsStof
```c
int a = b;
int b = 8;

//terniere operator
int c = a > b ? a : b;
```

## if, else
```c
int marge = 4;
int snelheid;
scanf("%d", &snelheid);
if (snelheid < 50 + marge)
{
	printf("U krijgt een compliment.\n");
}
else 
{
	printf("U krijgt een bekeuring.\m");
}
```

## Type bool
- C heeft geen [[bool]] [[Operators]] 
- Je kan hiervoor een [[int]] gebruiken 
	- `1` = waar
	- `0` = niet waar


## Oefening
```c
int a = 10;
int b = 5;
int c = 2;

if (a > b) // 10 > 5
{
	a = a + (a - b)/2; // 10 + (10 - 5)/2 = 10 + 5 / 2 = 10 + 2 = 12
}
while ( a > b + c) // 12 > 5 + 2 <=> 12 > 7; 13 > 6 + 4 <=> 13 > 10; 14 > 7 + 6 <=> 14 > 13; 15 !> 8 + 8 <=> 15 !> 16, hier stopt de loop
{
	a = a + 1; // a = 13; a = 14; a = 15
	b = b + 1; // b = 6; b = 7; b = 8
	c = c + 2; // c =  4; c = 6; c = 8
}
/*
a = 15
b = 8
c = 8
*/
```

## Geheugen
```c
int getal
int kwadraat;

//voer een getal in en bewaar het op dat adresoperator 
scanf("%d" &getal);

//bereken dat gta, keer zichzelf
//bewaar uitkoist in een variable
kwadraat = getal * getal;

```

## Nieuw type : [[float]] 

Hier komt `3.0` uit omdat je twee [[int]]  door elkaar deelt
```c
float helft = 7 / 2;// helft = 3.0
```

Hier komt `3.5` uit omdat je een [[float]]  door een [[int]]  deelt
```c
float helft = 7.0 / 2; // helft = 3.5
```

### Format specifier
Om een [[float]] te gebruiken voor [[Formatted strings]]  kun je de `%f` specifier gebruiken 
```c
printf("6.2f", 1.23456789);
```
- [[float]] , 2 decimalen, breedte van zes tekens
- Drie plaatsen nodig voor de pint en twee cijfers erachter
- Een cijfer voor de komma

`%[parameter][flags][width][precision][length]type`

## Getallen die nooit veranderen
```c
float straal;
scanf("%f" &straal);

float omtrek = 6.28 * straal;
printf("De omtrek is %f.\n", omtrek);
```

```c
float straal;
scanf("%f" &straal);

float omtrek = 2 * 3.14 * straal;
printf("De omtrek is %f.\n", omtrek);
```

```c
float pi 3.1415;
float r;
scanf("%f" &straal);

float omtrek = 2 * pi * r;
printf("De omtrek is %f.\n", omtrek);
```

### [[const]]

```c
const float pi 3.1415;
float r;
scanf("%f" &straal);

float omtrek = 2 * pi * r;
printf("De omtrek is %f.\n", omtrek);
```

### [[define]]
```c
#define pi = 3.14; 
float r;
scanf("%f" &straal);

float omtrek = 2 * pi * r;
printf("De omtrek is %f.\n", omtrek);
````

#Huiswerk 