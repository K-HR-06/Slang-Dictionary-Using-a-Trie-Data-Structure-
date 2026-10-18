# Data-Structure-AOL-

# Slang Dictionary Using a Trie

A command-line application for managing slang words and their descriptions, created as a Data Structure coursework project.

The project demonstrates how a **trie** can store words, support word lookup, and list entries through recursive traversal.

## Features

- Add a new slang word and its description.
- Update the description of an existing word.
- Search for a slang word and display its description.
- View words starting with a given prefix.
- List all stored slang words.

## Implementation

The program is written in **C++ using C-style structures and functions**.

- A trie stores words and their descriptions.
- Recursive traversal lists all stored words.
- A separate array is scanned to find words matching a prefix.
- Entries are stored in memory for the current session.

## Project Files

| File | Description |
| --- | --- |
| `TugasAOL_DataStructure.cpp` | Main application source code |
| `DOCUMENTATION.pdf` | Code explanations and manual testing screenshots |

## How to Use

Compile the source with a compatible C++ compiler and run the program. Select an option from the menu:

```text
1. Release a new slang word
2. Search a slang word
3. View all slang words starting with a certain prefix word
4. View all slang words
5. Exit
```

When adding a word, enter more than one character without spaces, followed by its description. Entering an existing word updates its description.

Searches are case-sensitive, and stored entries are cleared when the program exits.

## Notes

The search function does not distinguish a complete word from an existing trie prefix. Input validation and memory cleanup also have limitations.

The included documentation shows manual testing of word insertion, word searches, prefix searches, and dictionary listing.

## Author

Marcell Prasetyo  
Computer Science and Statistics — LA06
