## Expenses Command Line Program
> This project is not complete yet.
### Introduction
*Expenses* is a simple command line tool that records, lists, and filters day-to-day expenses. You can add expenses by categories and tags. It's written in the C programming language.

### How to Build
Download the repo and simply run `make` inside the main directory. The program will be built as an executable called `expenses` in the `bin` directory. You can then move the executable to a directory that is in your executable path.

```bash
$ cd expenses
$ make
```

To remove the build, simply run `make clean`.

### How to Add an Expense
You can add an expense with the `add` command. This following command adds 25.5 cents to the expenses for that day.

```bash
$ expenses add 25.5
```

You can associate an expense with a category and a tag with the `-c` and `-t` options, respectively:

```bash
$ expenses add 25.5 -c "groceries" -t "milk"
```

### This Document Will be Updated as I add features

