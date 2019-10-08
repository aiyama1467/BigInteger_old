CFLAGS = -Wall
OBJ_OUTDIR = out/objectfile/
TEST_OUTDIR = out/test/
FILES = add.c sub.c mul.c div.c to_bint.c to_others.c shift.c power.c compare.c
OBJECTS = $(addprefix $(OBJ_OUTDIR), $(FILES:.c=.o))

out/static_libraly/bigInteger.a: $(OBJECTS)
	@if [ ! -d out/static_libraly ]; \
    	then echo "mkdir -p out/static_libraly"; mkdir -p out/static_libraly;  \
    fi
	ar r $@ $(OBJECTS)

# src/atirhmetic/ ---------------------------------------------------
$(OBJ_OUTDIR)add.o: src/arithmetic/add.c
	@if [ ! -d $(OBJ_OUTDIR) ]; \
    	then echo "mkdir -p $(OBJ_OUTDIR)"; mkdir -p $(OBJ_OUTDIR);  \
    fi
	gcc -c -o $@ $<

$(OBJ_OUTDIR)sub.o: src/arithmetic/sub.c
	@if [ ! -d $(OBJ_OUTDIR) ]; \
    	then echo "mkdir -p $(OBJ_OUTDIR)"; mkdir -p $(OBJ_OUTDIR);  \
    fi
	gcc -c -o $@ $<

$(OBJ_OUTDIR)mul.o: src/arithmetic/mul.c
	@if [ ! -d $(OBJ_OUTDIR) ]; \
    	then echo "mkdir -p $(OBJ_OUTDIR)"; mkdir -p $(OBJ_OUTDIR);  \
    fi
	gcc -c -o $@ $<

$(OBJ_OUTDIR)div.o: src/arithmetic/div.c
	@if [ ! -d $(OBJ_OUTDIR) ]; \
    	then echo "mkdir -p $(OBJ_OUTDIR)"; mkdir -p $(OBJ_OUTDIR);  \
    fi
	gcc -c -o $@ $<
# -------------------------------------------------------------------

# src/translation/ --------------------------------------------------
$(OBJ_OUTDIR)to_bint.o: src/translation/to_bint.c
	@if [ ! -d $(OBJ_OUTDIR) ]; \
    	then echo "mkdir -p $(OBJ_OUTDIR)"; mkdir -p $(OBJ_OUTDIR);  \
    fi
	gcc -c -o $@ $<

$(OBJ_OUTDIR)to_others.o: src/translation/to_others.c
	@if [ ! -d $(OBJ_OUTDIR) ]; \
    	then echo "mkdir -p $(OBJ_OUTDIR)"; mkdir -p $(OBJ_OUTDIR);  \
    fi
	gcc -c -o $@ $<
# -------------------------------------------------------------------

# src/other/ --------------------------------------------------------
$(OBJ_OUTDIR)shift.o: src/other/shift.c
	@if [ ! -d $(OBJ_OUTDIR) ]; \
    	then echo "mkdir -p $(OBJ_OUTDIR)"; mkdir -p $(OBJ_OUTDIR);  \
    fi
	gcc -c -o $@ $<

$(OBJ_OUTDIR)power.o: src/other/power.c
	@if [ ! -d $(OBJ_OUTDIR) ]; \
    	then echo "mkdir -p $(OBJ_OUTDIR)"; mkdir -p $(OBJ_OUTDIR);  \
    fi
	gcc -c -o $@ $<

$(OBJ_OUTDIR)compare.o: src/other/compare.c
	@if [ ! -d $(OBJ_OUTDIR) ]; \
    	then echo "mkdir -p $(OBJ_OUTDIR)"; mkdir -p $(OBJ_OUTDIR);  \
    fi
	gcc -c -o $@ $<
# -------------------------------------------------------------------

# test --------------------------------------------------------------
fermat: test/fermat.c out/static_libraly/bigInteger.a
	@if [ ! -d $(TEST_OUTDIR) ]; \
    	then echo "mkdir -p $(TEST_OUTDIR)"; mkdir -p $(TEST_OUTDIR);  \
    fi
	gcc -o $(TEST_OUTDIR)$@.exe test/fermat.c out/static_libraly/bigInteger.a

test: test/test.c out/static_libraly/bigInteger.a
	@if [ ! -d $(TEST_OUTDIR) ]; \
    	then echo "mkdir -p $(TEST_OUTDIR)"; mkdir -p $(TEST_OUTDIR);  \
    fi
	gcc -o $(TEST_OUTDIR)$@.exe test/test.c out/static_libraly/bigInteger.a
# -------------------------------------------------------------------

.PHONY: clean
clean:
	rm -r out
	# rm -f $(OBJ_OUTDIR)*.o out/static_libraly/bigInteger.a $(TEST_OUTDIR)*.exe
