
OBJS  = 1_1.o 1_2.o 2.o test.o 
HEADERS = 1_1.h 1_2.h 2.h common.h

run: $(OBJS) $(HEADER) 
	g++ -g $(OBJS) -o run




$(OBJS): %.o: %.cxx
	@echo "Making $@"
	$(CC) -c -g -o $@ $<

clean:
	@rm -f *.o run 

