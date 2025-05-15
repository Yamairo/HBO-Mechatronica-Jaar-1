---
created: 2024-01-11T23:22
updated: 2024-09-05T11:09
---
# Inhoudsopgave

```toc
```

## Plus , min en keer
```c
int x = 7;
int y = 4;

printf("%d\n", x + y);
printf("%d\n", x - y);
printf("%d\n", x * y);
```

```
11
3
28
```

## Min als [[Operator]] 
```c
int x = -2;
int z = 2 * -x;

printf("%d\n", x + z);
printf("%d\n", x - z);
printf("%d\n", x * z);
```

```
2
-6
-8
```

## Gehele deling
```c
int x = 7;
int y = 2;
int z =-2;

printf("%d\n", x / y);
printf("%d\n", x / z);
```

```
3
-3
```


## Rest (Modulus)
```c
int x = 7;
int y = 2;
int z = -2;

printf("%d\n", x % y);
printf("%d\n", x % z);
```

```
1
1
```

## Gehele deling en modulus 
```c
int x = 7;
int y = 2;

printf("%d\n", (x / y) * y + x % y); // Dit wordt x omdat de een eventuele rest erbij opgeteld wordt 
/* x */
printf("%d\n", (x / y) * y); // Dit wordt x - de rest afhankelijk van of die er is
/* x - x % y */

```

```
7
6

```

## Commentaar

```c
// Beginwaarden van de variabelen 
int invoer = 20;
int uitkomst = 0;
/* De berekening van de resultaten vindt plaats aan het begin omdat ze al bij de controle van de invoer nodig zijn.*/ 
resultaat1 = 2 * invoer + marge;
resultaat2 = invoer + uitkomst;
```

Je kunt met `//` een [[comment]] toevoegen of met `/**/` een multiline [[comment]].

##  [[While]]
![[While]]

## Nummers en namen van pinnetjes
- Op de Arduino zijn alle pins genummerd.
- De pinnen zijn verbonden met de pinnen van de [[AVR]] 
- Pinnetjes zijn gegroepeerd in [[bank]] van elk maximaal acht pinnen.
- Lezen en schrijven vanuit software gaat via registers PA, PB, PC, PD etc.

## Configureer pin

### [[Pinnummer]]
![[Pinnummer]]

### [[Pinout]]
![[Pinout]]

### [[Output pin]]
![[Output pin]]

