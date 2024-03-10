# Variables
CC = clang
SRC_DIR = src
OUT_DIR = out
TARGET = seashell

# Compilation rule
$(OUT_DIR)/$(TARGET): $(SRC_DIR)/main.c
	mkdir -p $(OUT_DIR)
	$(CC) -o $@ $<

.PHONY: run
run: $(OUT_DIR)/$(TARGET)
	$(OUT_DIR)/$(TARGET)

.PHONY: clean
clean:
	rm -rf $(OUT_DIR)
