CFLAGS = -Wall
OBJ_OUTDIR = out/objectfile/
FILES = add.c sub.c mul.c div.c to_bint.c to_others.c shift.c power.c compare.c
OBJECTS = $(addprefix $(OBJ_OUTDIR), $(FILES:.c=.o))

out/static_libraly/bigInteger.a: $(OBJECTS)
	ar r $@ $<

# src/atirhmetic/ ---------------------------------------------------
$(OBJ_OUTDIR)add.o: src/arithmetic/add.c
	gcc -c -o $@ $<

$(OBJ_OUTDIR)sub.o: src/arithmetic/sub.c
	gcc -c -o $@ $<

$(OBJ_OUTDIR)mul.o: src/arithmetic/mul.c
	gcc -c -o $@ $<

$(OBJ_OUTDIR)div.o: src/arithmetic/div.c
	gcc -c -o $@ $<
# -------------------------------------------------------------------

# src/translation/ --------------------------------------------------
$(OBJ_OUTDIR)to_bint.o: src/translation/to_bint.c
	gcc -c -o $@ $<

$(OBJ_OUTDIR)to_others.o: src/translation/to_others.c
	gcc -c -o $@ $<
# -------------------------------------------------------------------

# src/other/ --------------------------------------------------------
$(OBJ_OUTDIR)shift.o: src/other/shift.c
	gcc -c -o $@ $<

$(OBJ_OUTDIR)power.o: src/other/power.c
	gcc -c -o $@ $<

$(OBJ_OUTDIR)compare.o: src/other/compare.c
	gcc -c -o $@ $<
# -------------------------------------------------------------------

.PHONY: clean
clean:
	rm -f $(OBJ_OUTDIR)*.o out/static_libraly/bigInteger.a
