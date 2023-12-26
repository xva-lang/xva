#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 27
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 41
#define ALIAS_COUNT 0
#define TOKEN_COUNT 24
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 2

enum {
  sym_suffix_no_e = 1,
  sym_decimal_literal = 2,
  sym_binary_literal = 3,
  sym_octal_literal = 4,
  sym_hex_literal = 5,
  anon_sym_SQUOTE = 6,
  aux_sym_character_literal_token1 = 7,
  anon_sym_BSLASH_SQUOTE = 8,
  anon_sym_BSLASH_DQUOTE = 9,
  anon_sym_BSLASHx = 10,
  aux_sym_ascii_escape_token1 = 11,
  aux_sym_ascii_escape_token2 = 12,
  anon_sym_BSLASHn = 13,
  anon_sym_BSLASHr = 14,
  anon_sym_BSLASHt = 15,
  anon_sym_BSLASH_BSLASH = 16,
  anon_sym_BSLASH0 = 17,
  aux_sym_unicode_escape_token1 = 18,
  anon_sym_DQUOTE = 19,
  aux_sym_string_literal_token1 = 20,
  sym__string_continuation = 21,
  anon_sym_true = 22,
  anon_sym_false = 23,
  sym_source_file = 24,
  sym__item = 25,
  sym_expression = 26,
  sym__primary_expression = 27,
  sym_literal = 28,
  sym_integer_literal = 29,
  sym_character_literal = 30,
  sym_quote_escape = 31,
  sym_ascii_escape = 32,
  sym_unicode_escape = 33,
  sym_string_literal = 34,
  sym__quote_escape = 35,
  sym__ascii_escape = 36,
  sym__unicode_escape = 37,
  sym_boolean_literal = 38,
  aux_sym_source_file_repeat1 = 39,
  aux_sym_string_literal_repeat1 = 40,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_suffix_no_e] = "suffix_no_e",
  [sym_decimal_literal] = "decimal_literal",
  [sym_binary_literal] = "binary_literal",
  [sym_octal_literal] = "octal_literal",
  [sym_hex_literal] = "hex_literal",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_character_literal_token1] = "character_literal_token1",
  [anon_sym_BSLASH_SQUOTE] = "\\'",
  [anon_sym_BSLASH_DQUOTE] = "\\\"",
  [anon_sym_BSLASHx] = "\\x",
  [aux_sym_ascii_escape_token1] = "ascii_escape_token1",
  [aux_sym_ascii_escape_token2] = "ascii_escape_token2",
  [anon_sym_BSLASHn] = "\\n",
  [anon_sym_BSLASHr] = "\\r",
  [anon_sym_BSLASHt] = "\\t",
  [anon_sym_BSLASH_BSLASH] = "\\\\",
  [anon_sym_BSLASH0] = "\\0",
  [aux_sym_unicode_escape_token1] = "unicode_escape_token1",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_literal_token1] = "string_literal_token1",
  [sym__string_continuation] = "_string_continuation",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_source_file] = "source_file",
  [sym__item] = "_item",
  [sym_expression] = "expression",
  [sym__primary_expression] = "_primary_expression",
  [sym_literal] = "literal",
  [sym_integer_literal] = "integer_literal",
  [sym_character_literal] = "character_literal",
  [sym_quote_escape] = "quote_escape",
  [sym_ascii_escape] = "ascii_escape",
  [sym_unicode_escape] = "unicode_escape",
  [sym_string_literal] = "string_literal",
  [sym__quote_escape] = "_quote_escape",
  [sym__ascii_escape] = "_ascii_escape",
  [sym__unicode_escape] = "_unicode_escape",
  [sym_boolean_literal] = "boolean_literal",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_string_literal_repeat1] = "string_literal_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_suffix_no_e] = sym_suffix_no_e,
  [sym_decimal_literal] = sym_decimal_literal,
  [sym_binary_literal] = sym_binary_literal,
  [sym_octal_literal] = sym_octal_literal,
  [sym_hex_literal] = sym_hex_literal,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_character_literal_token1] = aux_sym_character_literal_token1,
  [anon_sym_BSLASH_SQUOTE] = anon_sym_BSLASH_SQUOTE,
  [anon_sym_BSLASH_DQUOTE] = anon_sym_BSLASH_DQUOTE,
  [anon_sym_BSLASHx] = anon_sym_BSLASHx,
  [aux_sym_ascii_escape_token1] = aux_sym_ascii_escape_token1,
  [aux_sym_ascii_escape_token2] = aux_sym_ascii_escape_token2,
  [anon_sym_BSLASHn] = anon_sym_BSLASHn,
  [anon_sym_BSLASHr] = anon_sym_BSLASHr,
  [anon_sym_BSLASHt] = anon_sym_BSLASHt,
  [anon_sym_BSLASH_BSLASH] = anon_sym_BSLASH_BSLASH,
  [anon_sym_BSLASH0] = anon_sym_BSLASH0,
  [aux_sym_unicode_escape_token1] = aux_sym_unicode_escape_token1,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_literal_token1] = aux_sym_string_literal_token1,
  [sym__string_continuation] = sym__string_continuation,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_source_file] = sym_source_file,
  [sym__item] = sym__item,
  [sym_expression] = sym_expression,
  [sym__primary_expression] = sym__primary_expression,
  [sym_literal] = sym_literal,
  [sym_integer_literal] = sym_integer_literal,
  [sym_character_literal] = sym_character_literal,
  [sym_quote_escape] = sym_quote_escape,
  [sym_ascii_escape] = sym_ascii_escape,
  [sym_unicode_escape] = sym_unicode_escape,
  [sym_string_literal] = sym_string_literal,
  [sym__quote_escape] = sym__quote_escape,
  [sym__ascii_escape] = sym__ascii_escape,
  [sym__unicode_escape] = sym__unicode_escape,
  [sym_boolean_literal] = sym_boolean_literal,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_string_literal_repeat1] = aux_sym_string_literal_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_suffix_no_e] = {
    .visible = true,
    .named = true,
  },
  [sym_decimal_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_octal_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_hex_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_character_literal_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BSLASH_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHx] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_ascii_escape_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_ascii_escape_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BSLASHn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHr] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHt] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH0] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_unicode_escape_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_literal_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__string_continuation] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__item] = {
    .visible = false,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym__primary_expression] = {
    .visible = false,
    .named = true,
  },
  [sym_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_integer_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_character_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_quote_escape] = {
    .visible = true,
    .named = true,
  },
  [sym_ascii_escape] = {
    .visible = true,
    .named = true,
  },
  [sym_unicode_escape] = {
    .visible = true,
    .named = true,
  },
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym__quote_escape] = {
    .visible = false,
    .named = true,
  },
  [sym__ascii_escape] = {
    .visible = false,
    .named = true,
  },
  [sym__unicode_escape] = {
    .visible = false,
    .named = true,
  },
  [sym_boolean_literal] = {
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

enum {
  field_suffix = 1,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_suffix] = "suffix",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_suffix, 1},
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
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(19);
      if (lookahead == '"') ADVANCE(59);
      if (lookahead == '\'') ADVANCE(33);
      if (lookahead == 't') ADVANCE(24);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(28);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (lookahead == 'E' ||
          ('[' <= lookahead && lookahead <= '^') ||
          lookahead == '`' ||
          lookahead == 'e') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(28);
      if (('g' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      if (('A' <= lookahead && lookahead <= 'f')) ADVANCE(27);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1)
      if (lookahead == '"') ADVANCE(59);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(61);
      if (lookahead != 0) ADVANCE(60);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(62);
      if (lookahead == '"') ADVANCE(37);
      if (lookahead == '\'') ADVANCE(36);
      if (lookahead == '0') ADVANCE(45);
      if (lookahead == '\\') ADVANCE(44);
      if (lookahead == 'n') ADVANCE(41);
      if (lookahead == 'r') ADVANCE(42);
      if (lookahead == 't') ADVANCE(43);
      if (lookahead == 'u') ADVANCE(58);
      if (lookahead == 'x') ADVANCE(38);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(37);
      if (lookahead == '\'') ADVANCE(36);
      if (lookahead == '0') ADVANCE(45);
      if (lookahead == '\\') ADVANCE(44);
      if (lookahead == 'n') ADVANCE(41);
      if (lookahead == 'r') ADVANCE(42);
      if (lookahead == 't') ADVANCE(43);
      if (lookahead == 'u') ADVANCE(58);
      if (lookahead == 'x') ADVANCE(38);
      END_STATE();
    case 4:
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(35);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != 'n' &&
          lookahead != 'r' &&
          lookahead != 't') ADVANCE(34);
      END_STATE();
    case 5:
      if (lookahead == '_') ADVANCE(5);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(30);
      END_STATE();
    case 6:
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(31);
      END_STATE();
    case 7:
      if (lookahead == '_') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(11);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(63);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(65);
      END_STATE();
    case 11:
      if (lookahead == 'l') ADVANCE(13);
      END_STATE();
    case 12:
      if (lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 13:
      if (lookahead == 's') ADVANCE(10);
      END_STATE();
    case 14:
      if (lookahead == 'u') ADVANCE(9);
      END_STATE();
    case 15:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(15)
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(39);
      END_STATE();
    case 16:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(16)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'f')) ADVANCE(40);
      END_STATE();
    case 17:
      if (eof) ADVANCE(19);
      if (lookahead == '"') ADVANCE(59);
      if (lookahead == '\'') ADVANCE(33);
      if (lookahead == '0') ADVANCE(29);
      if (lookahead == 'f') ADVANCE(8);
      if (lookahead == 't') ADVANCE(12);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(17)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 18:
      if (eof) ADVANCE(19);
      if (lookahead == '"') ADVANCE(59);
      if (lookahead == '\'') ADVANCE(33);
      if (lookahead == '0') ADVANCE(29);
      if (lookahead == 'f') ADVANCE(20);
      if (lookahead == 't') ADVANCE(24);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(18)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(28);
      if (('A' <= lookahead && lookahead <= 'D') ||
          ('F' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'd') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (lookahead == 'a') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (lookahead == 'e') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (lookahead == 'e') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (lookahead == 'l') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (lookahead == 'r') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (lookahead == 's') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (lookahead == 'u') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_decimal_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_decimal_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(28);
      if (lookahead == 'b') ADVANCE(5);
      if (lookahead == 'o') ADVANCE(6);
      if (lookahead == 'x') ADVANCE(7);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_binary_literal);
      if (lookahead == '_') ADVANCE(30);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_octal_literal);
      if (lookahead == '_') ADVANCE(31);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_hex_literal);
      if (lookahead == '_') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_character_literal_token1);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_character_literal_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(35);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != '\\' &&
          lookahead != 'n' &&
          lookahead != 'r' &&
          lookahead != 't') ADVANCE(34);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_BSLASH_SQUOTE);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_BSLASH_DQUOTE);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_BSLASHx);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token1);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_BSLASHn);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_BSLASHr);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_BSLASHt);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_BSLASH_BSLASH);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_BSLASH0);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(47);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(46);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(46);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(54);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(54);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(56);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(61);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(60);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym__string_continuation);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 17},
  [2] = {.lex_state = 17},
  [3] = {.lex_state = 17},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 4},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 18},
  [10] = {.lex_state = 17},
  [11] = {.lex_state = 17},
  [12] = {.lex_state = 17},
  [13] = {.lex_state = 17},
  [14] = {.lex_state = 17},
  [15] = {.lex_state = 17},
  [16] = {.lex_state = 17},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 15},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 16},
  [22] = {.lex_state = 16},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 15},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_suffix_no_e] = ACTIONS(1),
    [sym_decimal_literal] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [aux_sym_ascii_escape_token1] = ACTIONS(1),
    [aux_sym_ascii_escape_token2] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(17),
    [sym__item] = STATE(2),
    [sym_expression] = STATE(2),
    [sym__primary_expression] = STATE(12),
    [sym_literal] = STATE(12),
    [sym_integer_literal] = STATE(13),
    [sym_character_literal] = STATE(13),
    [sym_string_literal] = STATE(13),
    [sym_boolean_literal] = STATE(13),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_decimal_literal] = ACTIONS(5),
    [sym_binary_literal] = ACTIONS(7),
    [sym_octal_literal] = ACTIONS(7),
    [sym_hex_literal] = ACTIONS(7),
    [anon_sym_SQUOTE] = ACTIONS(9),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [anon_sym_true] = ACTIONS(13),
    [anon_sym_false] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(5), 1,
      sym_decimal_literal,
    ACTIONS(9), 1,
      anon_sym_SQUOTE,
    ACTIONS(11), 1,
      anon_sym_DQUOTE,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym__primary_expression,
      sym_literal,
    ACTIONS(7), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(3), 3,
      sym__item,
      sym_expression,
      aux_sym_source_file_repeat1,
    STATE(13), 4,
      sym_integer_literal,
      sym_character_literal,
      sym_string_literal,
      sym_boolean_literal,
  [37] = 9,
    ACTIONS(17), 1,
      ts_builtin_sym_end,
    ACTIONS(19), 1,
      sym_decimal_literal,
    ACTIONS(25), 1,
      anon_sym_SQUOTE,
    ACTIONS(28), 1,
      anon_sym_DQUOTE,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym__primary_expression,
      sym_literal,
    ACTIONS(22), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(3), 3,
      sym__item,
      sym_expression,
      aux_sym_source_file_repeat1,
    STATE(13), 4,
      sym_integer_literal,
      sym_character_literal,
      sym_string_literal,
      sym_boolean_literal,
  [74] = 5,
    ACTIONS(36), 1,
      anon_sym_BSLASHx,
    ACTIONS(38), 1,
      anon_sym_DQUOTE,
    ACTIONS(40), 1,
      aux_sym_string_literal_token1,
    STATE(6), 4,
      sym__quote_escape,
      sym__ascii_escape,
      sym__unicode_escape,
      aux_sym_string_literal_repeat1,
    ACTIONS(34), 9,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
      aux_sym_unicode_escape_token1,
      sym__string_continuation,
  [101] = 5,
    ACTIONS(45), 1,
      anon_sym_BSLASHx,
    ACTIONS(48), 1,
      anon_sym_DQUOTE,
    ACTIONS(50), 1,
      aux_sym_string_literal_token1,
    STATE(5), 4,
      sym__quote_escape,
      sym__ascii_escape,
      sym__unicode_escape,
      aux_sym_string_literal_repeat1,
    ACTIONS(42), 9,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
      aux_sym_unicode_escape_token1,
      sym__string_continuation,
  [128] = 5,
    ACTIONS(36), 1,
      anon_sym_BSLASHx,
    ACTIONS(55), 1,
      anon_sym_DQUOTE,
    ACTIONS(57), 1,
      aux_sym_string_literal_token1,
    STATE(5), 4,
      sym__quote_escape,
      sym__ascii_escape,
      sym__unicode_escape,
      aux_sym_string_literal_repeat1,
    ACTIONS(53), 9,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
      aux_sym_unicode_escape_token1,
      sym__string_continuation,
  [155] = 6,
    ACTIONS(59), 1,
      aux_sym_character_literal_token1,
    ACTIONS(63), 1,
      anon_sym_BSLASHx,
    ACTIONS(67), 1,
      aux_sym_unicode_escape_token1,
    ACTIONS(61), 2,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
    STATE(19), 3,
      sym_quote_escape,
      sym_ascii_escape,
      sym_unicode_escape,
    ACTIONS(65), 5,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
  [181] = 2,
    ACTIONS(71), 1,
      aux_sym_string_literal_token1,
    ACTIONS(69), 11,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
      anon_sym_BSLASHx,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
      aux_sym_unicode_escape_token1,
      anon_sym_DQUOTE,
      sym__string_continuation,
  [198] = 3,
    ACTIONS(75), 1,
      sym_suffix_no_e,
    ACTIONS(77), 3,
      sym_decimal_literal,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(73), 6,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [215] = 2,
    ACTIONS(81), 1,
      sym_decimal_literal,
    ACTIONS(79), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [229] = 2,
    ACTIONS(85), 1,
      sym_decimal_literal,
    ACTIONS(83), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [243] = 2,
    ACTIONS(89), 1,
      sym_decimal_literal,
    ACTIONS(87), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [257] = 2,
    ACTIONS(93), 1,
      sym_decimal_literal,
    ACTIONS(91), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [271] = 2,
    ACTIONS(97), 1,
      sym_decimal_literal,
    ACTIONS(95), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [285] = 2,
    ACTIONS(101), 1,
      sym_decimal_literal,
    ACTIONS(99), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [299] = 2,
    ACTIONS(105), 1,
      sym_decimal_literal,
    ACTIONS(103), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [313] = 1,
    ACTIONS(107), 1,
      ts_builtin_sym_end,
  [317] = 1,
    ACTIONS(109), 1,
      aux_sym_ascii_escape_token1,
  [321] = 1,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
  [325] = 1,
    ACTIONS(113), 1,
      anon_sym_SQUOTE,
  [329] = 1,
    ACTIONS(115), 1,
      aux_sym_ascii_escape_token2,
  [333] = 1,
    ACTIONS(117), 1,
      aux_sym_ascii_escape_token2,
  [337] = 1,
    ACTIONS(119), 1,
      anon_sym_SQUOTE,
  [341] = 1,
    ACTIONS(121), 1,
      aux_sym_ascii_escape_token1,
  [345] = 1,
    ACTIONS(123), 1,
      anon_sym_SQUOTE,
  [349] = 1,
    ACTIONS(125), 1,
      anon_sym_SQUOTE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 37,
  [SMALL_STATE(4)] = 74,
  [SMALL_STATE(5)] = 101,
  [SMALL_STATE(6)] = 128,
  [SMALL_STATE(7)] = 155,
  [SMALL_STATE(8)] = 181,
  [SMALL_STATE(9)] = 198,
  [SMALL_STATE(10)] = 215,
  [SMALL_STATE(11)] = 229,
  [SMALL_STATE(12)] = 243,
  [SMALL_STATE(13)] = 257,
  [SMALL_STATE(14)] = 271,
  [SMALL_STATE(15)] = 285,
  [SMALL_STATE(16)] = 299,
  [SMALL_STATE(17)] = 313,
  [SMALL_STATE(18)] = 317,
  [SMALL_STATE(19)] = 321,
  [SMALL_STATE(20)] = 325,
  [SMALL_STATE(21)] = 329,
  [SMALL_STATE(22)] = 333,
  [SMALL_STATE(23)] = 337,
  [SMALL_STATE(24)] = 341,
  [SMALL_STATE(25)] = 345,
  [SMALL_STATE(26)] = 349,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [19] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(9),
  [22] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(9),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(7),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(4),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(11),
  [34] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [36] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [38] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [40] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [42] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(5),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(18),
  [48] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(5),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__ascii_escape, 3),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ascii_escape, 3),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_literal, 1),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_literal, 1),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean_literal, 1),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 1),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literal, 1),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_literal, 2, .production_id = 1),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_literal, 2, .production_id = 1),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3),
  [101] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_literal, 3),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_character_literal, 3),
  [107] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unicode_escape, 1),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ascii_escape, 1),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ascii_escape, 3),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote_escape, 1),
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
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
