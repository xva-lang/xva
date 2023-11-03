#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 23
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 58
#define ALIAS_COUNT 0
#define TOKEN_COUNT 41
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum {
  sym_identifier = 1,
  anon_sym_LBRACE = 2,
  anon_sym_RBRACE = 3,
  anon_sym_COLON = 4,
  anon_sym_LPAREN = 5,
  anon_sym_COMMA = 6,
  anon_sym_RPAREN = 7,
  anon_sym_def = 8,
  sym__fat_arrow = 9,
  sym_mutable_modifier = 10,
  sym__equals_symbol = 11,
  sym__let_keyword = 12,
  anon_sym_byte = 13,
  anon_sym_ushort = 14,
  anon_sym_uint = 15,
  anon_sym_ulong = 16,
  anon_sym_sbyte = 17,
  anon_sym_short = 18,
  anon_sym_int = 19,
  anon_sym_long = 20,
  anon_sym_float = 21,
  anon_sym_double = 22,
  anon_sym_boolean = 23,
  anon_sym_char = 24,
  anon_sym_PLUS_PLUS = 25,
  anon_sym_DASH_DASH = 26,
  anon_sym_DASH = 27,
  anon_sym_PLUS = 28,
  anon_sym_STAR = 29,
  anon_sym_SLASH = 30,
  anon_sym_PERCENT = 31,
  sym_hex_literal = 32,
  sym_octal_literal = 33,
  sym_binary_literal = 34,
  sym_decimal_literal = 35,
  sym_boolean_literal = 36,
  anon_sym_DQUOTE = 37,
  anon_sym_SQUOTE = 38,
  sym_character_literal_unescaped = 39,
  sym_escape_sequence = 40,
  sym_source_file = 41,
  sym__statement = 42,
  sym__expression = 43,
  sym__primary_expression = 44,
  sym__literal_constant = 45,
  sym__unary_expression = 46,
  sym_prefix_expression = 47,
  sym_prefix_unary_operator = 48,
  sym__binary_expression = 49,
  sym_multiplicative_expression = 50,
  sym_additive_expression = 51,
  sym_multiplicative_operator = 52,
  sym_additive_operator = 53,
  sym_string_literal = 54,
  sym_character_literal = 55,
  aux_sym_source_file_repeat1 = 56,
  aux_sym_string_literal_repeat1 = 57,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_COLON] = ":",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_def] = "def",
  [sym__fat_arrow] = "_fat_arrow",
  [sym_mutable_modifier] = "mutable_modifier",
  [sym__equals_symbol] = "_equals_symbol",
  [sym__let_keyword] = "_let_keyword",
  [anon_sym_byte] = "byte",
  [anon_sym_ushort] = "ushort",
  [anon_sym_uint] = "uint",
  [anon_sym_ulong] = "ulong",
  [anon_sym_sbyte] = "sbyte",
  [anon_sym_short] = "short",
  [anon_sym_int] = "int",
  [anon_sym_long] = "long",
  [anon_sym_float] = "float",
  [anon_sym_double] = "double",
  [anon_sym_boolean] = "boolean",
  [anon_sym_char] = "char",
  [anon_sym_PLUS_PLUS] = "++",
  [anon_sym_DASH_DASH] = "--",
  [anon_sym_DASH] = "-",
  [anon_sym_PLUS] = "+",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [sym_hex_literal] = "hex_literal",
  [sym_octal_literal] = "octal_literal",
  [sym_binary_literal] = "binary_literal",
  [sym_decimal_literal] = "decimal_literal",
  [sym_boolean_literal] = "boolean_literal",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_SQUOTE] = "'",
  [sym_character_literal_unescaped] = "character_literal_unescaped",
  [sym_escape_sequence] = "escape_sequence",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym__expression] = "_expression",
  [sym__primary_expression] = "_primary_expression",
  [sym__literal_constant] = "_literal_constant",
  [sym__unary_expression] = "_unary_expression",
  [sym_prefix_expression] = "prefix_expression",
  [sym_prefix_unary_operator] = "prefix_unary_operator",
  [sym__binary_expression] = "_binary_expression",
  [sym_multiplicative_expression] = "multiplicative_expression",
  [sym_additive_expression] = "additive_expression",
  [sym_multiplicative_operator] = "multiplicative_operator",
  [sym_additive_operator] = "additive_operator",
  [sym_string_literal] = "string_literal",
  [sym_character_literal] = "character_literal",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_string_literal_repeat1] = "string_literal_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_def] = anon_sym_def,
  [sym__fat_arrow] = sym__fat_arrow,
  [sym_mutable_modifier] = sym_mutable_modifier,
  [sym__equals_symbol] = sym__equals_symbol,
  [sym__let_keyword] = sym__let_keyword,
  [anon_sym_byte] = anon_sym_byte,
  [anon_sym_ushort] = anon_sym_ushort,
  [anon_sym_uint] = anon_sym_uint,
  [anon_sym_ulong] = anon_sym_ulong,
  [anon_sym_sbyte] = anon_sym_sbyte,
  [anon_sym_short] = anon_sym_short,
  [anon_sym_int] = anon_sym_int,
  [anon_sym_long] = anon_sym_long,
  [anon_sym_float] = anon_sym_float,
  [anon_sym_double] = anon_sym_double,
  [anon_sym_boolean] = anon_sym_boolean,
  [anon_sym_char] = anon_sym_char,
  [anon_sym_PLUS_PLUS] = anon_sym_PLUS_PLUS,
  [anon_sym_DASH_DASH] = anon_sym_DASH_DASH,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [sym_hex_literal] = sym_hex_literal,
  [sym_octal_literal] = sym_octal_literal,
  [sym_binary_literal] = sym_binary_literal,
  [sym_decimal_literal] = sym_decimal_literal,
  [sym_boolean_literal] = sym_boolean_literal,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [sym_character_literal_unescaped] = sym_character_literal_unescaped,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_source_file] = sym_source_file,
  [sym__statement] = sym__statement,
  [sym__expression] = sym__expression,
  [sym__primary_expression] = sym__primary_expression,
  [sym__literal_constant] = sym__literal_constant,
  [sym__unary_expression] = sym__unary_expression,
  [sym_prefix_expression] = sym_prefix_expression,
  [sym_prefix_unary_operator] = sym_prefix_unary_operator,
  [sym__binary_expression] = sym__binary_expression,
  [sym_multiplicative_expression] = sym_multiplicative_expression,
  [sym_additive_expression] = sym_additive_expression,
  [sym_multiplicative_operator] = sym_multiplicative_operator,
  [sym_additive_operator] = sym_additive_operator,
  [sym_string_literal] = sym_string_literal,
  [sym_character_literal] = sym_character_literal,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_string_literal_repeat1] = aux_sym_string_literal_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_def] = {
    .visible = true,
    .named = false,
  },
  [sym__fat_arrow] = {
    .visible = false,
    .named = true,
  },
  [sym_mutable_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym__equals_symbol] = {
    .visible = false,
    .named = true,
  },
  [sym__let_keyword] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_byte] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ushort] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uint] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ulong] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sbyte] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_short] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_long] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_double] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_boolean] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_char] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [sym_hex_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_octal_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_decimal_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_character_literal_unescaped] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym__primary_expression] = {
    .visible = false,
    .named = true,
  },
  [sym__literal_constant] = {
    .visible = false,
    .named = true,
  },
  [sym__unary_expression] = {
    .visible = false,
    .named = true,
  },
  [sym_prefix_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_prefix_unary_operator] = {
    .visible = true,
    .named = true,
  },
  [sym__binary_expression] = {
    .visible = false,
    .named = true,
  },
  [sym_multiplicative_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_additive_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_multiplicative_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_additive_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_character_literal] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(22);
      if (lookahead == '"') ADVANCE(43);
      if (lookahead == '%') ADVANCE(37);
      if (lookahead == '\'') ADVANCE(44);
      if (lookahead == '(') ADVANCE(26);
      if (lookahead == ')') ADVANCE(28);
      if (lookahead == '*') ADVANCE(35);
      if (lookahead == '+') ADVANCE(34);
      if (lookahead == ',') ADVANCE(27);
      if (lookahead == '-') ADVANCE(33);
      if (lookahead == '/') ADVANCE(36);
      if (lookahead == '0') ADVANCE(42);
      if (lookahead == ':') ADVANCE(25);
      if (lookahead == '=') ADVANCE(30);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '{') ADVANCE(23);
      if (lookahead == '}') ADVANCE(24);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(41);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(50);
      END_STATE();
    case 1:
      if (lookahead == 'U') ADVANCE(21);
      if (lookahead == 'u') ADVANCE(17);
      if (lookahead == 'x') ADVANCE(13);
      if (lookahead != 0) ADVANCE(46);
      END_STATE();
    case 2:
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(45);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(45);
      END_STATE();
    case 3:
      if (lookahead == '_') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      END_STATE();
    case 4:
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(40);
      END_STATE();
    case 5:
      if (lookahead == '_') ADVANCE(10);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(39);
      END_STATE();
    case 6:
      if (lookahead == '_') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(38);
      END_STATE();
    case 7:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(4);
      END_STATE();
    case 8:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(40);
      END_STATE();
    case 9:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(5);
      END_STATE();
    case 10:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(39);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(46);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(6);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(38);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 16:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      END_STATE();
    case 17:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(16);
      END_STATE();
    case 18:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(17);
      END_STATE();
    case 19:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(18);
      END_STATE();
    case 20:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(19);
      END_STATE();
    case 21:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(20);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym__fat_arrow);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym__equals_symbol);
      if (lookahead == '>') ADVANCE(29);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(32);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(31);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_hex_literal);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_octal_literal);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_binary_literal);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_decimal_literal);
      if (lookahead == '_') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_decimal_literal);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(7);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(9);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(12);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_character_literal_unescaped);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(46);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(50);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'b') ADVANCE(1);
      if (lookahead == 'c') ADVANCE(2);
      if (lookahead == 'd') ADVANCE(3);
      if (lookahead == 'f') ADVANCE(4);
      if (lookahead == 'i') ADVANCE(5);
      if (lookahead == 'l') ADVANCE(6);
      if (lookahead == 'm') ADVANCE(7);
      if (lookahead == 's') ADVANCE(8);
      if (lookahead == 't') ADVANCE(9);
      if (lookahead == 'u') ADVANCE(10);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'o') ADVANCE(11);
      if (lookahead == 'y') ADVANCE(12);
      END_STATE();
    case 2:
      if (lookahead == 'h') ADVANCE(13);
      END_STATE();
    case 3:
      if (lookahead == 'e') ADVANCE(14);
      if (lookahead == 'o') ADVANCE(15);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(16);
      if (lookahead == 'l') ADVANCE(17);
      END_STATE();
    case 5:
      if (lookahead == 'n') ADVANCE(18);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(19);
      if (lookahead == 'o') ADVANCE(20);
      END_STATE();
    case 7:
      if (lookahead == 'u') ADVANCE(21);
      END_STATE();
    case 8:
      if (lookahead == 'b') ADVANCE(22);
      if (lookahead == 'h') ADVANCE(23);
      END_STATE();
    case 9:
      if (lookahead == 'r') ADVANCE(24);
      END_STATE();
    case 10:
      if (lookahead == 'i') ADVANCE(25);
      if (lookahead == 'l') ADVANCE(26);
      if (lookahead == 's') ADVANCE(27);
      END_STATE();
    case 11:
      if (lookahead == 'o') ADVANCE(28);
      END_STATE();
    case 12:
      if (lookahead == 't') ADVANCE(29);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(30);
      END_STATE();
    case 14:
      if (lookahead == 'f') ADVANCE(31);
      END_STATE();
    case 15:
      if (lookahead == 'u') ADVANCE(32);
      END_STATE();
    case 16:
      if (lookahead == 'l') ADVANCE(33);
      END_STATE();
    case 17:
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 18:
      if (lookahead == 't') ADVANCE(35);
      END_STATE();
    case 19:
      if (lookahead == 't') ADVANCE(36);
      END_STATE();
    case 20:
      if (lookahead == 'n') ADVANCE(37);
      END_STATE();
    case 21:
      if (lookahead == 't') ADVANCE(38);
      END_STATE();
    case 22:
      if (lookahead == 'y') ADVANCE(39);
      END_STATE();
    case 23:
      if (lookahead == 'o') ADVANCE(40);
      END_STATE();
    case 24:
      if (lookahead == 'u') ADVANCE(41);
      END_STATE();
    case 25:
      if (lookahead == 'n') ADVANCE(42);
      END_STATE();
    case 26:
      if (lookahead == 'o') ADVANCE(43);
      END_STATE();
    case 27:
      if (lookahead == 'h') ADVANCE(44);
      END_STATE();
    case 28:
      if (lookahead == 'l') ADVANCE(45);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(46);
      END_STATE();
    case 30:
      if (lookahead == 'r') ADVANCE(47);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_def);
      END_STATE();
    case 32:
      if (lookahead == 'b') ADVANCE(48);
      END_STATE();
    case 33:
      if (lookahead == 's') ADVANCE(49);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(50);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym__let_keyword);
      END_STATE();
    case 37:
      if (lookahead == 'g') ADVANCE(51);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(52);
      END_STATE();
    case 39:
      if (lookahead == 't') ADVANCE(53);
      END_STATE();
    case 40:
      if (lookahead == 'r') ADVANCE(54);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(55);
      END_STATE();
    case 42:
      if (lookahead == 't') ADVANCE(56);
      END_STATE();
    case 43:
      if (lookahead == 'n') ADVANCE(57);
      END_STATE();
    case 44:
      if (lookahead == 'o') ADVANCE(58);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(59);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_byte);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_char);
      END_STATE();
    case 48:
      if (lookahead == 'l') ADVANCE(60);
      END_STATE();
    case 49:
      if (lookahead == 'e') ADVANCE(55);
      END_STATE();
    case 50:
      if (lookahead == 't') ADVANCE(61);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_long);
      END_STATE();
    case 52:
      if (lookahead == 'b') ADVANCE(62);
      END_STATE();
    case 53:
      if (lookahead == 'e') ADVANCE(63);
      END_STATE();
    case 54:
      if (lookahead == 't') ADVANCE(64);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_boolean_literal);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_uint);
      END_STATE();
    case 57:
      if (lookahead == 'g') ADVANCE(65);
      END_STATE();
    case 58:
      if (lookahead == 'r') ADVANCE(66);
      END_STATE();
    case 59:
      if (lookahead == 'a') ADVANCE(67);
      END_STATE();
    case 60:
      if (lookahead == 'e') ADVANCE(68);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_float);
      END_STATE();
    case 62:
      if (lookahead == 'l') ADVANCE(69);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_sbyte);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_short);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_ulong);
      END_STATE();
    case 66:
      if (lookahead == 't') ADVANCE(70);
      END_STATE();
    case 67:
      if (lookahead == 'n') ADVANCE(71);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_double);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(72);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_ushort);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_boolean);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_mutable_modifier);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 2},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_def] = ACTIONS(1),
    [sym__fat_arrow] = ACTIONS(1),
    [sym_mutable_modifier] = ACTIONS(1),
    [sym__equals_symbol] = ACTIONS(1),
    [sym__let_keyword] = ACTIONS(1),
    [anon_sym_byte] = ACTIONS(1),
    [anon_sym_ushort] = ACTIONS(1),
    [anon_sym_uint] = ACTIONS(1),
    [anon_sym_ulong] = ACTIONS(1),
    [anon_sym_sbyte] = ACTIONS(1),
    [anon_sym_short] = ACTIONS(1),
    [anon_sym_int] = ACTIONS(1),
    [anon_sym_long] = ACTIONS(1),
    [anon_sym_float] = ACTIONS(1),
    [anon_sym_double] = ACTIONS(1),
    [anon_sym_boolean] = ACTIONS(1),
    [anon_sym_char] = ACTIONS(1),
    [anon_sym_PLUS_PLUS] = ACTIONS(1),
    [anon_sym_DASH_DASH] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [sym_hex_literal] = ACTIONS(1),
    [sym_octal_literal] = ACTIONS(1),
    [sym_binary_literal] = ACTIONS(1),
    [sym_decimal_literal] = ACTIONS(1),
    [sym_boolean_literal] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(22),
    [sym__statement] = STATE(3),
    [sym__expression] = STATE(9),
    [sym__primary_expression] = STATE(9),
    [sym__literal_constant] = STATE(9),
    [sym__unary_expression] = STATE(9),
    [sym_prefix_expression] = STATE(9),
    [sym_prefix_unary_operator] = STATE(4),
    [sym__binary_expression] = STATE(9),
    [sym_multiplicative_expression] = STATE(9),
    [sym_additive_expression] = STATE(9),
    [sym_string_literal] = STATE(9),
    [sym_character_literal] = STATE(9),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_identifier] = ACTIONS(5),
    [anon_sym_PLUS_PLUS] = ACTIONS(7),
    [anon_sym_DASH_DASH] = ACTIONS(7),
    [anon_sym_DASH] = ACTIONS(9),
    [anon_sym_PLUS] = ACTIONS(9),
    [sym_hex_literal] = ACTIONS(11),
    [sym_octal_literal] = ACTIONS(11),
    [sym_binary_literal] = ACTIONS(11),
    [sym_decimal_literal] = ACTIONS(5),
    [sym_boolean_literal] = ACTIONS(5),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 10,
    ACTIONS(17), 1,
      ts_builtin_sym_end,
    ACTIONS(31), 1,
      anon_sym_DQUOTE,
    ACTIONS(34), 1,
      anon_sym_SQUOTE,
    STATE(4), 1,
      sym_prefix_unary_operator,
    ACTIONS(22), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
    ACTIONS(25), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(2), 2,
      sym__statement,
      aux_sym_source_file_repeat1,
    ACTIONS(19), 3,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(28), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(9), 10,
      sym__expression,
      sym__primary_expression,
      sym__literal_constant,
      sym__unary_expression,
      sym_prefix_expression,
      sym__binary_expression,
      sym_multiplicative_expression,
      sym_additive_expression,
      sym_string_literal,
      sym_character_literal,
  [47] = 10,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
    STATE(4), 1,
      sym_prefix_unary_operator,
    ACTIONS(7), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
    ACTIONS(9), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(2), 2,
      sym__statement,
      aux_sym_source_file_repeat1,
    ACTIONS(5), 3,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(11), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(9), 10,
      sym__expression,
      sym__primary_expression,
      sym__literal_constant,
      sym__unary_expression,
      sym_prefix_expression,
      sym__binary_expression,
      sym_multiplicative_expression,
      sym_additive_expression,
      sym_string_literal,
      sym_character_literal,
  [94] = 8,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    STATE(4), 1,
      sym_prefix_unary_operator,
    ACTIONS(7), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
    ACTIONS(9), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(39), 3,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(41), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(10), 10,
      sym__expression,
      sym__primary_expression,
      sym__literal_constant,
      sym__unary_expression,
      sym_prefix_expression,
      sym__binary_expression,
      sym_multiplicative_expression,
      sym_additive_expression,
      sym_string_literal,
      sym_character_literal,
  [134] = 8,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    STATE(4), 1,
      sym_prefix_unary_operator,
    ACTIONS(7), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
    ACTIONS(9), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(43), 3,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(45), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(8), 10,
      sym__expression,
      sym__primary_expression,
      sym__literal_constant,
      sym__unary_expression,
      sym_prefix_expression,
      sym__binary_expression,
      sym_multiplicative_expression,
      sym_additive_expression,
      sym_string_literal,
      sym_character_literal,
  [174] = 8,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    STATE(4), 1,
      sym_prefix_unary_operator,
    ACTIONS(7), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
    ACTIONS(9), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(47), 3,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(49), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(7), 10,
      sym__expression,
      sym__primary_expression,
      sym__literal_constant,
      sym__unary_expression,
      sym_prefix_expression,
      sym__binary_expression,
      sym_multiplicative_expression,
      sym_additive_expression,
      sym_string_literal,
      sym_character_literal,
  [214] = 5,
    STATE(5), 1,
      sym_multiplicative_operator,
    STATE(6), 1,
      sym_additive_operator,
    ACTIONS(55), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(53), 5,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(51), 8,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [243] = 4,
    STATE(5), 1,
      sym_multiplicative_operator,
    STATE(6), 1,
      sym_additive_operator,
    ACTIONS(59), 5,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(57), 11,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [270] = 6,
    STATE(5), 1,
      sym_multiplicative_operator,
    STATE(6), 1,
      sym_additive_operator,
    ACTIONS(65), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(55), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(63), 3,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(61), 8,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [301] = 6,
    STATE(5), 1,
      sym_multiplicative_operator,
    STATE(6), 1,
      sym_additive_operator,
    ACTIONS(65), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(55), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(69), 3,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(67), 8,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [332] = 2,
    ACTIONS(73), 5,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(71), 11,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [353] = 2,
    ACTIONS(77), 5,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(75), 11,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [374] = 2,
    ACTIONS(81), 5,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(79), 11,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [395] = 2,
    ACTIONS(83), 5,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(85), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [412] = 2,
    ACTIONS(87), 5,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(89), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [429] = 2,
    ACTIONS(91), 5,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(93), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [446] = 3,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(95), 1,
      anon_sym_DQUOTE,
    STATE(19), 2,
      sym_character_literal,
      aux_sym_string_literal_repeat1,
  [457] = 3,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(97), 1,
      anon_sym_DQUOTE,
    STATE(17), 2,
      sym_character_literal,
      aux_sym_string_literal_repeat1,
  [468] = 3,
    ACTIONS(99), 1,
      anon_sym_DQUOTE,
    ACTIONS(101), 1,
      anon_sym_SQUOTE,
    STATE(19), 2,
      sym_character_literal,
      aux_sym_string_literal_repeat1,
  [479] = 2,
    ACTIONS(104), 1,
      sym_character_literal_unescaped,
    ACTIONS(106), 1,
      sym_escape_sequence,
  [486] = 1,
    ACTIONS(108), 1,
      anon_sym_SQUOTE,
  [490] = 1,
    ACTIONS(110), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 47,
  [SMALL_STATE(4)] = 94,
  [SMALL_STATE(5)] = 134,
  [SMALL_STATE(6)] = 174,
  [SMALL_STATE(7)] = 214,
  [SMALL_STATE(8)] = 243,
  [SMALL_STATE(9)] = 270,
  [SMALL_STATE(10)] = 301,
  [SMALL_STATE(11)] = 332,
  [SMALL_STATE(12)] = 353,
  [SMALL_STATE(13)] = 374,
  [SMALL_STATE(14)] = 395,
  [SMALL_STATE(15)] = 412,
  [SMALL_STATE(16)] = 429,
  [SMALL_STATE(17)] = 446,
  [SMALL_STATE(18)] = 457,
  [SMALL_STATE(19)] = 468,
  [SMALL_STATE(20)] = 479,
  [SMALL_STATE(21)] = 486,
  [SMALL_STATE(22)] = 490,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [19] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(9),
  [22] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(14),
  [25] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(14),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(9),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(18),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(20),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_additive_expression, 3),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_additive_expression, 3),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiplicative_expression, 3),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_multiplicative_expression, 3),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 1),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statement, 1),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prefix_expression, 2),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prefix_expression, 2),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_literal, 3),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_character_literal, 3),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prefix_unary_operator, 1),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prefix_unary_operator, 1),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_additive_operator, 1),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_additive_operator, 1),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_multiplicative_operator, 1),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiplicative_operator, 1),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2),
  [101] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(20),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [106] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [110] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_xva(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
