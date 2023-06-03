# ms:
# 	g++ -std=c++17 -o output ./bin/merge_sort.cpp

# is:
# 	g++ -std=c++17 -o output insertion_sort.cpp

# bs:
# 	g++ -std=c++17 -o output binary_search_first.cpp

# clean:
# 	rm ./bin/*


CC=g++
CFLAGS  = -std=c++17 -Wall
# TARGET = binary_search_first
TARGET = insertion_sort
# TARGET = merge_sort

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET)