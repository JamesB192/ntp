/*
 *  28 bit character mapping generated 04/07/12 12:39:37
 *
 *  This file contains the character classifications
 *  used by AutoGen and AutoOpts for identifying tokens.
 *  The table is static scope, so %guard is empty.
 *
 *  This file is part of AutoGen.
 *  Copyright (c) 1992-2012 Bruce Korb - all rights reserved
 *
 *  AutoGen is free software: you can redistribute it and/or modify it under the
 *  terms of the GNU General Public License as published by the Free Software
 *  Foundation, either version 3 of the License, or (at your option) any later
 *  version.
 *
 *  AutoGen is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 *  A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef AG_CHAR_MAP_H_GUARD
#define AG_CHAR_MAP_H_GUARD 1

#ifdef HAVE_CONFIG_H
# if defined(HAVE_INTTYPES_H)
#   include <inttypes.h>

# elif defined(HAVE_STDINT_H)
#   include <stdint.h>

# elif !defined(HAVE_UINT32_T)
#   if SIZEOF_INT == 4
      typedef unsigned int    uint32_t;
#   elif SIZEOF_LONG == 4
      typedef unsigned long   uint32_t;
#   endif
# endif /* HAVE_*INT*_H header */

#else /* not HAVE_CONFIG_H -- */
# include <inttypes.h>
#endif /* HAVE_CONFIG_H */

#if 0 /* mapping specification source (from autogen.map) */
// 
// %guard
// %file           ag-char-map.h
// %backup
// 
// %comment -- see above
// %
// 
// newline         "\n"
// nul-byte        "\x00"
// dir-sep         "/\\"
// percent         "%"
// comma           ","
// colon           ":"
// underscore      "_"
// plus            "+"
// dollar          "$"
// 
// horiz-white     "\t "
// alt-white       "\v\f\r\b"
// whitespace      +horiz-white  +newline +alt-white
// non-nl-white    +horiz-white  +alt-white
// quote           "'\""
// parentheses     "()"
// 
// graphic         "!-~"
// inversion       "~-"
// oct-digit       "0-7"
// dec-digit       "89"          +oct-digit
// hex-digit       "a-fA-F"      +dec-digit
// lower-case      "a-z"
// upper-case      "A-Z"
// alphabetic      +lower-case   +upper-case
// alphanumeric    +alphabetic   +dec-digit
// var-first       +underscore   +alphabetic
// variable-name   +var-first    +dec-digit
// option-name     "^-"          +variable-name
// value-name      +colon        +option-name
// name-sep        "[.]"
// compound-name   +value-name   +name-sep +horiz-white
// scheme-note     +parentheses  +quote
// 
// unquotable      "!-~"         -"#,;<=>[\\]`{}?*" -quote -parentheses
// end-xml-token   "/>"          +whitespace
// plus-n-space    +plus         +whitespace
// punctuation     "!-~"         -alphanumeric -"_"
// suffix          "-._"         +alphanumeric
// suffix-fmt      +percent      +suffix +dir-sep
// false-type      "nNfF0"       +nul-byte
// file-name       +dir-sep      +suffix
// end-token       +nul-byte     +whitespace
// end-list-entry  +comma        +end-token
// set-separator   "|+"          +end-list-entry
// signed-number   +inversion    +dec-digit
// make-script     +dollar       +newline
//
#endif /* 0 -- mapping spec. source */


typedef uint32_t ag_char_map_mask_t;

