/*
** asm.h for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Tue Mar 11 13:13:26 2014 Antoine Buchser
** Last update Thu Apr 10 21:31:57 2014 Antoine Buchser
*/

#ifndef ASM_H_
# define ASM_H_

# define FILE_NOT_READABLE	"File file_name not accessible\n"
# define MALLOC_ERROR		"malloc() failed. Exiting\n"
# define COULDNT_CREATE_FILE	"Couldn't create output file\n"
# define HEX_BASE		"0123456789abcdef"

typedef struct	s_line
{
  char		**wordtab;
  int		move;
  struct s_line	*next;
}		t_line;

typedef struct	s_lab
{
  char		*name;
  int		pos;
  struct s_lab	*next;
}		t_lab;

typedef struct	s_asm
{
  t_line	*content;
  t_lab		*labels;
  char		*filename;
  int		size;
  int		writefd;
  int		readfd;
}		t_asm;

int	usable_file(char*);
char	*remove_space(char*);

void	write_magic_number(t_asm*);
void	write_program_name(t_asm*);
void	write_program_size(t_asm*);
void	write_program_comment(t_asm*);
void	write_program_content(t_asm*);

int	need_args_sum(char*);
int	is_opcode(char*);
op_t	*get_opcode_tab(t_asm*, char*);
int	write_opcode(t_asm*, char*);
void	write_args_sum(t_asm*, char**, int);
void	write_all_params(t_asm*, t_line*, int*, int);
int	write_sti_arg(t_asm*, char*, int, int);
t_line	*get_first_command(t_asm*);
void	write_direct_nb(t_asm*, long);

int	get_pos_jump(t_asm*, char**, int);
int	get_arg_type(char*);
int	is_valid_command(t_asm*, char**, int, int);
int	file_content_is_valid(t_asm*);
int	comment_is_valid(t_asm*);
int	name_is_valid(t_asm*);
int	content_is_valid(t_asm*, t_line*, int, int);

int	labelname_is_valid(char*);
int	validate_labels(t_asm*);
int	is_label(char*);
int	label_exists(t_lab*, char*);
int	save_label(t_asm*, char*, int);
int	get_label_pos(t_asm*, char*);

char	**my_explode(char*, char*);
void	content_put_in_list(t_line**, char**);
int	count_tab(char**);

void	my_putchar_fd(int, int);
void	my_putstr_fd(char*, int);
char	*my_concat(char*, char*);
void	my_error(char*);
char	*get_next_line(int);

#endif /* !ASM_H_ */
