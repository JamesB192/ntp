/* ntp_scanner.h
 *
 * The header file for a simple lexical analyzer. 
 *
 * Written By: Sachin Kamboj
 *             University of Delaware
 *             Newark, DE 19711
 * Copyright (c) 2006
 */


#define NO_ARG 0 
#define SINGLE_ARG 1
#define MULTIPLE_ARG 2

#define MAXLINE		1024	/* maximum length of line */
#define MAXINCLUDELEVEL	5	/* maximum include file levels */

/* STRUCTURES
 * ----------
 */

/* Define a structure to hold a (keyword, token) pair */
struct key_tok {
    char *keyword;             /* Keyword */
    int token;                 /* Associated Token */
    int expect_string;         /* A boolean flag, which when set, indicates
                                  that the next token should be a string */
};

/* Structure to hold a filename, file pointer and positional info */
struct FILE_INFO {
    char *fname;               /* Path to the file */
    FILE *fd;                  /* File Descriptor */
    int line_no;               /* Line Number in the file being scanned */
    int col_no;                /* Column Number in the file being scanned */
    int prev_line_col_no;      /* Col No on the previous line when a '\n' is
                                  seen */
};


/* SCANNER GLOBAL VARIABLES 
 * ------------------------
 */
extern struct state *key_scanner;   /* A FSA for recognizing keywords */
extern struct config_tree my_config;/* Root of the configuration tree */
extern int curr_include_level;      /* The current include level */

extern struct FILE_INFO *ip_file;   /* Pointer to the configuration file stream */

/* VARIOUS EXTERNAL DECLARATIONS
 * -----------------------------
 */
extern short default_ai_family;
extern int old_config_style;
extern int input_from_file;
extern struct FILE_INFO *fp[MAXINCLUDELEVEL];

/* VARIOUS SUBROUTINE DECLARATIONS
 * -------------------------------
 */
struct state *create_states(char *keyword, 
			    int token, 
			    int expect_string,
			    struct state *pre_state);
struct state *create_keyword_scanner(struct key_tok *keyword_list);
int yylex(void);

struct FILE_INFO *F_OPEN(const char *path, const char *mode);
int FGETC(struct FILE_INFO *stream);
int UNGETC(int ch, struct FILE_INFO *stream);
int FCLOSE(struct FILE_INFO *stream);

void print_keyword_scanner(struct state *, int);
void push_back_char(int ch);
