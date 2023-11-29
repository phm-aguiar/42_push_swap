NAME = push_swap
LIBFT = libs/libft/libft.a
CFLAGS = -Wall -Wextra -Werror -O3 -g3

LIBFT_PATH = libs/libft
OBJ_PATH = bin/
SRC_PATH = src/
TEMP = temp/

GREEN = \033[1;32m
RED = \033[1;31m
CYAN = \033[1;35m
RESET = \033[0m

CFILES = main.c \
		stacks.c\
		check_duplicate.c\
		ft_error.c\


OBJECTS = $(addprefix $(OBJ_PATH), $(CFILES:.c=.o))

INCLUDES = -I ./includes

all: libft $(OBJ_PATH) $(NAME)

libft:
	@make -C $(LIBFT_PATH) --no-print-directory


$(NAME): $(OBJECTS)
	@printf "\n$(CYAN)Creating $(NAME)$(RESET)\n\n"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME) $(INCLUDES)

$(OBJECTS): $(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "$(GREEN)Compiling $(notdir $(<))$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@if [ -d $(OBJ_PATH) ]; then \
		printf "$(RED)Cleaning $(OBJ_PATH)$(RESET)\n"; \
		rm -f $(OBJECTS) -r $(OBJ_PATH); \
	fi
	@make -C $(LIBFT_PATH) clean --no-print-directory

fclean: clean
	@printf "$(RED)Cleaning $(NAME)$(RESET)\n"
	@rm -rf $(NAME)
	@if [ -d $(TEMP) ]; then \
		printf "$(RED)Cleaning $(TEMP)$(RESET)\n"; \
		rm -rf $(TEMP) \
	@make -C $(LIBFT_PATH) fclean --no-print-directory

re: fclean all
	@make all --no-print-directory

$(TEMP):
	@mkdir -p $(TEMP)
valgrind_500: $(TEMP)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=temp/valgrind-out.txt \
	-s ./push_swap 964 674 8 717 299 169 837 501 233 523 109 903 912 906 206 363 571 780 226 547 64 106 59 472 935 395 643 957 205 767 401 642 229 506 54 608 338 148 666 612 633 844 225 56 488 141 314 320 339 180 270 326 761 411 589 987 529 247 601 158 827 257 139 127 18 457 260 242 796 556 454 304 288 738 387 355 505 \
	2 345 709 208 777 250 415 813 73 699 376 915 94 737 660 513 828 775 944 861 48 755 412 49 428 541 587 853 258 850 436 40 779 792 220 990 203 948 624 463 503 528 929 219 129 377 951 58 568 809 319 954 307 276 789 985 797 322 819 100 879 455 424 150 408 725 623 498 81 171 770 496 800 88 311 869 458 787 540 791 69 25 \
	215 537 782 829 218 165 961 731 350 393 671 510 722 431 824 965 213 484 279 697 818 274 533 657 685 891 256 277 296 267 461 955 878 820 52 467 273 855 107 318 398 889 923 692 378 680 365 569 871 80 804 259 526 400 870 927 426 168 298 969 652 177 228 936 778 911 632 525 372 196 833 504 742 308 465 184 301 991 450 353 \
	667 113 243 838 268 516	1000 560 13 300 577 278 382 644 61 621 507 822 38 70 872 641 609 836 535 68 749 120 988 483 333 606 729 721 20 97 634 114 593 873 995 255 821 153 637 522  9 600 500 710 432 596 842  3 123 626 708 639 163  5 397 144 975 434 313 551 245 214 953 530 776 310 244 977 548 663 649 874 75 997 14 104 840 \
	204 704 137 418 830 684 285 536 733 650 893 53 759 802 263 846 480 231 905 744 877 817 552 942 179 93 82 786 427 695 76 515 883 251 146 477 950 619 914 448 369 586 499 31 939 926 261 92 329 23 712 763 354 340 489 33 305 971 349 967 128 55 290 689 557 364 982 366 371 493 654 117 167 620 945 781 193 766 497 442 894 392 495 \
	170 417 520 187 421 174 239 178 920 447 388 597 441 897 698 898 111 351 669 149 555 24 344 892 202 391 544 361 595 760 659 216 832 237 403  6 85 11 190 627 221 471 598 152 334 882 275 99 201 154 602 992 438 665 62 974 280 384 468 607 443 211 572 367 223 956 420 750 451 272 648 981 45 679 558 198 543 336 687 446 562 312 235 \
	611 968 306 156 217 140 550 826 715 37 754 705

valgrind_100: $(TEMP)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=temp/valgrind-out.txt \
	-s ./push_swap 964 674 8 717 299 169 837 501 233 523 109 903 912 906 206 363 571 780 226 547 64 106 59 472 935 395 643 957 205 767 401 642 229 506 54 608 338 148 666 612 633 844 225 56 488 141 314 320 339 180 270 326 761 411 589 987 529 247 601 158 827 257 139 127 18 457 260 242 796 556 454 304 288 738 387 355 505 \
	2 345 709 208 777 250 415 813 73 699 376 915 94 737 660 513 828 775 944 861 48 755 412

valgrind_15: $(TEMP)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=temp/valgrind-out.txt \
	-s ./push_swap 964 674 8 717 299 144 122 111 212 124 542 875 654 564 852

duplicate: $(TEMP)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=temp/valgrind-out.txt \
	-s ./push_swap 964 674 8 717 299 8

invalide: $(TEMP)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=temp/valgrind-out.txt \
	-s ./push_swap a b c d e f


.PHONY: all clean fclean re libft valgrind_500 valgrind_100 valgrind_5 duplicate invalide