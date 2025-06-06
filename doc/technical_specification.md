# Technická specifikace: Invoker Trainer pro Arduino Esplora

## Přehled projektu
Invoker Trainer je tréninkové zařízení pro hráče Dota 2, které pomáhá procvičovat kombinace kouzel postavy Invoker. Projekt je implementován na Arduino Esplora, využívající vestavěné komponenty pro vstup, zobrazení a zvukovou zpětnou vazbu.

## Hardwarová architektura
Projekt využívá následující vestavěné komponenty Arduino Esplora:
- TFT displej (160x128 pixelů) pro vizuální zpětnou vazbu
- 4 tlačítka pro zadávání kouzel (Quas, Wex, Exort, Invoke)
- RGB LED pro vizuální zpětnou vazbu
- Bzučák pro zvukovou zpětnou vazbu
- Joystick pro navigaci v menu

## Datové struktury

### Systém kouzel
```cpp
// Kombinace kouzel (Q=1, W=2, E=3)
const int SPELL_COMBINATIONS[MAX_SPELLS][SPELL_LENGTH] = {
    {1, 1, 1},  // Cold Snap
    {1, 1, 2},  // Ghost Walk
    {1, 1, 3},  // Ice Wall
    {2, 2, 2},  // EMP
    {2, 2, 1},  // Tornado
    {2, 2, 3},  // Alacrity
    {3, 3, 3},  // Sun Strike
    {3, 3, 1},  // Forge Spirit
    {3, 3, 2},  // Chaos Meteor
    {1, 2, 3}   // Deafening Blast
};
```

### Herní stav
Hra používá stavový automat s následujícími stavy:
1. MENU - Počáteční stav pro výběr režimu
2. FREE_TRAINING - Tréninkový režim bez časového limitu
3. TIMED_MODE - Režim s časovým limitem
4. GAME_OVER - Konec hry

## Algoritmy

### Kontrola kombinace kouzel
Algoritmus pro kontrolu kombinací kouzel:
1. Uložení sekvence vstupů hráče
2. Porovnání s aktuální kombinací kouzla
3. Okamžitá zpětná vazba (vizuální a zvuková)
4. Generování nového náhodného kouzla při správné kombinaci

### Výpočet skóre
- FREE_TRAINING: Počítá úspěšná vyvolání kouzel
- TIMED_MODE: Počítá úspěšná kouzla v časovém limitu

## Systém zobrazení
Systém zobrazení používá EsploraTFT s následujícími funkcemi:
- Dvojité vyrovnávací paměti pro prevenci blikání obrazovky
- Sledování stavu pro minimalizaci překreslování
- Víceřádkové zobrazení herních informací
- Barevná zpětná vazba pro úspěch/neúspěch

## Zvukový systém
Zvukový systém využívá vestavěný bzučák s:
- Různými tóny pro úspěch/neúspěch
- Krátkými zvuky, které neruší hru
- Ovládáním hlasitosti pomocí potenciometru Esplora

## Herní režimy

### Tréninkový režim
- Bez časového limitu
- Zaměření na učení kombinací kouzel
- Okamžitá zpětná vazba
- Sledování skóre

### Režim s časovým limitem
- 60sekundový časový limit
- Náhodné generování kouzel
- Skóre založené na rychlosti a přesnosti
- Konec hry po vypršení času

## Uživatelské rozhraní
UI je navrženo intuitivně:
1. Hlavní menu:
   - Název hry
   - Výběr režimu
   - Indikátor aktuálního režimu

2. Herní obrazovka:
   - Název aktuálního kouzla
   - Kombinace vstupů
   - Zobrazení skóre/času
   - Vizuální zpětná vazba (RGB LED)

3. Obrazovka konce hry:
   - Finální skóre
   - Možnost restartu

## Technické výzvy a řešení

### Správa paměti
- Použití PROGMEM pro konstantní data
- Optimalizace ukládání řetězců
- Efektivní správa stavů

### Optimalizace výkonu
- Minimalizace překreslování obrazovky
- Efektivní odrušení tlačítek
- Optimalizovaná generace zvuku

### Uživatelský zážitek
- Okamžitá zpětná vazba na akce
- Jasná vizuální hierarchie
- Intuitivní ovládání

## Plánované vylepšení
1. Přidání úrovní obtížnosti
2. Implementace statistik kouzel
3. Přidání tréninkového režimu pro konkrétní kouzla
4. Ukládání nejlepších skóre
5. Přidání více vizuálních efektů 