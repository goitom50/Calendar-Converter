# Calendar Converter

> A **Programming Language and Paradigm** course project demonstrating date conversion between Ethiopian and Gregorian calendars using C and C++.

## Overview

This project implements bidirectional conversion between Ethiopian (Coptic) and Gregorian calendar systems. Both implementations use the Julian Day Number (JDN) as an intermediate representation for accurate conversion calculations.

## Implementation Details

### C Version (`mCalendarConverter.c`)
- **139 lines** of procedural code
- Two standalone functions: `GCtoEC()` and `ECtoGC()`
- Input validation for month ranges and day limits
- Leap year handling for both calendar systems
- Interactive CLI interface using scanf/printf

### C++ Version (`mCalendarConverter.cpp`)
- **224 lines** leveraging object-oriented design
- Two classes: `EthiopianDate` and `GregorianDate`
- Encapsulated data (day, month, year) with member functions
- Constructor overloading and method chaining
- iostream-based I/O with improved error handling

## Key Algorithms

Both versions use JDN (Julian Day Number) as the conversion intermediary:

1. **Gregorian → JDN**: Complex formula accounting for calendar offsets and leap years
2. **JDN → Ethiopian**: Modular arithmetic using offset `1723856`
3. **Ethiopian → JDN**: Linear calculation with 4-year cycles
4. **JDN → Gregorian**: Reverse transformation with month/day reconstruction

## Quick Start

**Compile C version:**
```bash
gcc mCalendarConverter.c -o converter_c
./converter_c
```

**Compile C++ version:**
```bash
g++ mCalendarConverter.cpp -o converter_cpp
./converter_cpp
```

## Usage Example

Both programs prompt for:
1. Conversion direction (1: EC→GC or 2: GC→EC)
2. Date input in `dd mm yyyy` format
3. Output in the target calendar system

## Paradigm Comparison

| Aspect | C (Procedural) | C++ (OOP) |
|--------|---|---|
| Code Organization | Functions | Classes |
| Data Encapsulation | None | Private/Public |
| Validation | Scattered | Methods |
| Error Handling | printf | cout/exit |
| Reusability | Function-based | Object-based |

## Limitations & Notes

- No range validation for extremely large dates
- Ethiopian calendar assumes 12 months + 1 (Pagume)
- Gregorian calendar validation includes leap year rules
- Basic input/output without file handling

## Course Context

This project was completed for a **Programming Language and Paradigm** course to demonstrate:
- Procedural vs. Object-oriented approaches
- Algorithm implementation across language paradigms
- Date/time calculations and calendar mathematics
- Code structure and maintainability
