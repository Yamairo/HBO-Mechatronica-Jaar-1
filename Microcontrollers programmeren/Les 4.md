---
created: 2023-09-20T12:21
updated: 2024-02-02T20:40
---
# Inhoudsopgave
```toc
```

## Maak pin [[Inputs]] 
- DDRx  register (Data Direction Register) bepaalt input/output
- Een 0 op de juiste plaats maakt corresponderende pin input
- Het PINx register kan n uitgelezen worden

```c
DDRF &= ~_BV(PF1);
DDRF &= ~(1 << 1);
```

#Huiswerk 