docpath=./doc/api

#CFLAGS+=-Wall -Wextra -ansi -pedantic -g -I"$(PWD)/include"
CFLAGS+=-Wall -Wextra -std=c11 -pedantic -g -I"$(PWD)/include"
#CFLAGS+=-DUPO_DEBUG
#CFLAGS+=-DUPO_BST_USE_RECURSIVE_PUT
#CFLAGS+=-DUPO_BST_USE_RECURSIVE_GET
#CFLAGS+=-DUPO_BST_DELETE_BY_MIN
#CFLAGS+=-DUPO_BST_USE_RECURSIVE_TRAVERSAL
#CFLAGS+=-DUPO_HASHTABLE_LINPROB_NEW_STYLE
#LDLIBS+=-lrt
#apps_targets=
#bin_targets=
#test_targets=

export CFLAGS
#export apps_targets
#export bin_targets
#export test_targets

#include mk/*.mk

.PHONY: all apps bin clean doc test more_exercises

all: bin test apps more_exercises

bin:
	cd bin && $(MAKE) all

apps: bin
	cd apps && $(MAKE) all

test: bin
	cd test && $(MAKE) all

more_exercises: 
	cd more_exercises/advanced_pointers && $(MAKE)
	cd more_exercises/cptrs_ex01_ex02_ex03/cptrs-ex01-any_copy && $(MAKE) all
	cd more_exercises/cptrs_ex01_ex02_ex03/cptrs-ex02-binary_search && $(MAKE) all
	cd more_exercises/cptrs_ex01_ex02_ex03/cptrs-ex03-dump_array && $(MAKE) all

doc:
	mkdir -p $(docpath)
	doxygen

clean:
	cd bin && $(MAKE) clean
	cd apps && $(MAKE) clean
	cd test && $(MAKE) clean
	cd more_exercises/cptrs_ex01_ex02_ex03/cptrs-ex01-any_copy && $(MAKE) clean
	cd more_exercises/cptrs_ex01_ex02_ex03/cptrs-ex02-binary_search && $(MAKE) clean
	cd more_exercises/cptrs_ex01_ex02_ex03/cptrs-ex03-dump_array && $(MAKE) clean

doc-clean:
	$(RM) -r $(docpath)

realclean: clean doc-clean
