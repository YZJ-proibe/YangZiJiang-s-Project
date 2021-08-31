src = $(wildcard Greed_Snake/*.cpp)
obj = $(patsubst %.cpp, %.o, $(src))
target = app
CC = g++  
$(target): $(obj)
	$(CC) $(obj) -o $(target)

%.o: %.cpp
	$(CC) -c $< -o $@
.PHONY: clean
clean:
	rm -rf $(obj) $(target)