
OBJS  = 1_1.o test.o 
HEADERS = 1_1.h common.h

run: $(OBJS) $(HEADER) 
	g++ $(OBJS) -o run




$(OBJS): %.o: %.cxx
	@echo "Making $@"
	$(CC) -c -o $@ $<

clean:
	@rm -f *.o run 