#define  IS_NEWLINE_CHAR( _c)          is_ag_char_map_char((char)( _c), 0x0000001)
#define SPN_NEWLINE_CHARS(_s)         spn_ag_char_map_chars((char *)_s, 0x0000001)
#define BRK_NEWLINE_CHARS(_s)         brk_ag_char_map_chars((char *)_s, 0x0000001)
#define SPN_NEWLINE_BACK(s,e)         spn_ag_char_map_back((char *)s, (char *)e, 0x0000001)
#define BRK_NEWLINE_BACK(s,e)         brk_ag_char_map_back((char *)s, (char *)e, 0x0000001)
#define  IS_NUL_BYTE_CHAR( _c)         is_ag_char_map_char((char)( _c), 0x0000002)
#define SPN_NUL_BYTE_CHARS(_s)        spn_ag_char_map_chars((char *)_s, 0x0000002)
#define BRK_NUL_BYTE_CHARS(_s)        brk_ag_char_map_chars((char *)_s, 0x0000002)
#define SPN_NUL_BYTE_BACK(s,e)        spn_ag_char_map_back((char *)s, (char *)e, 0x0000002)
#define BRK_NUL_BYTE_BACK(s,e)        brk_ag_char_map_back((char *)s, (char *)e, 0x0000002)
#define  IS_DIR_SEP_CHAR( _c)          is_ag_char_map_char((char)( _c), 0x0000004)
#define SPN_DIR_SEP_CHARS(_s)         spn_ag_char_map_chars((char *)_s, 0x0000004)
#define BRK_DIR_SEP_CHARS(_s)         brk_ag_char_map_chars((char *)_s, 0x0000004)
#define SPN_DIR_SEP_BACK(s,e)         spn_ag_char_map_back((char *)s, (char *)e, 0x0000004)
#define BRK_DIR_SEP_BACK(s,e)         brk_ag_char_map_back((char *)s, (char *)e, 0x0000004)
#define  IS_PERCENT_CHAR( _c)          is_ag_char_map_char((char)( _c), 0x0000008)
#define SPN_PERCENT_CHARS(_s)         spn_ag_char_map_chars((char *)_s, 0x0000008)
#define BRK_PERCENT_CHARS(_s)         brk_ag_char_map_chars((char *)_s, 0x0000008)
#define SPN_PERCENT_BACK(s,e)         spn_ag_char_map_back((char *)s, (char *)e, 0x0000008)
#define BRK_PERCENT_BACK(s,e)         brk_ag_char_map_back((char *)s, (char *)e, 0x0000008)
#define  IS_COMMA_CHAR( _c)            is_ag_char_map_char((char)( _c), 0x0000010)
#define SPN_COMMA_CHARS(_s)           spn_ag_char_map_chars((char *)_s, 0x0000010)
#define BRK_COMMA_CHARS(_s)           brk_ag_char_map_chars((char *)_s, 0x0000010)
#define SPN_COMMA_BACK(s,e)           spn_ag_char_map_back((char *)s, (char *)e, 0x0000010)
#define BRK_COMMA_BACK(s,e)           brk_ag_char_map_back((char *)s, (char *)e, 0x0000010)
#define  IS_COLON_CHAR( _c)            is_ag_char_map_char((char)( _c), 0x0000020)
#define SPN_COLON_CHARS(_s)           spn_ag_char_map_chars((char *)_s, 0x0000020)
#define BRK_COLON_CHARS(_s)           brk_ag_char_map_chars((char *)_s, 0x0000020)
#define SPN_COLON_BACK(s,e)           spn_ag_char_map_back((char *)s, (char *)e, 0x0000020)
#define BRK_COLON_BACK(s,e)           brk_ag_char_map_back((char *)s, (char *)e, 0x0000020)
#define  IS_UNDERSCORE_CHAR( _c)       is_ag_char_map_char((char)( _c), 0x0000040)
#define SPN_UNDERSCORE_CHARS(_s)      spn_ag_char_map_chars((char *)_s, 0x0000040)
#define BRK_UNDERSCORE_CHARS(_s)      brk_ag_char_map_chars((char *)_s, 0x0000040)
#define SPN_UNDERSCORE_BACK(s,e)      spn_ag_char_map_back((char *)s, (char *)e, 0x0000040)
#define BRK_UNDERSCORE_BACK(s,e)      brk_ag_char_map_back((char *)s, (char *)e, 0x0000040)
#define  IS_PLUS_CHAR( _c)             is_ag_char_map_char((char)( _c), 0x0000080)
#define SPN_PLUS_CHARS(_s)            spn_ag_char_map_chars((char *)_s, 0x0000080)
#define BRK_PLUS_CHARS(_s)            brk_ag_char_map_chars((char *)_s, 0x0000080)
#define SPN_PLUS_BACK(s,e)            spn_ag_char_map_back((char *)s, (char *)e, 0x0000080)
#define BRK_PLUS_BACK(s,e)            brk_ag_char_map_back((char *)s, (char *)e, 0x0000080)
#define  IS_DOLLAR_CHAR( _c)           is_ag_char_map_char((char)( _c), 0x0000100)
#define SPN_DOLLAR_CHARS(_s)          spn_ag_char_map_chars((char *)_s, 0x0000100)
#define BRK_DOLLAR_CHARS(_s)          brk_ag_char_map_chars((char *)_s, 0x0000100)
#define SPN_DOLLAR_BACK(s,e)          spn_ag_char_map_back((char *)s, (char *)e, 0x0000100)
#define BRK_DOLLAR_BACK(s,e)          brk_ag_char_map_back((char *)s, (char *)e, 0x0000100)
#define  IS_HORIZ_WHITE_CHAR( _c)      is_ag_char_map_char((char)( _c), 0x0000200)
#define SPN_HORIZ_WHITE_CHARS(_s)     spn_ag_char_map_chars((char *)_s, 0x0000200)
#define BRK_HORIZ_WHITE_CHARS(_s)     brk_ag_char_map_chars((char *)_s, 0x0000200)
#define SPN_HORIZ_WHITE_BACK(s,e)     spn_ag_char_map_back((char *)s, (char *)e, 0x0000200)
#define BRK_HORIZ_WHITE_BACK(s,e)     brk_ag_char_map_back((char *)s, (char *)e, 0x0000200)
#define  IS_ALT_WHITE_CHAR( _c)        is_ag_char_map_char((char)( _c), 0x0000400)
#define SPN_ALT_WHITE_CHARS(_s)       spn_ag_char_map_chars((char *)_s, 0x0000400)
#define BRK_ALT_WHITE_CHARS(_s)       brk_ag_char_map_chars((char *)_s, 0x0000400)
#define SPN_ALT_WHITE_BACK(s,e)       spn_ag_char_map_back((char *)s, (char *)e, 0x0000400)
#define BRK_ALT_WHITE_BACK(s,e)       brk_ag_char_map_back((char *)s, (char *)e, 0x0000400)
#define  IS_WHITESPACE_CHAR( _c)       is_ag_char_map_char((char)( _c), 0x0000601)
#define SPN_WHITESPACE_CHARS(_s)      spn_ag_char_map_chars((char *)_s, 0x0000601)
#define BRK_WHITESPACE_CHARS(_s)      brk_ag_char_map_chars((char *)_s, 0x0000601)
#define SPN_WHITESPACE_BACK(s,e)      spn_ag_char_map_back((char *)s, (char *)e, 0x0000601)
#define BRK_WHITESPACE_BACK(s,e)      brk_ag_char_map_back((char *)s, (char *)e, 0x0000601)
#define  IS_NON_NL_WHITE_CHAR( _c)     is_ag_char_map_char((char)( _c), 0x0000600)
#define SPN_NON_NL_WHITE_CHARS(_s)    spn_ag_char_map_chars((char *)_s, 0x0000600)
#define BRK_NON_NL_WHITE_CHARS(_s)    brk_ag_char_map_chars((char *)_s, 0x0000600)
#define SPN_NON_NL_WHITE_BACK(s,e)    spn_ag_char_map_back((char *)s, (char *)e, 0x0000600)
#define BRK_NON_NL_WHITE_BACK(s,e)    brk_ag_char_map_back((char *)s, (char *)e, 0x0000600)
#define  IS_QUOTE_CHAR( _c)            is_ag_char_map_char((char)( _c), 0x0000800)
#define SPN_QUOTE_CHARS(_s)           spn_ag_char_map_chars((char *)_s, 0x0000800)
#define BRK_QUOTE_CHARS(_s)           brk_ag_char_map_chars((char *)_s, 0x0000800)
#define SPN_QUOTE_BACK(s,e)           spn_ag_char_map_back((char *)s, (char *)e, 0x0000800)
#define BRK_QUOTE_BACK(s,e)           brk_ag_char_map_back((char *)s, (char *)e, 0x0000800)
#define  IS_PARENTHESES_CHAR( _c)      is_ag_char_map_char((char)( _c), 0x0001000)
#define SPN_PARENTHESES_CHARS(_s)     spn_ag_char_map_chars((char *)_s, 0x0001000)
#define BRK_PARENTHESES_CHARS(_s)     brk_ag_char_map_chars((char *)_s, 0x0001000)
#define SPN_PARENTHESES_BACK(s,e)     spn_ag_char_map_back((char *)s, (char *)e, 0x0001000)
#define BRK_PARENTHESES_BACK(s,e)     brk_ag_char_map_back((char *)s, (char *)e, 0x0001000)
#define  IS_GRAPHIC_CHAR( _c)          is_ag_char_map_char((char)( _c), 0x0002000)
#define SPN_GRAPHIC_CHARS(_s)         spn_ag_char_map_chars((char *)_s, 0x0002000)
#define BRK_GRAPHIC_CHARS(_s)         brk_ag_char_map_chars((char *)_s, 0x0002000)
#define SPN_GRAPHIC_BACK(s,e)         spn_ag_char_map_back((char *)s, (char *)e, 0x0002000)
#define BRK_GRAPHIC_BACK(s,e)         brk_ag_char_map_back((char *)s, (char *)e, 0x0002000)
#define  IS_INVERSION_CHAR( _c)        is_ag_char_map_char((char)( _c), 0x0004000)
#define SPN_INVERSION_CHARS(_s)       spn_ag_char_map_chars((char *)_s, 0x0004000)
#define BRK_INVERSION_CHARS(_s)       brk_ag_char_map_chars((char *)_s, 0x0004000)
#define SPN_INVERSION_BACK(s,e)       spn_ag_char_map_back((char *)s, (char *)e, 0x0004000)
#define BRK_INVERSION_BACK(s,e)       brk_ag_char_map_back((char *)s, (char *)e, 0x0004000)
#define  IS_OCT_DIGIT_CHAR( _c)        is_ag_char_map_char((char)( _c), 0x0008000)
#define SPN_OCT_DIGIT_CHARS(_s)       spn_ag_char_map_chars((char *)_s, 0x0008000)
#define BRK_OCT_DIGIT_CHARS(_s)       brk_ag_char_map_chars((char *)_s, 0x0008000)
#define SPN_OCT_DIGIT_BACK(s,e)       spn_ag_char_map_back((char *)s, (char *)e, 0x0008000)
#define BRK_OCT_DIGIT_BACK(s,e)       brk_ag_char_map_back((char *)s, (char *)e, 0x0008000)
#define  IS_DEC_DIGIT_CHAR( _c)        is_ag_char_map_char((char)( _c), 0x0018000)
#define SPN_DEC_DIGIT_CHARS(_s)       spn_ag_char_map_chars((char *)_s, 0x0018000)
#define BRK_DEC_DIGIT_CHARS(_s)       brk_ag_char_map_chars((char *)_s, 0x0018000)
#define SPN_DEC_DIGIT_BACK(s,e)       spn_ag_char_map_back((char *)s, (char *)e, 0x0018000)
#define BRK_DEC_DIGIT_BACK(s,e)       brk_ag_char_map_back((char *)s, (char *)e, 0x0018000)
#define  IS_HEX_DIGIT_CHAR( _c)        is_ag_char_map_char((char)( _c), 0x0038000)
#define SPN_HEX_DIGIT_CHARS(_s)       spn_ag_char_map_chars((char *)_s, 0x0038000)
#define BRK_HEX_DIGIT_CHARS(_s)       brk_ag_char_map_chars((char *)_s, 0x0038000)
#define SPN_HEX_DIGIT_BACK(s,e)       spn_ag_char_map_back((char *)s, (char *)e, 0x0038000)
#define BRK_HEX_DIGIT_BACK(s,e)       brk_ag_char_map_back((char *)s, (char *)e, 0x0038000)
#define  IS_LOWER_CASE_CHAR( _c)       is_ag_char_map_char((char)( _c), 0x0040000)
#define SPN_LOWER_CASE_CHARS(_s)      spn_ag_char_map_chars((char *)_s, 0x0040000)
#define BRK_LOWER_CASE_CHARS(_s)      brk_ag_char_map_chars((char *)_s, 0x0040000)
#define SPN_LOWER_CASE_BACK(s,e)      spn_ag_char_map_back((char *)s, (char *)e, 0x0040000)
#define BRK_LOWER_CASE_BACK(s,e)      brk_ag_char_map_back((char *)s, (char *)e, 0x0040000)
#define  IS_UPPER_CASE_CHAR( _c)       is_ag_char_map_char((char)( _c), 0x0080000)
#define SPN_UPPER_CASE_CHARS(_s)      spn_ag_char_map_chars((char *)_s, 0x0080000)
#define BRK_UPPER_CASE_CHARS(_s)      brk_ag_char_map_chars((char *)_s, 0x0080000)
#define SPN_UPPER_CASE_BACK(s,e)      spn_ag_char_map_back((char *)s, (char *)e, 0x0080000)
#define BRK_UPPER_CASE_BACK(s,e)      brk_ag_char_map_back((char *)s, (char *)e, 0x0080000)
#define  IS_ALPHABETIC_CHAR( _c)       is_ag_char_map_char((char)( _c), 0x00C0000)
#define SPN_ALPHABETIC_CHARS(_s)      spn_ag_char_map_chars((char *)_s, 0x00C0000)
#define BRK_ALPHABETIC_CHARS(_s)      brk_ag_char_map_chars((char *)_s, 0x00C0000)
#define SPN_ALPHABETIC_BACK(s,e)      spn_ag_char_map_back((char *)s, (char *)e, 0x00C0000)
#define BRK_ALPHABETIC_BACK(s,e)      brk_ag_char_map_back((char *)s, (char *)e, 0x00C0000)
#define  IS_ALPHANUMERIC_CHAR( _c)     is_ag_char_map_char((char)( _c), 0x00D8000)
#define SPN_ALPHANUMERIC_CHARS(_s)    spn_ag_char_map_chars((char *)_s, 0x00D8000)
#define BRK_ALPHANUMERIC_CHARS(_s)    brk_ag_char_map_chars((char *)_s, 0x00D8000)
#define SPN_ALPHANUMERIC_BACK(s,e)    spn_ag_char_map_back((char *)s, (char *)e, 0x00D8000)
#define BRK_ALPHANUMERIC_BACK(s,e)    brk_ag_char_map_back((char *)s, (char *)e, 0x00D8000)
#define  IS_VAR_FIRST_CHAR( _c)        is_ag_char_map_char((char)( _c), 0x00C0040)
#define SPN_VAR_FIRST_CHARS(_s)       spn_ag_char_map_chars((char *)_s, 0x00C0040)
#define BRK_VAR_FIRST_CHARS(_s)       brk_ag_char_map_chars((char *)_s, 0x00C0040)
#define SPN_VAR_FIRST_BACK(s,e)       spn_ag_char_map_back((char *)s, (char *)e, 0x00C0040)
#define BRK_VAR_FIRST_BACK(s,e)       brk_ag_char_map_back((char *)s, (char *)e, 0x00C0040)
#define  IS_VARIABLE_NAME_CHAR( _c)    is_ag_char_map_char((char)( _c), 0x00D8040)
#define SPN_VARIABLE_NAME_CHARS(_s)   spn_ag_char_map_chars((char *)_s, 0x00D8040)
#define BRK_VARIABLE_NAME_CHARS(_s)   brk_ag_char_map_chars((char *)_s, 0x00D8040)
#define SPN_VARIABLE_NAME_BACK(s,e)   spn_ag_char_map_back((char *)s, (char *)e, 0x00D8040)
#define BRK_VARIABLE_NAME_BACK(s,e)   brk_ag_char_map_back((char *)s, (char *)e, 0x00D8040)
#define  IS_OPTION_NAME_CHAR( _c)      is_ag_char_map_char((char)( _c), 0x01D8040)
#define SPN_OPTION_NAME_CHARS(_s)     spn_ag_char_map_chars((char *)_s, 0x01D8040)
#define BRK_OPTION_NAME_CHARS(_s)     brk_ag_char_map_chars((char *)_s, 0x01D8040)
#define SPN_OPTION_NAME_BACK(s,e)     spn_ag_char_map_back((char *)s, (char *)e, 0x01D8040)
#define BRK_OPTION_NAME_BACK(s,e)     brk_ag_char_map_back((char *)s, (char *)e, 0x01D8040)
#define  IS_VALUE_NAME_CHAR( _c)       is_ag_char_map_char((char)( _c), 0x01D8060)
#define SPN_VALUE_NAME_CHARS(_s)      spn_ag_char_map_chars((char *)_s, 0x01D8060)
#define BRK_VALUE_NAME_CHARS(_s)      brk_ag_char_map_chars((char *)_s, 0x01D8060)
#define SPN_VALUE_NAME_BACK(s,e)      spn_ag_char_map_back((char *)s, (char *)e, 0x01D8060)
#define BRK_VALUE_NAME_BACK(s,e)      brk_ag_char_map_back((char *)s, (char *)e, 0x01D8060)
#define  IS_NAME_SEP_CHAR( _c)         is_ag_char_map_char((char)( _c), 0x0200000)
#define SPN_NAME_SEP_CHARS(_s)        spn_ag_char_map_chars((char *)_s, 0x0200000)
#define BRK_NAME_SEP_CHARS(_s)        brk_ag_char_map_chars((char *)_s, 0x0200000)
#define SPN_NAME_SEP_BACK(s,e)        spn_ag_char_map_back((char *)s, (char *)e, 0x0200000)
#define BRK_NAME_SEP_BACK(s,e)        brk_ag_char_map_back((char *)s, (char *)e, 0x0200000)
#define  IS_COMPOUND_NAME_CHAR( _c)    is_ag_char_map_char((char)( _c), 0x03D8260)
#define SPN_COMPOUND_NAME_CHARS(_s)   spn_ag_char_map_chars((char *)_s, 0x03D8260)
#define BRK_COMPOUND_NAME_CHARS(_s)   brk_ag_char_map_chars((char *)_s, 0x03D8260)
#define SPN_COMPOUND_NAME_BACK(s,e)   spn_ag_char_map_back((char *)s, (char *)e, 0x03D8260)
#define BRK_COMPOUND_NAME_BACK(s,e)   brk_ag_char_map_back((char *)s, (char *)e, 0x03D8260)
#define  IS_SCHEME_NOTE_CHAR( _c)      is_ag_char_map_char((char)( _c), 0x0001800)
#define SPN_SCHEME_NOTE_CHARS(_s)     spn_ag_char_map_chars((char *)_s, 0x0001800)
#define BRK_SCHEME_NOTE_CHARS(_s)     brk_ag_char_map_chars((char *)_s, 0x0001800)
#define SPN_SCHEME_NOTE_BACK(s,e)     spn_ag_char_map_back((char *)s, (char *)e, 0x0001800)
#define BRK_SCHEME_NOTE_BACK(s,e)     brk_ag_char_map_back((char *)s, (char *)e, 0x0001800)
#define  IS_UNQUOTABLE_CHAR( _c)       is_ag_char_map_char((char)( _c), 0x0400000)
#define SPN_UNQUOTABLE_CHARS(_s)      spn_ag_char_map_chars((char *)_s, 0x0400000)
#define BRK_UNQUOTABLE_CHARS(_s)      brk_ag_char_map_chars((char *)_s, 0x0400000)
#define SPN_UNQUOTABLE_BACK(s,e)      spn_ag_char_map_back((char *)s, (char *)e, 0x0400000)
#define BRK_UNQUOTABLE_BACK(s,e)      brk_ag_char_map_back((char *)s, (char *)e, 0x0400000)
#define  IS_END_XML_TOKEN_CHAR( _c)    is_ag_char_map_char((char)( _c), 0x0800601)
#define SPN_END_XML_TOKEN_CHARS(_s)   spn_ag_char_map_chars((char *)_s, 0x0800601)
#define BRK_END_XML_TOKEN_CHARS(_s)   brk_ag_char_map_chars((char *)_s, 0x0800601)
#define SPN_END_XML_TOKEN_BACK(s,e)   spn_ag_char_map_back((char *)s, (char *)e, 0x0800601)
#define BRK_END_XML_TOKEN_BACK(s,e)   brk_ag_char_map_back((char *)s, (char *)e, 0x0800601)
#define  IS_PLUS_N_SPACE_CHAR( _c)     is_ag_char_map_char((char)( _c), 0x0000681)
#define SPN_PLUS_N_SPACE_CHARS(_s)    spn_ag_char_map_chars((char *)_s, 0x0000681)
#define BRK_PLUS_N_SPACE_CHARS(_s)    brk_ag_char_map_chars((char *)_s, 0x0000681)
#define SPN_PLUS_N_SPACE_BACK(s,e)    spn_ag_char_map_back((char *)s, (char *)e, 0x0000681)
#define BRK_PLUS_N_SPACE_BACK(s,e)    brk_ag_char_map_back((char *)s, (char *)e, 0x0000681)
#define  IS_PUNCTUATION_CHAR( _c)      is_ag_char_map_char((char)( _c), 0x1000000)
#define SPN_PUNCTUATION_CHARS(_s)     spn_ag_char_map_chars((char *)_s, 0x1000000)
#define BRK_PUNCTUATION_CHARS(_s)     brk_ag_char_map_chars((char *)_s, 0x1000000)
#define SPN_PUNCTUATION_BACK(s,e)     spn_ag_char_map_back((char *)s, (char *)e, 0x1000000)
#define BRK_PUNCTUATION_BACK(s,e)     brk_ag_char_map_back((char *)s, (char *)e, 0x1000000)
#define  IS_SUFFIX_CHAR( _c)           is_ag_char_map_char((char)( _c), 0x20D8000)
#define SPN_SUFFIX_CHARS(_s)          spn_ag_char_map_chars((char *)_s, 0x20D8000)
#define BRK_SUFFIX_CHARS(_s)          brk_ag_char_map_chars((char *)_s, 0x20D8000)
#define SPN_SUFFIX_BACK(s,e)          spn_ag_char_map_back((char *)s, (char *)e, 0x20D8000)
#define BRK_SUFFIX_BACK(s,e)          brk_ag_char_map_back((char *)s, (char *)e, 0x20D8000)
#define  IS_SUFFIX_FMT_CHAR( _c)       is_ag_char_map_char((char)( _c), 0x20D800C)
#define SPN_SUFFIX_FMT_CHARS(_s)      spn_ag_char_map_chars((char *)_s, 0x20D800C)
#define BRK_SUFFIX_FMT_CHARS(_s)      brk_ag_char_map_chars((char *)_s, 0x20D800C)
#define SPN_SUFFIX_FMT_BACK(s,e)      spn_ag_char_map_back((char *)s, (char *)e, 0x20D800C)
#define BRK_SUFFIX_FMT_BACK(s,e)      brk_ag_char_map_back((char *)s, (char *)e, 0x20D800C)
#define  IS_FALSE_TYPE_CHAR( _c)       is_ag_char_map_char((char)( _c), 0x4000002)
#define SPN_FALSE_TYPE_CHARS(_s)      spn_ag_char_map_chars((char *)_s, 0x4000002)
#define BRK_FALSE_TYPE_CHARS(_s)      brk_ag_char_map_chars((char *)_s, 0x4000002)
#define SPN_FALSE_TYPE_BACK(s,e)      spn_ag_char_map_back((char *)s, (char *)e, 0x4000002)
#define BRK_FALSE_TYPE_BACK(s,e)      brk_ag_char_map_back((char *)s, (char *)e, 0x4000002)
#define  IS_FILE_NAME_CHAR( _c)        is_ag_char_map_char((char)( _c), 0x20D8004)
#define SPN_FILE_NAME_CHARS(_s)       spn_ag_char_map_chars((char *)_s, 0x20D8004)
#define BRK_FILE_NAME_CHARS(_s)       brk_ag_char_map_chars((char *)_s, 0x20D8004)
#define SPN_FILE_NAME_BACK(s,e)       spn_ag_char_map_back((char *)s, (char *)e, 0x20D8004)
#define BRK_FILE_NAME_BACK(s,e)       brk_ag_char_map_back((char *)s, (char *)e, 0x20D8004)
#define  IS_END_TOKEN_CHAR( _c)        is_ag_char_map_char((char)( _c), 0x0000603)
#define SPN_END_TOKEN_CHARS(_s)       spn_ag_char_map_chars((char *)_s, 0x0000603)
#define BRK_END_TOKEN_CHARS(_s)       brk_ag_char_map_chars((char *)_s, 0x0000603)
#define SPN_END_TOKEN_BACK(s,e)       spn_ag_char_map_back((char *)s, (char *)e, 0x0000603)
#define BRK_END_TOKEN_BACK(s,e)       brk_ag_char_map_back((char *)s, (char *)e, 0x0000603)
#define  IS_END_LIST_ENTRY_CHAR( _c)   is_ag_char_map_char((char)( _c), 0x0000613)
#define SPN_END_LIST_ENTRY_CHARS(_s)  spn_ag_char_map_chars((char *)_s, 0x0000613)
#define BRK_END_LIST_ENTRY_CHARS(_s)  brk_ag_char_map_chars((char *)_s, 0x0000613)
#define SPN_END_LIST_ENTRY_BACK(s,e)  spn_ag_char_map_back((char *)s, (char *)e, 0x0000613)
#define BRK_END_LIST_ENTRY_BACK(s,e)  brk_ag_char_map_back((char *)s, (char *)e, 0x0000613)
#define  IS_SET_SEPARATOR_CHAR( _c)    is_ag_char_map_char((char)( _c), 0x8000613)
#define SPN_SET_SEPARATOR_CHARS(_s)   spn_ag_char_map_chars((char *)_s, 0x8000613)
#define BRK_SET_SEPARATOR_CHARS(_s)   brk_ag_char_map_chars((char *)_s, 0x8000613)
#define SPN_SET_SEPARATOR_BACK(s,e)   spn_ag_char_map_back((char *)s, (char *)e, 0x8000613)
#define BRK_SET_SEPARATOR_BACK(s,e)   brk_ag_char_map_back((char *)s, (char *)e, 0x8000613)
#define  IS_SIGNED_NUMBER_CHAR( _c)    is_ag_char_map_char((char)( _c), 0x001C000)
#define SPN_SIGNED_NUMBER_CHARS(_s)   spn_ag_char_map_chars((char *)_s, 0x001C000)
#define BRK_SIGNED_NUMBER_CHARS(_s)   brk_ag_char_map_chars((char *)_s, 0x001C000)
#define SPN_SIGNED_NUMBER_BACK(s,e)   spn_ag_char_map_back((char *)s, (char *)e, 0x001C000)
#define BRK_SIGNED_NUMBER_BACK(s,e)   brk_ag_char_map_back((char *)s, (char *)e, 0x001C000)
#define  IS_MAKE_SCRIPT_CHAR( _c)      is_ag_char_map_char((char)( _c), 0x0000101)
#define SPN_MAKE_SCRIPT_CHARS(_s)     spn_ag_char_map_chars((char *)_s, 0x0000101)
#define BRK_MAKE_SCRIPT_CHARS(_s)     brk_ag_char_map_chars((char *)_s, 0x0000101)
#define SPN_MAKE_SCRIPT_BACK(s,e)     spn_ag_char_map_back((char *)s, (char *)e, 0x0000101)
#define BRK_MAKE_SCRIPT_BACK(s,e)     brk_ag_char_map_back((char *)s, (char *)e, 0x0000101)

