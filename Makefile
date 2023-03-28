# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 14:10:40 by jperez            #+#    #+#              #
#    Updated: 2023/03/28 17:48:44 by jperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


define CUBE
                                                                                                             
                                                                                                              
                                                                                                              
                                                                                                              
                                                                                                              
                                                            .,                                                
                                          //////%#/////////////////,                                          
                         ,////(@&#///////////////////&##(///(%%%&&#//////                                     
              &##//////////////////#@%#/////(#&@&%(/////((&%(//////////////////                               
             ,,##@@##///////(#&&#///////(&#(//////////////////(&&#/////////(%&&&%(((.                         
             .,,,,,#%&&@%#%//////////////////@@%(((/((//(((#&%&@@@@@@@@(/////////////////(.                   
             .,,,,,,,&,*%&@@%#%///////////%%#@@@@@@@@////////////////(/((@@&&/////////////(#&#(#              
             .,,,,,,,%,,,,,*%@&@@##%//////////////////(@%&((/////////////(/(((@&@@@@@%#(////((#&%%            
             .,,,,,,,%,,,,,,,,#@#%@@@&%%/////////////////((/@#&%#%%&@@@@&#(/((((&@%%%%/ .. .    .%            
             .,,,,,,,#,,,,,,,,%@,,,,#%@@@&%#%#&@@@@@&%(//(/((&@#%@&&&%%%%(...   %&#..           .%            
             &&@,,,,,(,,,,,,,,%&,,,,,,,,#%@@&&&&&&&%%%%/....*%@&............... %&(.             #            
             ,,#%@@#%@,,,,,,,,%&,,,,,,,,,%&@&... ............&&%........ ...... %&/              #            
             ,,,,,,%%&@,,,,,,,%&,,,,,,,,,%&@&..........  ....&&%..   ...      ..&&*              #            
             ,,,,,,,%@%&@@%,,,%&,,,,,,,,,%&&&...............,&&%  .          ...&&*  ..          (            
             ,,,,,,,,&,,,,#%@@@@#,,,,,,,,%&&&.......      ..*@&%..            .#@&%%    ./%%%%%&%%            
             ,,,,,,,,%,,,,,,,%(@@@#,,,,,*%&&&....  ..    ...%@&%  .       . .%%@@@@@%/#%%%%#.    #            
             ,,,,,,,,%,,,,,,,,%@@%%%%%,,/%&&%........ ....%%@@@@&%%&@@@@#*/(%%%&@@@%             #            
             #*,,,,,,%,,,,,,,,,&@,,,,.%%&%&&&%/%%&@@@#@@&(//&@@@@@%%           .%&%              #            
             ,,,%&,,/&,,,,,,,,,&&,,,,,,,,%%%@%(&%%%%%%,..    %@@%/.             %&%              (            
             ,,,,,,%@@(,,,,,,,,&%,,,,,,,,,%&&&%.              @&%               %&%              (            
             ,,,,,,,%@@%#,,,,,,&#,,,,,,,,,%&&&#.             .@&%               %&%              /            
             ,,,,,,,,&,,,%@#,,%&(,,,,,,,,,%&&&#              .@&%               %&%             %.            
             ,,,,,,,,&,,,,,,%&@@@,,,,,,,,,%&&&(              *@&#              %@@&%. .#%%@@@@%(/             
             *,,,,,,,&,,,,,,,,%@@@%,,,,,,,%&&&*              /@&%           *%@@@@@@//%%%%%/   .%             
                ,,,,,&,,,,,,,,,@%%%%@%,,,,%&&&.             (@@@@%%%%&@@#*/%%%&@@@%/            %             
                  #,,&,,,,,,,,,%,,,,(%%@%#%&&%. .   *%%%&@@@@@@@@%%#,          %&&             .%             
                     &,,,,,,,,,#,,,,,,,(%#@@@@@#(#%%%%%/ ,%%%@&%               %&%              %             
                       .*,,,,,,(,,,,,,,,/%&&%.             .%@&                %&%             .&             
                          %,,,,/,,,,,,,,(%&&&     .         %@%                %&%             .%             
                             %%*,,,,,,,,#%&&%               %@%              ..%&% .       . .%%%             
                               *#,,,,,,,%%&&(              .%@%.         .  . *%@&#%%&&(                      
                                  %,,,,,&%&&*.             .%@&. ......(%&&&&,                                
                                     %,,&%&&.           .. %&@&&&&/                                           
                                       (%&&&/   (%%&&&%.                                                      
                                          ((                                                                  
                                                                                                              
                                                                                                              
                                                                                                              
                                                                                                             
endef
export CUBE

S = srcs/
O = objs/

NAME = cub3D 

F = -fsanitize=address -g3

CC = gcc $(F) 
#CFLAGS = -Wall -Werror -Wextra

RM = -rm -rf


SRC = main.c				\
	   utils/ft_manage_imgs.c		\
	   ft_create_minimap.c			\
	   raycasting/ft_assing_xy_variables.c	\
	   raycasting/ft_raycasting_aux.c	\
	   raycasting/ft_raycasting.c	\
	   raycasting/ft_manage_colisions.c	\
	   raycasting/ft_manage_angles.c	\
	   utils/ft_print_map.c				\
	   utils/ft_save_map.c				\
	   utils/ft_get_next_line.c			\
	   utils/ft_args_len.c				\
	   painting/ft_calculate_viewport.c	\
	   painting/ft_calculate_wall_height.c	\
	   painting/ft_lightning_gun.c				\
	   painting/ft_paint_columns.c			\
	   utils/ft_round_number.c				\


HEADER := cub3D.h
		
WHITE = \033[0;37m
RED = \033[0;31m
CYAN = \033[0;36m
GREEN = \033[0;32m
MAGENTA = \033[0;35m

OBJ := $(SRC:%.c=%.o)

SANI 	:= -fsanitize=address -g3

CC 		:= gcc
#CFLAGS 	:= -Wall  -Wextra -Werror

RM 		:= rm -rf

MLXF	:= -I mlx/libmlx.a -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	@echo "$(GREEN)libft compiled...$(WHITE)"
	$(MAKE) -C mlx 2> logs
	$(RM) logs
	@echo "$(GREEN)MLX compiled...$(WHITE)"
	$(CC) $(SANI) $(CFLAGS) $(MLXF) ./libft/libft.a $(OBJ) -o $(NAME)
	@echo "$(GREEN)Cub3d compiled...$(WHITE)"
	@echo "$(CYAN)$$CUBE$(WHITE)"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

sani: fclean
	$(MAKE) CFLAGS='$(CFLAGS) $(SANI)' all

flagless:
	$(MAKE) CFLAGS='' all

normi:
	norminette $(SRC) $(HEADER)

commit:
	git add $(SRC) $(HEADER) ./Makefile
	git commit -m "commit general"
	git push

test: all
	./Cub3d test.cub
	
clean : 
		$(RM) $(OBJ)
		make clean -C libft
		make clean -C mlx
		@echo "$(RED)clean done...$(WHITE)"

fclean : clean
		$(RM) $(NAME)
		@echo "$(RED)fclean done...$(WHITE)"

re : fclean all

.PHONY : all clean fclean re sani flagless normi commit test
