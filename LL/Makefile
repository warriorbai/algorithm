
OBJS  = lltest.o llcpp.o llc.o
HEADERS = llc.h llcpp.h

run: $(OBJS) $(HEADER) 
	g++ $(OBJS) -o run




$(OBJS): %.o: %.cxx
	@echo "Making $@"
	$(CC) -c -o $@ $<

clean:
	@rm -f *.o run 

