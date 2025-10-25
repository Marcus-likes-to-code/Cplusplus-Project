# Cplusplus-Project

# Corner Grocer Frequency Tracker

## Project Summary
The Corner Grocer Frequency Tracker is a C++ console application designed to analyze and report the frequency of grocery item purchases from a daily transaction log. It reads an input file containing item names, builds a frequency map, and provides users with the ability to:

- Search for the number of times a specific item was purchased
- Print all item frequencies
- Display a histogram of item frequencies
- Save the frequency data to a backup file (`frequency.dat`)

This project solves the problem of quickly summarizing and visualizing purchase data in a user-friendly and maintainable way.

---

## What Went Well
- **Encapsulation**: All core logic is contained within the `GroceryTracker` class, promoting modularity and reuse.
- **User Experience**: The menu-driven interface is intuitive and includes input validation to handle unexpected user input gracefully.
- **Readable Output**: The histogram is neatly formatted using `setw` and `left` for alignment.
- **Data Persistence**: Automatically writes a backup file to preserve frequency data for future use.

---

## Areas for Enhancement
- **Case Insensitivity**: Normalize item names to lowercase to avoid treating `"Apple"` and `"apple"` as different items.
- **File Error Handling**: Add checks to ensure the input file exists and is readable before processing.
- **Histogram Scaling**: For large datasets, scale the histogram to maintain readability.
- **Sorting Options**: Allow users to sort items alphabetically or by frequency for better data analysis.

These improvements would enhance the program’s robustness, scalability, and user experience.

---

## Challenges and Solutions
The most challenging aspect was implementing robust input validation for the menu system. To address this, I used `cin.fail()` checks and `cin.ignore()` to clear the input buffer and prevent infinite loops or crashes. I also consulted C++ documentation and community forums to refine my approach to stream state management.

To support future development, I’ve added resources like C++ reference sites, Stack Overflow, and zyBooks examples to my toolkit.

---

## Transferable Skills
- **Modular Programming**: Designing reusable classes and methods is applicable to nearly all software development projects.
- **File I/O and Error Handling**: Essential for applications that interact with external data.
- **User Input Validation**: Ensures reliability and a smooth user experience.
- **Data Visualization**: Skills in formatting and presenting data clearly are valuable in analytics and reporting tasks.

---

## Maintainability and Adaptability
- **Clear Naming Conventions**: Descriptive variable and method names make the code self-documenting.
- **Encapsulation**: All item-tracking logic is isolated within a single class, simplifying future updates.
- **Commenting and Structure**: Logical organization and inline comments guide future developers.
- **Scalable Design**: The use of `std::map` allows for efficient lookups and easy feature expansion.

---

## Files
- `CornerGrocerTracker.cpp`: Main program file containing the `GroceryTracker` class and user interface logic.
- `CS210_Project_Three_Input_File.txt`: Input file containing a list of purchased grocery items.
- `frequency.dat`: Output file storing item frequencies for backup and future use.

---

## Getting Started
1. Ensure you have a C++ compiler installed (e.g., g++, clang++).
2. Place `main.cpp` and `CS210_Project_Three_Input_File.txt` in the same directory.
3. Compile the program:
   ```bash
   g++ main.cpp -o GroceryTracker
