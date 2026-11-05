# Studentų Rezultatai v0.3

Šis projektas yra C++ programėlė, skirta tvarkyti studentų rezultatus, skaičiuoti galutinius balus ir palyginti konteinerių efektyvumą testiniuose duomenų rinkiniuose.

## Apžvalga

Programa leidžia:

- rankiniu būdu įvesti studentų duomenis;
- automatiškai sugeneruoti studentų testinius duomenis;
- apskaičiuoti galutinį balą pagal namų darbų ir egzamino rezultatus;
- rūšiuoti studentus pagal vardą, pavardę ar galutinį balą;
- palyginti `std::vector` ir `std::list` veikimą dideliuose duomenų rinkiniuose;
- išsaugoti testavimo rezultatus į failą `rezultatai.md`.

Projektas skirtas mokymosi tikslais ir iliustruoja duomenų apdorojimo, rūšiavimo ir programinės įrangos našumo analizės principus.

## Funkcijos

- rankinis studentų įvedimas;
- atsitiktinių pažymių ir egzamino rezultatų generavimas;
- galutinio balo skaičiavimas;
- rūšiavimas pagal:
  - vardą,
  - pavardę,
  - galutinį balą;
- konteinerių testavimas (`vector` vs `list`);
- rezultatinės lentelės generavimas `rezultatai.md` faile;
- meniu pagrįsta sąsaja konsolėje.

## Reikalavimai

- Windows operacinė sistema;
- Microsoft Visual Studio 2022 arba suderinama MSVC įranga;
- C++20 palaikymas;
- "Desktop development with C++" komponentas.

## Projekto struktūra

Šiame repozitoriume yra pagrindiniai C++ failai ir Visual Studio konfigūracija:

- `main.cpp` – programos pradžia ir meniu;
- `manual.cpp` / `manual.h` – rankinis duomenų įvedimas ir apdorojimas;
- `studentas.cpp` / `studentas.h` – studentų duomenų struktūra ir skaičiavimai;
- `failai.cpp` / `failai.h` – failų generavimas ir skaitymas;
- `results.cpp` / `results.h` – rezultatų išvedimas į lenteles;
- `utils.cpp` / `utils.h` – pagalbinės funkcijos;
- `testai.cpp` / `testai.h` – konteinerių testavimas;
- `StudentuRezultatai.vcxproj` ir `StudentuRezultatai.slnx` – projekto nustatymai.

## Kaip paleisti

1. Atidarykite `StudentuRezultatai.slnx` arba `StudentuRezultatai.vcxproj` Visual Studio.
2. Įsitikinkite, kad projekto nuostatos atitinka C++20 ir MSVC.
3. Sukompiliuokite projektą Debug arba Release režimu.
4. Paleiskite programos vykdomąjį failą.

Taip pat galite paleisti programą iš komandinės eilutės:

```bash
StudentuRezultatai.exe
```

Pasirenkamas argumentas:

```bash
StudentuRezultatai.exe 10000000
```

Šis argumentas nurodo maksimalų sugeneruotų duomenų dydį testavimui.

## Programos naudojimas

Paleidus programą, pasirodo meniu:

- `1` – Rankinis įvedimas
- `2` – Konteinerių testavimas (`vector` vs `list`)
- `0` – Išeiti

### 1. Rankinis įvedimas

Šiame režime vartotojas įveda:

- studento vardą;
- studento pavardę;
- namų darbų pažymius;
- egzamino rezultatą.

Programa automatiškai apskaičiuoja galutinį balą ir atspausdina rezultatų sąrašą.

### 2. Konteinerių testavimas

Šiame režime programa:

- sugeneruoja testinius studentų failus;
- įkrauna duomenis į `std::vector` ir `std::list`;
- palygina jų veikimą,
- rūšiuoja pagal vartotojo pasirinktą kriterijų:
  - vardą,
  - pavardę,
  - galutinį balą;
- sukuria rezultatų ataskaitą failo `rezultatai.md` pavidalu.

## Rezultatų failas

Programos vykdymo metu sukuriamas failas `rezultatai.md`, kuriame pateikiama:

- duomenų skaitymo trukmė;
- galutinių rezultatų skaičiavimo laikas;
- rūšiavimo efektyvumas;
- skaidymas į grupes;
- išvedimo greitis;
- palyginimas tarp `std::vector` ir `std::list`.

## Pastabos

- Programa pritaikyta lietuviškam tekstui, todėl naudojamas UTF-8 kodavimas.
- Kodo struktūra padaryta taip, kad būtų lengviau suvokti C++ konteinerių veikimo skirtumus dideliems duomenų kiekiams.
- Projektas yra gana tinkamas akademiniams darbams, laboratorijoms ir C++ efektyvumo demonstravimo užduotims.

## Santrauka

`Studentų Rezultatai v0.3` yra praktinis C++ projektas, skirtas studentų duomenų valdymui, galutinių balų skaičiavimui ir standartinių konteinerių veikimo analizei. Jo tikslas – parodyti, kaip išduodami studentų rezultatai, rūšiuojami duomenys ir vertinamas programos našumas realiame pavyzdyje.
