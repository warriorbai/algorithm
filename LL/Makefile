
OBJS  = lltest.o llcpp.o llc.o

run: $(OBJS) 
	g++ $(OBJS) -o run




$(OBJS): %.o: %.cxx
        @echo "Making $@"
        $(CC) -c -o $@ $<

clean:
	@rm -f *.o run 

