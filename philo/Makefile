NAME	=	philo
SRCS	=	$(addprefix srcs/, philo.c philo_utils.c parsing_and_init.c testting_funct.c time_manager.c)
TSRCS	=	$(addprefix srcs/, test.c philo_utils.c parsing_and_init.c testting_funct.c time_manager.c)
OBJS	=	${SRCS:%.c=${OBJDIR}/%.o}
CC		=	gcc
CFLAGS	=	-Werror -Wextra -Wall
OBJDIR	=	objets

# Colors and style
END		:= \033[0m
WHITE	:= \033[1;37m
NC		:= \033[0m
PINK	:= \033[1;35m
GREEN	:= \033[32m
BOLD	:= \033[1m
L_PURPLE:= \033[38;5;55m
YELLOW	:= \033[33m
BLUE	:= \033[34m

# Counter for compiled files
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE = 0

all:	${NAME} display_ascii

${NAME}:	${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "${BOLD}${GREEN}📦 Link complete: ${NAME}${END}"

${OBJDIR}/%.o: %.c | ${OBJDIR}
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@printf "${BOLD}${L_PURPLE}⚡ [%2d/%2d] Compiling: %-20s ${END}" $(CURRENT_FILE) $(TOTAL_FILES) "$<"
	@${CC} ${CFLAGS} -c -o $@ $<
	@echo "${BOLD}${GREEN}✓${END}"

${OBJDIR}:
	@mkdir -p ${OBJDIR}
	@mkdir -p ${OBJDIR}/srcs
	@echo "${BOLD}${BLUE}📁 Created objects directory${END}"

test:
	${CC} $(TSRCS) -o test

clean:
	@echo "${BOLD}${YELLOW}🧹 Cleaning objects...${END}"
	@rm -rf ${OBJDIR}
	@echo "${BOLD}${GREEN}✓ Clean complete${END}"

fclean: clean
	@echo "${BOLD}${YELLOW}🗑️  Deep cleaning...${END}"
	@rm -f ${NAME}
	@rm -f a.out
	@echo "${BOLD}${GREEN}✨ All clean ✨${END}"

re: fclean all

.PHONY: all clean fclean re display_ascii

display_ascii:
	@echo "$(BOLD)$(GREEN)"
	@if [ -f ascii_art.txt ]; then \
		cat ascii_art.txt; \
	fi
	@echo "$(END)"
	@echo "${BOLD}${L_PURPLE} ✨Push_Swap✨ ${GREEN}is ready 🎉 ${END}"
	@echo "${BOLD}${BLUE}➜ Use ./${NAME} to run the program${END}"