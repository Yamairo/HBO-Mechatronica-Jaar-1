---
created: 2024-01-11T23:22
updated: 2024-09-05T10:47
---
# Inhoudsopgave
```toc
```

## Hello world

```c
#include <stdio.h>

int main(void){
	printf("Hello world")
	return 0;
}
```

## [[Formatted strings]]
![[Formatted strings]]

## [[Variabele]]
![[Variabele]]

### [[Eisen aan variabele namen]]
![[Eisen aan variabele namen]]

### [[Invoer variable]]
![[Invoer variable]]

---

```c
#include <stdio.h>

int main(void)
{
	int huidig_jaar = 2023;
	int geboortejaar;
	int leeftijd;
	printf("Wat is uw geboortejaar");
	scanf("%d", &geboortejaar);
	leeftijd = huidig_jaar - geboortejaar;
	printf("U bent %d jaar oud. \n", leeftijd);
	return 0;
}
```

## [[Operators]]