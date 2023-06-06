CC=g++
CFLAGS  = -std=c++17 -Wall
# TARGET = binary_search_first
# TARGET = insertion_sort
# TARGET = merge_sort
# TARGET = find_sum
# TARGET = count_inversion
TARGET = temp

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET)