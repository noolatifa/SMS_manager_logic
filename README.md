# SMS Manager — Data Structures Project in C

My second C project, written in **2021** as a student for my *Algorithmique et Structures de Données 2* course, **without any AI assistance**. It's a console app that simulates a phone's contacts and SMS history, built on hand-written linked lists, array lists and a stack. Kept here as it was originally written (French-language interface).

## Features

- **Contacts:** list and add contacts (name, phone number, email)
- **Message history:** view sent messages with recipient, date, time and price
- **Send a message:** type a message to a contact; it's split into SMS parts automatically
  - plain text: up to 160 chars in one SMS, otherwise split into 153-char parts
  - with special characters: up to 70 chars in one SMS, otherwise split into 67-char parts
  - price: 0.5 per SMS part
- **Input validation:** phone numbers must be 8 digits starting with 2, 5 or 9 (Tunisian format); emails must end in `.com`, `.tn` or `.fr`
- **Analysis functions:**
  - top *m* most frequent words (unigrams) across all messages, returned in a stack
  - most contacted contact
  - contacts never contacted
  - messages sent between two dates
  - longest message

## Data structures

Each type follows the course's layered pattern: `*SDD.h` defines the structure, `*PRIM.h` declares the primitives (create, read, display, copy, compare, destroy), and the `.c` file implements them.

| Module | Holds | Implementation |
|--------|-------|----------------|
| `ELTCON` / `LSTCON` | Contacts | Singly linked list |
| `ELTMSG` / `LSTMSG` | Message history | Doubly linked list (head + tail) |
| `ELTSMS` / `LSTSMS` | SMS parts of one message | Static array list (max 8 parts) |
| `ELT` / `PILE` | Words for the unigram result | Array-based stack |

The contact list and message history start with built-in sample data.

## Build and run

With Code::Blocks: open `projetasd2.cbp`, then **Build & Run**.

With GCC (Windows / MinGW):

```bash
gcc *.c -o sms_manager.exe
sms_manager.exe
```

## Usage

The app shows a menu and runs one operation per launch:

```
1: Repertoire                 6: Test contact le plus contacte
2: Historique messages        7: Test contact jamais contacte
3: Ajout contact              8: Test affichage selon deux dates
4: Envoyer une message        9: Test le plus long message
5: Test unigramme
```

## Note

This is a beginner project. Some logic is rough (for example, the date filter only compares years, and memory isn't always freed). I'm keeping it unchanged as a record of where I was in 2021.