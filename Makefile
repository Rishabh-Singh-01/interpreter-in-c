# ---- COMPILER RELATED VARS ---- #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

# --------- OTHER VARS --------- #
OBJ_DIR = ./obj
BIN_DIR = ./bin
EXEC_TARGET = exec
EXEC_TEST_TARGET = test_exec

SRC_DIR = ./src
STD_DIR = ./std
TESTS_DIR = ./tests

# --------- PREPROCESSING PROCESS --------- #
pre: clean init build 

# --------- FINAL PROCESS --------- #
all: pre run

# --------- TESTS PROCESS --------- #
test: pre test_build test_run

# --------- EXECUTABLE BUILD PROCESS --------- #
build: $(OBJ_DIR)/main.o $(OBJ_DIR)/parser.o $(OBJ_DIR)/lexer.o $(OBJ_DIR)/std_files_file.o $(OBJ_DIR)/std_ds_int_auto_list.o $(OBJ_DIR)/std_loggers_log.o $(OBJ_DIR)/std_calendars_date_time.o $(OBJ_DIR)/std_assertions_assert_conditions.o $(OBJ_DIR)/std_assertions_assert_condition.o
	@echo "--------------- Linking and producing the final application --------------------"
	@echo
	$(CC) $(OBJ_DIR)/main.o $(OBJ_DIR)/parser.o $(OBJ_DIR)/lexer.o $(OBJ_DIR)/std_files_file.o $(OBJ_DIR)/std_ds_int_auto_list.o $(OBJ_DIR)/std_loggers_log.o $(OBJ_DIR)/std_calendars_date_time.o $(OBJ_DIR)/std_assertions_assert_conditions.o -o $(BIN_DIR)/$(EXEC_TARGET)
	@echo


$(OBJ_DIR)/main.o: main.c
	@echo "----------------------- Compiling the main file -------------------------------"
	@echo
	$(CC) -c main.c -o $(OBJ_DIR)/main.o
	@echo


$(OBJ_DIR)/parser.o: $(SRC_DIR)/parser/parser.c	
	@echo "------------------------ Compiling the parser file ----------------------------"
	@echo
	$(CC) -c $(SRC_DIR)/parser/parser.c -o $(OBJ_DIR)/parser.o
	@echo


$(OBJ_DIR)/lexer.o: $(SRC_DIR)/lexer/lexer.c	
	@echo "------------------------ Compiling the lexer file ----------------------------"
	@echo
	$(CC) -c $(SRC_DIR)/lexer/lexer.c -o $(OBJ_DIR)/lexer.o
	@echo

$(OBJ_DIR)/std_files_file.o \
$(OBJ_DIR)/std_ds_int_auto_list.o \
$(OBJ_DIR)/std_calendars_date_time.o \
$(OBJ_DIR)/std_loggers_log.o \
$(OBJ_DIR)/std_strings_formatter_str_formatter.o \
$(OBJ_DIR)/std_assertions_assert_condition.o : $(STD_DIR)/data_structures/auto_lists/int_auto_list.c $(STD_DIR)/loggers/log.c $(STD_DIR)/calendars/date_time.c $(STD_DIR)/assertions/assert_conditions.c $(STD_DIR)/strings/formatter/str_formatter.c
	@echo "------------------------ Compiling the std file ----------------------------"
	@echo
	$(CC) -c $(STD_DIR)/files/file.c -o $(OBJ_DIR)/std_files_file.o
	$(CC) -c $(STD_DIR)/data_structures/auto_lists/int_auto_list.c -o $(OBJ_DIR)/std_ds_int_auto_list.o
	$(CC) -c $(STD_DIR)/calendars/date_time.c -o $(OBJ_DIR)/std_calendars_date_time.o
	$(CC) -c $(STD_DIR)/loggers/log.c -o $(OBJ_DIR)/std_loggers_log.o
	$(CC) -c $(STD_DIR)/assertions/assert_conditions.c -o $(OBJ_DIR)/std_assertions_assert_conditions.o
	$(CC) -c $(STD_DIR)/strings/formatter/str_formatter.c -o $(OBJ_DIR)/std_strings_formatter_str_formatter.o
	@echo


# --------- TESTING SUITE ------------ #
test_build: $(OBJ_DIR)/tests_main.o $(OBJ_DIR)/tests_lexer_test.o $(OBJ_DIR)/parser.o $(OBJ_DIR)/lexer.o $(OBJ_DIR)/std_files_file.o $(OBJ_DIR)/std_ds_int_auto_list.o $(OBJ_DIR)/std_loggers_log.o $(OBJ_DIR)/std_calendars_date_time.o $(OBJ_DIR)/std_assertions_assert_conditions.o $(OBJ_DIR)/std_strings_formatter_str_formatter.o
	@echo "--------------- Linking and producing the test application --------------------"
	@echo
	$(CC) $(OBJ_DIR)/tests_main.o $(OBJ_DIR)/tests_lexer_test.o $(OBJ_DIR)/parser.o $(OBJ_DIR)/lexer.o $(OBJ_DIR)/std_files_file.o $(OBJ_DIR)/std_ds_int_auto_list.o $(OBJ_DIR)/std_loggers_log.o $(OBJ_DIR)/std_calendars_date_time.o $(OBJ_DIR)/std_assertions_assert_conditions.o $(OBJ_DIR)/std_strings_formatter_str_formatter.o -o $(BIN_DIR)/$(EXEC_TEST_TARGET)
	@echo

$(OBJ_DIR)/tests_main.o \
$(OBJ_DIR)/tests_lexer_test.o : $(TESTS_DIR)/main.c $(TESTS_DIR)/lexer/test.c 
	@echo "------------------------ Compiling the Test Main files ----------------------------"
	@echo
	$(CC) -c $(TESTS_DIR)/main.c -o $(OBJ_DIR)/tests_main.o
	$(CC) -c $(TESTS_DIR)/lexer/test.c -o $(OBJ_DIR)/tests_lexer_test.o
	@echo




# --------- EXCESS CLEANUP PROCESS --------- #
clean:
	@echo "-------------- Removing all the object files and executable --------------------"
	@echo
	rm -rf $(OBJ_DIR)/ $(BIN_DIR)
	@echo


# --------- PRE CONDN INIT PROCESS --------- #
init:
	@echo "----------------------- Trying to add obj and bin dir --------------------------"
	@echo
	mkdir obj bin
	@echo

# --------- EXECUTABLE RUN PROCESS --------- #
run:
	@echo "------------------------ STARTING THE APPLICATION BELOW -------------------------"
	
	@$(BIN_DIR)/$(EXEC_TARGET)
# --------- EXECUTABLE TEST RUN PROCESS --------- #
test_run:
	@echo "------------------------ STARTING THE TEST BELOW -------------------------"
	@$(BIN_DIR)/$(EXEC_TEST_TARGET)
