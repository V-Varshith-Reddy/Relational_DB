# Relational Database

## Problem Statement
- Write a C++ program for implementing some functionalities of a Relational database using basic operators from Relational Algebra. A relational database is a database where all data age organised in terms of relations or tables of records or tuples or rows. Relations can be thought of as sets of records.
- Each record is an array of attribute values (also called columns). Finally, the database is a collection of such relations. The attributes in a relation are also described in a schema using attribute names, which are used as keys for various operations on the data in a database. For more details, see: https://en.wikipedia.org/wiki/Relational_database.
- In your program, implement the following classes:
```
class Attr { //Base class for attributes
// Add operators for different attribute type in derived classes
public: virtual bool operator== (const Attr & right) = 0;
…
…
…
};
class Record { //storing data for each record
vector <Attr *> attrptr;
//methods
…
…
};
class Relation { // storing a relation
int natttr, nrecs; // number of attributes and records
vector <string> attrnames; // schema
vector <int> attrinds; // mapping schema to indices
list <Record *> recs; // list of records
// methods
…
…
};
```

Relational algebra (https://en.wikipedia.org/wiki/Relational_algebra) describes 5 fundamental operations, each creating a new relation object from one or two. These operations can be used to build more complex transformations on relational data.
1. Union: All records of both R1 and R2.
`Relation * union(Relation * R1, Relation * R2)`
2. Difference: Records in `R1` but not in `R2`
`Relation * difference (Relation * R1, Relation * R2)`
3. Cartesian Product: All possible pairs of records from `R1` and `R2`
`Relation * catersianproduct(Relation * R1, Relation * R2)`
4. Projection: New relation with a subset of columns
`Relation * projection(Relation * R1, list<string> projectattrs)`
5. Selection: New relation with a subset of records matching a boolean
expression in the attribute values in disjunctive normal form.
`Relation * union (Relation * R1, DNFformula * f)` where
`struct DNFformula { list(list(tuple(string, char, Attr *) ) ) ops; }` is a list of list of tuples with each tuple representing a comparison.
The top level list stores dis-junctions of clauses, each of which represents a list
of conjunctions of comparisons. For simplicity assume that there are no
negations.S
6. Rename: rename an attribute in schema
`Relation * difference (Relation * R1, string s1, string s2)`

### Task 1
---
Implement the above 6 functionalities assuming that the generic
comparison operators `(==, !=, <, <=, >, >=)` have been overloaded for each `Attr`
object. Although the prototypes given here are non-member functions, implement the
functionalities and member functions, when appropriate.

### Task 2
---
- Implement some common Attribute types, e.g. `integerAttribute`, `floatAttribute`, `stringAttribute`, etc. and overload the operators appropriately. Also, implement the natural join operator using the above implemented primitive operations: `Relation * naturaljoin(Relation * R1, Relation * R2, list<string> joinattr)`.
- The list of names in `joinattr` should be attribute names in both `R1` and `R2`, and are the join attributes. See the excerpt below for hints on how to implement (source: https://en.wikipedia.org/wiki/Relational_algebra).

### Task 3
---
Provide a simple console based user interface which provides the following functionalities using the above developed ***library***:
• Create a new empty table: the user can interactively enter the schema.
• Delete an existing table with all data in it.
• Add a record to a table.
• Print a table in appropriate format.
• Create a table from existing tables using the above developed operations.

### Submission
---
Divided the code into the following:    
• A header file (`rdb.h`) which has all the Library API.    
• A c++ file (`rdb-basics.cpp`) with implementations of all the basic operators.   
• A c++ file (`rdb-join.cpp`) with implementation of the join operation.     
• A c++ file (`rdb-attr.cpp`) with implementations of all supported attribute types.      
• A c++ file (`rdb-main.cpp`) with implementation of the UI.

## Code
### Files
---
The code is present in the directory [A3](./A3).
```bash
A3
├── a.out
├── assignment-3.pdf
├── rdb_basics.cpp
├── rdb.h
├── rdb_join.cpp
└── rdb_main.cpp
```

### Run the code
---
The main UI is available for use in terminal, when you run the [rdb_main.cpp](./A3/rdb_main.cpp). 
To run the code:
- Change directory to `A3`: `cd ./A3`
- `g++ rdb_main.cpp -o a.out`
- `./a.out`

```bash
$ cd ./A3/
$ g++ rdb_main.cpp -o a.out
$ ./a.out

Enter 1 : to Create a new empty table
Enter 2 : to Delete an existing table
Enter 3 : to add a record  to a table
Enter 4 : to print a table in the appropriate format
Enter 5 : to Create a new table using Union
Enter 6 : to Create a new table using Difference 
Enter 7 : to Create a new table using Cartesian Product
Enter 8 : to Create a new table using Projection
Enter 9 : to Rename an existing table using Rename
Enter 10 : to Create a new table using Natural Join
Enter 11 : to print the current number of existing tables
Enter 0 : to exit

Enter the value:

```
