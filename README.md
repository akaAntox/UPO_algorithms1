UPO alglib
==========

Collection of algorithms and abstract data types developed at the [Computer Science Institute](http://www.di.unipmn.it) of the [University of Piemonte Orientale](http://www.uniupo.it) by [Marco Guazzone](https://github.com/sguazt) for the *Algorithm 1 - Lab* course.

## upo_algorithms1
* [General info](#general-info)
* [Technologies](#technologies)
* [Compile and run](#compile-and-run)

## General info
Collection of algorithms and abstract data types developed at the [Computer Science Institute](http://www.di.unipmn.it) of the [University of Piemonte Orientale](http://www.uniupo.it) by [Marco Guazzone](https://github.com/sguazt) for the *Algorithm 1 - Lab* course.

It includes algorithms in C regarding stack, data sorting, binary search trees, and hash tables.

## Exercises
Project includes:
* C advanced pointers exercises
* Stack exercises
* Queue exercises
* Postfix evaluation with stack
* Sorting algorithms exercises
* Sorting playlist exercises
* Binary search trees (BST) exercises
* Hash tables exercises

## Compile and run
* You need a Unix environment, the gcc compiler and the valgrind debugger to check for possible memory leaks.

To compile and run:
TODO: FIX cptrs ex1 ex2 ex3 (make a single makefile)
* Advanced Pointer (more exercises)
```
$ make clean more_exercises
$ cd ./more_exercises
$ ./advanced_pointers/advanced_pointers
$ cd ./cptrs_ex01_ex02_ex03
$ ./cptrs-ex01-any_copy/any_copy
$ ./cptrs-ex02-binary_search/binary_search
$ ./cptrs-ex03-dump_array/dump_array
```

* Stack exercises
```
$ make clean bin
$ make clean test
$ ./test/test_stack
$ valgrind --tool=memcheck --leak-check=full ./test/test_stack
```

* Postfix eval with stack
```
$ make clean apps
$ ./apps/postfix_eval -f ./data/postfix.txt
$ valgrind --tool=memcheck --leak-check=full ./apps/postfix_eval -f ./data/postfix.txt
```

* Queue exercises
```
$ make clean bin
$ make clean test
$ ./test/test_queue
$ valgrind --tool=memcheck --leak-check=full ./test/test_queue
```

* Sorting algorithms exercises
```
$ make clean bin
$ make clean test
$ ./test/test_sort
$ valgrind --tool=memcheck --leak-check=full ./test/test_sort
```

* Sorting playlist exercises
```
$ make clean apps
$ ./apps/sort_compare -h
$ ./apps/sort_compare -a insertion -a merge -a quick -a stdc -n 10000 -r 3 -s 5489
$ ./apps/sort_playlist_multi -i ./data/playlist_multi.txt -s year -s artist -s album
$ ./apps/sort_playlist_multi -i ./data/playlist_multi.txt -s artist -s year -s album
$ ./apps/sort_playlist_multi -i ./data/playlist_multi.txt -s artist -s album -s year
```

* Binary search trees (BST) exercises
```
$ make clean bin
$ make clean test
$ ./test/test_bst
$ valgrind --tool=memcheck --leak-check=full ./test/test_bst
$ ./test/test_bst_more
$ valgrind --tool=memcheck --leak-check=full ./test/test_bst_more
```

* Hash tables exercises
```
$ make clean bin
$ make clean test
$ ./test/test_hashtable_sepchain
$ valgrind --tool=memcheck --leak-check=full ./test/test_hashtable_sepchain
$ ./test/test_hashtable_linprob
$ valgrind --tool=memcheck --leak-check=full ./test/test_hashtable_linprob
$ ./test/test_hashtable_sepchain_more
$ valgrind --tool=memcheck --leak-check=full ./test/test_hashtable_sepchain_more
$ ./test/test_hashtable_linprob_more
$ valgrind --tool=memcheck --leak-check=full ./test/test_hashtable_linprob_more
```