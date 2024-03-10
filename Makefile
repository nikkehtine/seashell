# Variables
CC = clang
SRC_DIR = src
BUILD_DIR = build
OUT_DIR = $(BUILD_DIR)/out
TARGET = seashell
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
HEADER_FILES = $(wildcard $(SRC_DIR)/*.h)
OBJ_DIR = $(BUILD_DIR)/obj
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
FLAGS = -Wall

# Compilation rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_FILES)
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

# Linking rule
$(OUT_DIR)/$(TARGET): $(OBJ_FILES)
	mkdir -p $(OUT_DIR)
	$(CC) $(FLAGS) $^ -o $@

# Run rule
.PHONY: run
run: $(OUT_DIR)/$(TARGET)
	$(OUT_DIR)/$(TARGET)

# Clean rule
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