static ag_char_map_mask_t const ag_char_map_table[128] = {
  /*NUL*/ 0x0000002, /*x01*/ 0x0000000, /*x02*/ 0x0000000, /*x03*/ 0x0000000,
  /*x04*/ 0x0000000, /*x05*/ 0x0000000, /*x06*/ 0x0000000, /*BEL*/ 0x0000000,
  /* BS*/ 0x0000400, /* HT*/ 0x0000200, /* NL*/ 0x0000001, /* VT*/ 0x0000400,
  /* FF*/ 0x0000400, /* CR*/ 0x0000400, /*x0E*/ 0x0000000, /*x0F*/ 0x0000000,
  /*x10*/ 0x0000000, /*x11*/ 0x0000000, /*x12*/ 0x0000000, /*x13*/ 0x0000000,
  /*x14*/ 0x0000000, /*x15*/ 0x0000000, /*x16*/ 0x0000000, /*x17*/ 0x0000000,
  /*x18*/ 0x0000000, /*x19*/ 0x0000000, /*x1A*/ 0x0000000, /*ESC*/ 0x0000000,
  /*x1C*/ 0x0000000, /*x1D*/ 0x0000000, /*x1E*/ 0x0000000, /*x1F*/ 0x0000000,
  /*   */ 0x0000200, /* ! */ 0x1402000, /* " */ 0x1002800, /* # */ 0x1002000,
  /* $ */ 0x1402100, /* % */ 0x1402008, /* & */ 0x1402000, /* ' */ 0x1002800,
  /* ( */ 0x1003000, /* ) */ 0x1003000, /* * */ 0x1002000, /* + */ 0x9402080,
  /* , */ 0x1002010, /* - */ 0x3506000, /* . */ 0x3602000, /* / */ 0x1C02004,
  /* 0 */ 0x440A000, /* 1 */ 0x040A000, /* 2 */ 0x040A000, /* 3 */ 0x040A000,
  /* 4 */ 0x040A000, /* 5 */ 0x040A000, /* 6 */ 0x040A000, /* 7 */ 0x040A000,
  /* 8 */ 0x0412000, /* 9 */ 0x0412000, /* : */ 0x1402020, /* ; */ 0x1002000,
  /* < */ 0x1002000, /* = */ 0x1002000, /* > */ 0x1802000, /* ? */ 0x1002000,
  /* @ */ 0x1402000, /* A */ 0x04A2000, /* B */ 0x04A2000, /* C */ 0x04A2000,
  /* D */ 0x04A2000, /* E */ 0x04A2000, /* F */ 0x44A2000, /* G */ 0x0482000,
  /* H */ 0x0482000, /* I */ 0x0482000, /* J */ 0x0482000, /* K */ 0x0482000,
  /* L */ 0x0482000, /* M */ 0x0482000, /* N */ 0x4482000, /* O */ 0x0482000,
  /* P */ 0x0482000, /* Q */ 0x0482000, /* R */ 0x0482000, /* S */ 0x0482000,
  /* T */ 0x0482000, /* U */ 0x0482000, /* V */ 0x0482000, /* W */ 0x0482000,
  /* X */ 0x0482000, /* Y */ 0x0482000, /* Z */ 0x0482000, /* [ */ 0x1202000,
  /* \ */ 0x1002004, /* ] */ 0x1202000, /* ^ */ 0x1502000, /* _ */ 0x2402040,
  /* ` */ 0x1002000, /* a */ 0x0462000, /* b */ 0x0462000, /* c */ 0x0462000,
  /* d */ 0x0462000, /* e */ 0x0462000, /* f */ 0x4462000, /* g */ 0x0442000,
  /* h */ 0x0442000, /* i */ 0x0442000, /* j */ 0x0442000, /* k */ 0x0442000,
  /* l */ 0x0442000, /* m */ 0x0442000, /* n */ 0x4442000, /* o */ 0x0442000,
  /* p */ 0x0442000, /* q */ 0x0442000, /* r */ 0x0442000, /* s */ 0x0442000,
  /* t */ 0x0442000, /* u */ 0x0442000, /* v */ 0x0442000, /* w */ 0x0442000,
  /* x */ 0x0442000, /* y */ 0x0442000, /* z */ 0x0442000, /* { */ 0x1002000,
  /* | */ 0x9402000, /* } */ 0x1002000, /* ~ */ 0x1406000, /*x7F*/ 0x0000000
};
static inline int
is_ag_char_map_char(char ch, ag_char_map_mask_t mask)
{
    unsigned int ix = (unsigned char)ch;
    return ((ix < 128) && ((ag_char_map_table[ix] & mask) != 0));
}

static inline char *
spn_ag_char_map_chars(char * p, ag_char_map_mask_t mask)
{
    while ((*p != '\0') && is_ag_char_map_char(*p, mask))  p++;
    return p;
}

static inline char *
brk_ag_char_map_chars(char * p, ag_char_map_mask_t mask)
{
    while ((*p != '\0') && (! is_ag_char_map_char(*p, mask)))  p++;
    return p;
}

static inline char *
spn_ag_char_map_back(char * s, char * e, ag_char_map_mask_t mask)
{
    if (s == e) e += strlen(e);
    while ((e > s) && is_ag_char_map_char(e[-1], mask))  e--;
    return e;
}

static inline char *
brk_ag_char_map_back(char * s, char * e, ag_char_map_mask_t mask)
{
    if (s == e) e += strlen(e);
    while ((e > s) && (! is_ag_char_map_char(e[-1], mask)))  e--;
    return e;
}
#endif /* AG_CHAR_MAP_H_GUARD */
