CC= gcc
FLAGS= -Wall -Werror -Wextra
FLAGS_GCOV= -fprofile-arcs -ftest-coverage

ifeq ($(shell uname -s), Darwin)
	FLAGS_TESTS= -lcheck
endif
ifeq ($(shell uname -s), Linux)
	FLAGS_TESTS= -lcheck -lm -lsubunit
endif

DIR_REPORT= ./report
DIR_INFO= ./info

NAME_C_FORLIB= s21_math.c
NAME_O_FORLIB= s21_math.o
NAME_LIB= s21_math.a
NAME_TEST= test_s21_math
NAME_GCOVTEST= gcov_s21_math

SRCS = s21_abs.c\
			s21_ceil.c\
			s21_exp.c\
			s21_fabs.c\
			s21_floor.c\
			s21_fmod.c\
			s21_log.c\
			s21_pow.c\
			s21_sqrt.c\
			s21_acos.c\
			s21_asin.c\
			s21_atan.c\
			s21_cos.c\
			s21_sin.c\
			s21_tan.c\

OBJS		= $(SRCS:.c=.o)

TESTDIR = tests
TEST = $(TESTDIR)/test_s21_math.c\

all: $(NAME_LIB) test gcov_report

$(NAME_LIB): 
	@$(CC) -c $(SRCS) $(FLAGS)
	@ar rcs $(NAME_LIB) $(OBJS)
	@rm -rf *.o

test:
	@$(CC) -o $(NAME_TEST) $(SRCS) $(TEST) $(FLAGS_TESTS) $(FLAGS)


gcov_report:
	@$(CC) -o $(NAME_GCOVTEST) $(SRCS) $(TEST) $(FLAGS_TESTS) $(FLAGS) $(FLAGS_GCOV)
	@chmod +x *
	@./$(NAME_GCOVTEST)
	@mkdir $(DIR_INFO) $(DIR_REPORT)
	@gcov ./* ./
	@mv *.gcno *.gcda *.gcov $(DIR_INFO)/
	@lcov -d $(DIR_INFO) -c -o $(DIR_INFO)/lcov.info
	@genhtml -o $(DIR_REPORT) $(DIR_INFO)/lcov.info
	@open $(DIR_REPORT)/index.html

check: test
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.c *.h */*.c */*.h
	@cp ../materials/linters/.clang-format .clang-format
	clang-format -style=Google -n *.c *.h */*.c */*.h
	clang-format -style=Google -i *.c *.h */*.c */*.h
	@rm -rf .clang-format

clean:
	@rm -rf *.o *.a *.gcno *.gcda *.gcov $(NAME_TEST) $(NAME_GCOVTEST) $(DIR_INFO) $(DIR_REPORT)  


rebuid: clean test