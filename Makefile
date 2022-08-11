# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 14:23:03 by fmauguin          #+#    #+#              #
#    Updated: 2022/08/11 15:03:02 by fmauguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL				=	/bin/sh

PROGNAME			:=	ft_containers

INCLUDEDIR			:=	vector/includes map/includes stack/includes
SRCDIR				:=	./

OBJDIR				:=	./obj
DEBUGDIR			:=	./debugobj

CPPSRC				:=	main.cpp
VECTORSRC			:=	$(addprefix vector/srcs/, Vector.cpp \
						)

CC					:=	c++
RM					:=	rm

CCFLAGS				:=	-Wall -Wextra -Werror
LIBFLAGS			:=
OPTFLAG				:= -std=c++98

NAME				:=	$(PROGNAME)

OUTDIR				:=	$(OBJDIR)

DEBUGNAME			:= $(addsuffix .debug,$(PROGNAME))

ifdef DEBUG
	OPTFLAG 		:=	-g
	LIBFT			:=	$(addsuffix .debug,$(LIBFT))
	NAME			:=	$(DEBUGNAME)
	BONUSNAME		:=	$(BONUSDEBUGNAME)
	OUTDIR			:=	$(DEBUGDIR)
endif

$(OUTDIR)/%.o		:	$(SRCDIR)/%.cpp | $(OUTDIR)
	@mkdir -p $(dir $@)
	$(CC) -c -MMD -MP $(CCFLAGS) $(OPTFLAG) $(addprefix -I ,$(INCLUDEDIR)) $< -o $@

$(NAME)				:	$(addprefix $(OUTDIR)/,$(CPPSRC:.cpp=.o)) $(addprefix $(OUTDIR)/,$(VECTORSRC:.cpp=.o))
	$(CC) $(CCFLAGS) $(OPTFLAG) -o $(NAME) $(addprefix $(OUTDIR)/,$(CPPSRC:.cpp=.o)) $(addprefix $(OUTDIR)/,$(VECTORSRC:.cpp=.o)) $(LIBFLAGS)

all					:	$(NAME)

$(DEBUGNAME)		:
ifndef DEBUG
	$(MAKE) $(DEBUGNAME) DEBUG=1
endif

ifdef DEBUG
$(PROGNAME)			:	$(NAME)
endif

debug				:
ifndef DEBUG
	$(MAKE) DEBUG=1
endif

$(OUTDIR)			:
	mkdir $(OUTDIR)

clean				:
	$(RM) -rf $(OBJDIR);

fclean				:	clean
	$(RM) -f $(PROGNAME) $(DEBUGNAME)

re					:	fclean
	$(MAKE) $(NAME)

.PHONY				:	all bonus clean fclean re

-include	$(addprefix $(OUTDIR)/,$(CPPSRC:.cpp=.d))
-include	$(addprefix $(OUTDIR)/,$(VECTORSRC:.cpp=.d))
