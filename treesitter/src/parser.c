#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 23
#define LARGE_STATE_COUNT 17
#define SYMBOL_COUNT 27
#define ALIAS_COUNT 0
#define TOKEN_COUNT 18
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum {
  sym_identifier = 1,
  anon_sym_DASH = 2,
  anon_sym_not = 3,
  anon_sym_PLUS = 4,
  anon_sym_STAR = 5,
  anon_sym_SLASH = 6,
  anon_sym_PERCENT = 7,
  anon_sym_STAR_STAR = 8,
  sym_hex_literal = 9,
  sym_octal_literal = 10,
  sym_binary_literal = 11,
  sym_decimal_literal = 12,
  sym_boolean_literal = 13,
  anon_sym_DQUOTE = 14,
  anon_sym_SQUOTE = 15,
  sym_character_literal_unescaped = 16,
  sym_escape_sequence = 17,
  sym_source_file = 18,
  sym__expression = 19,
  sym_unary_expression = 20,
  sym_binary_expression = 21,
  sym_string_literal = 22,
  sym_character_literal = 23,
  sym_literal = 24,
  aux_sym_source_file_repeat1 = 25,
  aux_sym_string_literal_repeat1 = 26,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_DASH] = "-",
  [anon_sym_not] = "not",
  [anon_sym_PLUS] = "+",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_STAR_STAR] = "**",
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
  [sym__expression] = "_expression",
  [sym_unary_expression] = "unary_expression",
  [sym_binary_expression] = "binary_expression",
  [sym_string_literal] = "string_literal",
  [sym_character_literal] = "character_literal",
  [sym_literal] = "literal",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_string_literal_repeat1] = "string_literal_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_not] = anon_sym_not,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_STAR_STAR] = anon_sym_STAR_STAR,
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
  [sym__expression] = sym__expression,
  [sym_unary_expression] = sym_unary_expression,
  [sym_binary_expression] = sym_binary_expression,
  [sym_string_literal] = sym_string_literal,
  [sym_character_literal] = sym_character_literal,
  [sym_literal] = sym_literal,
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
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_not] = {
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
  [anon_sym_STAR_STAR] = {
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
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_unary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
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
  [sym_literal] = {
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
      if (lookahead == '"') ADVANCE(34);
      if (lookahead == '%') ADVANCE(27);
      if (lookahead == '\'') ADVANCE(35);
      if (lookahead == '*') ADVANCE(25);
      if (lookahead == '+') ADVANCE(24);
      if (lookahead == '-') ADVANCE(23);
      if (lookahead == '/') ADVANCE(26);
      if (lookahead == '0') ADVANCE(33);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(32);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      END_STATE();
    case 1:
      if (lookahead == 'U') ADVANCE(21);
      if (lookahead == 'u') ADVANCE(17);
      if (lookahead == 'x') ADVANCE(13);
      if (lookahead != 0) ADVANCE(37);
      END_STATE();
    case 2:
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(36);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(36);
      END_STATE();
    case 3:
      if (lookahead == '_') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 4:
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(31);
      END_STATE();
    case 5:
      if (lookahead == '_') ADVANCE(10);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(30);
      END_STATE();
    case 6:
      if (lookahead == '_') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(29);
      END_STATE();
    case 7:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(4);
      END_STATE();
    case 8:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(31);
      END_STATE();
    case 9:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(5);
      END_STATE();
    case 10:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(30);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(37);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(6);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(40);
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(29);
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
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(28);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_STAR_STAR);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_hex_literal);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_octal_literal);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_binary_literal);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_decimal_literal);
      if (lookahead == '_') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_decimal_literal);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(7);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(9);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(12);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_character_literal_unescaped);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(37);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(38);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
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
      if (lookahead == 'f') ADVANCE(1);
      if (lookahead == 'n') ADVANCE(2);
      if (lookahead == 't') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'a') ADVANCE(4);
      END_STATE();
    case 2:
      if (lookahead == 'o') ADVANCE(5);
      END_STATE();
    case 3:
      if (lookahead == 'r') ADVANCE(6);
      END_STATE();
    case 4:
      if (lookahead == 'l') ADVANCE(7);
      END_STATE();
    case 5:
      if (lookahead == 't') ADVANCE(8);
      END_STATE();
    case 6:
      if (lookahead == 'u') ADVANCE(9);
      END_STATE();
    case 7:
      if (lookahead == 's') ADVANCE(10);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_not);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(11);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(11);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_boolean_literal);
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
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_not] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_STAR_STAR] = ACTIONS(1),
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
    [sym_source_file] = STATE(21),
    [sym__expression] = STATE(5),
    [sym_unary_expression] = STATE(5),
    [sym_binary_expression] = STATE(5),
    [sym_string_literal] = STATE(11),
    [sym_character_literal] = STATE(11),
    [sym_literal] = STATE(5),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_identifier] = ACTIONS(5),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_not] = ACTIONS(9),
    [sym_hex_literal] = ACTIONS(11),
    [sym_octal_literal] = ACTIONS(11),
    [sym_binary_literal] = ACTIONS(11),
    [sym_decimal_literal] = ACTIONS(13),
    [sym_boolean_literal] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [anon_sym_SQUOTE] = ACTIONS(17),
  },
  [2] = {
    [sym__expression] = STATE(5),
    [sym_unary_expression] = STATE(5),
    [sym_binary_expression] = STATE(5),
    [sym_string_literal] = STATE(11),
    [sym_character_literal] = STATE(11),
    [sym_literal] = STATE(5),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(19),
    [sym_identifier] = ACTIONS(5),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_not] = ACTIONS(9),
    [sym_hex_literal] = ACTIONS(11),
    [sym_octal_literal] = ACTIONS(11),
    [sym_binary_literal] = ACTIONS(11),
    [sym_decimal_literal] = ACTIONS(13),
    [sym_boolean_literal] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [anon_sym_SQUOTE] = ACTIONS(17),
  },
  [3] = {
    [sym__expression] = STATE(5),
    [sym_unary_expression] = STATE(5),
    [sym_binary_expression] = STATE(5),
    [sym_string_literal] = STATE(11),
    [sym_character_literal] = STATE(11),
    [sym_literal] = STATE(5),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(21),
    [sym_identifier] = ACTIONS(23),
    [anon_sym_DASH] = ACTIONS(26),
    [anon_sym_not] = ACTIONS(29),
    [sym_hex_literal] = ACTIONS(32),
    [sym_octal_literal] = ACTIONS(32),
    [sym_binary_literal] = ACTIONS(32),
    [sym_decimal_literal] = ACTIONS(35),
    [sym_boolean_literal] = ACTIONS(35),
    [anon_sym_DQUOTE] = ACTIONS(38),
    [anon_sym_SQUOTE] = ACTIONS(41),
  },
  [4] = {
    [sym__expression] = STATE(16),
    [sym_unary_expression] = STATE(16),
    [sym_binary_expression] = STATE(16),
    [sym_string_literal] = STATE(11),
    [sym_character_literal] = STATE(11),
    [sym_literal] = STATE(16),
    [sym_identifier] = ACTIONS(44),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_not] = ACTIONS(9),
    [sym_hex_literal] = ACTIONS(11),
    [sym_octal_literal] = ACTIONS(11),
    [sym_binary_literal] = ACTIONS(11),
    [sym_decimal_literal] = ACTIONS(13),
    [sym_boolean_literal] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [anon_sym_SQUOTE] = ACTIONS(17),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(46),
    [sym_identifier] = ACTIONS(48),
    [anon_sym_DASH] = ACTIONS(50),
    [anon_sym_not] = ACTIONS(48),
    [anon_sym_PLUS] = ACTIONS(50),
    [anon_sym_STAR] = ACTIONS(52),
    [anon_sym_SLASH] = ACTIONS(54),
    [anon_sym_PERCENT] = ACTIONS(54),
    [anon_sym_STAR_STAR] = ACTIONS(56),
    [sym_hex_literal] = ACTIONS(46),
    [sym_octal_literal] = ACTIONS(46),
    [sym_binary_literal] = ACTIONS(46),
    [sym_decimal_literal] = ACTIONS(48),
    [sym_boolean_literal] = ACTIONS(48),
    [anon_sym_DQUOTE] = ACTIONS(46),
    [anon_sym_SQUOTE] = ACTIONS(46),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(58),
    [sym_identifier] = ACTIONS(60),
    [anon_sym_DASH] = ACTIONS(50),
    [anon_sym_not] = ACTIONS(60),
    [anon_sym_PLUS] = ACTIONS(50),
    [anon_sym_STAR] = ACTIONS(52),
    [anon_sym_SLASH] = ACTIONS(54),
    [anon_sym_PERCENT] = ACTIONS(54),
    [anon_sym_STAR_STAR] = ACTIONS(56),
    [sym_hex_literal] = ACTIONS(58),
    [sym_octal_literal] = ACTIONS(58),
    [sym_binary_literal] = ACTIONS(58),
    [sym_decimal_literal] = ACTIONS(60),
    [sym_boolean_literal] = ACTIONS(60),
    [anon_sym_DQUOTE] = ACTIONS(58),
    [anon_sym_SQUOTE] = ACTIONS(58),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(62),
    [sym_identifier] = ACTIONS(64),
    [anon_sym_DASH] = ACTIONS(62),
    [anon_sym_not] = ACTIONS(64),
    [anon_sym_PLUS] = ACTIONS(62),
    [anon_sym_STAR] = ACTIONS(64),
    [anon_sym_SLASH] = ACTIONS(62),
    [anon_sym_PERCENT] = ACTIONS(62),
    [anon_sym_STAR_STAR] = ACTIONS(62),
    [sym_hex_literal] = ACTIONS(62),
    [sym_octal_literal] = ACTIONS(62),
    [sym_binary_literal] = ACTIONS(62),
    [sym_decimal_literal] = ACTIONS(64),
    [sym_boolean_literal] = ACTIONS(64),
    [anon_sym_DQUOTE] = ACTIONS(62),
    [anon_sym_SQUOTE] = ACTIONS(62),
  },
  [8] = {
    [sym__expression] = STATE(14),
    [sym_unary_expression] = STATE(14),
    [sym_binary_expression] = STATE(14),
    [sym_string_literal] = STATE(11),
    [sym_character_literal] = STATE(11),
    [sym_literal] = STATE(14),
    [sym_identifier] = ACTIONS(66),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_not] = ACTIONS(9),
    [sym_hex_literal] = ACTIONS(11),
    [sym_octal_literal] = ACTIONS(11),
    [sym_binary_literal] = ACTIONS(11),
    [sym_decimal_literal] = ACTIONS(13),
    [sym_boolean_literal] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [anon_sym_SQUOTE] = ACTIONS(17),
  },
  [9] = {
    [sym__expression] = STATE(15),
    [sym_unary_expression] = STATE(15),
    [sym_binary_expression] = STATE(15),
    [sym_string_literal] = STATE(11),
    [sym_character_literal] = STATE(11),
    [sym_literal] = STATE(15),
    [sym_identifier] = ACTIONS(68),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_not] = ACTIONS(9),
    [sym_hex_literal] = ACTIONS(11),
    [sym_octal_literal] = ACTIONS(11),
    [sym_binary_literal] = ACTIONS(11),
    [sym_decimal_literal] = ACTIONS(13),
    [sym_boolean_literal] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [anon_sym_SQUOTE] = ACTIONS(17),
  },
  [10] = {
    [sym__expression] = STATE(6),
    [sym_unary_expression] = STATE(6),
    [sym_binary_expression] = STATE(6),
    [sym_string_literal] = STATE(11),
    [sym_character_literal] = STATE(11),
    [sym_literal] = STATE(6),
    [sym_identifier] = ACTIONS(70),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_not] = ACTIONS(9),
    [sym_hex_literal] = ACTIONS(11),
    [sym_octal_literal] = ACTIONS(11),
    [sym_binary_literal] = ACTIONS(11),
    [sym_decimal_literal] = ACTIONS(13),
    [sym_boolean_literal] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [anon_sym_SQUOTE] = ACTIONS(17),
  },
  [11] = {
    [ts_builtin_sym_end] = ACTIONS(72),
    [sym_identifier] = ACTIONS(74),
    [anon_sym_DASH] = ACTIONS(72),
    [anon_sym_not] = ACTIONS(74),
    [anon_sym_PLUS] = ACTIONS(72),
    [anon_sym_STAR] = ACTIONS(74),
    [anon_sym_SLASH] = ACTIONS(72),
    [anon_sym_PERCENT] = ACTIONS(72),
    [anon_sym_STAR_STAR] = ACTIONS(72),
    [sym_hex_literal] = ACTIONS(72),
    [sym_octal_literal] = ACTIONS(72),
    [sym_binary_literal] = ACTIONS(72),
    [sym_decimal_literal] = ACTIONS(74),
    [sym_boolean_literal] = ACTIONS(74),
    [anon_sym_DQUOTE] = ACTIONS(72),
    [anon_sym_SQUOTE] = ACTIONS(72),
  },
  [12] = {
    [ts_builtin_sym_end] = ACTIONS(76),
    [sym_identifier] = ACTIONS(78),
    [anon_sym_DASH] = ACTIONS(76),
    [anon_sym_not] = ACTIONS(78),
    [anon_sym_PLUS] = ACTIONS(76),
    [anon_sym_STAR] = ACTIONS(78),
    [anon_sym_SLASH] = ACTIONS(76),
    [anon_sym_PERCENT] = ACTIONS(76),
    [anon_sym_STAR_STAR] = ACTIONS(76),
    [sym_hex_literal] = ACTIONS(76),
    [sym_octal_literal] = ACTIONS(76),
    [sym_binary_literal] = ACTIONS(76),
    [sym_decimal_literal] = ACTIONS(78),
    [sym_boolean_literal] = ACTIONS(78),
    [anon_sym_DQUOTE] = ACTIONS(76),
    [anon_sym_SQUOTE] = ACTIONS(76),
  },
  [13] = {
    [ts_builtin_sym_end] = ACTIONS(80),
    [sym_identifier] = ACTIONS(82),
    [anon_sym_DASH] = ACTIONS(80),
    [anon_sym_not] = ACTIONS(82),
    [anon_sym_PLUS] = ACTIONS(80),
    [anon_sym_STAR] = ACTIONS(82),
    [anon_sym_SLASH] = ACTIONS(80),
    [anon_sym_PERCENT] = ACTIONS(80),
    [anon_sym_STAR_STAR] = ACTIONS(80),
    [sym_hex_literal] = ACTIONS(80),
    [sym_octal_literal] = ACTIONS(80),
    [sym_binary_literal] = ACTIONS(80),
    [sym_decimal_literal] = ACTIONS(82),
    [sym_boolean_literal] = ACTIONS(82),
    [anon_sym_DQUOTE] = ACTIONS(80),
    [anon_sym_SQUOTE] = ACTIONS(80),
  },
  [14] = {
    [ts_builtin_sym_end] = ACTIONS(84),
    [sym_identifier] = ACTIONS(86),
    [anon_sym_DASH] = ACTIONS(84),
    [anon_sym_not] = ACTIONS(86),
    [anon_sym_PLUS] = ACTIONS(84),
    [anon_sym_STAR] = ACTIONS(52),
    [anon_sym_SLASH] = ACTIONS(54),
    [anon_sym_PERCENT] = ACTIONS(54),
    [anon_sym_STAR_STAR] = ACTIONS(56),
    [sym_hex_literal] = ACTIONS(84),
    [sym_octal_literal] = ACTIONS(84),
    [sym_binary_literal] = ACTIONS(84),
    [sym_decimal_literal] = ACTIONS(86),
    [sym_boolean_literal] = ACTIONS(86),
    [anon_sym_DQUOTE] = ACTIONS(84),
    [anon_sym_SQUOTE] = ACTIONS(84),
  },
  [15] = {
    [ts_builtin_sym_end] = ACTIONS(84),
    [sym_identifier] = ACTIONS(86),
    [anon_sym_DASH] = ACTIONS(84),
    [anon_sym_not] = ACTIONS(86),
    [anon_sym_PLUS] = ACTIONS(84),
    [anon_sym_STAR] = ACTIONS(86),
    [anon_sym_SLASH] = ACTIONS(84),
    [anon_sym_PERCENT] = ACTIONS(84),
    [anon_sym_STAR_STAR] = ACTIONS(56),
    [sym_hex_literal] = ACTIONS(84),
    [sym_octal_literal] = ACTIONS(84),
    [sym_binary_literal] = ACTIONS(84),
    [sym_decimal_literal] = ACTIONS(86),
    [sym_boolean_literal] = ACTIONS(86),
    [anon_sym_DQUOTE] = ACTIONS(84),
    [anon_sym_SQUOTE] = ACTIONS(84),
  },
  [16] = {
    [ts_builtin_sym_end] = ACTIONS(84),
    [sym_identifier] = ACTIONS(86),
    [anon_sym_DASH] = ACTIONS(84),
    [anon_sym_not] = ACTIONS(86),
    [anon_sym_PLUS] = ACTIONS(84),
    [anon_sym_STAR] = ACTIONS(86),
    [anon_sym_SLASH] = ACTIONS(84),
    [anon_sym_PERCENT] = ACTIONS(84),
    [anon_sym_STAR_STAR] = ACTIONS(84),
    [sym_hex_literal] = ACTIONS(84),
    [sym_octal_literal] = ACTIONS(84),
    [sym_binary_literal] = ACTIONS(84),
    [sym_decimal_literal] = ACTIONS(86),
    [sym_boolean_literal] = ACTIONS(86),
    [anon_sym_DQUOTE] = ACTIONS(84),
    [anon_sym_SQUOTE] = ACTIONS(84),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(17), 1,
      anon_sym_SQUOTE,
    ACTIONS(88), 1,
      anon_sym_DQUOTE,
    STATE(18), 2,
      sym_character_literal,
      aux_sym_string_literal_repeat1,
  [11] = 3,
    ACTIONS(17), 1,
      anon_sym_SQUOTE,
    ACTIONS(90), 1,
      anon_sym_DQUOTE,
    STATE(19), 2,
      sym_character_literal,
      aux_sym_string_literal_repeat1,
  [22] = 3,
    ACTIONS(92), 1,
      anon_sym_DQUOTE,
    ACTIONS(94), 1,
      anon_sym_SQUOTE,
    STATE(19), 2,
      sym_character_literal,
      aux_sym_string_literal_repeat1,
  [33] = 2,
    ACTIONS(97), 1,
      sym_character_literal_unescaped,
    ACTIONS(99), 1,
      sym_escape_sequence,
  [40] = 1,
    ACTIONS(101), 1,
      ts_builtin_sym_end,
  [44] = 1,
    ACTIONS(103), 1,
      anon_sym_SQUOTE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(17)] = 0,
  [SMALL_STATE(18)] = 11,
  [SMALL_STATE(19)] = 22,
  [SMALL_STATE(20)] = 33,
  [SMALL_STATE(21)] = 40,
  [SMALL_STATE(22)] = 44,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(5),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(10),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(10),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(11),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(11),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(17),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(20),
  [44] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 1),
  [48] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 1),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [52] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2),
  [60] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 2),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2),
  [64] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [70] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1),
  [74] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literal, 1),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3),
  [78] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_literal, 3),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_character_literal, 3),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2),
  [94] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(20),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [101] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
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
